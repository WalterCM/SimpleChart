# CMakeLists.txt for Simple Graph
# by Walter Capa

cmake_minimum_required(VERSION 3.0)
project(SimpleChart)

# C++ Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find any version 2.X of SFML
find_package(SFML REQUIRED Graphics Window)

# Set executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# set source files and executables
set(SOURCE_FILES src/Main.cpp)
add_executable(SimpleChart ${SOURCE_FILES}
                src/Main.cpp
                src/Program.hpp
                src/Program.cpp
                src/StateManager.hpp
                src/StateManager.cpp
                src/ProgramState.hpp
                src/ProgramState.cpp
                src/MainMenu.hpp
                src/MainMenu.cpp
                src/ProgramConstants.hpp
                src/SelectFunction.hpp
                src/SelectFunction.cpp
                src/Functions/FuzzyLogicFunctions.cpp
                src/Functions/FuzzyLogicFunctions.hpp
                src/SimpleChart/SimpleChart.hpp
                src/SimpleChart/SimpleChart.cpp
                src/SimpleChart/VariablesHandler.hpp
                src/SimpleChart/VariablesHandler.cpp)

# Link SFML library
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(SimpleChart ${SFML_LIBRARY})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
