#include "cfixeddespositaccount.hpp"
#include "xml_utils.h"

CFixedDepositAccount::CFixedDepositAccount(CBank* bank, std::string iban, CCustomer* customer, CMoney balance, CMoney* disposit, double interest_rate)
	:CCurrentAccount(bank, std::move(iban), customer, std::move(balance), disposit), CSavingsAccount(bank, std::move(iban), customer, std::move(balance), interest_rate) {}

CFixedDepositAccount::~CFixedDepositAccount()
{
    printf("CFixedDepositAccount: \t Konto ("); CCurrentAccount::print_iban(); printf(") wird vernichtet! \n");
}

void CFixedDepositAccount::load(std::ifstream* file, std::vector<CBank*>* bank_list, std::vector<CCustomer*>* customer_list){
	long customer_id, disposit_amount, balance_amount;
	double interest_rate;
	std::string bank_bic, line, iban, disposit_currency, balance_currency;

	std::getline(*file, line);

	while (line.find("</Account") == std::string::npos)
	{
		if (line.find("<IBAN>") != std::string::npos) { iban = get_value(&line); }
		else if (line.find("<Customer>") != std::string::npos) { customer_id = std::stol(get_value(&line)); }
		else if (line.find("<Bank>") != std::string::npos) { bank_bic = get_value(&line); }
		else if (line.find("<Balance>") != std::string::npos)
		{
			std::getline(*file, line);
			while (line.find("</Balance") == std::string::npos)
			{
				if (line.find("<Amount>") != std::string::npos) { balance_amount = std::stod(get_value(&line)); }
				else if (line.find("<Currency>") != std::string::npos) { balance_currency = get_value(&line); }
				std::getline(*file, line);
			}
		}
		else if (line.find("<Dispo>") != std::string::npos)
		{
			std::getline(*file, line);
			while (line.find("</Dispo") == std::string::npos)
			{
				if (line.find("<Amount>") != std::string::npos) { disposit_amount = std::stod(get_value(&line)); }
				else if (line.find("<Currency>") != std::string::npos) { disposit_currency = get_value(&line); }
				std::getline(*file, line);
			}
		}
		else if (line.find("<InterestRate>") != std::string::npos) { interest_rate = std::stod(get_value(&line)); }

		std::getline(*file, line);
	}

	CCustomer customer = find_customer_from_id(customer_list, &customer_id);
	CBank bank = find_bank_from_bic(bank_list, &bank_bic);
	auto balance_money = CMoney(balance_amount, balance_currency);
	auto disposit_money = CMoney(disposit_amount, disposit_currency);

	auto fixed_deposit_account = CFixedDepositAccount(&bank, iban, &customer, balance_money, &disposit_money, interest_rate);

	// How to implement this
	/*
		customer.add_account(static_cast<CAccount*>(fixed_deposit_account));
		bank.add_account(&fixed_deposit_account);
	*/
}