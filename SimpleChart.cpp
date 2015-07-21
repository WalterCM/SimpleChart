
#include <cmath>
#include "SimpleChart.hpp"
#include "Functions.hpp"
#include "SelectFunction.hpp"

SimpleChart::SimpleChart(int function)
        : xAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , yAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , graphWindow((WINDOW_WIDTH - AXIS_SIZE) / 2, (WINDOW_HEIGHT - AXIS_SIZE) / 2, AXIS_SIZE, AXIS_SIZE)
        , font()
        , title()
        , functionName()
{
    this->function = function;
}

void SimpleChart::init()
{
    time = sf::Time(sf::Time::Zero);
    xAxis.setOrigin(xAxis.getLocalBounds().width / 2, xAxis.getLocalBounds().height / 2);
    yAxis.setOrigin(yAxis.getLocalBounds().width / 2, yAxis.getLocalBounds().height / 2);
    xAxis.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    yAxis.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    yAxis.rotate(90);

    xAxis.setFillColor(AXIS_COLOR);
    yAxis.setFillColor(AXIS_COLOR);

    font.loadFromFile(PROGRAM_FONT);
    title.setString(SIMPLE_TITLE_STRING);
    title.setFont(font);
    title.setPosition(SIMPLE_TITLE_POS_X, SIMPLE_TITLE_POS_Y);
    title.setCharacterSize(SIMPLE_TITLE_SIZE);

    functionName.setString(getFunctionTitle());
    functionName.setFont(font);
    functionName.setPosition(SIMPLE_FUNCTION_POS_X, SIMPLE_FUNCTION_POS_Y);
    functionName.setCharacterSize(SIMPLE_FUNCTION_SIZE);

    for (int i = 0; i < SIMPLE_NUMBER_OPTIONS; i++) {
        sf::Text newVariableName;
        variableNames.push_back(newVariableName);
        variableNames[i].setFont(font);
        variableNames[i].setString(SIMPLE_OPTION[i]);
        variableNames[i].setPosition(SIMPLE_OPTION1_POS_X[i], SIMPLE_OPTION_POS_Y);
        variableNames[i].setCharacterSize(SIMPLE_OPTION_SIZE);
    }

    for (int i = 0; i < SIMPLE_NUMBER_OPTIONS; i++) {
        sf::Text newVariableValue;
        variableValue.push_back(newVariableValue);
        variableValue[i].setFont(font);
        variableValue[i].setPosition(SIMPLE_OPTION1_POS_X[i], SIMPLE_OPTION_VALUE_POS_Y);
        variableValue[i].setCharacterSize(SIMPLE_OPTION_SIZE);
    }
    updateScale();
    updatePoints();

    selected = 0;
}

void SimpleChart::update()
{
    initializeAxis();
    updateVariableValues();

    time += clock.restart();
    if (time > sf::seconds(KEYBOARD_DELAY)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
            this->changeState(this->stateManager, new SelectFunction());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        variable.increase(selected);
        updatePoints();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        variable.decrease(selected);
        updatePoints();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !leftKey)
        selected--;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !rightKey)
        selected++;
    if (selected < 0)
        selected = SIMPLE_NUMBER_OPTIONS - 1;
    else if (selected >= SIMPLE_NUMBER_OPTIONS)
        selected = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
        switch (selected) {
            default:
                break;
        }
    }

    upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

void SimpleChart::draw(sf::RenderWindow* window)
{
    window->draw(xAxis);
    window->draw(yAxis);
    window->draw(title);
    window->draw(functionName);

    for (sf::Text t : xAxisNumbers) {
        if (t.getString() != "0" && (int)t.getPosition().x % pixelsByGroup == 0)
            window->draw(t);
    }

    for (sf::Text t : yAxisNumbers) {
        if (t.getString() != "0" && (int)t.getPosition().y % pixelsByGroup == 0)
            window->draw(t);
    }

    for (sf::CircleShape* p : points) {
        if (graphWindow.contains(p->getPosition()))
            window->draw(*p);
    }
    for (int i = 0; i < SIMPLE_NUMBER_OPTIONS; i++) {
        variableNames[i].setColor(TEXT_COLOR);
    }

    variableNames[selected].setColor(TEXT_COLOR_SELECTED);
    for (sf::Text t : variableNames)
        window->draw(t);

    for (int i = 0; i < SIMPLE_NUMBER_OPTIONS; i++) {
        variableValue[i].setColor(TEXT_COLOR);
    }

    variableValue[selected].setColor(TEXT_COLOR_SELECTED);
    for (sf::Text t : variableValue)
        window->draw(t);
}

