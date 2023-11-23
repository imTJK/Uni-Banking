//
//  caddress.cpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#include "caddress.hpp"
#include <string>

// Constructors
CAddress::CAddress(std::string n_street, std::string n_postcode, std::string n_town)
:street_(std::move(n_street)), postcode_(std::move(n_postcode)), town_(std::move(n_town))
{
	// Basic Custom Constructor
}


// Display
void CAddress::print() const { printf("\n%s \n%s %s", street_.c_str(), postcode_.c_str(), town_.c_str()); }