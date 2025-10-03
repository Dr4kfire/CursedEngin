#include "test_state.h"

#include <curses.h>
#include "../../../core/types/vec2.h"
#include "../../../core/types/uchar.h"


void draw_outline(vec2 size, vec2 pos)
{
    mvhline(pos.y, pos.x, uchar::box_line_hori, size.x);
}