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

void writeMarketFile(Market* stkMkt,std::string stkSym, std::string fileDir) {
	// Ideally we would want this to be more diverse in its writing but we need to narrow it down for now.
	// It will have only write the stkSym of the single, maybe later we can work on this to make it
	// write out all sorts of files. It might even check for which stocks are empty or not and print
	// the ones that aren't? We can work on that later.

	/* Code will check to see if the file exists, if it does, it will open it. Otherwise create it.*/
	std::fstream file;
	file.open(fileDir,std::ios::out | std::ios::trunc);
	file.close();
	file.open(fileDir,std::ios::in | std::ios::out | std::ios::trunc);

	// file << "Writing to a file.\n";
	Stock* stkInfo = stkMkt->findStock(stkSym);
	LinkedList<Buyer*> buyList = stkInfo->getBuyList(); // Use this to print out buy list;
	LinkedList<Seller*> sellList = stkInfo->getSellList();

	std::string outputBuy = stkInfo->retBuyInfo();
	std::string outputSell = stkInfo->retSellInfo();

	std::cout << outputBuy << std::endl;
	file << outputBuy;

	stkInfo = NULL;
	file.close(); // Always remember to close the file when done.
	
}

void genRandOffer(std::vector<Stock*>* symPrices, Market* stkMkt) {
	/* Actual RNG Algorithm*/
	// std::random_device rd;
	// std::mt19937 gen(rd());
	// std::uniform_int_distribution<> distr(0,symPrice->size());
	// std::cout << distr(gen) << std::endl;
	// std::cout << (symPrice.at(rnd)).getStkName() << std::endl;
	
	/* Controlled Algorithm */
	// int range = max - min + 1;
	// int num = rand() % range + min;
	int stkRange = symPrices->size() - 0 + 1;
	int stkNum = rand() % stkRange + 0;
	std::string currSym = symPrices->at(stkNum)->getStkSym();
	// std::cout << "Symbol: " << currSym << std::endl;
	int offerRange = 10000 - 100 + 1;
	int offerNum = rand() % offerRange + 100;
	// std::cout <<  "Number of Offers: " << offerNum << std::endl;
	
	int accRange = 15 - 3 + 1;
	int accNum = (rand() % accRange) + 1;
	std::cout << "Number of Accounts: " << accNum << std::endl;

	// std::cout << "Producing accounts..." << std::endl;
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
		newCustomer = NULL;
		// std::cout << stkMkt->getCustomer(fullName)->getAccName() << std::endl;
	}

	/* Distribute the number of values*/
	int bidPrice;
	
	int origPrice = symPrices->at(stkNum)->getLastPrice();
	int priceRange = origPrice - 1 + 1;
	Buyer* prodBuy;
	Seller* prodSell;
	int rndTimeRange;
	int rndTime;
	int rndNumAccRange;
	int rndNumAcc;
	
	for(int i = 0; i <= offerNum; i++) { // Percent price changes
		// We need the price distribution for each of the stocks
		prodBuy = new Buyer();
		prodSell = new Seller();

		int rndBSRange = 2;
		int rndBS = (rand() % rndBSRange);

		rndNumAccRange = cstrList.size() - 1;
		rndNumAcc = rand() % rndNumAccRange;
		
		// std::cout << "RndNumAcc: " << (rndNumAcc % rndNumAccRange) << std::endl;
		switch(rndBS) {
			case 0:
				bidPrice = (origPrice + (rand() % priceRange)/2);;
				prodBuy->setStkName(currSym);
				prodBuy->setPrice(bidPrice);
				prodBuy->setID(stkMkt->getOfferNum());
				rndTimeRange = 60; // Trade per minute or hour, some interval.
				rndTime = (rand() % rndTimeRange);
				prodBuy->setTime(rndTime); // Preloaded Examples
				prodBuy->setNumStks((rand() % 500) + 1);
				prodBuy->setCustName("Customer" + std::to_string(rndNumAcc));
				cstrList.at(rndNumAcc)->addBOffer(prodBuy->getStkName(), prodBuy);
				stkMkt->addBOffer(currSym, prodBuy);
				prodBuy = NULL;
				break;
			case 1:
				bidPrice = (origPrice + (rand() % priceRange)/2);
				prodSell->setStkName(currSym);
				prodSell->setPrice(bidPrice);
				prodSell->setID(stkMkt->getOfferNum());
				prodSell->setTime(rndTime); // Preloaded Examples
				prodSell->setNumStks((rand() % 500) + 1);
				prodSell->setCustName("Customer");
				cstrList.at(rndNumAcc)->addSOffer(prodSell->getStkName(), prodSell);
				stkMkt->addSOffer(currSym, prodSell);
				prodSell = NULL;
				break;
			// default:
			// 	std::cout << "Error. Beyond range." << std::endl;
			// 	break;
		}	
	}
	
	// We need to check both cstrlist and stkMarket, below is the debugging to check
	// for(int i = 0; i < cstrList.size(); i++) {
	// 	cstrList.at(i)->findStock(currSym)->printBuy();
	// 	cstrList.at(i)->findStock(currSym)->printSell();
	// }
	
	// stkMkt->findStock(currSym)->printBuy();
	// stkMkt->findStock(currSym)->printSell();

	writeMarketFile(stkMkt,currSym, "test.txt");

	newCustomer = NULL;
	cstrList.empty();
}

int main() {
	std::cout << "Stock Market Initiating" << std::endl;
	std::cout << "Creating Stock Market account now...\n";

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
		// std::cout << convStrDecToInt(token) << std:: endl;
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


