//
//  ccustomer.cpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#include "ccustomer.hpp"
#include "caccount.hpp"
#include "xml_utils.h"

// Constructors
CCustomer::CCustomer(long n_id, std::string name, CDate birthday, CAddress address)
:id_(n_id), name_(std::move(name)), birthday_(birthday), address_(std::move(address)), account_list_(NULL)
{}


// -- Custom Methods --
// Add Account to Customer
void CCustomer::add_account(CAccount * account_ptr) { account_list_.push_back(account_ptr); }

void CCustomer::load(std::ifstream * file)
{
	std::string line, name, street, postcode, town;
	int day, month, year;

	std::getline(*file, line);

	// Iterates over each customer element, line by line
	while (line.find("</Customer>") == std::string::npos)
	{
		if (line.find("<ID") != std::string::npos) { id_ = std::stol(get_value(&line)); }
		else if (line.find("<Name>") != std::string::npos) { name_ = get_value(&line); }
		else if (line.find("<Day>") != std::string::npos) { day = std::stoi(get_value(&line)); }
		else if (line.find("<Month>") != std::string::npos) { month = std::stoi(get_value(&line)); }
		else if (line.find("<Year>") != std::string::npos) { year = std::stoi(get_value(&line)); }
		else if (line.find("<Street>") != std::string::npos) { street = get_value(&line); }
		else if (line.find("<Postcode>") != std::string::npos) { postcode = get_value(&line); }
		else if (line.find("<Town>") != std::string::npos) { town = get_value(&line); }

		std::getline(*file, line);
	}
	address_ = CAddress(street, postcode, town);
	birthday_ = CDate(day, month, year);
}

// Display
void CCustomer::print() const {
    printf("%s (Kd-Nr. %ld)", name_.c_str(), id_);
    address_.print();

    printf("\ngeboren am: "); birthday_.print();
    printf("\nKonten:");
    
    for (auto const & element : account_list_) {
        printf("\n- Kontonr.: "); element->print_iban();
    }
}

