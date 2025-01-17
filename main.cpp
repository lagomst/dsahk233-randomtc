#include "RandomTest.cpp"
#include <iostream>
#if WINDOW_OS == 1
        #include <windows.h>
#else
        #include<unistd.h>
#endif
#include <thread>

int main()
{  
    const size_t stack_max = STACK_MAX;
    const size_t arr_max = ARR_MAX;
    const size_t line = LINE;
    const std::string destination = "./";
    const std::string name = "rand_tc";
    const std::string format = ".txt";
    for(int i = 0; i < NUM_OF_FILE; i++){
        std::string filename = destination + name + std::to_string(line) + '-' +  std::to_string(i) + format;
        RandomTest rt(stack_max, arr_max);
        rt.printFile(filename, line);
#if WINDOW_OS == 1
        Sleep(100);
#else
        usleep(10000);
#endif
    }
    return 0;
}