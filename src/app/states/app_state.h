#pragma once


#include "../../core/functional/signal.h"
#include "../../core/types/vec2.h"


class AppState
{
public:
    AppState()
    {
        this->_call_process.connect([this](double delta_time) {
            this->process(delta_time);
        });
        this->_call_draw.connect([this]() {
            this->draw();
        });
        this->_call_input.connect([this](char input) {
            this->input(input);
        });
    }

    Signal<> _on_activate;
    Signal<> _on_deactivate;
    
    Signal<> _on_process;
    Signal<> _on_draw;

    Signal<double> _call_process;
    Signal<> _call_draw;
    Signal<char> _call_input;

protected:

    virtual void process(double delta_time);
    virtual void draw();
    virtual void input(char input);
};