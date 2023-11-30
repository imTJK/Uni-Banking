//
//  caccount.hpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef caccount_hpp
#define caccount_hpp

#include <string>
#include "cmoney.hpp"
#include "ccustomer.hpp"
#include "cbank.hpp"

class CAccount {
	private:
	    friend class CFixedDepositAccount;

    protected:
        std::string iban_;
        CMoney balance_;
        CCustomer * customer_;
        CBank * bank_;
    
    public:
        // Constructors
        CAccount(CBank *, std::string, CCustomer*, CMoney);
        CAccount(std::string, CCustomer*, CMoney);

        // Destructors
        ~CAccount();

		// -- Methods --
        // Setter
	    void set_iban(std::string iban)       { iban_ = std::move(iban);       }
        void set_balance(CMoney balance)      { balance_ = std::move(balance); }
        void set_customer(CCustomer customer) { customer_ = &customer;         }
        void set_bank(CBank bank)             { bank_ = &bank;                 }

        // Getter
        std::string get_iban() const   { return iban_;      }
        CMoney get_balance() const     { return balance_;   }
        CCustomer get_customer() const { return *customer_; }
        CBank get_bank() const         { return *bank_;     }

        // Misc
        static void load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);

        // Display
        void print_iban() const;
		void print() const;
};
#endif /* caccount_hpp */
