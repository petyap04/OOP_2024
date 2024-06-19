#include "DataOfClients.h"

int DataOfClients::indexClientWithThatName(const char* firstName, const char* secondName) const
{
	for (int i = 0; i < clients.getSize(); i++) {
		if (clients[i].getClient().amITheUserYouAreSearchingFor(firstName, secondName)) {
			return i;
		}
	}
	return -1;
}


const DataOfClientInTheBank DataOfClients::operator[](int ind) const
{
	if (ind < 0 || ind >= clients.getSize()) {
		throw std::exception("error");
	}
	return clients[ind];
}


DataOfClientInTheBank DataOfClients::operator[](int ind) 
{
	if (ind < 0 || ind >= clients.getSize()) {
		throw std::exception("error");
	}
	return clients[ind];
}

void DataOfClients::addClient(const Client& c)
{
	clients.pushBack(c);
}
