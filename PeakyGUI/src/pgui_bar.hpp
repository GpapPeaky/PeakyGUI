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

#endif
