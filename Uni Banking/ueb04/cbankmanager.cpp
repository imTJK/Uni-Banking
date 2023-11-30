#include "cbankmanager.hpp"
#include "ccustomer.hpp"
#include "cbank.hpp"
#include "caccount.hpp"
#include "ccurrentaccount.hpp"
#include "csavingsaccount.hpp"
#include "cfixeddespositaccount.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

CBankManager::CBankManager(std::string filename)
{
	// Input: Filename of .xml as string
	std::ifstream file(filename);

	if (file.is_open())
	{
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
				CAccount::load(&file, &bank_list_, &customer_list_);
			}

			else if (line.find("<CurrentAccount>") != std::string::npos)
			{
				CCurrentAccount::load(&file, &bank_list_, &customer_list_);
			}

			else if (line.find("<SavingsAccount>") != std::string::npos)
			{
				CSavingsAccount::load(&file, &bank_list_, &customer_list_);
			}

			else if (line.find("<FixedDepositAccount>") != std::string::npos)
			{
				CFixedDepositAccount::load(&file, &bank_list_, &customer_list_);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Failed to open the file: " << filename;
		_fcloseall();
	}






}

void CBankManager::print_customer_list() const
{
	for (auto const& element : customer_list_) {
		element->print();
	}
}

void CBankManager::print_bank_list() const
{
	for (auto const& element : bank_list_) {
		element->print();
	}
}