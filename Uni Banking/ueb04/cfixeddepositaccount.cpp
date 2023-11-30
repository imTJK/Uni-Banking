#include "cfixeddespositaccount.hpp"
#include "cbank.hpp"
#include "ccustomer.hpp"
#include "xml_utils.h"

CFixedDepositAccount::CFixedDepositAccount(CBank* bank, std::string iban, CCustomer* customer, CMoney balance, CMoney* disposit, double interest_rate)
	:CCurrentAccount(bank, iban, customer, balance, disposit), CSavingsAccount(bank, iban, customer, balance, interest_rate) {}


CFixedDepositAccount::~CFixedDepositAccount()
{
    printf("CFixedDepositAccount: \t Konto ("); CCurrentAccount::print_iban(); printf(") wird vernichtet! \n");
}

void CFixedDepositAccount::load(std::ifstream* file, std::vector<CBank*>* bank_list, std::vector<CCustomer*>* customer_list){
	long customer_id, disposit_amount = 0, balance_amount = 0;
	double interest_rate = 0;
	std::string bank_bic, line, iban, disposit_currency, balance_currency;

	std::getline(*file, line);

	while (line.find("</Account") == std::string::npos)
	{
		if (line.find("<IBAN>") != std::string::npos)                  { iban = get_value(&line);                           }
		else if (line.find("<Customer>") != std::string::npos)         { customer_id = std::stol(get_value(&line));    }
		else if (line.find("<Bank>") != std::string::npos)             { bank_bic = get_value(&line);                       }
		else if (line.find("<Balance>") != std::string::npos)
		{
			std::getline(*file, line);
			while (line.find("</Balance") == std::string::npos)
			{
				if (line.find("<Amount>") != std::string::npos)        { balance_amount = std::stol(get_value(&line)); }
				else if (line.find("<Currency>") != std::string::npos) { balance_currency = get_value(&line);               }
				std::getline(*file, line);
			}
		}
		else if (line.find("<Dispo>") != std::string::npos)
		{
			std::getline(*file, line);
			while (line.find("</Dispo") == std::string::npos)
			{
				if (line.find("<Amount>") != std::string::npos)        { disposit_amount = std::stol(get_value(&line)); }
				else if (line.find("<Currency>") != std::string::npos) { disposit_currency = get_value(&line); }
				std::getline(*file, line);
			}
		}
		else if (line.find("<InterestRate>") != std::string::npos)    { interest_rate = std::stod(get_value(&line));     }

		std::getline(*file, line);
	}

	CCustomer * customer = find_customer_from_id(customer_list, &customer_id);
	CBank * bank = find_bank_from_bic(bank_list, &bank_bic);
	auto const balance_money = CMoney(balance_amount, balance_currency);
	auto disposit_money = CMoney(disposit_amount, disposit_currency);

	auto const fixed_deposit_account = new CFixedDepositAccount(bank, iban, customer, balance_money, &disposit_money, interest_rate);

	/*
	customer->add_account(&fixed_deposit_account);
	bank->add_account(&fixed_deposit_account);
	*/
}