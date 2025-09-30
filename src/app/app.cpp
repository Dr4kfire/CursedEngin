#include "app.h"
#include <curses.h>


Application::Application()
{
    // Initialize screen/window
    initscr();
    cbreak();
    noecho();

    // Disable scrolling
    scrollok(stdscr, FALSE);

    // Set the window size
    win_size = vec2(getmaxy(stdscr), getmaxx(stdscr));
}
Application::~Application()
{
    endwin();
}

void Application::draw()
{
    // Clear the previous frame
    clear();


    // Update the window size
    win_size = vec2(getmaxy(stdscr), getmaxx(stdscr));

    
    // Refresh (show changes)
    refresh();
}

void Application::process()
{
    if (getch() == 'q')
    {
        should_close = true;
    }
}