﻿//
//  ccurrentaccount.cpp
//  Uni Banking
//
//  Created by Tj on 22.11.23.
//

#include "ccurrentaccount.hpp"
#include "xml_utils.h"

// Constructors
CCurrentAccount::CCurrentAccount(CBank* bank, std::string iban, CCustomer* customer, CMoney balance, CMoney* disposit)
	:CAccount(bank, std::move(iban), customer, std::move(balance)), disposit_(disposit) {}

// Destructors
CCurrentAccount::~CCurrentAccount()
{
	
}

void CCurrentAccount::load(std::ifstream* file, std::vector<CBank*>* bank_list, std::vector<CCustomer*>* customer_list)
{
		long customer_id, amount;
		double balance_amount, disposit_amount;
		std::string bank_bic, line, iban, balance_currency, disposit_currency;

		std::getline(*file, line);

		while (line.find("</Account") == std::string::npos)
		{
			if (line.find("<IBAN>") != std::string::npos)          { iban = get_value(&line);                   }
			else if (line.find("<Customer>") != std::string::npos) { customer_id = std::stol(get_value(&line)); }
			else if (line.find("<Bank>") != std::string::npos)     { bank_bic = get_value(&line);               }
			else if (line.find("<Balance>") != std::string::npos)  
			{
				std::getline(*file, line);
				while (line.find("</Balance") == std::string::npos)
				{
					if (line.find("<Amount>") != std::string::npos)        { balance_amount = std::stod(get_value(&line)); }
					else if (line.find("<Currency>") != std::string::npos) { balance_currency = get_value(&line);          }
					std::getline(*file, line);
				}
			}
			else if (line.find("<Dispo>") != std::string::npos)
			{
				std::getline(*file, line);
				while (line.find("</Dispo") == std::string::npos)
				{
					if (line.find("<Amount>") != std::string::npos)        { disposit_amount = std::stod(get_value(&line)); }
					else if (line.find("<Currency>") != std::string::npos) { disposit_currency = get_value(&line);          }
					std::getline(*file, line);
				}
			}
			std::getline(*file, line);
		}

		CCustomer customer = find_customer_from_id(customer_list, &customer_id);
		CBank bank = find_bank_from_bic(bank_list, &bank_bic);
		auto balance_money = CMoney(balance_amount, balance_currency);
		auto disposit_money = CMoney(disposit_amount, disposit_currency);

		auto current_account = CCurrentAccount(&bank, iban, &customer, balance_money, &disposit_money);

		customer.add_account(&current_account);
		bank.add_account(&current_account);
}

// Display
void CCurrentAccount::print() const
{
	CAccount::print();
	printf("\nDispo\t  : "); disposit_->print();
}
