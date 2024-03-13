#include <iostream>
constexpr int MAX_SIZE = 15;

enum class Subject {
    undefined,
    Math,
    English,
    Pe,
    Art
};
class Teacher {
    char name[MAX_SIZE] = "";
    unsigned int age = 0;
    Subject sj = Subject::undefined;
    unsigned int salary = 0;
    
public:
	const char* getName() const{
		return name;
	}
	int getAge() const{
		return age;
	}
    Subject getSubject()const {
        return sj;
    }
    unsigned int getSalary()const {
        return salary;
    }
    void setName(char* name) {
        if (name && strlen(name) <= 15) {
            strcpy(this->name, name);
        }
    }
	void setAge(int age){
		if (age >= 18 && age <=70) {
			this->age = age;
		}
	}
    void setSubject(const Subject& subject) {
        if (subject != Subject::undefined) {
            this->sj = subject;
        }
    }
    void setSalary(unsigned int salary) {
        if (salary >= 500) {
            this->salary = salary;
        }
    }
    Teacher(){}
    Teacher(char* name, unsigned int age, const Subject& sj, unsigned int salary) {
        setName(name);
        setAge(age);
        setSubject(sj);
        setSalary(salary);
    }
};
