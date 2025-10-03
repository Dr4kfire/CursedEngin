#include "states_manager.h"


AppStatesManager::AppStatesManager()
{

}


void AppStatesManager::addState(const char* state_name, AppState &new_state)
{
    states.emplace(state_name, std::move(new_state));
}
bool AppStatesManager::hasState(const char* state_name)
{
    return states.find(state_name) != states.end();
}
AppState *AppStatesManager::getState(const char* state_name)
{
    return &states[state_name];
}


void AppStatesManager::changeActiveState(const char* state_name)
{
    states[active_state]._on_deactivate.emit();

    if (states.find(state_name) != states.end())
    {
        active_state = state_name;
    }

    states[active_state]._on_activate.emit();
}
const char* AppStatesManager::getActiveState() const
{
    return active_state;
}