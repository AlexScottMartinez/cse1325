#include "tool.h"

Tool::Tool(std::string name, double price, std::string description)
    : Product(name, price, description) { }


void Tool::save(std::ostream& ost) {
	for (Plant* p : Plant) {
    	ost << typeid(*p).name() << ' '; // Write the name of the actual type
      	p->save(ost);
      	ost << std::endl;  // one line per shape (this is ignored when loading)
	}
}

Tool::Tool(std::istream& ist) : Product(ist) {}
