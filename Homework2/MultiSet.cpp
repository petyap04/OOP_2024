#include <iostream>
#include "MultiSet.h"

bool MultiSet::countOfNumberIsSmallerThanTheBiggestPosible(int number) {
	return number < (2 * numberOfBitsNeedForOneNumber - 1);
}
void MultiSet::copyFrom(const MultiSet& other) {
	buckets = new uint8_t[other.countOfBuckets];
	for (int i = 0; i < countOfBuckets; i++) {
		buckets[i] = other.buckets[i];
	}
	n = other.n;
	countOfBuckets = other.countOfBuckets;
	numberOfBitsNeedForOneNumber = other.numberOfBitsNeedForOneNumber;
}
void MultiSet::free() {
	delete[]buckets;
	buckets = nullptr;
	n = 0;
	countOfBuckets = 0;
	numberOfBitsNeedForOneNumber = 0;
}
bool MultiSet::isValid(unsigned int number) {
	if (number >= 1 && number <= 8){
		return true;
    }
	return false;
}
void MultiSet::makeBitOne(size_t indexOfBucket, size_t indexOfBit) {
	buckets[indexOfBucket] |= (1 << indexOfBit);
}
void MultiSet::makeBitZero(size_t indexOfBucket, size_t indexOfBit) {
	int mask = 1 << indexOfBit;
	if ((buckets[indexOfBucket] & mask) == mask) {
		buckets[indexOfBucket] ^= mask;
	}
}
bool MultiSet::isBitZero(size_t indexOfBucket, size_t indexOfBit) const{
	return (buckets[indexOfBucket] & (1 << indexOfBit)) == 0;
}


MultiSet::MultiSet(size_t n, size_t numberOfBitsNeedForOneNumber) {
	if (isValid(numberOfBitsNeedForOneNumber)) {
		countOfBuckets = ((n + 1) * numberOfBitsNeedForOneNumber) / BYTE_SIZE + ((((n + 1) * numberOfBitsNeedForOneNumber) % BYTE_SIZE) > 0 ? 1 : 0);
		buckets = new uint8_t[countOfBuckets]{ 0 };
	    this->n = n;
	    this->numberOfBitsNeedForOneNumber = numberOfBitsNeedForOneNumber;
	}
	
}
MultiSet::MultiSet(const MultiSet& other) {
	copyFrom(other);
}
MultiSet& MultiSet::operator=(const MultiSet& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

size_t MultiSet::getSize()const {
	return n;
}
size_t MultiSet::findIndexOfBucket(size_t index)const {
	return index / BYTE_SIZE;
}
size_t MultiSet::findIndexOfBit(size_t index)const {
	return BYTE_SIZE - index % BYTE_SIZE - 1;
}

void MultiSet::addNumber(unsigned int number) {
	if (number > n) {
		throw std::out_of_range("The number is not part of the set");
	}
	int indexOfBucket = findIndexOfBucket((number + 1) * numberOfBitsNeedForOneNumber - 1);
	int currentIndexOfBit = findIndexOfBit((number + 1) * numberOfBitsNeedForOneNumber - 1);
	for (int i = 0; i < numberOfBitsNeedForOneNumber; i++) {
		if (currentIndexOfBit >= BYTE_SIZE) {
			currentIndexOfBit = 0;
			indexOfBucket--;
		}
		if (isBitZero(indexOfBucket,currentIndexOfBit)) {
			makeBitOne(indexOfBucket, currentIndexOfBit);
			for (int j = i - 1; j >= 0; j--) {
				currentIndexOfBit--;
				if (currentIndexOfBit < 0) {
					currentIndexOfBit = BYTE_SIZE - 1;
					indexOfBucket++;
				}
				makeBitZero(indexOfBucket, currentIndexOfBit);
			}
			return;
		}
	currentIndexOfBit++;
	}
	
}
void MultiSet::addNumber(unsigned int number, unsigned int times) {
	if (number > n) {
		throw std::out_of_range("The number is not part of the set");
	}
	while (times > 0) {
		addNumber(number);
		times--;
	}
}
unsigned int MultiSet::countOfNumber(size_t number) const{
	if (number > n) {
		throw std::out_of_range("The number is not part of the set");
	}
	unsigned int count = 0;
	int indexOfBucket = findIndexOfBucket((number + 1) * numberOfBitsNeedForOneNumber - 1);
	int currentIndexOfBit = findIndexOfBit((number + 1) * numberOfBitsNeedForOneNumber - 1);
	for (int i = 0; i < numberOfBitsNeedForOneNumber; i++) {
		if (currentIndexOfBit >= 8) {
			currentIndexOfBit = 0;
			indexOfBucket--;
		}
		if (!isBitZero(indexOfBucket, currentIndexOfBit)) {
			count += (1 << i);
		}
		currentIndexOfBit++;
	}
	return count;
}

const uint8_t* MultiSet::getBuckets()const {
	return buckets;
}
void MultiSet::print()const {
	for (int i = 0; i <= n; i++) {
		if (countOfNumber(i) > 0) {
			std::cout << "Number:" << i << "|Count:" << countOfNumber(i) << std::endl;
		}
	}
}

MultiSet intersectionOfSets(const MultiSet& lhs, const MultiSet& rhs) {
	int nOfRes = std::min(lhs.n, rhs.n);
	int numberOfBitsNeedForOneNumberOfRes = std::min(lhs.numberOfBitsNeedForOneNumber, rhs.numberOfBitsNeedForOneNumber);
	MultiSet result(nOfRes, numberOfBitsNeedForOneNumberOfRes);
	for (int i = 0; i < nOfRes; i++) {
		int countOfCurrentNumber = std::min(lhs.countOfNumber(i), rhs.countOfNumber(i));
		result.addNumber(i, countOfCurrentNumber);
	}
	return result;
}


int main()
{
	try {
		MultiSet m(100, 6);
		m.addNumber(5,5);
        m.addNumber(1,56);
	    m.addNumber(17,17);
	    m.addNumber(7,4);
	    m.addNumber(0,19);
		m.print();
	}
	catch (std::out_of_range) {
		std::cout << "Invalid number" << std::endl;
	}
	catch (std::length_error) {
		std::cout << "" << std::endl;
	}
}
