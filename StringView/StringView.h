#pragma once
#include "MyString.h"

class StringView {
private:
	const char* begin;
	const char* end;
public:
	StringView(const char* begin, const char* end);
	StringView(const char* begin, size_t howMany);
	StringView(const MyString& str);
	StringView(const char* str);

	size_t length()const;
	StringView substr(size_t begin, size_t howMany);
	friend std::ostream& operator<<(std::ostream& os, const StringView& sv);
};