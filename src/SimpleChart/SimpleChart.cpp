
#include <cmath>
#include "SimpleChart.hpp"
#include "../Functions/FuzzyLogicFunctions.hpp"
#include "../SelectFunction.hpp"

// Initialize all the objects that are be drawn
SimpleChart::SimpleChart(int function)
        : xAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , yAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , graphWindow((WINDOW_WIDTH - AXIS_SIZE) / 2, (WINDOW_HEIGHT - AXIS_SIZE) / 2, AXIS_SIZE, AXIS_SIZE)
        , quicksandFontBold()
        , quicksandFontRegular()
        , title()
        , functionName()
        , variables(function, (int)scale)
{
    this->function = function;
}

void SimpleChart::init()
{
    // Set the time to zero
    time = sf::Time(sf::Time::Zero);
    // initialize the axis
    xAxis.setOrigin(xAxis.getLocalBounds().width / 2, xAxis.getLocalBounds().height / 2);
    yAxis.setOrigin(yAxis.getLocalBounds().width / 2, yAxis.getLocalBounds().height / 2);
    xAxis.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    yAxis.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    yAxis.rotate(90);
    xAxis.setFillColor(AXIS_COLOR);
    yAxis.setFillColor(AXIS_COLOR);

    // Load the fonts
    quicksandFontBold.loadFromFile(QUICKSAND_BOLD_FONT);
    quicksandFontRegular.loadFromFile(QUICKSAND_REGULAR_FONT);

    // Initialize the title
    title.setString(SIMPLE_TITLE_STRING);
    title.setFont(quicksandFontBold);
    title.setPosition(SIMPLE_TITLE_POS_X, SIMPLE_TITLE_POS_Y);
    title.setCharacterSize((uint)SIMPLE_TITLE_SIZE);

    // initialize the function name
    functionName.setString(getFunctionTitle());
    functionName.setFont(quicksandFontRegular);
    functionName.setPosition(SIMPLE_FUNCTION_POS_X, SIMPLE_FUNCTION_POS_Y);
    functionName.setCharacterSize((uint)SIMPLE_FUNCTION_SIZE);

    // initialize the variable names
    for (int i = 0; i < variables.index.size(); i++) {
        sf::Text newVariableName;
        variableNames.push_back(newVariableName);
        variableNames[i].setFont(quicksandFontBold);
        variableNames[i].setPosition(SIMPLE_OPTION_POS_X[i], SIMPLE_OPTION_POS_Y);
        variableNames[i].setCharacterSize((uint)SIMPLE_OPTION_SIZE);

        // Set the string of the variable names
        variableNames[i].setString(SIMPLE_OPTION[variables.index[i]]);
    }

    // initialize the values of the variables
    for (int i = 0; i < variables.index.size(); i++) {
        sf::Text newVariableValue;
        variableValue.push_back(newVariableValue);
        variableValue[i].setFont(quicksandFontRegular);
        variableValue[i].setPosition(SIMPLE_OPTION_POS_X[i], SIMPLE_OPTION_VALUE_POS_Y);
        variableValue[i].setCharacterSize((uint)SIMPLE_OPTION_SIZE);
    }

    // nitialize the annotations
    for (int i = 0; i < 3; i++) {
        sf::Text newAnnotation;
        annotation.push_back(newAnnotation);
        annotation[i].setFont(quicksandFontRegular);
        annotation[i].setString(ANNOTATION[i]);
        annotation[i].setPosition(ANNOTATION_POS_X, ANNOTATION_POS_Y[i]);
        annotation[i].setCharacterSize((uint)ANNOTATION_SIZE);
    }

    // Start the axis with the default scale
    updateScale();
    // Start the points with the default variables and scale
    updatePoints();

    // initialize the selected option
    selected = 0;
}

