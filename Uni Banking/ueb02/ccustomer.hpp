//
//  ccustomer.hpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef ccustomer_hpp
#define ccustomer_hpp

// Local Imports
#include "cdate.hpp"
#include "caddress.hpp"

// Standard Imports
#include <stdio.h>
#include <string>
#include <vector>

// Forward declarations, include respective .h in main-file
class CAccount; // caccount.h

class CCustomer {
    long id_;
    std::string name_;
    CDate birthday_;
    CAddress address_;
    std::vector<CAccount *> account_list_;
    
    public:
        CCustomer(long, std::string, CDate, CAddress);
    
        // Setter
        void set_id(long const new_id)                                 { id_ = new_id;                                }
        void set_name(std::string new_name)                            { name_ = std::move(new_name);                 }
        void set_address(CAddress new_address)                         { address_ = std::move(new_address);           }
        void set_birthday(const CDate new_birthday)                    { birthday_ = new_birthday;                    }
        void set_account_list(std::vector<CAccount*> new_account_list) { account_list_ = std::move(new_account_list); }

        // Getter
        long get_id() const                             { return id_;              }
        std::string get_name() const                    { return name_;         }
        CAddress get_address() const                    { return address_;      }
        CDate get_birthday() const                      { return birthday_;        }
        std::vector<CAccount*> get_account_list() const { return account_list_; }
        
        // -- Methods --
        void add_account(CAccount *);
        
        // Display
        void print() const;
};

#endif /* ccustomer_hpp */
