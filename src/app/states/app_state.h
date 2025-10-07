#pragma once


#include "../../core/functional/signal.h"
#include "../../core/types/vec2.h"
#include "states_manager.h"


class AppState
{
public:
    AppState(AppStatesManager *manager) : manager(manager)
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

    // AppState signals
    Signal<> _on_activate;
    Signal<> _on_deactivate;
    
    Signal<> _on_process;
    Signal<> _on_draw;

    // Constructor signals
    Signal<> _call_preprocess;
    Signal<> _call_ready;

    // Function signals
    Signal<double> _call_process;
    Signal<> _call_draw;
    Signal<char> _call_input;


    // Variales
    AppStatesManager *manager = nullptr;

protected:

    virtual void process(double delta_time) {};
    virtual void draw();
    virtual void input(char input);
};