void SimpleChart::update()
{
    time += clock.restart();
    if (time > sf::seconds(KEYBOARD_DELAY)) {
        // If user presses escape the window goes back to the function selector
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            this->changeState(this->stateManager, new SelectFunction());
        }

        // If the user presses "+", the chart zooms in
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add) && !addKey) {
            zoomIn();
            updatePoints();
            variables.setScale((int)scale);
        }

        // If the user presses "+", the chart zooms out
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract) && !subtractKey) {
            zoomOut();
            updatePoints();
            variables.setScale((int)scale);
        }
    }

    // If the user presses R, the selected variable randomize
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && !rKey) {
        variables.randomize(selected);
        updatePoints();
    }

    // If the user presses up, the selected variable increase
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        variables.increase(selected);
        updatePoints();
    }

    // If the user presses down, the selected variable decrease
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        variables.decrease(selected);
        updatePoints();
    }

    // If the user presses left, the variable at the left is selected
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !leftKey)
        selected--;

    // If the user presses right, the selected variable at the right is selected
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !rightKey)
        selected++;

    // Check if the selected variable reached the end of a side
    if (selected < 0)
        selected = (int)(variables.index.size() - 1);
    else if (selected >= (int)(variables.index.size()))
        selected = 0;

    // Check if a key is holded
    addKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add);
    subtractKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract);
    rKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R);
    leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

void SimpleChart::draw(sf::RenderWindow* window)
{
    // Draw the axis, the title and the function name
    window->draw(xAxis);
    window->draw(yAxis);
    window->draw(title);
    window->draw(functionName);

    // Draw the x axis numbers
    for (sf::Text t : xAxisNumbers) {
        if (t.getString() != "0" && (int)t.getPosition().x % (int)pixelsByGroup == 0)
            window->draw(t);
    }

    // Draw the y axis numbers
    for (sf::Text t : yAxisNumbers) {
        if (t.getString() != "0" && (int)t.getPosition().y % (int)pixelsByGroup == 0)
            window->draw(t);
    }

    // Draw the points
    for (sf::CircleShape p : points) {
        if (graphWindow.contains(p.getPosition()))
            window->draw(p);
    }

    // Set the color of the variable names
    for (int i = 0; i < variables.index.size(); i++) {
        variableNames[i].setColor(TEXT_COLOR);
    }

    // Set the color of the selected variable
    variableNames[selected].setColor(TEXT_COLOR_SELECTED);

    // Draw the variable names
    for (sf::Text t : variableNames)
        window->draw(t);

    // Draw the annotation
    for (sf::Text t: annotation)
        window->draw(t);

    // Set the color of the variable
    for (int i = 0; i < variables.index.size(); i++) {
        variableValue[i].setColor(TEXT_COLOR);
    }

    // Draw the values of variables
    variableValue[selected].setColor(TEXT_COLOR_SELECTED);
    for (sf::Text t : variableValue)
        window->draw(t);
}

void SimpleChart::destroy()
{
    // Doesn't need a destroy method
}

// Update the scale after there is a zoom in or out
void SimpleChart::updateScale()
{
    if (scale <= 9)             pixelsByGroup = 1;
    else if (scale == 10)       pixelsByGroup = 10;
    pixelsByUnit = AXIS_SIZE / ((int)scale * 2);
    updateAxis();
}

// Update the points after there is an update of variables
void SimpleChart::updatePoints()
{
    if (!points.empty())
        points.clear();
    int i = 0;
    for (float p = -scale; p <= scale; p += EPSILON) {
        sf::CircleShape newPoint(1);
        points.push_back(newPoint);
        points[i].setPosition(WINDOW_WIDTH / 2 + p * pixelsByUnit, WINDOW_HEIGHT / 2 - f(p) * pixelsByUnit);
        i++;
    }
    // Then update the text values of variables
    updateVariableValues();
}

// Function that decrease the scale of the axis
void SimpleChart::zoomIn()
{
    if (scale > MIN_SCALE) {
        scale--;
        updateScale();
    }
}

// Function that increase the scale of the axis
void SimpleChart::zoomOut()
{
    if (scale < MAX_SCALE) {
        scale++;
        updateScale();
    }
}

