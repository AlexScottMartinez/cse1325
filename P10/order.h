#ifndef __ORDER_H
#define __ORDER_H

#include "item.h"
#include "customer.h"

#include <vector>

class Order {
  public:
    Order(const Customer& customer);
	Order(std::istream& ist);
    void add_item(const Item& item);
	void save(std::ostream& ost);
    double total();
private:
    std::vector<Item> _items;
    void Customer customer;
};

#endif
