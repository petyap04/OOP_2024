#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;

namespace Students {
    enum class Major {
        Si,
        Is,
        Cs,
        Pm,
        M,
        Inf, 
        unknown
    };
    struct Student {
        int grade;
        int fn;
        char name[24] = "";
        Major mj;
    };
    void printMajor(const Major& major)
    {
        switch (major) {
        case Major::Si: std::cout << "Software engineering" << std::endl; break;
        case Major::Is: std::cout << "Information systems" << std::endl; break;
        case Major::Cs: std::cout << "Computer sience" << std::endl; break;
        case Major::Pm: std::cout << "Applied Mathematics" << std::endl; break;
        case Major::M: std::cout << "Mathematics" << std::endl; break;
        case Major::Inf: std::cout << "Informatics" << std::endl; break;
        default: std::cout << "Unknown" << std::endl;
        }
    }
    
    Major readMajor(int number) {
        switch (number) {
        case 0:return Major::Si;
        case 1:return Major::Is;
        case 2:return Major::Cs;
        case 3:return Major::Pm;
        case 4:return Major::M;
        case 5:return Major::Inf;
        default:return Major::unknown;
        }
    }
    bool isMajorValid(const Major& m) {
        switch (m) {
        case Major::Si:return true;
        case Major::Is:return true;
        case Major::Cs:return true;
        case Major::Pm:return true;
        case Major::M:return true;
        case Major::Inf:return true;
        case Major::unknown:return false;
        }
    }
    Student& initializeStudent() {
        int grade;
        int fn;
        char name[24];
        int mj;
        cin >> grade >> fn;
        std::cin.getline(name, 24, '\n');
        std::cin >> mj;
        Major m = readMajor(mj);
        assert(grade < 0 && grade > 12 && fn < 0 && isMajorValid(m));
        Student s = { grade, fn, "", m };
        strcpy(s.name, name);
        return s;
    }
    void printStudent(const Student& s) {
        cout << "|Grade:" << s.grade << " |Fn:" << s.fn << " |Name:" << s.name << " |Major:";
        printMajor(s.mj);
        cout << std::endl;
    }
}
namespace University {
    using namespace Students;
    
    struct Group{
        size_t numberOfStudents;
        Student* students = new Student[numberOfStudents];
        double averageGrade;
    };
    void readStudentsInGroup(Group& g) {
        cin >> g.numberOfStudents;
        double sumOfAllStudentsGrades = 0;
        for (int i = 0; i < g.numberOfStudents; i++) {
            Student s = initializeStudent();
            g.students[i] = s;
            sumOfAllStudentsGrades += s.grade;
        }
        g.averageGrade = sumOfAllStudentsGrades / g.numberOfStudents;
    }
    int numberOfStudentsWhoAreGettingScholarship(const Group& g, double minGradeForScholarship) {
        int count = 0;
        for (int i = 0; i < g.numberOfStudents; i++) {
            if (g.students[i].grade - minGradeForScholarship >= 0, 0001) {
                count++;
            }
        }
        return count;
    }
    void printGroup(Student* arr, size_t size) {
        for (int i = 0; i < size; i++) {
            printStudent(arr[i]);
        }
    }
    void printStudentWhoAreGettingScholarship(const Group& g, double minGradeForScholarship) {
        Student* studentsGettingScholarship = new Student[g.numberOfStudents];
        int currentIndex = 0;
        for (int i = 0; i < g.numberOfStudents; i++) {
            if (g.students[i].grade - minGradeForScholarship >= 0,0001) {
                studentsGettingScholarship[currentIndex] = g.students[i];
                currentIndex++;
            }
        }
        printGroup(studentsGettingScholarship, currentIndex + 1);
    }
}

int main()
{
    using namespace University;
    Group group;
    readStudentsInGroup(group);
    delete[] group.students;
}
