
#ifndef SIMPLECHART_SELECTFUNCTION_HPP
#define SIMPLECHART_SELECTFUNCTION_HPP

#include "StateManager.hpp"
#include "ProgramConstants.hpp"

class SelectFunction : public ProgramState {
public:
            SelectFunction();
    void    init();
    void    update();
    void    draw(sf::RenderWindow *window);
    void    destroy();

private:
    enum Option {
        Back = 7
    };

    sf::Font                                        titleFont;
    sf::Font                                        optionFont;
    sf::Text                                        title;
    std::array<sf::Text, SELECTOR_NUMBER_OPTIONS>   option;

    int     selected;
    bool    upKey, downKey;
    bool    leftKey, rightKey;
};

#endif //SIMPLECHART_SELECTFUNCTION_HPP
