#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
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

void display_menu(tState * self){
    fseek(stdout, 0, SEEK_SET);
    printf("=========================Menu===================\n");
    printf("1: Print pattern 1\n");
    printf("2: Print pattern 2\n");
    printf("3. Print pattern 3\n");
    printf("4. Print pattern 4\n");
    printf("5: Exit the program\n");
    printf("================================================\n");
    self->current_operation_status = DONE;
}
void get_input_from_console(tState * self){
    /*! The input taker shall wait 5 ms every cycle to read a character input  */
    static uint8_t state_counter = 0;
    if(state_counter < ){
        char tmp[10] = {'\0'};
        fseek(stdout, 0, SEEK_CUR);
        if(state_counter > 0 && state_counter < 5){
            tmp[0] = (char)(48 + state_counter);
        }
        if(tmp[0] != '\0'){
            self->data[0] = tmp[0];
            state_counter = 0;
            self->current_operation_status = DONE;
        }
        else{
            self->current_operation_status = ONGOING;
            state_counter++;
        }
    }
    else{
        state_counter = 0;
        self->current_operation_status = DONE;        
    }
}
void display_pattern1(tState * self){
    printf("Pattern 1\n");
    self->current_operation_status = DONE;
}
void display_pattern2(tState * self){
    printf("Pattern 2\n");
    self->current_operation_status = DONE;
}
void display_pattern3(tState * self){
    printf("Pattern 3\n");
    self->current_operation_status = DONE;    
}
void display_pattern4(tState * self){
    printf("Pattern 4\n");
    self->current_operation_status = DONE;    
}

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
            case DISPLAY_MENU:
                statehandlers[DISPLAY_MENU](state_variable);
                break;
            case CHECK_INPUT:
                statehandlers[CHECK_INPUT](state_variable);
                break;
            case PATTERN1:
                statehandlers[PATTERN1](state_variable);
                break;
            case PATTERN2:
                statehandlers[PATTERN2](state_variable);
                break;
            case PATTERN3:
                statehandlers[PATTERN3](state_variable);
                break;
            case PATTERN4:
                statehandlers[PATTERN4](state_variable);
                break;                        
        }
    }
    else{
        statehandlers[state_variable->next_state](state_variable);
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
                uint8_t choice = atoi(&(state_variable->data[0]));
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
                    case 5:
                        printf("Goodbye!\n");
                        break;
                        exit(EXIT_SUCCESS);
                    default:
                        printf("Wrong choice entered! Please try again!\n");
                        state_variable->next_state = DISPLAY_MENU;
                }
                break;
            }
            case PATTERN1:
            case PATTERN2:
            case PATTERN3:
            case PATTERN4:
                state_variable->next_state = DISPLAY_MENU;
                break;
        }
        state_variable->current_operation_status = INIT;
    }
}

void sm_timer(bool * stop_timer){
    if(*stop_timer == false){
        sleep(1);   /*! State machine clocking frequency: 1 Hz  */
        *stop_timer = true;
    }
}

void sm_main(tState * self, bool * periodic_scheduler_state){
    if(*periodic_scheduler_state == true){
        determine_state(self);
        switch_state(self);
        *periodic_scheduler_state = false;
    }
}

int main(void){
    tState StateObj = {
        .current_operation_status = INIT,
        .data = {0},
        .present_state = DISPLAY_MENU,
        .next_state = DISPLAY_MENU
    };

    bool periodic_scheduler_state = true;

    while(true){
        sm_main(&StateObj, &periodic_scheduler_state);
        sm_timer(&periodic_scheduler_state); /*! State machine wait timer  */
    }

}