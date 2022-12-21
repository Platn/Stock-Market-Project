// Project created by Kevin(Phu) Le

#include "common.h"
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <random>
#include "stock.h"
#include "market.h"

int convStrDecToInt(std::string input) {
	float convF = std::stof(input);
	int convInt = (int)(convF * 1000);
	return convInt;
}

void genRandOffer(std::vector<Stock*>* symPrice, Market* stkMkt) {
	/* Actual RNG Algorithm*/
	// std::random_device rd;
	// std::mt19937 gen(rd());
	// std::uniform_int_distribution<> distr(0,symPrice->size());
	// std::cout << distr(gen) << std::endl;
	// std::cout << (symPrice.at(rnd)).getStkName() << std::endl;
	
	/* Controlled Algorithm */
	// int range = max - min + 1;
	// int num = rand() % range + min;
	int stkRange = symPrice->size() - 0 + 1;
	int stkNum = rand() % stkRange + 0;
	std::string currSym = symPrice->at(stkNum)->getStkSym();
	std::cout << "Symbol: " << currSym << std::endl;
	int offerRange = 10000 - 100 + 1;
	int offerNum = rand() % offerRange + 100;
	std::cout <<  "Number of Offers: " << offerNum << std::endl;
	
	int accRange = 10 - 3 + 1;
	int accNum = rand() % accRange + 0;
	std::cout << "Number of Accounts: " << accNum << std::endl;

	std::cout << "Producing accounts..." << std::endl;
	Customer* newCustomer;
	std::string customerName = "Customer";
	std::string fullName;
	std::vector<Customer*> cstrList;

	for(int i = 0; i < accNum; i++) {
		fullName = customerName + std::to_string(i);
		newCustomer = new Customer(fullName);
		// newCustomer->setAccName(fullName);
		// std::cout << "NewCustomer: " << newCustomer->getAccName() << std::endl;
		stkMkt->addCustomer(newCustomer);
		cstrList.push_back(newCustomer);
		std::cout << stkMkt->getCustomer(fullName)->getAccName() << std::endl;
	}

	/* Distribute the number of values*/
	int bidPrice;
	
	int origPrice = symPrice->at(stkNum)->getLastPrice();
	int priceRange = origPrice - 1 + 1;
	Buyer* prodBuy;
	Seller* prodSell;
	int rndAcc;
	int rndAccRange;
	
	for(int i = 0; i <= offerNum; i++) { // Percent price changes
		// We need the price distribution for each of the stocks
		prodBuy = new Buyer();
		prodSell = new Seller();

		bidPrice = (origPrice + (rand() % priceRange)/2);;
		prodBuy->setStkName(currSym);
		prodBuy->setPrice(bidPrice);
		prodBuy->setID(stkMkt->getOfferNum());
		prodBuy->setTime(0); // Preloaded Examples
		prodBuy->setNumStks(rand() % 501);

		bidPrice = (origPrice + (rand() % priceRange)/2);
		prodSell->setStkName(currSym);
		prodSell->setPrice(bidPrice);
		prodSell->setID(stkMkt->getOfferNum());
		prodSell->setTime(0); // Preloaded Examples
		prodSell->setNumStks(rand() % 501);

		// Add to each Customer Account
		rndAccRange = cstrList.size() - 1 - 0 + 1;
		rndAcc = rand() % rndAccRange + 0;
		cstrList.at(rndAcc)->addBOffer(prodBuy->getStkName(), prodBuy);
		cstrList.at(rndAcc)->addSOffer(prodSell->getStkName(), prodSell);
		stkMkt->addBOffer(currSym, prodBuy);
		stkMkt->addSOffer(currSym, prodSell);
		prodBuy = NULL;
		prodSell = NULL;
	}
	
	// We need to check both cstrlist and stkMarket, below is the debugging to check
	// for(int i = 0; i < cstrList.size(); i++) {
	// 	cstrList.at(i)->findStock(currSym)->printBuy();
	// 	cstrList.at(i)->findStock(currSym)->printSell();
	// }
	stkMkt->findStock(currSym)->printBuy();
	stkMkt->findStock(currSym)->printSell();


	
	newCustomer = NULL;
	cstrList.empty();
}

int main() {
	std::cout << "Stock Market Initiating" << std::endl;
	std::cout << "Creating Stock Market account now...\n";
	Offer newOffer;
	Buyer newBuy;
	std::cout << "NewAcc: " << std::to_string(newBuy.getNumStks()) << std::endl;
	newBuy.setNumStks(1);

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
	int stkIndex = 0;
	Market* stkMkt = new Market("Stock Market");
	std::vector<Stock*>* symPrice = new std::vector<Stock*>; // Used for RNG generation of values

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
		stkMkt->addStock(newStock); // Createstock requires the price to be available. But for something like
		symPrice->push_back(newStock);
		newStock = NULL;
	}
	
	// std::cout << "Stock: " << stkMkt.findStock("ZYXI")->getLastPrice() << std::endl;
	std::cout << "Stock symbols have been loaded in." << std::endl;
	// We need to create the random number generator now. 
	srand(1);
	genRandOffer(symPrice, stkMkt);
	
	

	return 0;
}


