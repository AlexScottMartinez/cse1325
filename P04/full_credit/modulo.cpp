#include "modulo.h"

void set_nmsd(Modulo* nmsd){
	*_nmsd = *nmsd;
}
int value(){
	return this->_value;
};
Modulo& operator+=(int rhs){
	value = _value + rhs;
	if (_value > _modulo){
		++(*_nmsd);
		_value = rhs + _modulo - _value;
	}
	return *this;
}
}
Modulo operator+(int rhs){
	
}
Modulo& operator++(){
	
}
Modulo operator++(int ignored){
	++_value;
	if(_value > _modulo){
		++_nmsd;
		_value = _offset;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& ost,Modulo& m){
	ost <<_value + _offset;
	return ost;
}
std::ostream& operator>>(std::ostream& ost,Modulo& m){
	ost <<(_value - _offset) % _modulo;
	return ost;
}

