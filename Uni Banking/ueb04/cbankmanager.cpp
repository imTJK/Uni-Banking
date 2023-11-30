#include "cbankmanager.hpp"
#include "caccount.hpp"
#include "ccustomer.hpp"
#include "ccurrentaccount.hpp"
#include "cfixeddespositaccount.hpp"
#include "csavingsaccount.hpp"

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
				auto* customer_ptr = new CCustomer(*new long, *new std::string, *new CDate(*new int, *new int, *new int), *new CAddress(*new std::string, *new std::string, *new std::string));
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

			else
			{
				std::cout << "Failed to open the file: " << filename;
				_fcloseall();
			}
		}
	}
	file.close();
}
