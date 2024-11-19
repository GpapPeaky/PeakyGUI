#ifndef __PGUI_BAR_HPP__
/**
 * @brief PeakyGUI bar for integers and floats
 */
#define __PGUI_BAR_HPP__

#include "pgui_primitives.hpp"
#include "pgui_component.hpp"

typedef struct PGUI_intBar{
    PGUI_Component backgroundComponent;
    PGUI_Component foregroundComponent;
    int maxVariableValue;
    int minVariableValue;
    int rateOfChange;
    PGUI_Uniform uniformVariable; /* Variable that will change through the bar */
}PGUI_IntBar;

typedef struct PGUI_floatBar{
    PGUI_Component backgroundComponent;
    PGUI_Component foregroundComponent;
    float maxVariableValue;
    float minVariableValue;
    float rateOfChange;
    PGUI_Uniform uniformVariable; /* Variable that will change through the bar */
}PGUI_FloatBar;

#endif
