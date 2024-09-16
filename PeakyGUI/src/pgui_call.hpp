#include <iostream>
#include <vector> 
#include "pgui_action.hpp"

#ifndef __PGUI_CALL_H__
/**
 * @attention We need to create wrapper functions in order to call them from a PGUI_button
 *  void* foo(std::vector<void*> args); //Explicitly functions like his
 */
#define __PGUI_CALL_H__

/**
 * @brief A debug print for button presses
 */
void PGUI_DebugPrint(void);

/**
 * @brief A debug print for button presses
 * 
 * @param args arguments ({ })
 * 
 * @returns NULL
 */
void* PGUI_DebugWrapper(std::vector<void*> args);

/**
 * @brief increments a static count
 */
void PGUI_Increment(void);

/**
 * @brief increments a static count
 * 
 * @param args arguments ({ })
 * 
 * @returns NULL
 */
void* PGUI_IncrementWrapper(std::vector<void*> args);

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
