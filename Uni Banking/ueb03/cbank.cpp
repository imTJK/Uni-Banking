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

void CBank::load(std::ifstream * file)
{
	// Lambda to find get values from xml file
	auto get_value = [](const std::string* line)
		{
			return line->substr(line->find('>') + 1, line->find("</ID>") - line->find('>') - 1);
		};

	std::string line;
	std::getline(*file, line);

	// Iterates over each bank element, line by line
	while (line.find("</Bank") == std::string::npos)
	{
		if (line.find("<Name>") != std::string::npos) { name_ = get_value(&line); }
		else if (line.find("<BIC>") != std::string::npos) { bic_ = get_value(&line); }

		std::getline(*file, line);
	}
}


// Display 
void CBank::print() const
{
	// It's not pretty, but it works
	printf("%s \nBLZ %s \nAnzahl Konten: %llu \nKontenliste: \n", name_.c_str(), bic_.c_str(), account_list_.size());
	printf("IBAN                   | Kundenname     | Anz. Buchungen | Kontostand \n");
	printf("-----------------------|----------------|----------------|---------------");

	for (auto const& element : account_list_) {
		printf("\n");
		element->print_iban();
		printf("| %-14.14s | %14i | ", element->get_customer().get_name().c_str(), 0);
		element->get_balance().print();
	}
}
