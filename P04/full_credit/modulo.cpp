#include "modulo.h"

Modulo& operator+=(int rhs){
	return minutes = minutes + 30;
}
Modulo operator+(int rhs){
	return hour += 12;
}
Modulo& operator++(){
	return ++minutes;
}
Modulo operator++(int ignored){
	return std::cout << hour++;
}

std::ostream& operator<<(std::ostream& ost,Modulo& m){
	ost <<_value + _offset;
	return ost;
}
std::ostream& operator>>(std::ostream& ost,Modulo& m){
	ost <<(_value - _offset) % _modulo;
	return ost;
}

