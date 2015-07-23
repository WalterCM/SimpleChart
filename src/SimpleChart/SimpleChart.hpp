
#ifndef SIMPLECHART_SIMPLECHART_HPP
#define SIMPLECHART_SIMPLECHART_HPP

#include "../StateManager.hpp"
#include "VariablesHandler.hpp"

class SimpleChart : public ProgramState
{
public:
                                    SimpleChart(int);

    void                            init();
    void                            update();
    void                            draw(sf::RenderWindow *window);
    void                            destroy();

private:
    // Functions of scale
    void                            updateScale();
    void                            updatePoints();
    void                            zoomIn();
    void                            zoomOut();

    // Functions of object updates
    void                            updateAxis();
    std::string                     getFunctionTitle();
    void                            updateVariableValues();

    // Main method that connects Simple Chart with the math functions
    float                           f(float x);

    // Drawable objects for the chart
    sf::RectangleShape              xAxis;
    sf::RectangleShape              yAxis;
    std::vector<sf::Text>           xAxisNumbers;
    std::vector<sf::Text>           yAxisNumbers;
    std::vector<sf::Text>           variableNames;
    std::vector<sf::Text>           variableValue;
    std::vector<sf::Text>           annotation;
    sf::Text                        title;
    sf::Text                        functionName;

    // Font for the text
    sf::Font                        quicksandFontBold;
    sf::Font                        quicksandFontRegular;

    // Little window inside the main window to avoid values that don't need to be drawn
    sf::Rect<float>                 graphWindow;
    std::vector<sf::CircleShape>    points;

    // Scale of axis
    float                           scale = 5;

    // Scale helpers
    float                           pixelsByUnit;
    float                           pixelsByGroup;

    // Function number
    int                             function;

    // Variables for keyboard support
    int                             selected;
    bool                            leftKey, rightKey;
    bool                            addKey, subtractKey;
    bool                            rKey;

    // Object that stores all the variable values as well as the functions used to randomize and edit
    VariablesHandler                variables;
};

#endif //SIMPLECHART_SIMPLECHART_HPP
