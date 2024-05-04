#include <iostream>
#include "MyString.h"
#include "StringView.h"

StringView::StringView(const char* begin, const char* end) :begin(begin), end(end) {}
StringView::StringView(const char* begin, size_t howMany) :begin(begin), end(begin + howMany) {}
StringView::StringView(const MyString& str) :StringView(str.getData()){}
StringView::StringView(const char* str): begin(str), end(str+strlen(str)){}

size_t StringView::length() const
{
	return end - begin;//tova e taka zashoto rabotim s char koito ima razmer 1byte, ako rabotim s drug tip she tryabva tova da go umnochim po razmera na tipa
}

StringView StringView::substr(size_t begin, size_t howMany)
{
	return StringView(this->begin+begin, this->begin + begin +howMany);
}

std::ostream& operator<<(std::ostream& os, const StringView& sv)
{
	const char* current = sv.begin;
	while (current != sv.end) {
		os << *current;
		current++;
	}
	return os;
}
