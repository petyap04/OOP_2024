#include <iostream>
#include <assert.h>

namespace Employees {
	using std::cin;
	using std::cout;
	enum class Position {
		SoftwareEngineer,
		SeniorSoftwareEngineer,
		EngineerManager,
		LeadSoftwareEngineer,
		unknown
	};
	struct Employee {
		char name[100] = {};
		Position position;
		double salary;
		int rating;
	};
	Position readPosition(int position) {
		switch (position) {
		case 0: return Position::SoftwareEngineer;
		case 1:return Position::SeniorSoftwareEngineer;
		case 2:return Position::EngineerManager;
		case 3:return Position::LeadSoftwareEngineer;
		default:return Position::unknown;
		}
	}
	bool isPositionValid(const Position& p) {
		switch (p) {
		case Position::SoftwareEngineer:return true;
		case Position::SeniorSoftwareEngineer:return true;
		case Position::EngineerManager:return true;
		case Position::LeadSoftwareEngineer:return true;
		case Position::unknown:return false;
		}
	}
	Employee initializeEmployee() {
		char name[100];
		int position;
		double salary;
		int rating;
		std::cin.get();
		cout << "|Name:";
		std::cin.getline(name, 100, '\n');
		cout << "|Position:";
		cin >> position;
		cout << "|Salary:";
		cin >> salary;
		cout << "|Rating:";
		cin >> rating;
		Position p = readPosition(position);
		assert(salary > 0 && rating > 0 && isPositionValid(p));
		Employee e = { "",p,salary,rating };
		strcpy_s(e.name, name);
		return e;
	}
	void printPosition(const Position& p) {
		switch (p) {
		case Position::SoftwareEngineer:std::cout << "SoftwareEngineer"; break;
		case Position::SeniorSoftwareEngineer:std::cout << "SeniorSoftwareEngineer"; break;
		case Position::EngineerManager:std::cout << "EngineerManager"; break;
		case Position::LeadSoftwareEngineer:std::cout << "LeadSoftwareEngineer"; break;
		}
	}
	void printEmployee(const Employee& e) {
		cout << "|Name:" << e.name << " |Position:";
		printPosition(e.position);
		cout << " |Rating:" << e.rating << " |Salary:" << e.salary << std::endl;
	}
}


namespace CompanyBussness {
	using namespace Employees;
	size_t numberOfEmployeesInTheFirm;
	struct Company {
		Employee* employeesArr = new Employee[numberOfEmployeesInTheFirm];
		double averageSalary;
	};
	double findAverageSalary(Employee* arr) {
		double sum = 0;
		for (size_t i = 0; i < numberOfEmployeesInTheFirm; i++)
		{
			sum += arr[i].salary;
		}
		return sum / numberOfEmployeesInTheFirm;
	}
	void readTheEmployeesInTheFirm(Company& c) {
		for (size_t i = 0; i < numberOfEmployeesInTheFirm; i++)
		{
			Employee e = initializeEmployee();
			c.employeesArr[i] = e;
		}
		c.averageSalary = findAverageSalary(c.employeesArr);
	}
	void printEmployees(const Employee* employeesArr, size_t size) {
		for (size_t i = 0; i < size; i++)
		{
			printEmployee(employeesArr[i]);
		}
	}
	void sortArrByName(Employee* arr, size_t size) {
		for (size_t i = 0; i < size - 1; i++) {
			size_t minElIndex = i;
			for (size_t j = i + 1; j < size; j++) {
				if (strcmp(arr[minElIndex].name, arr[j].name) > 0) {
					minElIndex = j;
				}
			}
			std::swap(arr[minElIndex], arr[i]);
		}
	}
	void printEmployeesWithSalaryBiggerThanTheAverage(const Company& c) {
		Employee* employeesWithBiggerThanTheAverageSalary = new Employee[numberOfEmployeesInTheFirm];
		size_t sizeOfArr = 0;
		size_t current = 0;
		for (size_t i = 0; i < numberOfEmployeesInTheFirm; i++)
		{
			if (c.employeesArr[i].salary > c.averageSalary) {
				employeesWithBiggerThanTheAverageSalary[current] = c.employeesArr[i];
				sizeOfArr++;
				current++;
			}
		}
		sortArrByName(employeesWithBiggerThanTheAverageSalary, sizeOfArr);
		printEmployees(employeesWithBiggerThanTheAverageSalary, sizeOfArr);
		delete[]employeesWithBiggerThanTheAverageSalary;
	}
	void printMaxandMinRatingForEveryPosition(const Company& c) {
		const int positionsInCompany = 4;
		double maxRatingOfEveryPosition[positionsInCompany]{ 0 };
		double minRatingOfEveryPosition[positionsInCompany]{ 0 };
		for (size_t i = 0; i < numberOfEmployeesInTheFirm; i++) {
			int currentIndex = (int)c.employeesArr[i].position;
			if (maxRatingOfEveryPosition[currentIndex] < c.employeesArr[i].rating) {
				maxRatingOfEveryPosition[currentIndex] = c.employeesArr[i].rating;
			}
			if (minRatingOfEveryPosition[currentIndex] > c.employeesArr[i].rating) {
				minRatingOfEveryPosition[currentIndex] = c.employeesArr[i].rating;
			}
		}
		for (int i = 0; i < positionsInCompany; i++) {
			printPosition(readPosition(i));
			cout << "|Max:" << maxRatingOfEveryPosition[i] << " |Min:" << minRatingOfEveryPosition[i] << std::endl;
		}
	}
}
int main()
{
	using namespace CompanyBussness;
	std::cin >> numberOfEmployeesInTheFirm;
	Company c;
	readTheEmployeesInTheFirm(c);
	printEmployeesWithSalaryBiggerThanTheAverage(c);
	printMaxandMinRatingForEveryPosition(c);
	std::cout << "|Average Salary:" << c.averageSalary;
	delete[] c.employeesArr;

}
