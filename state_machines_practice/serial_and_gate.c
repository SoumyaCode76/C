#include <stdio.h>

/* 
	* Design a serial synchoronous AND gate using state machine concept.
	* Here, there's only 3 states: get input, determine output and display output
	* The main function will run a continuous WHILE LOOP, that will schedule an alarm of 1 second.
	* After each second, the signal handler should call the state handler to determine what should be the next state.
	* The state handler will then call the transition handler with the corresponding next state's function passed as argument.
	* The transition handler's job is to make the call to the corresponding state's function.
	* The determine output state will have 2 sub-states: True and False. When the handler of this state will be called, it will switch to the desired state's execution area, determine the boolean output from the inputs passed and save in the output variable.
	* The display output state's handler will only print the current value in the output variable.
	* Make use of Object-oriented design pattern. There will be one operational object, having the input variable, the output variable, and the state variable as follows:
	typedef struct operation_object_tag{
		int input_variable;
		int output_variable;
		tState * state_variable;
	}tOpObject;
	
	* The tState type will have the following:
	typedef struct state_variable_tag{
		enum State present_state;
		enum State next_state;
	}tState;
	* enum State{
			GET_INPUT,
			PROCESS_INPUT,
			DISPLAY_OUTPUT
	}
	* enum OpState{
			OK,
			PENDING,
			NOT_OK
	}
	* The 'determine_output' state will have a static variable to remember what was the last sub-state it had received. It has to be of 'enum_detstate' type whose values are TRUE_STATE and FALSE_STATE
	* Based on the OpState's value, the state handler will decide whether to switch to the next logical state or retain in the current state. 

*/

int main(){
	return 0;
}

