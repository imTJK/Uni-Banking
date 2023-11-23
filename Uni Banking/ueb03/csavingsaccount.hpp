#pragma once

#include "caccount.hpp"

class CSavingsAccount : private CAccount
{
	private:
		double interest_rate_;

	public:
		// Constructors
		CSavingsAccount(CBank*, std::string, CCustomer*, CMoney, double);

		// Destructors
		~CSavingsAccount();

		// Display
		void print() const;
};