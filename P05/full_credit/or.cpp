#include "or.h"

Signal Or::output() override {
	if (_input1 == true || _input2 == true) {
		return true;
	}
	else {
		return false;
	}
};
