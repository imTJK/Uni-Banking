//
//  cbank.cpp
//  Uni Banking
//
//  Created by Tj on 17.11.23.
//

#include "cbank.hpp"
#include "caccount.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors
CBank::CBank(string name, string bic)
	:name_(move(name)), bic_(move(bic))
{};

// Methods
void CBank::add_account(CAccount* account_ptr)
{
	account_list_.push_back(account_ptr);
}

// Display 
void CBank::print() const
{
	printf("%s \n BLZ %s \n Anzahl Konten: %llu \n Kontenliste: \n", name_.c_str(), bic_.c_str(), account_list_.size());
	printf(" IBAN \t\t\t | Kundenname \t | Anz. Buchungen \t | Kontostand \t");
	printf("\n ------------------------|---------------|-----------------------|----------");

	for (auto const& element : account_list_) {
		printf("\n ");
		element->print_iban();
		cout
			<< setfill(' ')
			<< left
			<< setw(22)
			<< element->get_customer().get_name()
			<< "|"
			<<




		printf("\n ");
		element->print_iban();
		printf(" | %s   | 0 \t\t\t | ", element->get_customer().get_name().c_str());
		element->get_balance().print();
	}
}
