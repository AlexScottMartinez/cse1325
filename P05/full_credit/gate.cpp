#include "gate.h"

void Gate::connect(Gate& gate, Pin input_pin){
	*_to_gate = gate;
	_to_pin = input_pin;
};
void Gate::input(Pin pin, Signal signal) {
	_to_pin = pin;
	if (pin == 1) {
		_input1 = signal;
	}
	else {
		_input2 = signal;
	}
};
Signal Gate::input(Pin pin) {
	if (pin == 1) {
		return _input1;
	}
	else {
		return _input2;
	}
};
virtual Signal Gate::output() = 0;
