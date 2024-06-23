#include "../h/Message.h"

void Message::setMessage(const MyString& text){
	this->text = text;
}

const MyString& Message::getMessage() const
{
	return text;
}
