#pragma once

#include "caccount.hpp"

class CSavingsAccount : private CAccount
{
	private:
		double interest_rate_;

	public:
		// Constructors
		CSavingsAccount(CBank*, std::string, CCustomer*, CMoney, double);
		CSavingsAccount();

		// Destructors
		~CSavingsAccount();

		// -- Methods --
		// Misc
		static void load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);

		// Display
		void print() const;
};