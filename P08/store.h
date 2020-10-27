#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "product.h"

#include <vector>
#include <iostream>
#include <fstream>

class Store {
  public:
    std::string get_filename();
    void set_filename(std::string filename);
    Store(std::string name);
    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    const Product& product(int index);
	Store(std::istream& ist);
	virtual void save(std::ostream& ost);
  protected:
    std::string filename;
  private:
    std::string _name;
    std::vector<Product*> _products;
};

#endif
