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

void DataOfClients::addClient(const Client& c)
{
	clients.pushBack(c);
}
