
#ifndef SIMPLECHART_MAINMENU_HPP
#define SIMPLECHART_MAINMENU_HPP

#include "StateManager.hpp"
#include "ProgramConstants.hpp"

class MainMenu : public ProgramState
{
public:
                MainMenu();
    void        init();
    void        update();
    void        draw(sf::RenderWindow *window);
    void        destroy();

private:
    // Enum of options inside the main menu
    enum Option {
        Draw,
        Quit
    };

    // Different fonts for the title and the options
    sf::Font    titleFont;
    sf::Font    optionFont;
    sf::Text    title;

    // Array of sf::Text(options)
    std::array<sf::Text, MENU_NUMBER_OPTIONS> option;

    // Variables for keyboard support
    int         selected;
    bool        upKey, downKey;
    bool        leftKey, rightKey;
};

#endif //SIMPLECHART_MAINMENU_HPP
