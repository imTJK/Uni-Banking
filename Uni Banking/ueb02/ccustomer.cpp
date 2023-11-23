//
//  ccustomer.cpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#include "ccustomer.hpp"
#include "caccount.hpp"

// Constructors
CCustomer::CCustomer(long n_id, std::string name, CDate birthday, CAddress address)
:id_(n_id), name_(std::move(name)), birthday_(birthday), address_(std::move(address)), account_list_(NULL)
{}


// -- Custom Methods --
// Add Account to Customer
void CCustomer::add_account(CAccount * account_ptr) { account_list_.push_back(account_ptr); }

// Display
void CCustomer::print() const {
    printf("%s (Kd-Nr. %ld)", name_.c_str(), id_);
    address_.print();

    printf("\ngeboren am: "); birthday_.print();
    printf("\nKonten:");
    
    for (auto const & element : account_list_) {
        printf("\n- Kontonr.: "); element->print_iban();
    }
}
