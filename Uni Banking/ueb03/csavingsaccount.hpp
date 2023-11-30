#pragma once

#include "caccount.hpp"
#include <vector>

class CSavingsAccount : private CAccount
{
	private:
		double interest_rate_;

	public:
		// Constructors
		CSavingsAccount(CBank*, std::string, CCustomer*, CMoney, double);

		// Destructors
		~CSavingsAccount();

		// -- Methods --
		// Misc
		static void load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);

		// Display
		void print() const;
};