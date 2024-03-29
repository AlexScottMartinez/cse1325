#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>
#include <fstream>

class Customer {
  public:
	Customer(std::string name, std::string phone, std::string email);
	Customer(std::istream& ist);
	void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
  protected:
    virtual std::string to_string() const;
  private:
	std::string _name;
	std::string _phone;
	std::string _email;
};
#endif
