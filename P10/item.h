#ifndef __ITEM_H
#define __ITEM_H

#include "product.h"

class Item {
  public:
    double subtotal();
    Item(const Product& product, int quantity);
    Item(istream& ist);
    void save(ostream& ost);
  private:
    Product* _product;
    int quantity;
};

#endif
