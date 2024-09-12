#include <iostream> /* TODO: Make it so that we can input any function with any type and number of parameters */
#include <vector> 
#include "pgui_action.hpp"

#ifndef __PGUI_CALL_H__
/**
 * @attention ONLY FUNCTIONS: VOID FOO(VOID) CAN BE USED FOR NOW
 */
#define __PGUI_CALL_H__

/**
 * @brief A debug print for button presses
 */
void PGUI_DebugPrint(void);

/**
 * @brief increments a static count
 */
void PGUI_Increment(void);

/**
 * @brief Forces an exit
 */
void PGUI_Exit(void);

/**
 * @brief adds up two numbers
 * 
 * @param args arguments and number of arguments
 * 
 * @returns a pointer to the sum
 */
void* PGUI_Sum(std::vector<void*> args);

#endif
