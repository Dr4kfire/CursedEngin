#pragma once


#include "../core/types/vec2.h"


class Application
{
public:
    Application();
    ~Application();

    void draw();
    void process();

public:
    bool should_close = false;

private:
    vec2 win_size;
};