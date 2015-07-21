
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
    enum Option {
        Draw,
        Quit
    };
    sf::Font    font;
    sf::Text    title;
    std::array<sf::Text, MENU_NUMBER_OPTIONS> option;

    int         selected;
    bool        upKey, downKey;
    bool        leftKey, rightKey;
};

#endif //SIMPLECHART_MAINMENU_HPP
