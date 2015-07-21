
#ifndef SIMPLECHART_SIMPLECHART_HPP
#define SIMPLECHART_SIMPLECHART_HPP

#include "StateManager.hpp"
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
    void                            initializeAxis();
    float                           f(float x);

    sf::RectangleShape              xAxis;
    sf::RectangleShape              yAxis;

    sf::Font                        font;
    std::vector<sf::Text>           xAxisNumbers;
    std::vector<sf::Text>           yAxisNumbers;

    sf::Text                        title;
    sf::Text                        functionName;

    sf::Rect<float>                 graphWindow;
    std::vector<sf::CircleShape>    points;

    const float                     epsilon = 0.01f;
    
    float                           lo = -5;
    float                           hi = 5;
    int                             numberOfPoints;
    float                           range;
    int                             firstGraphNumber;

    int                             pixelsByUnit;
    int                             pixelsByGroup;

    int                             function;

    int                             selected;
    bool                            upKey, downKey;
    bool                            leftKey, rightKey;

    VariablesHandler                variable;
};

#endif //SIMPLECHART_SIMPLECHART_HPP
