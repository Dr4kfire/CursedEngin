#pragma once


#include <chrono>

#include "states/states_manager.h"
#include "../core/types/vec2.h"


class Application
{
public:
    Application();
    ~Application();

    void draw();
    void process();

public:
    vec2 win_size;

    bool should_close = false;
    
    AppStatesManager states;

private:
    std::chrono::high_resolution_clock::time_point last_time;
};