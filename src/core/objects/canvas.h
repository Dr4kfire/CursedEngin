#pragma once


#include <vector>
#include "../types/pixel.h"
#include "../types/vec2.h"


class Canvas
{
public:
    Canvas(vec2 size = vec2(72, 160)) 
        : size(size) 
    {
        buffer.reserve(size.y * size.x);
    }


    void draw();
    void process();


    vec2 position;
    vec2 size;

    std::vector<wchar_t> buffer;
};