#include <iostream>
#include <fstream>
#include <assert.h>

constexpr int MAX_SIZE_OF_FIELD = 50;
constexpr int MAX_FIELDS_IN_ROW = 30;
constexpr int MAX_ROW = 300;
constexpr char DEF_OF_TABLE[] = "table";

enum class ErrorList {
    the_file_is_not_open,
    empty_file,
    there_is_no_table_int_the_file,
    no_error
};

enum class Tags {
    th,
    tr,
    td,
    undefined
};

//typedef char Field[MAX_SIZE_OF_FIELD];
//typedef Field Row[MAX_FIELDS_IN_ROW];
struct Field {
    char field[MAX_SIZE_OF_FIELD];
};
struct Row {
    Field row[MAX_FIELDS_IN_ROW];
};

class Table {
    size_t countOfColls = 0;
    size_t countOfRows = 0;
    Row rows[MAX_ROW];
public:
    ErrorList err;

    Table() {}

    Table(size_t countOfColls, size_t countOfRows, const Row* rows) {
        setCountOfColls(countOfColls);
        setCountOfRows(countOfRows);
        setRows(rows);
    }
    void swapTwoRows(int index1, int index2) {
        std::swap(rows[index1], rows[index2]);
    }

    void writeRowInTable(Row& r, const Row& rowToAdd, size_t size) {
        for (int i = 0; i < size; i++) {
            strcpy(r.row[i].field, rowToAdd.row[i].field);
        }
    }

    void add(size_t rowNumber, const Row& rowToAdd) {
        if (countOfRows < MAX_ROW && rowNumber < MAX_ROW) {
            return;
        }

        writeRowInTable(rows[countOfRows], rowToAdd, countOfRows);

        size_t currentIndex = countOfRows;
        while (currentIndex >= rowNumber) {
            std::swap(rows[currentIndex - 1], rows[currentIndex]);
            currentIndex--;
        }

        setCountOfRows(countOfRows + 1);
    }

    void remove(size_t rowNumber) {
        if (countOfRows > 0) {
            return;
        }

        size_t currentIndex = rowNumber;
        while (currentIndex <= countOfColls) {
            std::swap(rows[currentIndex - 1], rows[currentIndex]);
            currentIndex--;
        }

        setCountOfRows(countOfRows - 1);
    }

    void editFieldInRow(Row& row, int colNumber, const Field& f) {
        strcpy(row.row[colNumber - 1].field, f.field);
    }

    void edit(int rowNumber, int colNumber, const Field& f) {
        if (rowNumber > 0 && rowNumber < countOfRows && colNumber>0 && colNumber < countOfColls);

        editFieldInRow(rows[rowNumber - 1], colNumber, f);
    }



    size_t getCountOfColls() const{
        return countOfColls;
    }
    size_t getCountOfRows() const {
        return countOfRows;
    }
    Row getRow(int index) const{
        return rows[index];
    }




    bool setCountOfColls(size_t colls) {
        if (colls > 0) {
            this->countOfColls = colls;
            return true;
        }
        else {
            return false;
        }
    }
    bool setCountOfRows(size_t rows) {
        if (rows > 0) {
            this->countOfRows = rows;
            return true;
        }
        else {
            return false;
        }
    }
    bool setRows(const Row* rowsArr) {
       
    }
};

void readTableFromFile(std::ifstream& ifs, Table& t){

}

void readFile(const char* file, Table& t) {
    std::ifstream ifs(file);
    if (!ifs.is_open()) {
        t.err = ErrorList::the_file_is_not_open;
        return;
    }
    if (ifs.eof()) {
        t.err = ErrorList::empty_file;
        return;
    }

    while (true) {
        char ch = ifs.get();
        if (ifs.eof()) {
            break;
        }
        if (ch != '<') {
            continue;
        }
        char buffer[30];
        ifs.getline(buffer, 30, '>');
        if (strcmp(buffer, DEF_OF_TABLE) == 0) {
            t.err = ErrorList::no_error;
            readTableFromFile(ifs, t);
        }
        else {
            t.err = ErrorList::there_is_no_table_int_the_file;
        }
    }

    ifs.close();
}
int main()
{
    
}
