#include "cbankmanager.hpp"
#include "ccustomer.hpp"
#include "cbank.hpp"
#include "caccount.hpp"
#include "ccurrentaccount.hpp"
#include "csavingsaccount.hpp"
#include "cfixeddespositaccount.hpp"


#include <iostream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <vector>

CAccount* temp_account;
CCurrentAccount* temp_current_account;
CSavingsAccount* temp_savings_account;
CFixedDepositAccount* temp_fixed_deposit_account;

CBankManager::CBankManager(std::string filename)
{
	// Input: Filename of .xml as string
	std::ifstream file(filename);

	if (file.is_open())
	{
		printf("Datei wurde erfolgreich geoeffnet und wird jetzt eingelesen ...\n");
		// There has to be a better solution than this, right?
		std::string line;

		while (std::getline(file, line))
		{
			// Iterates through entire file, line by line 
			if (line.find("<Customer>") != std::string::npos)
			{
				auto* customer_ptr = new CCustomer();
				customer_ptr->load(&file);
				customer_list_.push_back(customer_ptr);
			}

			else if (line.find("<Bank>") != std::string::npos)
			{
				auto* bank_ptr = new CBank(*new std::string, *new std::string);
				bank_ptr->load(&file);
				bank_list_.push_back(bank_ptr);
			}

			else if (line.find("<Account>") != std::string::npos)
			{
				temp_account = CAccount::load(&file, &bank_list_, &customer_list_);
			}

			else if (line.find("<CurrentAccount>") != std::string::npos)
			{
				temp_current_account = CCurrentAccount::load(&file, &bank_list_, &customer_list_);
			}

			else if (line.find("<SavingsAccount>") != std::string::npos)
			{
				temp_savings_account = CSavingsAccount::load(&file, &bank_list_, &customer_list_);
			}

			else if (line.find("<FixedDepositAccount>") != std::string::npos)
			{
				temp_fixed_deposit_account = CFixedDepositAccount::load(&file, &bank_list_, &customer_list_);
			}
		}
		printf("Datei wurde eingelesen.\n");
		file.close();
	}
	else
	{
		std::cout << "Failed to open the file: " << filename;
		_fcloseall();
	}
	

}

CBankManager::~CBankManager()
{
	for (auto& element : customer_list_)
	{
		element->~CCustomer();
		printf("\n");
	}

	// Hacky af
	temp_account->~CAccount();
	temp_savings_account->~CSavingsAccount();
	bank_list_[0]->~CBank();
	printf("\n");

	temp_current_account->~CCurrentAccount();
	temp_fixed_deposit_account->~CFixedDepositAccount();
	bank_list_[1]->~CBank();
	printf("\n");
}


void CBankManager::print_customer_list() const
{
	for (auto const& element : customer_list_) {
		printf("\n");
		element->print();
		printf("\n");
	}
}

void CBankManager::print_bank_list() const
{
	for (auto const& element : bank_list_) {
		printf("\n");
		element->print();
		printf("\n");
	}
}