#ifndef __PGUI_BAR_HPP__
/**
 * @brief PeakyGUI bar for integers and floats, they can be found in the PGUI_Widgets as a field
 */
#define __PGUI_BAR_HPP__

#include "pgui_primitives.hpp"
#include "pgui_component.hpp"

typedef struct PGUI_intBar{
    PGUI_Component backgroundComponent;
    PGUI_Component foregroundComponent;
    int maxVariableValue;
    int minVariableValue;
    int default;
    int rateOfChange;
    int* uniformVariable; /* Variable that will change through the bar */
}PGUI_IntBar;

typedef struct PGUI_floatBar{
    PGUI_Component backgroundComponent;
    PGUI_Component foregroundComponent;
    float maxVariableValue;
    float minVariableValue;
    float rateOfChange;
    float default;
    float* uniformVariable; /* Variable that will change through the bar */
}PGUI_FloatBar;

/**
 * @brief Creates an integer bar
 * 
 * @param background Bar background component 
 * @param foreground Bar foreground componenet
 * @param max Max value of variable in the bar
 * @param min Min value of variable in the bar
 * @param rateOfChange Steps taken per slide of the bar
 * @param variable Uniform Variable to change
 * @param default Default value of the uniform if not initialised otherwise
 * 
 * @returns Pointer to the created bar Widget
 */
PGUI_IntBar* PGUI_CreateIntegerBar(PGUI_Component background, PGUI_Component foreground,\
int max, int min, int rateOfChange, int* variable, int default);

/**
 * @brief Creates an integer bar
 * 
 * @param x X axis
 * @param y Y axis
 * @param marginSize Margin size for foreground bar
 * @param background Background component surface
 * @param foreground Foreground component surface
 * @param min Minimum value
 * @param max Maximum value
 * @param rateOfChange rate of change per slide/click
 * @param variable Uniform variable to change 
 * @param default Default value of uniform
 * @param rnd Renderer to use
 * 
 * @returns Pointer to the created bar Widget
 */
PGUI_IntBar* PGUI_CreateIntegerBarMargin(int x, int y, int marginSize, SDL_Surface* background,\
SDL_Surface* foreground, int min, int max, int rateOfChange, int* variable, int default);

/**
 * @brief Gets The attributres of an integer bar
 * 
 * @param integerBar Integer bar to get the attributes from
 * @param backX Background x
 * @param backY Background y
 * @param foreX Foreground x
 * @param foreY Foreground y
 * @param min Minimum value
 * @param max Maximum value
 * @param rateOfChange Rate of change per click
 */
void PGUI_GetIntegerBarAttributes(PGUI_IntBar integerBar, int* backX = NULL, int* backY  = NULL, int* foreX = NULL, int* foreY = NULL, int* min = NULL, int* max = NULL,\
int* rateOfChange = NULL);

/**
 * @brief Gets The attributres of an integer bar
 * 
 * @param integerBar Integer bar to get the attributes from
 * @param backX Background x
 * @param backY Background y
 * @param foreX Foreground x
 * @param foreY Foreground y
 * @param min Minimum value
 * @param max Maximum value
 * @param rateOfChange Rate of change per click
 */
void PGUI_QueryIntegerBar(PGUI_IntBar integerBar, int* backX = NULL, int* backY = NULL, int* foreX = NULL, int* foreY = NULL, int* min = NULL, int* max = NULL,\
int* rateOfChange = NULL);

/**
 * @brief Print the attributes of a bar
 * 
 * @param bar Bar to print
 */
void PGUI_PrintIntegerBar(PGUI_IntBar bar);

#endif
