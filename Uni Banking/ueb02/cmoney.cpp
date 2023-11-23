//
//  cmoney.cpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//
#include "cmoney.hpp"
#include <string>

// Constructors
CMoney::CMoney(){
    // Basic Default Constructor
    amount_ = 0.0;
    currency_ = "EUR";
}

CMoney::CMoney(const double n_amount, std::string n_currency)
:amount_(n_amount), currency_(std::move(n_currency))
{
	// Basic Custom Constructor
}

// Display
void CMoney::print() const { printf("%.2f %s", amount_, currency_.c_str() ); }