// Function that updates axis numbers
void SimpleChart::updateAxis()
{
    // Clear the x axis numbers if it's not empty
    if (!xAxisNumbers.empty())
        xAxisNumbers.clear();

    // Initiialize new x axis numbers
    for (int i = 0; i <= scale * 2; i++) {
        sf::Text newText;
        xAxisNumbers.push_back(newText);
        xAxisNumbers[i].setFont(quicksandFontBold);
        int number = i - (int)scale;
        std::stringstream ss;
        ss << number;
        std::string s = ss.str();
        xAxisNumbers[i].setString(s);
        xAxisNumbers[i].setOrigin(xAxisNumbers[i].getLocalBounds().width / 2, xAxisNumbers[i].getLocalBounds().height / 2);
        xAxisNumbers[i].setCharacterSize(15);
        xAxisNumbers[i].setOrigin(xAxisNumbers[i].getLocalBounds().width / 2,
                                  xAxisNumbers[i].getLocalBounds().height / 2);
        xAxisNumbers[i].setPosition(WINDOW_WIDTH / 2 + number * pixelsByUnit, WINDOW_HEIGHT / 2 + 10);
    }

    // Clear the y axis numbers if it's not empty
    if (!yAxisNumbers.empty())
        yAxisNumbers.clear();

    // Initiialize new x axis numbers
    for (int i = 0; i <= scale * 2; i++) {
        sf::Text newText;
        yAxisNumbers.push_back(newText);
        yAxisNumbers[i].setFont(quicksandFontBold);
        std::stringstream ss;
        int number = i - (int)scale;
        ss << number;
        std::string s = ss.str();
        yAxisNumbers[i].setString(s);
        yAxisNumbers[i].setOrigin(yAxisNumbers[i].getLocalBounds().width / 2, yAxisNumbers[i].getLocalBounds().height / 2);
        yAxisNumbers[i].setCharacterSize(15);
        yAxisNumbers[i].setOrigin(yAxisNumbers[i].getLocalBounds().width / 2,
                                  yAxisNumbers[i].getLocalBounds().height / 2);
        yAxisNumbers[i].setPosition(WINDOW_WIDTH / 2 - 10, WINDOW_HEIGHT / 2 - number * pixelsByUnit);
    }
}

// Function that returns the name of the funciton dependinf ot its number
std::string SimpleChart::getFunctionTitle()
{
    std::string functionName = "Funcion ";
    switch(function) {
        case Triangular:
            functionName += "Triangular";
            break;
        case Function::FuncionR:
            functionName += "r (Gamma)";
            break;
        case Function::FuncionG:
            functionName += "G (Gamma)";
            break;
        case Function::FuncionS:
            functionName += "S";
            break;
        case Function::Gausiana:
            functionName += "Gausiana";
            break;
        case Function::Trapezoidal:
            functionName += "Trapezoidal";
            break;
        case Function::PseudoExponencial:
            functionName += "Pseudo Exponencial";
            break;
        default:
            break;
    }
    return functionName;
}

// Function that updates the values of variables
void SimpleChart::updateVariableValues()
{
    std::vector<std::string> variableString = variables.getVariableString();
    for (int i = 0; i < variables.index.size(); i++) {
        variableValue[i].setString(variableString[i]);
    }
}

// Function that exchanges one function of type f(x) by one of type f(x, a, b, c, d, m, k)
float SimpleChart::f(float x)
{
    switch (function) {
        case Function::Triangular:
            return Functions::triangular(x, variables);
        case Function::FuncionR:
            return Functions::funcionR(x, variables);
        case Function::FuncionG:
            return Functions::funcionG(x, variables);
        case Function::FuncionS:
            return Functions::funcionS(x, variables);
        case Function::Gausiana:
            return Functions::gausiana(x, variables);
        case Function::Trapezoidal:
            return Functions::trapezoidal(x, variables);
        case Function::PseudoExponencial:
            return Functions::pseudoExponencial(x, variables);
        default:
            return 1;
    }
}