void SimpleChart::destroy()
{
    for (sf::CircleShape* p : points) {
        delete p;
        points.pop_back();
    }
}

void SimpleChart::updateScale()
{
    range = hi - lo;
    firstGraphNumber = (int)std::max(abs((int)hi), abs((int)lo));
    if (firstGraphNumber <= 9)          pixelsByGroup = 1;
    else if (firstGraphNumber <= 19)    pixelsByGroup = 10;
    else                                pixelsByGroup = 50;
    pixelsByUnit = AXIS_SIZE / (firstGraphNumber * 2);
}

void SimpleChart::updatePoints()
{
    if (!points.empty())
        destroy();
    int i = 0;
    for (float p = lo; p <= hi; p += epsilon) {
        points.push_back(new sf::CircleShape(1));
        points[i]->setPosition(WINDOW_WIDTH / 2 + p * pixelsByUnit, WINDOW_HEIGHT / 2 - f(p) * pixelsByUnit);
        i++;
    }
}

void SimpleChart::initializeAxis()
{
    for (int i = 0; i <= firstGraphNumber * 2; i++) {
        sf::Text newText;
        xAxisNumbers.push_back(newText);
        xAxisNumbers[i].setFont(font);
        int number = i - firstGraphNumber;
        std::stringstream ss;
        ss << number;
        std::string s = ss.str();
        xAxisNumbers[i].setString(s);
        xAxisNumbers[i].setCharacterSize(15);
        xAxisNumbers[i].setOrigin(xAxisNumbers[i].getLocalBounds().width / 2,
                                  xAxisNumbers[i].getLocalBounds().height / 2);
        xAxisNumbers[i].setPosition(WINDOW_WIDTH / 2 + number * pixelsByUnit, WINDOW_HEIGHT / 2 + 10);
    }

    for (int i = 0; i <= firstGraphNumber * 2; i++) {
        sf::Text newText;
        yAxisNumbers.push_back(newText);
        yAxisNumbers[i].setFont(font);

        std::stringstream ss;
        int number = i - firstGraphNumber;
        ss << number;
        std::string s = ss.str();
        yAxisNumbers[i].setString(s);
        yAxisNumbers[i].setCharacterSize(15);
        yAxisNumbers[i].setOrigin(yAxisNumbers[i].getLocalBounds().width / 2,
                                  yAxisNumbers[i].getLocalBounds().height / 2);
        yAxisNumbers[i].setPosition(WINDOW_WIDTH / 2 - 10, WINDOW_HEIGHT / 2 - number * pixelsByUnit);
    }
}

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

void SimpleChart::updateVariableValues()
{
    std::array<std::string, SIMPLE_NUMBER_OPTIONS> variableString = variable.getVariableString();
    for (int i = 0; i < SIMPLE_NUMBER_OPTIONS; i++) {
        variableValue[i].setString(variableString[i]);
    }
}

float SimpleChart::f(float x)
{
    switch (function) {
        case Function::Triangular:
            return triangular(x, variable);
        case Function::FuncionR:
            return funcionR(x, variable);
        case Function::FuncionG:
            return funcionG(x, variable);
        case Function::FuncionS:
            return funcionS(x, variable);
        case Function::Gausiana:
            return gausiana(x, variable);
        case Function::Trapezoidal:
            return trapezoidal(x, variable);
        case Function::PseudoExponencial:
            return pseudoExponencial(x, variable);
        default:
            return 1;
    }
}
