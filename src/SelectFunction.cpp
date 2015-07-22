
#include "SelectFunction.hpp"
#include "MainMenu.hpp"
#include "SimpleChart/SimpleChart.hpp"

SelectFunction::SelectFunction()
        : font()
        , title()
{}

void SelectFunction::init()
{
    time = sf::Time(sf::Time::Zero);

    font.loadFromFile(PROGRAM_FONT);

    title.setString(SELECTOR_TITLE_STRING);
    title.setFont(font);
    title.setCharacterSize(SELECTOR_TITLE_SIZE);

    title.setColor(TEXT_COLOR);
    title.setOrigin(title.getGlobalBounds().width / 2,
                    title.getGlobalBounds().height / 2);
    title.setPosition(SELECTOR_TITLE_POS_X, SELECTOR_TITLE_POS_Y);

    for (int i = 0; i < option.size(); i++) {
        option[i].setString(SELECTOR_OPTION[i]);
        option[i].setFont(font);
        option[i].setCharacterSize(SELECTOR_OPTION_SIZE);
        option[i].setColor(TEXT_COLOR);
        option[i].setOrigin(option[i].getGlobalBounds().width / 2, option[i].getGlobalBounds().height / 2);

        option[i].setPosition(SELECTOR_OPTION_POS_X, SELECTOR_OPTION1_POS_Y[i]);
    }

    selected = 0;
}

void SelectFunction::update()
{
    time += clock.restart();

    if (time > sf::seconds(KEYBOARD_DELAY)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            this->changeState(this->stateManager, new MainMenu());
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !upKey) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !leftKey))
            selected--;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !downKey) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !rightKey))
            selected++;
        if (selected < 0)
            selected = SELECTOR_NUMBER_OPTIONS - 1;
        else if (selected >= SELECTOR_NUMBER_OPTIONS)
            selected = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
            switch (selected) {
                case Back:
                    this->changeState(this->stateManager, new MainMenu());
                    break;
                default:
                    this->changeState(this->stateManager, new SimpleChart(selected));
                    break;
            }
        }

        upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
        leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
        rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    }
}

void SelectFunction::draw(sf::RenderWindow *window)
{
    for (int i = 0; i < SELECTOR_NUMBER_OPTIONS; i++) {
        option[i].setColor(TEXT_COLOR);
    }

    option[selected].setColor(TEXT_COLOR_SELECTED);

    window->draw(title);
    for (int i = 0; i < SELECTOR_NUMBER_OPTIONS; i++)
        window->draw(option[i]);
}

void SelectFunction::destroy()
{}
