#include "../h/Check.h"

bool Check::isValid(const MyString& code)
{
	if (code.getSize() == 3) {
		for (int i = 0; i < 3; i++) {
			if (code[i] >= '0' && code[i] <= '9') {
				continue;
			}
			if (code[i] >= 'a' && code[i] <= 'z') {
				continue;
			}
			if (code[i] >= 'A' && code[i] <= 'Z') {
				continue;
			}
			return false;
		}
		return true;
	}
	return false;
}

Check::Check(const MyString& code, double money) {
	if (money < 0) {
		throw std::exception("Money cannot be negative number");
	}
	if (isValid) {
		this->code = code;
		this->money = money;
	}
	throw std::exception("The cod is not valid");
}

const MyString& Check::getCode()const {
	return code;
}

double Check::getMoney()const {
	return money;
}

bool operator==(const Check& lhs, const Check& rhs) {
	return lhs.getCode() == rhs.getCode() && lhs.getMoney() == rhs.getMoney();
}

bool operator!=(const Check& lhs, const Check& rhs) {
	return !(lhs == rhs);
}