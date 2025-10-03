#pragma once

#include <map>
#include <string>
#include "app_state.h"


class AppStatesManager
{
public:
    AppStatesManager();


    void addState(const char* state_name, AppState &new_state);
    bool hasState(const char* state_name);
    AppState *getState(const char* state_name);

    void changeActiveState(const char* state_name);
    const char* getActiveState() const;


    // New app state, old app state
    Signal<AppState *, AppState *> _on_state_change;

protected:
    std::map<std::string, AppState> states;
    const char* active_state = nullptr;
};