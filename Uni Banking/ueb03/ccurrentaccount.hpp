#pragma once

#include <string>
#include "caccount.hpp"

class CCurrentAccount : private CAccount
{
	private:
		CMoney* disposit_;

	public:
		using CAccount::print_iban;

		// Constructors
		CCurrentAccount(CBank*, std::string, CCustomer*, CMoney, CMoney*);
		CCurrentAccount();

		// Destructors
		~CCurrentAccount();

		// -- Methods -- 
		// Misc
		static void load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);
			
		// Display
		void print() const;
};