#include "canvas.h"
#include <curses.h>


#include "../types/uchar.h"


void Canvas::draw()
{
    // draw the inisde (content)
    for (int y = 0; y < size.y; y++)
    {
        for (int x = 0; x < size.x; x++)
        {
            mvaddch(position.y + y, position.x + x, static_cast<wchar_t>(uchar::full_block));
        }
    }

    // draw the outline
    mvhline(position.y-1, position.x-1, static_cast<wchar_t>(uchar::box_line_hori), size.x+2);
    mvhline(position.y+size.y, position.x-1, static_cast<wchar_t>(uchar::box_line_hori), size.x+2);

    mvvline(position.y-1, position.x-1, static_cast<wchar_t>(uchar::box_line_vert), size.y+2);
    mvvline(position.y-1, position.x+size.x, static_cast<wchar_t>(uchar::box_line_vert), size.y+2);

    // upper corners
    mvaddch(position.y-1, position.x-1, static_cast<wchar_t>(uchar::box_corner_up_left));
    mvaddch(position.y-1, position.x+size.x, static_cast<wchar_t>(uchar::box_corner_up_right));
    // bottom corners
    mvaddch(position.y+size.y, position.x-1, static_cast<wchar_t>(uchar::box_corner_down_left));
    mvaddch(position.y+size.y, position.x+size.x, static_cast<wchar_t>(uchar::box_corner_down_right));
}