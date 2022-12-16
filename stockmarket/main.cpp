// Project created by Kevin(Phu) Le

#include "common.h"


class Buyer : public Offer {
	public:
	Buyer();
};

class Seller : 	public Offer {
	// Inherit from the Offer class to use its values
	public:
	Seller();
};

// Buyer::Buyer(){}
// Seller::Seller(){}

int main() {
	std::cout << "Stock Market Initiating" << std::endl;
	std::cout << "Creating an empty account now...\n";
	// Offer newOffer;
	Buyer newBuy;
	std::cout << "NewAcc: " << std::to_string(newBuy.getNumStks()) << std::endl;
	return 0;
}	
