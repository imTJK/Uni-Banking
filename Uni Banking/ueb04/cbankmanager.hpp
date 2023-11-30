#ifndef cbankmanager_hpp
#define cbankmanager_hpp
#include <vector>
#include <string>


// Forward declarations, include respective .h in main-file
class CCustomer; // ccustomer.h
class CBank; // caccount.h


class CBankManager {
private:
	std::vector<CCustomer*> customer_list_;
	std::vector<CBank*> bank_list_;

public:
	// Constructors
	CBankManager(std::string);

	// -- Methods -
	// Display
	void print_customer_list() const;
	void print_bank_list() const;
};

#endif