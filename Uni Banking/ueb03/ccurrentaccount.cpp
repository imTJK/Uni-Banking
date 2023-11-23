//
//  ccurrentaccount.cpp
//  Uni Banking
//
//  Created by Tj on 22.11.23.
//

#include "ccurrentaccount.hpp"

// Constructors
CCurrentAccount::CCurrentAccount(CBank* bank, std::string iban, CCustomer* customer, CMoney balance, CMoney* disposit)
	:CAccount(bank, std::move(iban), customer, std::move(balance)), disposit_(disposit) {}

// Destructors
CCurrentAccount::~CCurrentAccount()
{
	printf("CCurrentAccount: \t Konto ("); print_iban(); printf(") wird vernichtet! \n");
}

// Display
void CCurrentAccount::print() const
{
	CAccount::print();
	printf("\nDispo:"); disposit_->print();
}
