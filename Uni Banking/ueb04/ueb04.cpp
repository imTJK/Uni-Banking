#include <iostream>
#include <vector>

using namespace std;

#include "cmoney.h"
#include "caccount.h"
#include "ccustomer.h"
#include "cbank.h"
#include "cbankmanager.h"

int main()
{
   CBankManager BankManager("data.xml");

   cout << endl;
   BankManager.printCustomerList();
   cout << endl;
   BankManager.printBankList();
   cout << endl;

   return 0;
}
