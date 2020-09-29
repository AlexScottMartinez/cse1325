#include "and.h"

Signal And::output() override {
	if ((_input1 == true && _input2 == true || (_input1 == false && _input2 == true) || (_input1 == false && _input2 == false))) {
		return true;
	}
	else {
		return false;
	}
};
