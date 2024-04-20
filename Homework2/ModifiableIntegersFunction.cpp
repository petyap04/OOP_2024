#include <iostream>
#include "ModifiableIntegersFunction.h"


ModifiableIntegersFunction::ModifiableIntegersFunction(int16_t(*g)(int16_t)) {
    if (!g) {
        throw std::exception("Not valid function!");
    }
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        arrWithValues[i] = MAX_VALUE_OF_INT16_T + 1;
    }
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        arrWithValues[i] = g(MIN_VALUE_OF_INT16_T + i);
    }
}

int16_t ModifiableIntegersFunction::getValueOfFunc(int16_t input) const{
      return arrWithValues[input - MIN_VALUE_OF_INT16_T];
}
void ModifiableIntegersFunction::funcModif(int16_t spacificInput, int16_t spacificOutput) {
    arrWithValues[spacificInput - MIN_VALUE_OF_INT16_T] = spacificOutput;
}
void ModifiableIntegersFunction::excudePoint(int16_t input) {
    arrWithValues[input - MIN_VALUE_OF_INT16_T] = EXCLUDE_POINTS_VALUE;
}
double ModifiableIntegersFunction::slope()const {
    int16_t x1 = 0;
    while (true) {
        if (arrWithValues[x1] != NOT_DEF_POINTS_VALUE && arrWithValues[x1] != EXCLUDE_POINTS_VALUE) {
            break;
        }
        x1++;
    }
    int16_t x2 = x1 + 1;
    while (true) {
        if (arrWithValues[x2] != NOT_DEF_POINTS_VALUE && arrWithValues[x2] != EXCLUDE_POINTS_VALUE) {
            break;
        }
        x2++;
    }
    return (double)(arrWithValues[x2] - arrWithValues[x1]) / (x2 - x1);
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other) {
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        if (arrWithValues[i] == NOT_DEF_POINTS_VALUE || other.arrWithValues[i] == NOT_DEF_POINTS_VALUE) {
            arrWithValues[i] = NOT_DEF_POINTS_VALUE;
        }
        else if(arrWithValues[i] == EXCLUDE_POINTS_VALUE || other.arrWithValues[i] == EXCLUDE_POINTS_VALUE) {
            arrWithValues[i] = EXCLUDE_POINTS_VALUE;
        }
        else {
            int currentValue = arrWithValues[i] + other.arrWithValues[i];
            if (currentValue < MAX_VALUE_OF_INT16_T || currentValue > MIN_VALUE_OF_INT16_T) {
                arrWithValues[i] = currentValue;
            }
            else {
                arrWithValues[i] = NOT_DEF_POINTS_VALUE;
            }
        }
    }
    return *this;
}
ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other) {
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        if (arrWithValues[i] == NOT_DEF_POINTS_VALUE || other.arrWithValues[i] == NOT_DEF_POINTS_VALUE) {
            arrWithValues[i] = NOT_DEF_POINTS_VALUE;
        }
        else if (arrWithValues[i] == EXCLUDE_POINTS_VALUE || other.arrWithValues[i] == EXCLUDE_POINTS_VALUE) {
            arrWithValues[i] = EXCLUDE_POINTS_VALUE;
        }
        else {
            int currentValue = arrWithValues[i] - other.arrWithValues[i];
            if (currentValue < MAX_VALUE_OF_INT16_T || currentValue > MIN_VALUE_OF_INT16_T) {
                arrWithValues[i] = currentValue;
            }
            else {
                arrWithValues[i] = NOT_DEF_POINTS_VALUE;
            }
        }
    }
    return *this;
}
ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    ModifiableIntegersFunction result(lhs);
    result += rhs;
    return result;
}
ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    ModifiableIntegersFunction result(lhs);
    result -= rhs;
    return result;
}


ModifiableIntegersFunction compositionOfFunctions(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    ModifiableIntegersFunction result(rhs);
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentValue = result.arrWithValues[i];
        if (currentValue != NOT_DEF_POINTS_VALUE && currentValue != EXCLUDE_POINTS_VALUE) {
            result.arrWithValues[i] = lhs.arrWithValues[currentValue - MIN_VALUE_OF_INT16_T];
        }
    }
    return result;
}

bool ModifiableIntegersFunction::injection() const {
    bool otherInputHasThatOutput[SIZE_OF_INT16_T]{ false };
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentOutput = arrWithValues[i - MIN_VALUE_OF_INT16_T];
        if (otherInputHasThatOutput[currentOutput - MIN_VALUE_OF_INT16_T] == true) {
            return false;
        }
        otherInputHasThatOutput[currentOutput] = true;
    }
    return true;
}
bool ModifiableIntegersFunction::surjection() const {
    bool outputArr[SIZE_OF_INT16_T]{ false };
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentOutput = arrWithValues[i - MIN_VALUE_OF_INT16_T];
        if (currentOutput == NOT_DEF_POINTS_VALUE) {
            continue;
        }
        outputArr[currentOutput - MIN_VALUE_OF_INT16_T] = true;
    }
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        if (outputArr[i - MIN_VALUE_OF_INT16_T] == false) {
            return false;
        }
    }
    return true;
}
bool ModifiableIntegersFunction::bijection() const {
    return injection() && bijection();
}

