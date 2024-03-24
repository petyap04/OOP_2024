#include <iostream>
#include <fstream>
#include <assert.h>
#include "Table.h"
#pragma warning(disable:4996)

enum class ErrorList {
    the_file_is_not_open,
    empty_file,
    there_is_no_table_int_the_file,
    no_error
};

enum class TypeOfTags {
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
Table::Table(size_t countOfColls, size_t countOfRows, const Row* rows) {
    setCountOfColls(countOfColls);
    setCountOfRows(countOfRows);
}

void Table::swapTwoRows(int index1, int index2) {
    std::swap(rows[index1], rows[index2]);
}

void Table::writeRowInTable(const Row& rowToAdd, int indexOfRow, size_t size) {
    for (int i = 1; i < size; i++) {
        strcpy(rows[indexOfRow].row[i], rowToAdd.row[i - 1]);
    }
}

void Table::add(size_t rowNumber, const Row& rowToAdd) {
    if (countOfRows > MAX_ROW && rowNumber > MAX_ROW) {
        return;
    }

    writeRowInTable(rowToAdd, countOfRows + 1, countOfColls);
    setCountOfRows(countOfRows + 1);
    size_t currentIndex = countOfRows;
    while (currentIndex >= rowNumber) {
        std::swap(rows[currentIndex - 1], rows[currentIndex]);
        currentIndex--;
    }
    print();
    
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
        for (int j = 1; j <= countOfColls; j++) {
            int currentIndex = strlen(rows[i].row[j]);
            if (i == 1) {
                std::cout << "|" << '*' << rows[i].row[j];
                while ((char)currentIndex < rows[0].row[j][0]) {
                    std::cout << " ";
                    currentIndex++;
                }
                std::cout << "*" << "|";
            }
            else {
                std::cout << "|" << " " << rows[i].row[j];
                while ((char)currentIndex < rows[0].row[j][0]) {
                    std::cout << " ";
                    currentIndex++;
                }
                std::cout << " " << "|";
            }
        }
        std::cout << std::endl;
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
const Field& Table::getFieldInRow(int indexOfRow, int indexOfColl) const {
    return rows[indexOfRow].row[indexOfColl];
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
void Table::setFieldInRow(char ch, size_t indexOfRow, size_t indexOfColl) {
    rows[indexOfRow].row[indexOfColl][0] = ch;
}
bool Table::setFieldInRow(const char* str, size_t indexOfRow, size_t indexOfColl) {
    if (!str) {
        return false;
    }
    strcpy(rows[indexOfRow].row[indexOfColl], str);
    if (strcmp(rows[0].row[indexOfColl],"") == 0 || (char)strlen(str) > rows[0].row[indexOfColl][0]) {
        setFieldInRow(strlen(str), 0, indexOfColl);
    }
    return true;
}


class FileHandler {
    const char* filename="";
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

void defTag(std::ifstream& ifs, TypeOfTags& tag, bool& isClosingTag) {
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
    bool isTag = false;

    for (int i = currentIndOfBuf; i < MAX_SIZE_OF_FIELD; i++) {
        TypeOfTags newtag;
        defTag(ifs, newtag, isTag);
        if (newtag != TypeOfTags::is_not_tag) {
            buffer[i] = '\0';
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
void readTableFromFile(std::ifstream& ifs, Table& t, size_t currentCol, size_t currentRow, bool& hasFoundClosingTableTag);
void readBetweenTags(std::ifstream& ifs, Table& t, const TypeOfTags& tag, size_t& currentCol, size_t& currentRow, bool& hasFoundClosingTableTag) {
    char buffer[MAX_SIZE_OF_FIELD];
    ifs.getline(buffer, MAX_SIZE_OF_FIELD, '>');
    if (tag == TypeOfTags::tr) {
        currentCol = 0;
        currentRow++;
        readTableFromFile(ifs, t, currentCol, currentRow, hasFoundClosingTableTag);
    }
    else {
        currentCol++;
        if (currentCol > t.getCountOfColls()) {
            t.setCountOfColls(currentCol);
        }
        readTextBetweenTags(ifs, t, tag, currentCol, currentRow);
    }
}

void readTableFromFile(std::ifstream& ifs, Table& t, size_t currentCol, size_t currentRow, bool& hasFoundClosingTableTag) {
    if (ifs.eof()) {
        return;
    }
    size_t currentPos = ifs.tellg();
    TypeOfTags tag;
    bool isClosingTag = false;
    defTag(ifs, tag, isClosingTag);
    if (tag == TypeOfTags::table) {
        hasFoundClosingTableTag = true;
        t.setCountOfRows(currentRow);
        return;
    }
    if (!isClosingTag && tag != TypeOfTags::is_not_tag) {
        readBetweenTags(ifs, t, tag, currentCol, currentRow, hasFoundClosingTableTag);
    }
    else {
        ifs.seekg(currentPos + 1);
    }
    if (hasFoundClosingTableTag == false) {
        readTableFromFile(ifs, t, currentCol, currentRow, hasFoundClosingTableTag);
    }
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
            bool hasFoundClosingTableTag = false;
            readTableFromFile(ifs, t, currentCol, currentRow, hasFoundClosingTableTag);
            fh.setTable(t);
        }
        else {
            fh.setError(ErrorList::there_is_no_table_int_the_file);
        }
    }
    ifs.close();
}

void safeToFile(FileHandler& fh, const Table& t) {
    std::ofstream ofs(fh.getFile());
    if (!ofs.is_open()) {
        return;
    }
    ofs << "<table>" << std::endl;
    for (int i = 1; i <= t.getCountOfRows(); i++) {
        ofs << "<tr>" << std::endl;
        for (int j = 1; j <= t.getCountOfColls(); j++) {
            if (i == 1) {
                ofs << "<th>" << t.getFieldInRow(i, j) << "</th>" << std::endl;
            }
            else {
                ofs << "<td>" << t.getFieldInRow(i, j) << "</td>" << std::endl;
            }
        }
        ofs << "</tr>" << std::endl;
    }
    ofs << "</table>" << std::endl;

    ofs.close();
}

int main()
{
    FileHandler f;
    Table t;
    f.setFilename("HTML.txt");
    readFile(f, t);
    t.print();
    Row toAdd = { "Petur Ivanov", "34", "12345" };
    t.add(3, toAdd);
    safeToFile(f, t);
}
