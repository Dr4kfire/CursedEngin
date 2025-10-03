#include <curses.h>
#include "app/app.h"

int main(int argc, char const *argv[])
{
    Application app;
    while (!app.should_close)
    {
        app.draw();
        app.process();
    }
}
