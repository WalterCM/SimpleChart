
#include "MainMenu.hpp"
#include "SelectFunction.hpp"

MainMenu::MainMenu()
        : font()
        , title()
{}

void MainMenu::init() {
    time = sf::Time(sf::Time::Zero);

    font.loadFromFile(PROGRAM_FONT);

    title.setString(MENU_TITLE_STRING);
    title.setFont(font);
    title.setCharacterSize(MENU_TITLE_SIZE);

    title.setColor(TEXT_COLOR);
    title.setOrigin(title.getGlobalBounds().width / 2,
                    title.getGlobalBounds().height / 2);
    title.setPosition(MENU_TITLE_POS_X, MENU_TITLE_POS_Y);

    for (int i = 0; i < MENU_NUMBER_OPTIONS; i++) {

        option[i].setString(MENU_OPTION[i]);
        option[i].setFont(font);
        option[i].setCharacterSize(MENU_OPTION_SIZE);
        option[i].setColor(TEXT_COLOR);
        option[i].setOrigin(option[i].getGlobalBounds().width / 2, option[i].getGlobalBounds().height / 2);

        option[i].setPosition(MENU_OPTION_POS_X, MENU_OPTION1_POS_Y[i]);
    }

    selected = 0;
}

void MainMenu::update() {

    time += clock.restart();

    if (time > sf::seconds(KEYBOARD_DELAY)) {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !upKey) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !leftKey))
            selected--;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !downKey) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !rightKey))
            selected++;
        if (selected < 0)
            selected = MENU_NUMBER_OPTIONS - 1;
        else if (selected >= MENU_NUMBER_OPTIONS)
            selected = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
            switch (selected) {
                case Draw:
                    this->changeState(this->stateManager, new SelectFunction());
                    break;
                case Quit:
                    exit(0);
                default:
                    break;
            }
        }

        upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
        leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
        rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    }
}

void MainMenu::draw(sf::RenderWindow *window)
{
    for (int i = 0; i < MENU_NUMBER_OPTIONS; i++) {
        option[i].setColor(TEXT_COLOR);
    }

    option[selected].setColor(TEXT_COLOR_SELECTED);
    window->draw(title);
    for (int i = 0; i < MENU_NUMBER_OPTIONS; i++)
        window->draw(option[i]);
}

void MainMenu::destroy()
{}
