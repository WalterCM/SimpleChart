
#include "MainMenu.hpp"
#include "SelectFunction.hpp"

// The constructor initialize the variables
MainMenu::MainMenu()
        : titleFont()
        , optionFont()
        , title()
{}

void MainMenu::init() {
    // Start the timer
    time = sf::Time(sf::Time::Zero);

    // Load the fonts
    titleFont.loadFromFile(QUICKSAND_BOLD_FONT);
    optionFont.loadFromFile(QUICKSAND_REGULAR_FONT);

    // initialize the title
    title.setString(MENU_TITLE_STRING);
    title.setFont(titleFont);
    title.setCharacterSize(MENU_TITLE_SIZE);
    title.setColor(TEXT_COLOR);
    title.setOrigin(title.getGlobalBounds().width / 2,
                    title.getGlobalBounds().height / 2);
    title.setPosition(MENU_TITLE_POS_X, MENU_TITLE_POS_Y);

    // initialize the options
    for (int i = 0; i < MENU_NUMBER_OPTIONS; i++) {
        option[i].setString(MENU_OPTION[i]);
        option[i].setFont(optionFont);
        option[i].setCharacterSize(MENU_OPTION_SIZE);
        option[i].setColor(TEXT_COLOR);
        option[i].setOrigin(option[i].getGlobalBounds().width / 2, option[i].getGlobalBounds().height / 2);

        option[i].setPosition(MENU_OPTION_POS_X, MENU_OPTION_POS_Y[i]);
    }

    // initialize the selected option index
    selected = 0;
}

void MainMenu::update() {

    time += clock.restart();

    // Check if there is a key pressed to move the selected option
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
        // Check if the keys are holded
        upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
        leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
        rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    }
}

void MainMenu::draw(sf::RenderWindow *window)
{
    // Draw the title
    window->draw(title);

    // Set the color of the options the options
    for (int i = 0; i < MENU_NUMBER_OPTIONS; i++) {
        option[i].setColor(TEXT_COLOR);
    }

    // Change the color of the selected option
    option[selected].setColor(TEXT_COLOR_SELECTED);

    // Draw the options
    for (int i = 0; i < MENU_NUMBER_OPTIONS; i++)
        window->draw(option[i]);
}

void MainMenu::destroy()
{
    // Don't need a destroy method
}
