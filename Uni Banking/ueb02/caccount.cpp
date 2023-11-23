//
//  caccount.cpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#include "caccount.hpp"
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


// Destructors
CAccount::~CAccount()
{
	printf("CAccount: \t\t Konto ("); print_iban(); printf(") wird vernichtet! \n");printf("CCurrentAccount: \t Konto ("); print_iban(); printf(") wird vernichtet! \n");
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
	printf("Kunde:\t    %s (Kd-Nr. %ld)", customer_->get_name().c_str(), customer_->get_id());
	printf("\nIBAN:\t    "); print_iban();
	printf("\nKontostand: "); this->balance_.print();
}
