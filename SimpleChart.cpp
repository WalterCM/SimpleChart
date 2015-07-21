#include <iostream>
#include <sstream>
#include <cmath>
#include "SimpleChart.hpp"
#include "ProgramConstants.hpp"
#include "Functions.hpp"
#include "SelectFunction.hpp"
using namespace std;
SimpleChart::SimpleChart(int function)
        : xAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , yAxis(sf::Vector2f(AXIS_SIZE, AXIS_THICKNESS))
        , graphWindow((WINDOW_WIDTH - AXIS_SIZE) / 2, (WINDOW_HEIGHT - AXIS_SIZE) / 2, AXIS_SIZE, AXIS_SIZE)
        , font()
        , title()
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
}

void SimpleChart::update()
{
    updateScale();
    for (int i = 0; i <= numberOfPoints; i++) {
        sf::CircleShape newPoint(1);
        points.push_back(newPoint);
    }
    initializeAxis();

    time += clock.restart();
    if (time > sf::seconds(KEYBOARD_DELAY)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
            this->changeState(this->stateManager, new SelectFunction());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !upKey)
        variable.increase(selected);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !downKey)
        variable.decrease(selected);
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

    int i = 0;
    for (float p = lo; p <= hi; p += epsilon) {
    points[i].setPosition(WINDOW_WIDTH / 2 + p * pixelsByUnit, WINDOW_HEIGHT / 2 - f(p) * pixelsByUnit);
        i++;
    }
}

void SimpleChart::draw(sf::RenderWindow* window)
{
    window->draw(xAxis);
    window->draw(yAxis);
    window->draw(title);

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
}

void SimpleChart::destroy()
{}

void SimpleChart::updateScale()
{
    range = hi - lo;
    firstGraphNumber = (int)std::max(abs((int)hi), abs((int)lo));
    if (firstGraphNumber <= 9)          pixelsByGroup = 1;
    else if (firstGraphNumber <= 19)    pixelsByGroup = 10;
    else                                pixelsByGroup = 50;
    pixelsByUnit = AXIS_SIZE / (firstGraphNumber * 2);
    numberOfPoints = (int)(range / epsilon);
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


