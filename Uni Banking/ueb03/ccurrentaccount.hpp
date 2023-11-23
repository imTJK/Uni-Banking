#pragma once

#include <string>
#include "caccount.hpp"

class CCurrentAccount : private CAccount
{
	private:
		CMoney* disposit_;

	public:
		// Constructors
		CCurrentAccount(CBank*, std::string, CCustomer*, CMoney, CMoney*);

		// Destructors
		~CCurrentAccount();

		// Display
		void print() const;
};