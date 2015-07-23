
#ifndef SIMPLECHART_PROGRAMCONSTANTS_HPP
#define SIMPLECHART_PROGRAMCONSTANTS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

typedef unsigned int uint;

const float FPS = 120;                                  // Frames per second

// Width on the window
const float WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width;
// Height of the window
const float WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;

const std::string TITLE_STRING = "Simple Chart";        // Title of the program.
const sf::Color BACKGROUND_COLOR = sf::Color::Black;

// -----------------------------------------------------------------------------------------

// Constants for the menu
const std::string MENU_TITLE_STRING = "Simple Chart";    // Title of the menu
const int MENU_TITLE_SIZE = 100;                         // Size of the title
const float MENU_TITLE_POS_X = WINDOW_WIDTH / 2;         // Position of the title
const float MENU_TITLE_POS_Y = WINDOW_HEIGHT / 4;

const int MENU_NUMBER_OPTIONS = 2;                       // Number of options in the menu
const std::string MENU_OPTION[] = {"Dibujar funcion", "Salir"};
const int MENU_OPTION_SIZE = 50;                         // Size of the options
const float MENU_OPTION_POS_X = WINDOW_WIDTH / 2;        // Position of each option
const float MENU_OPTION_POS_Y[] = {    WINDOW_HEIGHT * 9 / 16,
                                        WINDOW_HEIGHT * 12 / 16};

// -----------------------------------------------------------------------------------------

// Constants for the Function Selector
const std::string SELECTOR_TITLE_STRING = "Seleccione una funcion";     // Title of the selector
const int SELECTOR_TITLE_SIZE = 50;                                     // Size of the selector title
const float SELECTOR_TITLE_POS_X = WINDOW_WIDTH / 2;                    // Position of the selector title
const float SELECTOR_TITLE_POS_Y = WINDOW_HEIGHT / 8;

const int SELECTOR_NUMBER_OPTIONS = 8;                                  // Number of optiosn in the selector
const std::string SELECTOR_OPTION[] = {"Triangular", "Funcion r", "Funcion G", "Funcion S",
                                       "Gausiana", "Trapezoidal", "Pseudo-Exponencial", "Atras"};
const int SELECTOR_OPTION_SIZE = 50;                                    // Size of the selector options
const float SELECTOR_OPTION_POS_X = WINDOW_WIDTH / 2;                   // Position of each option
const float SELECTOR_OPTION_POS_Y[] = {    WINDOW_HEIGHT * 5 / 16,
                                            WINDOW_HEIGHT * 6 / 16,
                                            WINDOW_HEIGHT * 7 / 16,
                                            WINDOW_HEIGHT * 8 / 16,
                                            WINDOW_HEIGHT * 9 / 16,
                                            WINDOW_HEIGHT * 10 / 16,
                                            WINDOW_HEIGHT * 11 / 16,
                                            WINDOW_HEIGHT * 13 / 16,};

// -----------------------------------------------------------------------------------------

// Constants for SimpleChart
const float EPSILON = 0.003f;
const sf::Color AXIS_COLOR = sf::Color::Green;
const int AXIS_THICKNESS = 3;
const float AXIS_SIZE = WINDOW_WIDTH / 2;

const float MAX_SCALE = 10;
const float MIN_SCALE = 2;

const std::string SIMPLE_TITLE_STRING = "Simple Chart";         // Title of the chart
const int SIMPLE_TITLE_SIZE = (int)WINDOW_HEIGHT * 3 / 60;      // Size of the title
const float SIMPLE_TITLE_POS_X = WINDOW_WIDTH / 16;             // Position of the title
const float SIMPLE_TITLE_POS_Y = WINDOW_HEIGHT / 16;

const int SIMPLE_FUNCTION_SIZE = (int)WINDOW_HEIGHT * 2 / 60;;  // Size of the title
const float SIMPLE_FUNCTION_POS_X = WINDOW_WIDTH / 16;          // Position of the title
const float SIMPLE_FUNCTION_POS_Y = WINDOW_HEIGHT / 8;

const std::string SIMPLE_OPTION[] = {"a", "b", "c", "d", "m", "k"};
const int SIMPLE_OPTION_SIZE = (int)WINDOW_HEIGHT * 2 / 60;     // Size of the options
// Position of each option
const float SIMPLE_OPTION_POS_X[] = {WINDOW_WIDTH * 9 / 16,
                                      WINDOW_WIDTH * 10 / 16,
                                      WINDOW_WIDTH * 11 / 16,
                                      WINDOW_WIDTH * 12 / 16,
                                      WINDOW_WIDTH * 13 / 16,
                                      WINDOW_WIDTH * 14 / 16,
                                      WINDOW_WIDTH * 15 / 16,
                                      WINDOW_WIDTH * 16 / 16};
const float SIMPLE_OPTION_POS_Y = WINDOW_HEIGHT * 13 / 16;
const float SIMPLE_OPTION_VALUE_POS_Y = WINDOW_HEIGHT * 14 / 16;

const std::string ANNOTATION[] = {"[R] : Random",
                                  "[+] : Zoom In",
                                  "[-] : Zoom Out"};
const int ANNOTATION_SIZE = (int)WINDOW_HEIGHT * 2 / 60;
// Position of annotation
const float ANNOTATION_POS_X = WINDOW_WIDTH * 1 / 32;
const float ANNOTATION_POS_Y[] = {WINDOW_HEIGHT * 12 / 16,
                                  WINDOW_HEIGHT * 13 / 16,
                                  WINDOW_HEIGHT * 14 / 16};



// -----------------------------------------------------------------------------------------

const std::string QUICKSAND_BOLD_FONT = "../content/fonts/Quicksand-Bold.otf";
const std::string QUICKSAND_REGULAR_FONT = "../content/fonts/Quicksand-Regular.otf";
const sf::Color TEXT_COLOR = sf::Color::White;                  // Color of the non selected option

// Color of selected option
const sf::Color TEXT_COLOR_SELECTED = sf::Color::Green;

const float KEYBOARD_DELAY = 0.3;
const float VARIABLE_DELTA = 0.1f;

#endif //SIMPLECHART_PROGRAMCONSTANTS_HPP
