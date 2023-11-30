//
//  caddress.hpp
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef caddress_hpp
#define caddress_hpp

#include <string>

class CAddress {
    private:
        std::string street_;
        std::string postcode_;
        std::string town_;

    public:
	    // Constructors
	    CAddress(std::string, std::string, std::string);
	    
	    // Getter
	    std::string get_street() const   { return street_;   }
	    std::string get_postcode() const { return postcode_; }
	    std::string get_town() const     { return town_;     }

	    // Setter
	    void set_town(std::string town)         { town_ = std::move(town);         }
	    void set_street(std::string street)     { street_ = std::move(street);     }
	    void set_postcode(std::string postcode) { postcode_ = std::move(postcode); }
	    
	    // Display
	    void print() const;
};

#endif /* caddress_hpp */
