#include "State/State.h"
#include "helpers/user_input_helper.h"
#include "stdlib.h"

int main() {
    State state = State_value_initial();

    while (true){
        State_print_board(&state);
        Coordinates *user_move = get_user_move(state.current_side);
        State_perform_action(&state, user_move);
        free(user_move);
    }
}
