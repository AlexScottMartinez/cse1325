#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "order.h"

#include <vector>

class Store {
  private:
    std::string _name;
    std::vector<Product*> _products;
	std::vector<Customer*> _customers;
    typedef std::vector<Order*>_orders;
	_orders i_orders;
  public:
    Store(std::string name);
	Store(std::istream& ist);
	std::string name();

    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
	void add_customer(const Customer& customer);
    void add_item(int order, Product& product, int quantity);
	void save(std::ostream& ost);

    int add_order(const Customer& customer);
    int products();
	int customers();
    int orders();

    Product& product(int index);
	const Customer& customer(int index);
    const Order& order(int index);
	typedef _orders::iterator iterator;
	typedef _orders::const_iterator const_iterator;
	iterator begin();
	iterator end();
};

#endif
