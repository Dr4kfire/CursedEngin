#pragma once


struct color
{
    int r, g, b;
    bool transparent;

    color(int red, int green, int blue, bool transparent = false)
        : r(red), g(green), b(blue), transparent(transparent) {}
};
