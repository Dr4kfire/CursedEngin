#include "../app_state.h"

class TestState : protected AppState
{
public:
    TestState(AppStatesManager *manager) : AppState(manager) {}

    void process(double delta_time) override;
    void draw() override;
    void input(char input) override;
};