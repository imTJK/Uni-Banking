//
//  caccount.hpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef caccount_hpp
#define caccount_hpp

#include "cmoney.hpp"
#include "ccustomer.hpp"

#include <string>
#include <vector>

// Forward declarations, include respective .h in main-file
class CBank;

class CAccount {
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
        void set_iban(std::string iban) { iban_ = std::move(iban); }
        void set_balance(CMoney balance);
        void set_customer(CCustomer customer);
        void set_bank(CBank bank);

        // Getter
        std::string get_iban() const   { return iban_;      }
        CMoney get_balance() const;
        CCustomer* get_customer() const;
        CBank* get_bank() const;

        // Misc
        static CAccount* load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);

        // Display
        void print_iban() const;
		void print() const;
};
#endif /* caccount_hpp */
