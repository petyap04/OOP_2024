#pragma once
constexpr int MAX_SIZE_OF_FIELD = 50;
constexpr int MAX_FIELDS_IN_ROW = 15;
constexpr int MAX_ROW = 100;

constexpr char DEF_OF_TABLE[] = "table";
constexpr int MAX_SIZE_OF_TAG = 7;
constexpr int SIZE_OF_CHARECTER_REFERENCE = 2;
constexpr char REFERENCE[SIZE_OF_CHARECTER_REFERENCE + 1] = "&#";

typedef char Field[MAX_SIZE_OF_FIELD];

struct Row {
    Field row[MAX_FIELDS_IN_ROW] = {};
};


class Table {
    size_t countOfColls = 0;
    size_t countOfRows = 0;
    Row rows[MAX_ROW] = {};
public:
    Table();
    Table(size_t countOfColls, size_t countOfRows, const Row* rows);

    void swapTwoRows(int index1, int index2);

    void writeRowInTable(const Row& rowToAdd, int indexOfRow, size_t size);

    void add(size_t rowNumber, const Row& rowToAdd);

    void remove(size_t rowNumber);

    void editFieldInRow(Row& row, int colNumber, const Field& f);

    void edit(int rowNumber, int colNumber, const Field& f);

    void print()const;

    size_t getCountOfColls() const;
    size_t getCountOfRows() const;
    const Row& getRow(int index) const;
    const Field& getFieldInRow(int indexOfRow, int indexOfColl) const;

    bool setCountOfColls(size_t colls);
    bool setCountOfRows(size_t rows);
    void setFieldInRow(char str, size_t indexOfRow, size_t indexOfColl);
    bool setFieldInRow(const char* str, size_t indexOfRow, size_t indexOfColl);
}; 
