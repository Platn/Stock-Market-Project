// Project created by Kevin(Phu) Le

#include "common.h"

int main() {
	std::cout << "Stock Market Initiating" << std::endl;
	std::cout << "Creating an empty account now...\n";
	Account newAcc;
	std::cout << "NewAcc: " << std::to_string(newAcc.getNumStks()) << std::endl;
	return 0;
}	
