
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
    void                            updateScale();
    void                            updatePoints();
    void                            zoomIn();
    void                            zoomOut();

    void                            updateAxis();
    std::string                     getFunctionTitle();
    void                            updateVariableValues();
    float                           f(float x);

    sf::RectangleShape              xAxis;
    sf::RectangleShape              yAxis;

    std::vector<sf::Text>           xAxisNumbers;
    std::vector<sf::Text>           yAxisNumbers;

    std::vector<sf::Text>           variableNames;
    std::vector<sf::Text>           variableValue;

    sf::Font                        font;
    sf::Text                        title;
    sf::Text                        functionName;

    sf::Rect<float>                 graphWindow;
    std::vector<sf::CircleShape>    points;

    const float                     epsilon = 0.01f;

    float                           scale = 5;

    int                             pixelsByUnit;
    int                             pixelsByGroup;

    int                             function;

    int                             selected;
    bool                            leftKey, rightKey;
    bool                            rKey;

    VariablesHandler                variables;
};

#endif //SIMPLECHART_SIMPLECHART_HPP
