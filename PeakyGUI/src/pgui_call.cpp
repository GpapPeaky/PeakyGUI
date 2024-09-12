#include "pgui_call.hpp"

void PGUI_DebugPrint(void){
    std::printf("PGUI function called\n");
    return;
}

void* PGUI_DebugWrapper(std::vector<void*> args){
    std::printf("PGUI function called\n");
    return NULL;
}

void PGUI_Increment(void){
    static int c = 0;
    std::printf("count: %d\n", c++);
    return;
}

void* PGUI_IncrementWrapper(std::vector<void*> args){
    static int i = 0;
    std::printf("%d\n", i++);
    return NULL;
}

void PGUI_Exit(void){
    exit(EXIT_SUCCESS);
}

void* PGUI_Sum(std::vector<void*> args){
    int sum = 0;

    for(auto arg : args){
        sum += *(int*)arg;
    }

    int* result = new int(sum); /* Memory need to be allocated */
    std::printf("%d\n", *(int*)(result));
    return (void*)result;
}
