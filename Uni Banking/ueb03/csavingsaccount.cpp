//
//  ueb02.h
//  Uni Banking
//
//  Created by Tj on 17.11.23.
//

#include "csavingsaccount.hpp"
#include "ccustomer.hpp"
#include "cbank.hpp"
#include "xml_utils.h"


// Constructors
CSavingsAccount::CSavingsAccount(CBank* bank, std::string iban, CCustomer* customer, CMoney balance, double interest_rate)
	:CAccount(bank, std::move(iban), customer, std::move(balance)), interest_rate_(interest_rate) {};


// Destructors
CSavingsAccount::~CSavingsAccount()
{
	printf("CSavingsAccount: \t Konto ("); print_iban(); printf(") wird vernichtet! \n");
}

void CSavingsAccount::load(std::ifstream* file, std::vector<CBank*>* bank_list, std::vector<CCustomer*>* customer_list)
{
	long customer_id, amount = 0;
	double interest_rate = 0;
	std::string bank_bic, line, iban, currency;

	std::getline(*file, line);

	while (line.find("</Account") == std::string::npos)
	{
		if (line.find("<IBAN>") != std::string::npos)              { iban = get_value(&line);                     }
		else if (line.find("<Customer>") != std::string::npos)     { customer_id = std::stol(get_value(&line));   }
		else if (line.find("<Bank>") != std::string::npos)         { bank_bic = get_value(&line);                 }
		else if (line.find("<Amount>") != std::string::npos)       { amount = std::stol(get_value(&line));        }
		else if (line.find("<Currency>") != std::string::npos)     { currency = get_value(&line);                 }
		else if (line.find("<InterestRate>") != std::string::npos) { interest_rate = std::stod(get_value(&line)); }
		
		std::getline(*file, line);
	}

	auto const customer = find_customer_from_id(customer_list, &customer_id);
	auto const bank = find_bank_from_bic(bank_list, &bank_bic);

	auto const savings_account = new CSavingsAccount(bank, iban, customer, CMoney(amount, currency), interest_rate);

	customer->add_account(savings_account);
	bank->add_account(savings_account);
}


// Display
void CSavingsAccount::print() const
{
	CAccount::print();
	printf("\nSparzinsen: %f %%", interest_rate_);
}

