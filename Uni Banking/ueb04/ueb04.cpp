#include <iostream>
#include <vector>

using namespace std;

#include "cmoney.hpp"
#include "caccount.hpp"
#include "ccustomer.hpp"
#include "cbank.hpp"
#include "cbankmanager.hpp"

void ueb04()
{
   CBankManager BankManager("D:\\Programming\\CPP\\Uni\\Uni Banking\\Uni Banking\\resources\\ueb04\\data.xml");

   cout << endl;
   BankManager.print_customer_list();
   cout << endl;
   BankManager.print_bank_list();
   cout << endl;
}
