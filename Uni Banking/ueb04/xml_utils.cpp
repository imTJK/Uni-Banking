#include "xml_utils.h"
#include "ccustomer.hpp"
#include "cbank.hpp"


// Lambda to find get values from xml file
std::string get_value(const std::string* line)
	{
		return line->substr(line->find('>') + 1, line->find("</ID>") - line->find('>') - 1);
	};

CCustomer* find_customer_from_id(const std::vector<CCustomer*>* customer_list, const long* id) {
	// Will always find a value in given data, but exceptions could occur
	// TODO: Handle exceptions

	for (auto const& element : *customer_list) {
		if (element->get_id() == *id)
		{
			return element;
		}
	}
}

CBank* find_bank_from_bic(const std::vector<CBank*>* bank_list, const std::string* bic) {
	// Will always find a value in given data, but exceptions could occur
	// TODO: Handle exceptions

	for (auto const& element : *bank_list) {
		if (element->get_bic() == *bic)
		{
			return element;
		}
	}
}
