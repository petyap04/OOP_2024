#pragma once
#include <iostream>
#include <fstream>
class Task
{
private:
	bool isApproved = false;
public:
	friend std::ifstream& operator>>(std::ifstream& ifs, Task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Task* task);

	virtual Task* clone()const = 0;
	virtual ~Task() = default;
};