ModifiableIntegersFunction reverseFunction(const ModifiableIntegersFunction& func) {
    if (!func.injection()) {
        throw std::exception("Reverse function can not be def");
    }
    ModifiableIntegersFunction result;
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        result.arrWithValues[func.arrWithValues[i]] = i;
    }
    return result;
}

bool* operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    bool arr[SIZE_OF_INT16_T];
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentValueOfLhs = lhs.arrWithValues[i];
        int16_t currentValueOfRhs = rhs.arrWithValues[i];
        if (currentValueOfLhs == NOT_DEF_POINTS_VALUE || currentValueOfLhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = false;
        }
        else if (currentValueOfRhs == NOT_DEF_POINTS_VALUE || currentValueOfRhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = true;
        }
        else {
            if (currentValueOfLhs < currentValueOfRhs) {
                arr[i] = true;
            }
            else {
                arr[i] = false;
            }
        }
    }
    return arr;
}
bool* operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    bool arr[SIZE_OF_INT16_T];
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentValueOfLhs = lhs.arrWithValues[i];
        int16_t currentValueOfRhs = rhs.arrWithValues[i];
        if (currentValueOfLhs == NOT_DEF_POINTS_VALUE || currentValueOfLhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = false;
        }
        else if (currentValueOfRhs == NOT_DEF_POINTS_VALUE || currentValueOfRhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = true;
        }
        else {
            if (currentValueOfLhs <= currentValueOfRhs) {
                arr[i] = true;
            }
            else {
                arr[i] = false;
            }
        }
    }
    return arr;
}
bool* operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    bool arr[SIZE_OF_INT16_T];
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentValueOfLhs = lhs.arrWithValues[i];
        int16_t currentValueOfRhs = rhs.arrWithValues[i];
        if (currentValueOfLhs == NOT_DEF_POINTS_VALUE || currentValueOfLhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = true;
        }
        else if (currentValueOfRhs == NOT_DEF_POINTS_VALUE || currentValueOfRhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = false;
        }
        else {
            if (currentValueOfLhs > currentValueOfRhs) {
                arr[i] = false;
            }
            else {
                arr[i] = true;
            }
        }
    }
    return arr;
}
bool* operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    bool arr[SIZE_OF_INT16_T];
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentValueOfLhs = lhs.arrWithValues[i];
        int16_t currentValueOfRhs = rhs.arrWithValues[i];
        if (currentValueOfLhs == NOT_DEF_POINTS_VALUE || currentValueOfLhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = true;
        }
        else if (currentValueOfRhs == NOT_DEF_POINTS_VALUE || currentValueOfRhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = false;
        }
        else {
            if (currentValueOfLhs >= currentValueOfRhs) {
                arr[i] = false;
            }
            else {
                arr[i] = true;
            }
        }
    }
    return arr;
}
bool* operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    bool arr[SIZE_OF_INT16_T];
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        int16_t currentValueOfLhs = lhs.arrWithValues[i];
        int16_t currentValueOfRhs = rhs.arrWithValues[i];
        if (currentValueOfLhs == NOT_DEF_POINTS_VALUE || currentValueOfLhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = false;
        }
        else if (currentValueOfRhs == NOT_DEF_POINTS_VALUE || currentValueOfRhs == EXCLUDE_POINTS_VALUE) {
            arr[i] = false;
        }
        else {
            if (currentValueOfLhs == currentValueOfRhs) {
                arr[i] = true;
            }
            else {
                arr[i] = false;
            }
        }
    }
    return arr;
}
bool* operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    bool* arr = (lhs == rhs);
    for (int i = 0; i < SIZE_OF_INT16_T; i++) {
        if (arr[i] == true) {
            arr[i] = false;
        }
        else {
            arr[i] = true;
        }
    }
    return arr;
}

ModifiableIntegersFunction ModifiableIntegersFunction::operator^(int times) {
    if (times < -1 || times == 0) {
        throw std::exception("Not existing func");
    }
    if (times == -1) {
        return reverseFunction(*this);
    }
    ModifiableIntegersFunction result(*this);
    while (times != 0) {
        result = compositionOfFunctions(*this, result);
    }
    return result;
}

bool areParallel(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
    return lhs.slope() == rhs.slope();
}

void readFromFile(std::istream& is,  ModifiableIntegersFunction& func) {
    is.read((char*)&func, sizeof(func));
}
void writeInFile(std::ostream& os, const ModifiableIntegersFunction& func) {
    os.write((const char*)&func, sizeof(func));
}

int16_t f(int16_t x) {
    return x * 2;
}
int16_t g(int16_t x) {
    return x * x;
}

int main()
{
    ModifiableIntegersFunction m1(*f);

    std::cout << m1.getValueOfFunc(1) << std::endl;

    std::cout << m1.injection() << std::endl;
    
}
