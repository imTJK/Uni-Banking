//
//  caccount.cpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#include "caccount.hpp"
#include "xml_utils.h"
#include <iostream>

// Constructors
CAccount::CAccount(CBank * bank, std::string iban, CCustomer * customer, CMoney balance)
{
	bank_ = bank;
	iban_ = std::move(iban);
	customer_ = customer;
	balance_ = std::move(balance);
	customer->add_account(this);
	bank->add_account(this);
}

CAccount::CAccount(std::string iban, CCustomer* customer, CMoney balance)
{
	// Custom Constructor without bank (for backwards compatibility)
	iban_ = std::move(iban);
	customer_ = customer;
	balance_ = std::move(balance);
	customer->add_account(this);
}

void CAccount::load(std::ifstream * file, std::vector<CBank*> *bank_list, std::vector<CCustomer*> *customer_list)
{
	long customer_id, amount;
	std::string currency, bank_bic, line, iban;

	std::getline(*file, line);

	while (line.find("</Account") == std::string::npos)
	{
		if (line.find("<IBAN>") != std::string::npos) { iban = get_value(&line); }
		else if (line.find("<Customer>") != std::string::npos) { customer_id = std::stol(get_value(&line)); }
		else if (line.find("<Bank>") != std::string::npos) { bank_bic = get_value(&line); }
		else if (line.find("<Amount>") != std::string::npos) { amount = std::stol(get_value(&line)); }
		else if (line.find("<Currency>") != std::string::npos) { currency = get_value(&line); }

		std::getline(*file, line);
	}

	CCustomer customer = find_customer_from_id(customer_list, &customer_id);
	CBank bank = find_bank_from_bic(bank_list, &bank_bic);
	auto money = CMoney(amount, currency);

	CAccount account = CAccount(&bank, iban, &customer, money);

	customer.add_account(&account);
	bank.add_account(&account);
}

// Destructors
CAccount::~CAccount()
{
	printf("CAccount: \t\t Konto ("); print_iban(); printf(") wird vernichtet! \n");
}


// Display
void CAccount::print_iban() const
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s ", iban_.substr(i + i * 4, 4).c_str());
	}
}

void CAccount::print() const
{
	printf("Kunde\t  : %s (Kd-Nr. %ld)", customer_->get_name().c_str(), customer_->get_id());
	printf("\nIBAN / BIC: "); print_iban(); printf("/ %s", bank_->get_bic().c_str());
	printf("\nKontostand: "); this->balance_.print();
}
