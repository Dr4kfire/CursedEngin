#include "test_state.h"

#include <curses.h>
#include "../../../core/types/vec2.h"
#include "../../../core/types/uchar.h"


void TestState::draw()
{
    vec2 pos;
    vec2 size;

    // Draw the outline
    // Lines
    mvhline(pos.y, pos.x, uchar::box_line_hori, size.x);
    mvhline(pos.y+size.y, pos.x, uchar::box_line_hori, size.x);

    mvvline(pos.y, pos.x, uchar::box_line_vert, size.y);
    mvvline(pos.y, pos.x+size.x, uchar::box_line_vert, size.y);


    // Corners
    mvaddch(pos.y, pos.x, uchar::box_corner_up_left);
    mvaddch(pos.y, pos.x+size.x, uchar::box_corner_up_right);

    mvaddch(pos.y+size.y, pos.x, uchar::box_corner_down_left);
    mvaddch(pos.y+size.y, pos.x+size.x, uchar::box_corner_down_right);


}