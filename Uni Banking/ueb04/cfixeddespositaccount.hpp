#include "ccurrentaccount.hpp"
#include "csavingsaccount.hpp"

class CFixedDepositAccount : private CCurrentAccount, private CSavingsAccount {

	public:
		CFixedDepositAccount(CBank*, std::string, CCustomer*, CMoney, CMoney*, double);
		~CFixedDepositAccount();

	// -- Methods --
	// Misc
	static void load(std::ifstream*, std::vector<CBank*>*, std::vector<CCustomer*>*);

};
