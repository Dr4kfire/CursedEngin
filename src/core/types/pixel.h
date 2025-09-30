#pragma once


#include "color.h"


struct pixel
{
    color color_data;

    pixel(color color_data)
        : color_data(color_data)
    {}
};