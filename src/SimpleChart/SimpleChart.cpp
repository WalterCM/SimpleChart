
#include <cmath>
#include "SimpleChart.hpp"
#include "../Functions/Functions.hpp"
#include "../SelectFunction.hpp"

SimpleChart::SimpleChart(int function)
        : xAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , yAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , graphWindow((WINDOW_WIDTH - AXIS_SIZE) / 2, (WINDOW_HEIGHT - AXIS_SIZE) / 2, AXIS_SIZE, AXIS_SIZE)
        , font()
        , title()
        , functionName()
        , variables(function, (int)scale)
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

    for (int i = 0; i < variables.index.size(); i++) {
        sf::Text newVariableName;
        variableNames.push_back(newVariableName);
        variableNames[i].setFont(font);
        variableNames[i].setString(SIMPLE_OPTION[variables.index[i]]);
        variableNames[i].setPosition(SIMPLE_OPTION1_POS_X[i], SIMPLE_OPTION_POS_Y);
        variableNames[i].setCharacterSize(SIMPLE_OPTION_SIZE);
    }

    for (int i = 0; i < variables.index.size(); i++) {
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
    time += clock.restart();
    if (time > sf::seconds(KEYBOARD_DELAY)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            this->changeState(this->stateManager, new SelectFunction());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add)) {
            zoomIn();
            updatePoints();
            variables.setScale((int)scale);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract)) {
            zoomOut();
            updatePoints();
            variables.setScale((int)scale);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        variables.increase(selected);
        updatePoints();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        variables.decrease(selected);
        updatePoints();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && !rKey) {
        variables.randomize(selected);
        updatePoints();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !leftKey)
        selected--;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !rightKey)
        selected++;
    if (selected < 0)
        selected = (int)(variables.index.size() - 1);
    else if (selected >= (int)(variables.index.size()))
        selected = 0;

    rKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R);
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

    for (sf::CircleShape p : points) {
        if (graphWindow.contains(p.getPosition()))
            window->draw(p);
    }
    for (int i = 0; i < variables.index.size(); i++) {
        variableNames[i].setColor(TEXT_COLOR);
    }

    variableNames[selected].setColor(TEXT_COLOR_SELECTED);
    for (sf::Text t : variableNames)
        window->draw(t);

    for (int i = 0; i < variables.index.size(); i++) {
        variableValue[i].setColor(TEXT_COLOR);
    }

    variableValue[selected].setColor(TEXT_COLOR_SELECTED);
    for (sf::Text t : variableValue)
        window->draw(t);
}

void SimpleChart::destroy()
{}

void SimpleChart::updateScale()
{
    /*if (firstGraphNumber <= 9)          pixelsByGroup = 1;
    else if (firstGraphNumber <= 19)    pixelsByGroup = 10;
    else                                pixelsByGroup = 50; */
    pixelsByGroup = 1;
    pixelsByUnit = AXIS_SIZE / ((int)scale * 2);
    updateAxis();
}

void SimpleChart::updatePoints()
{
    if (!points.empty())
        points.clear();
    int i = 0;
    for (float p = -scale; p <= scale; p += epsilon) {
        sf::CircleShape newPoint(1);
        points.push_back(newPoint);
        points[i].setPosition(WINDOW_WIDTH / 2 + p * pixelsByUnit, WINDOW_HEIGHT / 2 - f(p) * pixelsByUnit);
        i++;
    }

    updateVariableValues();
}

void SimpleChart::zoomIn()
{
    if (scale - 1 > 1) {
        scale--;
        updateScale();
    }
}

void SimpleChart::zoomOut()
{
    scale++;
    updateScale();
}

void SimpleChart::updateAxis()
{
    if (!xAxisNumbers.empty())
        xAxisNumbers.clear();
    for (int i = 0; i <= scale * 2; i++) {
        sf::Text newText;
        xAxisNumbers.push_back(newText);
        xAxisNumbers[i].setFont(font);
        int number = i - scale;
        std::stringstream ss;
        ss << number;
        std::string s = ss.str();
        xAxisNumbers[i].setString(s);
        xAxisNumbers[i].setCharacterSize(15);
        xAxisNumbers[i].setOrigin(xAxisNumbers[i].getLocalBounds().width / 2,
                                  xAxisNumbers[i].getLocalBounds().height / 2);
        xAxisNumbers[i].setPosition(WINDOW_WIDTH / 2 + number * pixelsByUnit, WINDOW_HEIGHT / 2 + 10);
    }

    if (!yAxisNumbers.empty())
        yAxisNumbers.clear();
    for (int i = 0; i <= scale * 2; i++) {
        sf::Text newText;
        yAxisNumbers.push_back(newText);
        yAxisNumbers[i].setFont(font);

        std::stringstream ss;
        int number = i - scale;
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
    std::vector<std::string> variableString = variables.getVariableString();
    for (int i = 0; i < variables.index.size(); i++) {
        variableValue[i].setString(variableString[i]);
    }
}

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
