
#ifndef SIMPLECHART_PROGRAMCONSTANTS_HPP
#define SIMPLECHART_PROGRAMCONSTANTS_HPP

#include <iostream>
#include <Graphics/Color.hpp>
#include <Window/VideoMode.hpp>

const float FPS = 120;                                  // Frames per second

// Width on the window
const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width;
// Height of the window
const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;

const std::string TITLE_STRING = "Simple Chart";        // Title of the program.
const sf::Color BACKGROUND_COLOR = sf::Color::Black;

// -----------------------------------------------------------------------------------------

// Constants for the menu
const std::string MENU_TITLE_STRING = "Simple Chart";    // Title of the menu
const int MENU_TITLE_SIZE = 100;                         // Size of the title
const float MENU_TITLE_POS_X = WINDOW_WIDTH / 2;         // Position of the title
const float MENU_TITLE_POS_Y = WINDOW_HEIGHT / 4;

const int MENU_NUMBER_OPTIONS = 2;                       // Number of optiosn in the menu
const std::string MENU_OPTION[] = {"Dibujar funcion", "Salir"};
const int MENU_OPTION_SIZE = 50;                         // Size of the options
const float MENU_OPTION_POS_X = WINDOW_WIDTH / 2;        // Position of each option
const float MENU_OPTION1_POS_Y[] = {    WINDOW_HEIGHT * 9 / 16,
                                        WINDOW_HEIGHT * 12 / 16};

// -----------------------------------------------------------------------------------------

// Constants for the Function Selector
const std::string SELECTOR_TITLE_STRING = "Seleccione una funcion";    // Title of the selector
const int SELECTOR_TITLE_SIZE = 50;                         // Size of the selector title
const float SELECTOR_TITLE_POS_X = WINDOW_WIDTH / 2;         // Position of the selector title
const float SELECTOR_TITLE_POS_Y = WINDOW_HEIGHT / 8;

const int SELECTOR_NUMBER_OPTIONS = 8;                       // Number of optiosn in the selector
const std::string SELECTOR_OPTION[] = {"Triangular", "Funcion r", "Funcion G", "Funcion S",
                                       "Gausiana", "Trapezoidal", "Pseudo-Exponencial", "Atras"};
const int SELECTOR_OPTION_SIZE = 50;                         // Size of the selector options
const float SELECTOR_OPTION_POS_X = WINDOW_WIDTH / 2;        // Position of each option
const float SELECTOR_OPTION1_POS_Y[] = {    WINDOW_HEIGHT * 5 / 16,
                                            WINDOW_HEIGHT * 6 / 16,
                                            WINDOW_HEIGHT * 7 / 16,
                                            WINDOW_HEIGHT * 8 / 16,
                                            WINDOW_HEIGHT * 9 / 16,
                                            WINDOW_HEIGHT * 10 / 16,
                                            WINDOW_HEIGHT * 11 / 16,
                                            WINDOW_HEIGHT * 13 / 16,};

// -----------------------------------------------------------------------------------------

// Constants for SimpleChart
const sf::Color AXIS_COLOR = sf::Color::Green;
const int AXIS_THICKNESS = 3;
const int AXIS_SIZE = 500;

const std::string SIMPLE_TITLE_STRING = "Simple Chart";    // Title of the chart
const int SIMPLE_TITLE_SIZE = 30;                          // Size of the title
const float SIMPLE_TITLE_POS_X = WINDOW_WIDTH / 16;         // Position of the title
const float SIMPLE_TITLE_POS_Y = WINDOW_HEIGHT / 16;

const int SIMPLE_FUNCTION_SIZE = 20;                          // Size of the title
const float SIMPLE_FUNCTION_POS_X = WINDOW_WIDTH / 16;         // Position of the title
const float SIMPLE_FUNCTION_POS_Y = WINDOW_HEIGHT / 8;

const std::string SIMPLE_OPTION[] = {"a", "b", "c", "d", "m", "k"};
const int SIMPLE_OPTION_SIZE = 20;                         // Size of the options
// Position of each option
const float SIMPLE_OPTION1_POS_X[] = {    WINDOW_WIDTH * 9 / 16,
                                          WINDOW_WIDTH * 10 / 16,
                                          WINDOW_WIDTH * 11 / 16,
                                          WINDOW_WIDTH * 12 / 16,
                                          WINDOW_WIDTH * 13 / 16,
                                          WINDOW_WIDTH * 14 / 16,
                                          WINDOW_WIDTH * 15 / 16,
                                          WINDOW_WIDTH * 16 / 16};
const float SIMPLE_OPTION_POS_Y = WINDOW_HEIGHT * 6 / 8;
const float SIMPLE_OPTION_VALUE_POS_Y = WINDOW_HEIGHT * 7 / 8;


// -----------------------------------------------------------------------------------------

const std::string DUMB_FONT = "../content/fonts/dumb/2Dumb.ttf";
const std::string QUICKSAND_BOLD_FONT = "../content/fonts/quicksand/Quicksand-Bold.otf";
const std::string QUICKSAND_REGULAR_FONT = "../content/fonts/quicksand/Quicksand-Regular.otf";
const sf::Color TEXT_COLOR = sf::Color::White;                  // Color of the non selected option

// Color of selected option
const sf::Color TEXT_COLOR_SELECTED = sf::Color::Green;

const float KEYBOARD_DELAY = 0.5;
const float VARIABLE_DELTA = 0.15f;
#endif //SIMPLECHART_PROGRAMCONSTANTS_HPP
