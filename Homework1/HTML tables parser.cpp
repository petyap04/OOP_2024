#include <iostream>
#include <fstream>
#include <assert.h>
#include "Table.h"
#pragma warning(disable:4996)

constexpr char DEF_OF_TABLE[] = "table";
constexpr int MAX_SIZE_OF_TAG = 7;
constexpr int SIZE_OF_CHARECTER_REFERENCE = 2;
constexpr char REFERENCE[SIZE_OF_CHARECTER_REFERENCE + 1] = "&#";


enum class ErrorList {
    the_file_is_not_open,
    empty_file,
    there_is_no_table_int_the_file,
    no_error
};

enum class TypeOfTags{
    table,
    th,
    tr,
    td, 
    is_not_tag
};
TypeOfTags& defineTag(TypeOfTags& t, char ch) {
    switch (ch) {
    case 'a':t = TypeOfTags::table; break;
    case 'h':t = TypeOfTags::th; break;
    case 'r':t = TypeOfTags::tr; break;
    case 'd':t = TypeOfTags::td; break;
    default: t = TypeOfTags::is_not_tag;
    }
    return t;
}

Table::Table() = default;
Table:: Table(size_t countOfColls, size_t countOfRows, const Row* rows) {
    setCountOfColls(countOfColls);
    setCountOfRows(countOfRows);
}

void Table::swapTwoRows(int index1, int index2) {
    std::swap(rows[index1], rows[index2]);
}

void Table:: writeRowInTable(Row& r, const Row& rowToAdd, size_t size) {
    for (int i = 0; i < size; i++) {
        strcpy(r.row[i], rowToAdd.row[i]);
    }
}

