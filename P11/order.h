#ifndef __ORDER_H
#define __ORDER_H

#include "item.h"
#include "customer.h"
#include <vector>

class Order {
  public:
    Order(Customer customer);
	Order(std::istream& ist);
    void add_item(Item item);
	void save(std::ostream& ost);
    double total() const;
    friend std::ostream& operator<<(std::ostream& ost, const Order& order);
private:
    std::vector<Item> _items;
    Customer _customer;
};

#endif
