#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name} { }
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

void Store::save(std::ostream& ost) {
	ost << _name << std::endl;
	ost << _products.size() << std::endl;
	for (Product* p : _products) {
		p->save(ost);
	}
	
}
Store::Store(std::istream& ist) {
	getline(ist, _name);
	//getline(ist, new Tool{ist});
 	int size;

  	ist >> size;
  	for (int i=0; i<size; ++i) _products.push_back(new Product{ist});
  		ist >> _name;
	
}

std::string Store::get_filename() {return filename;}
void Store::set_filename(std::string filename) {this->filename = filename;}
