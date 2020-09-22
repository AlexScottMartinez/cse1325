#ifndef _MODULO_H
#define _MODULO_H
#include <iostream>

class Modulo {
	public:
		Modulo(int modulo=10, int value=0, int offset=0);
		void set_nmsd(Modulo* nmsd);
		int value();
		Modulo& operator+=(int rhs);
		Modulo operator+(int rhs);
		Modulo& operator++();
		Modulo operator++(int ignored);
		inline bool operator==(int rhs);
		inline bool operator!=(int rhs); 
		inline bool operator<(int rhs); 
		inline bool operator<=(int rhs); 
		inline bool operator>(int rhs); 
		inline bool operator>=(int rhs);
		friend std::ostream& operator<<(std::ostream& ost,Modulo& m);
		friend std::ostream& operator>>(std::ostream& ost,Modulo& m);
	private:
		int compare(const int rhs);
		int _value;
		int _modulo;
		int _offset;
		Modulo* _nmsd;
};
#endif
