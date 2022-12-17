// Project created by Kevin(Phu) Le

#include "common.h"

int main() {
	std::cout << "Stock Market Initiating" << std::endl;
	std::cout << "Creating an empty account now...\n";
	// Offer newOffer;
	Buyer newBuy;
	std::cout << "NewAcc: " << std::to_string(newBuy.getNumStks()) << std::endl;
	newBuy.setNumStks(1);
	std::cout << "Buyer Stocks: " << std::to_string(newBuy.getNumStks()) << std::endl;
	std::string fileName = "./nasdaq_Dec16_2022.csv";
	std::cout << "Reading from file: " << fileName << "..." << std::endl;
	

	

	return 0;
}	