void Table::add(size_t rowNumber, const Row& rowToAdd) {
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

void Table::remove(size_t rowNumber) {
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

void Table::editFieldInRow(Row& row, int colNumber, const Field& f) {
    strcpy(row.row[colNumber - 1], f);
}

void Table::edit(int rowNumber, int colNumber, const Field& f) {
    if (rowNumber > 0 && rowNumber < countOfRows && colNumber>0 && colNumber < countOfColls);

    editFieldInRow(rows[rowNumber - 1], colNumber, f);
}

void Table::print()const {
    for (int i = 1; i <= countOfRows; i++) {
        for (int j = 1; j < countOfColls; j++) {
            std::cout << rows[i].row[j];
        }
    }
}

size_t Table::getCountOfColls() const {
    return countOfColls;
}
size_t Table::getCountOfRows() const {
    return countOfRows;
}
const Row& Table::getRow(int index) const {
    return rows[index];
}

bool Table::setCountOfColls(size_t colls) {
    if (colls > 0) {
        this->countOfColls = colls;
        return true;
    }
    else {
        return false;
    }
}
bool Table::setCountOfRows(size_t rows) {
    if (rows > 0) {
        this->countOfRows = rows;
        return true;
    }
    else {
        return false;
    }
}
bool Table::setFieldInRow(const char* str, size_t indexOfRow, size_t indexOfColl) {
    if (!str) {
        return false;
    }
    strcpy(rows[indexOfRow].row[indexOfColl], str);
}


class FileHandler {
    const char* filename;
    Table table;
    ErrorList err = ErrorList::no_error;;
public:
    void setFilename(const char* filename) {
        this->filename = filename;
    }
    void setTable(const Table& table) {
        this->table = table;
    }
    void setError(const ErrorList& err) {
        this->err = err;
    }

    const char* getFile()const {
        return filename;
    }
    const Table& getTable()const {
        return table;
    }
    const ErrorList& getError()const {
        return err;
    }

};
void defTag(std::ifstream& ifs, TypeOfTags& tag, bool isClosingTag) {
    char ch1 = ifs.get();
    if (ch1 == '<') {
        ch1 = ifs.get();
        if (ch1 == '/') {
            isClosingTag = true;
            ch1 = ifs.get();
        }
        if (ch1 == 't') {
            defineTag(tag, ifs.get());
        }
    }
    else {
        tag = TypeOfTags::is_not_tag;
        ifs.seekg(-1, std::ios::cur);
    }
}
bool isIndex(char ch) {
    return ch >= '0' && ch <= '9';
}
int symbolToIndex(char ch) {
    return ch - '0';
}
int indexOfCharacter(std::ifstream& ifs) {
    int index = 0;
    char ch = ifs.get();
    while (index < 127 && isIndex(ch)) {
        (index *= 10) += symbolToIndex(ch);
        ch = ifs.get();
    }
    ifs.seekg(-1, std::ios::cur);
    return index;
}
bool characterEntityReference(char* buffer) {
    return strcmp(buffer, REFERENCE) == 0;
}
void readTextBetweenTags(std::ifstream& ifs, Table& t, const TypeOfTags& tag, size_t currentCol, size_t currentRow) {
    char buffer[MAX_SIZE_OF_FIELD];
    int currentIndOfBuf = 0;
    if (tag == TypeOfTags::th) {
        buffer[currentIndOfBuf] = '*';
        currentIndOfBuf++;
    }
    
    bool isTag = false;
    for (int i = currentIndOfBuf; i < MAX_SIZE_OF_FIELD; i++) {
        TypeOfTags newtag;
        defTag(ifs, newtag, isTag);
        if (newtag!=TypeOfTags::is_not_tag) {
            if (tag == TypeOfTags::th) {
                buffer[i] = '*';
                buffer[i + 1] = '\0';
            }
            t.setFieldInRow(buffer, currentRow, currentCol);
            return;
        }


        size_t currentPos = ifs.tellg();
        char buffer2[SIZE_OF_CHARECTER_REFERENCE + 1];
        ifs.getline(buffer2, SIZE_OF_CHARECTER_REFERENCE + 1);

        if (characterEntityReference(buffer2)) {
            ifs.clear();
            buffer[i] = indexOfCharacter(ifs);
        }
        
        else {
            ifs.clear();
            ifs.seekg(currentPos);
            buffer[i] = ifs.get();
        }
    }     
}
void readTableFromFile(std::ifstream& ifs, Table& t, size_t currentCol, size_t currentRow);
void readBetweenTags(std::ifstream& ifs, Table& t, const TypeOfTags& tag, size_t currentCol, size_t currentRow){
    char buffer[MAX_SIZE_OF_FIELD];
    ifs.getline(buffer, MAX_SIZE_OF_FIELD, '>');
    if (tag == TypeOfTags::tr) {
        currentRow++;
        readTableFromFile(ifs, t, currentCol, currentRow);
    }
    else if (tag == TypeOfTags::th) {
        currentCol++;
        readTextBetweenTags(ifs, t, tag, currentCol, currentRow);
    }
    else if (tag == TypeOfTags::td) {
        currentCol++;
        readTextBetweenTags(ifs, t, tag, currentCol, currentRow);
    }
}

void readTableFromFile(std::ifstream& ifs, Table& t, size_t currentCol, size_t currentRow){
    if (ifs.eof()) {
        return;
    }
    size_t currentPos = ifs.tellg();
    TypeOfTags tag;
    bool isClosingTag = false;
    defTag(ifs, tag, isClosingTag);
    if (tag == TypeOfTags::table) {
        return;
    }
    if (!isClosingTag && tag != TypeOfTags::is_not_tag) {
          readBetweenTags(ifs, t, tag, currentCol, currentRow);
    }
    else {
        ifs.seekg(currentPos + 1);
    }
    readTableFromFile(ifs, t, currentCol, currentRow);

}

void readFile(FileHandler& fh, Table& t) {
    std::ifstream ifs(fh.getFile());
    if (!ifs.is_open()) {
        fh.setError(ErrorList::the_file_is_not_open);
        return;
    }
    if (ifs.eof()) {
        fh.setError(ErrorList::empty_file);
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
            fh.setError(ErrorList::no_error);
            size_t currentCol = 0;
            size_t currentRow = 0;
            readTableFromFile(ifs, t, currentCol, currentRow);
            fh.setTable(t);
        }
        else {
            fh.setError(ErrorList::there_is_no_table_int_the_file);
        }
    }

    ifs.close();
}
int main()
{
    FileHandler f;
    Table t;
    f.setFilename("HTML.txt");
    readFile(f, t);
    t.print();
}
