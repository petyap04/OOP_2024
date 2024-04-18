#pragma once
#include <fstream>
constexpr unsigned int BYTE_SIZE = 8;
class MultiSet {
	size_t countOfBuckets = 0;
	size_t n = 0;
	size_t numberOfBitsNeedForOneNumber = 0;
	uint8_t* buckets = nullptr;

	unsigned int maxCountForThisBits() const;
	bool countOfNumberIsSmallerThanTheBiggestPossible(int number);
	void copyFrom(const MultiSet& other);
	void free();
	static bool isValid(unsigned int number);
	bool isBitZero(size_t indexOfBucket, size_t indexOfBit) const;
	void makeBitOne(size_t indexOfBucket, size_t indexOfBit);
	void makeBitZero(size_t indexOfBucket, size_t indexOfBit);
	size_t findIndexOfBucket(size_t index)const;
	size_t findIndexOfBit(size_t index)const;
public:
	MultiSet() = default;
	MultiSet(size_t n, size_t numberOfBitsNeedForOneNumber);
	MultiSet(const MultiSet& other);

	MultiSet& operator=(const MultiSet& other);

	size_t getSize()const;
	const uint8_t* getBuckets()const;
	void addNumber(unsigned int number);
	void addNumber(unsigned int number, unsigned int times);
	unsigned int countOfNumber(size_t number) const;
	void print()const;
	void printHex()const;
	void printBucketInBinary(int indexOfBucket)const;
	void printBinary()const;

	friend std::istream& operator>>(std::istream& is, MultiSet& m);
	friend std::ostream& operator<<(std::ostream& os, const MultiSet& m);
	friend MultiSet intersectionOfSets(const MultiSet& lhs, const MultiSet& rhs);
	friend MultiSet addition(const MultiSet& set);
};
