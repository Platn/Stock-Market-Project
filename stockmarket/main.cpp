// Project created by Kevin(Phu) Le

#include "common.h"
#include <sstream>
#include <fstream>

int convStrDecToInt(std::string input) {
	float tempF = std::stof(input);
	int convInt = (int)(tempF * 100);
	return convInt;
}

int main() {
	std::cout << "Stock Market Initiating" << std::endl;
	std::cout << "Creating Stock Market account now...\n";
	Offer newOffer;
	Buyer newBuy;
	std::cout << "NewAcc: " << std::to_string(newBuy.getNumStks()) << std::endl;
	newBuy.setNumStks(1);
	std::cout << "Buyer Stocks: " << std::to_string(newBuy.getNumStks()) << std::endl;
	newBuy.setID(12345);
	std::cout << "Buyer ID: " << std::to_string(newBuy.getID()) << std::endl;
	Market stkMkt("Stock Market");
	std::string fileName = "./nasdaq_Dec16_2022.csv";
	std::cout << "Reading from file: " << fileName << "..." << std::endl;
	std::ifstream file(fileName);
	if (!file) {
		std::cout << "File not found" << std::endl;
		return 0;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string token;
	std::getline(buffer,token,'\n'); // Take out the initial line
	Stock* newStock;
	while(std::getline(buffer,token,'\n')){
		getline(buffer,token, ','); // Get Symbol
		// std::cout << token << std::endl;
		newStock = new Stock(token);

		getline(buffer,token,','); // Get Name
		getline(buffer,token,'$'); // Extract $ from Last Sale

		getline(buffer,token,','); // Get Last Sale
		newStock->setLastPrice(convStrDecToInt(token)); // Store last price
		std::cout << convStrDecToInt(token) << std:: endl;
		getline(buffer,token,','); // Get Net Change
		getline(buffer,token,','); // Get % Change
		getline(buffer,token,','); // Get Market Change
		getline(buffer,token,','); // Get Country
		getline(buffer,token,','); // Get IPO Year
		getline(buffer,token,','); // Get Volume
		getline(buffer,token,','); // Get Sector
		getline(buffer,token,','); // Get Industry
		stkMkt.addStock(newStock); // Createstock requires the price to be available. But for something like 
		newStock = NULL;
	}
	
	std::cout << "Stock: " << stkMkt.findStock("ZYXI")->getLastPrice() << std::endl;
	

	return 0;
}


