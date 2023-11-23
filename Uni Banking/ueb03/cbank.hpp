//
//  cbank.h
//  Uni Banking
//
//  Created by Tj on 17.11.23.
//

#ifndef cbank_hpp
#define cbank_hpp

#include <string>
#include <vector>

// Forward declarations, include respective .h in main-file
class CAccount; // caccount.h

class CBank
{
	std::string name_;
	std::string bic_;
	std::vector<CAccount*> account_list_;

	public:
		CBank(std::string, std::string);

		// -- Methods --
		void add_account(CAccount *);

		// Display
		void print() const;
};
#endif