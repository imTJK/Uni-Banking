#pragma once
#include "string"
#include "vector"


class CCustomer;
class CBank;

auto get_value(const std::string* line);

CCustomer find_customer_from_id(const std::vector<CCustomer*>* customer_list, const long* id);
CBank find_bank_from_bic(const std::vector<CBank*>* bank_list, const std::string* bic);