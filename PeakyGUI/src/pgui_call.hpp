#include <iostream> /* TODO: Make it so that we can input any function with any type and number of parameters */

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

#endif
