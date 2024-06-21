#include "../h/DataOfClientInTheBank.h"


const Client* DataOfClientInTheBank::getClient() const
{
	return client;
}

DataOfClientInTheBank::DataOfClientInTheBank(const Client& client) {
	this->client = &client;
}

int DataOfClientInTheBank::hasAccountWithThatNumber(unsigned accountNumber) const
{
	for (int i = 0; i < accounts.getSize(); i++) {
		if (accountNumber == accounts[i].accountNumber) {
			return i;
		}
	}
	return -1;
}

unsigned DataOfClientInTheBank::openNewAccount()
{
	//tryabva da se vavedat danni v accounta
	Account newAccount;
	accounts.pushBack(newAccount);
	return newAccount.accountNumber;
}



DataOfClientInTheBank::Account::Account(unsigned accountNumber, double availableMoney):accountNumber(accountNumber), availableMoney(availableMoney){}
