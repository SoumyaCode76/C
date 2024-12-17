#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
    * In this program, we are going to create an FSM of 4 states that behave 
    * In each state, it will only print in which state it is.
    * Approaching the problem using dynamic programming method
    * Subproblem 1: How to switch between the states? 
    * Subproblem 2: How to know whether to change the state?
    * Subproblem 3: How to know which state is now and the next state to move into?
 */


typedef enum states_tag{
    DISPLAY_MENU,
    CHECK_INPUT,
    PATTERN1,
    PATTERN2,
    PATTERN3,
    PATTERN4,
}States;

typedef enum operation_t{
    INIT,           /*! Entry */
    ONGOING,        /*! During */
    DONE            /*! Exit  */
}Operations;

typedef struct state_tag{
    uint8_t data[10];
    States next_state;
    States present_state;
    Operations current_operation_status;
}tState;

void display_menu(tState *);
void get_input_from_console(tState *);
void display_pattern1(tState *);
void display_pattern2(tState *);
void display_pattern3(tState *);
void display_pattern4(tState *);

typedef void (*state_handler)(tState *);
state_handler statehandlers[6] = {
        &display_menu,
        &get_input_from_console,
        &display_pattern1,
        &display_pattern2,
        &display_pattern3,
        &display_pattern4
    };

void switch_state(tState * state_variable){
    if(state_variable->next_state != state_variable->present_state){
    state_variable->present_state = state_variable->next_state;
        switch(state_variable->next_state){
            case CHECK_INPUT:
                get_input_from_console(*state_variable);
                break;
            case PATTERN1:
                void display_pattern1(*state_variable);
                break;
            case PATTERN2:
                void display_pattern2(*state_variable);
                break;
            case PATTERN3:
                void display_pattern3(*state_variable);
                break;
            case PATTERN4:
                void display_pattern4(*state_variable);
                break;                        
        }
    }
}

/* There must be a function to know what state to set, when the task for the current state is complete. */
void determine_state(tState * state_variable){
    /* Decide the next state only when the current state's task/operation is complete */
    if(state_variable->current_operation_status == DONE){
        switch (state_variable->present_state)
        {
            case DISPLAY_MENU:
            {
                state_variable->next_state = CHECK_INPUT;
                break;
            }
            case CHECK_INPUT:
            {   
                uint8_t choice = atoi(state_variable->data);
                switch(choice){
                    case 1:
                        state_variable->next_state = PATTERN1;
                        break;
                    case 2:
                        state_variable->next_state = PATTERN2;
                        break;
                    case 3:
                        state_variable->next_state = PATTERN3;
                        break;
                    case 4:
                        state_variable->next_state = PATTERN4;
                        break;
                    default:
                        printf("Wrong choice entered! Please try again!\n");
                        state_variable->next_state = DISPLAY_MENU;
                }
                break;
            }
            default:
                state_variable->next_state = DISPLAY_MENU;
        }
        state_variable->current_operation_status = INIT;
    }
}

void sm_timer(bool stop_timer){
    if(stop_timer == false){
        sleep(1);   /*! State machine clocking frequency: 1 kHz  */
        stop_timer = true;
    }
}

void sm_main(tState * self, bool periodic_scheduler_state){
    if(periodic_scheduler_state == true){
        determine_state(self);
        switch_state(self);
        periodic_scheduler_state = false;
    }
}

int main(void){
    tState StateObj = {
        .current_operation_status = INIT,
        .data = {0},
        .present_state = DISPLAY_MENU,
        .next_state = DISPLAY_MENU
    };

    bool periodic_scheduler_state = false;

    while(true){
        sm_main(&StateObj, periodic_scheduler_state);
        sm_timer(periodic_scheduler_state); /*! State machine wait timer  */
    }

}