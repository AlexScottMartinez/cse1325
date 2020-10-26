#include "tool.h"

Tool::Tool(std::string name, double price, std::string description)
    : Product(name, price, description) { }


void Tool::save(std::ostream& ost) {
	ost << "tool";
	save(ost);
	Product::save(ost);
}

Tool::Tool(std::istream& ist) : Product(ist) {}
