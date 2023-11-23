//
//  ueb02.h
//  Uni Banking
//
//  Created by Tj on 17.11.23.
//

#include "csavingsaccount.hpp"

// Constructors
CSavingsAccount::CSavingsAccount(CBank* bank, std::string iban, CCustomer* customer, CMoney balance, double interest_rate)
	:CAccount(bank, std::move(iban), customer, std::move(balance)), interest_rate_(interest_rate) {};

// Destructors
CSavingsAccount::~CSavingsAccount()
{
	printf("CSavingsAccount: \t Konto ("); print_iban(); printf(") wird vernichtet! \n");
}

// Display
void CSavingsAccount::print() const
{
	CAccount::print();
	printf("\nSparzinsen: %f %%", interest_rate_);
}

