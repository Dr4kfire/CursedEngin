#include "app.h"
#include <curses.h>

#include <chrono>


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

    
    // get the active state
    const char* active_state = states.getActiveState();
    if (active_state == "") return;

    // call draw if there is an active state
    states.getState(active_state)->_call_draw.emit();

    
    // Refresh (show changes)
    refresh();
}

void Application::process()
{
    // calculate delta time
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> delta = now - last_time;
    last_time = now;

    double delta_time = delta.count();

    // get the active state
    const char* active_state = states.getActiveState();
    if (active_state == "") return;

    // call process if there is an active state
    states.getState(active_state)->_call_process.emit(delta_time);
}