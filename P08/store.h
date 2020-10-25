#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"

#include <vector>
#include <iostream>
#include <fstream>

class Store {
  public:
    Store(std::string name);
    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    const Product& product(int index);
	Store(std::istream& ist);
	void save(std::ostream& ost);
  private:
    std::string _name;
    std::vector<Product*> _products;
};

#endif
