//
//  cmoney.hpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef cmoney_hpp
#define cmoney_hpp

#include <string>

class CMoney {
    private:
        double amount_;
        std::string currency_;
    
    public:
        // Constructors
        CMoney();
        explicit CMoney(double, std::string = "EUR");

        // Setter
        void set_amount(double const new_amount)    { amount_ = new_amount;                }
        void set_currency(std::string new_currency) { currency_ = std::move(new_currency); }

        // Getter
        double get_amount() const { return amount_; }
        std::string get_currency() const { return currency_; }

        // Display
        void print() const;
};

#endif /* cmoney_hpp */
