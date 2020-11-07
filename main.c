#include "State/State.h"
#include "helpers/user_input_helper.h"

int main() {
    State state = State_value_initial();

    while (true){
        State_print_board(&state);
        Coordinates *user_move = get_user_move(state.current_side);
        if(user_move == NULL) continue;
        State_perform_action(&state, user_move);
        free(user_move);
    }

    return 0;
}
