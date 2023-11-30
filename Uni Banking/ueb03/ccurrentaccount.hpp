#pragma once

#include "caccount.hpp"
#include <vector>

class CCurrentAccount : private CAccount
{
	private:
		CMoney* disposit_;

	public:
		using CAccount::print_iban;

		// Constructors
		CCurrentAccount(CBank*, std::string, CCustomer*, CMoney, CMoney*);

		// Destructors
		~CCurrentAccount();

		// -- Methods -- 
		// Misc
		static void load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);
			
		// Display
		void print() const;
};