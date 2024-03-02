#include<iostream>
#include<cstring>
#include<fstream>
#include<assert.h>

enum class ErrorInCatalog {
    catalog_not_open,
    read_from_empty_catalog,
    movie_not_in_catalog,
    no_error_occurred
};
struct SafeAnswer {
    int number;
    ErrorInCatalog error;
};
struct Movie {
    char name[128];
    unsigned int price;
};
unsigned int getSymbolCount(std::ifstream& ifs, char symbol) {
    int count = 0;
    while (true) {
        char ch = ifs.get();
        if (ifs.eof())break;
        if (ch == symbol)
            count++;
    }
    return count;
}
unsigned int getLinesCount(std::ifstream& ifs) {
    return getSymbolCount(ifs, '\n') + 1;
}
SafeAnswer getNumberOfMovies(const char* catalogName) {
    std::ifstream ifs(catalogName);
    if (!ifs.is_open())
        return { 0, ErrorInCatalog::catalog_not_open };
    int countOfMovies = 0;
    if (!*catalogName)
        return { countOfMovies, ErrorInCatalog::read_from_empty_catalog };
    countOfMovies = getLinesCount(ifs);
    return { countOfMovies, ErrorInCatalog::no_error_occurred };
}
SafeAnswer averagePrice(const char* catalogName) {
    std::ifstream ifs(catalogName);
    if (!ifs.is_open())
        return { 0, ErrorInCatalog::catalog_not_open };
    int averagePrice = 0;
    int countOfMovies = 0;
    if (!*catalogName)
        return { averagePrice , ErrorInCatalog::read_from_empty_catalog };
    while (!ifs.eof()) {
        int currentPrice = 0;
        char buffer[100];
        ifs.getline(buffer, 100, ' ');
        ifs >> currentPrice;
        averagePrice += currentPrice;
        ifs.ignore();
        countOfMovies++;
    }
    averagePrice /= countOfMovies;
    return{ averagePrice , ErrorInCatalog::no_error_occurred };
}
SafeAnswer getMoviePrice(const char* catalogName, const char* movieName) {
    std::ifstream ifs(catalogName);
    if (!ifs.is_open())
        return { 0, ErrorInCatalog::catalog_not_open };
    int price = 0;
    if (!*catalogName)
        return { price , ErrorInCatalog::read_from_empty_catalog };
    while (!ifs.eof()) {
        char buffer[100];
        ifs.getline(buffer, 100, ' ');
        if (std::strcmp(buffer, movieName) == 0) {
            ifs >> price;
            return { price , ErrorInCatalog::no_error_occurred };
        }
        ifs >> price;
        ifs.ignore();
    }
    price = 0;
    return{ price , ErrorInCatalog::movie_not_in_catalog };
}

Movie readMovie(std::ifstream& ifs) { //добавете аргумент - файлов поток за четене
    Movie m;
    ifs >> m.name >> m.price;
    return m;
}

Movie* saveMoviesInArray(std::ifstream& file, int numberOfMovies) {
    Movie* arr = new Movie[numberOfMovies];
    for (int i = 0; i < numberOfMovies; i++) {
        arr[i] = readMovie(file);
    }
    return arr;
}
void freeMoviesFromArray(Movie* arr) { // добавете нужните аргументи
    delete[]arr;
}
void sortMoviesInArray(Movie* arr, size_t size) { // добавете нужните аргументи
    for (size_t i = 0; i < size - 1; i++) {
        int indexOfMinEl = i;
        for (size_t j = 0; j < size; j++) {
            if (arr[indexOfMinEl].price > arr[j].price)
                indexOfMinEl = j;
        }
        if(i!=indexOfMinEl)
            std::swap(arr[i], arr[indexOfMinEl]);
   }
}
void printTextInFile(std::ofstream& ofs, const Movie* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ofs << arr->name << " " << arr->price << std::endl;
        arr++;
    }
}
ErrorInCatalog saveMoviesSorted(const char* catalogName, const char* catalogSortedName) {
    std::ifstream ifs(catalogName);
    if (!ifs.is_open())
        return ErrorInCatalog::catalog_not_open;
    if (!*catalogName)
        return ErrorInCatalog::read_from_empty_catalog;
    size_t countOfMovies = (getNumberOfMovies(catalogName)).number;
    Movie* arr = saveMoviesInArray(ifs, countOfMovies);
    sortMoviesInArray(arr, countOfMovies);
    std::ofstream ofs(catalogSortedName);
    if (!ofs.is_open())
        return ErrorInCatalog::catalog_not_open;
    printTextInFile(ofs, arr, countOfMovies);
    freeMoviesFromArray(arr);
    return ErrorInCatalog::no_error_occurred;
}

int main() {
    SafeAnswer safeNumberOfMovies = getNumberOfMovies("movieCatalog.txt");
    if (safeNumberOfMovies.error == ErrorInCatalog::no_error_occurred) {
        std::cout << "The number of movies is: " << safeNumberOfMovies.number << std::endl;
    }
    SafeAnswer safeAveragePrice = averagePrice("movieCatalog.txt");
    if (safeAveragePrice.error == ErrorInCatalog::no_error_occurred) {
        std::cout << "The average price is: " << safeAveragePrice.number << std::endl;
    }

    SafeAnswer safePrice = getMoviePrice("movieCatalog.txt", "Black-bullet");
    if (safePrice.error == ErrorInCatalog::no_error_occurred) {
        std::cout << "The price for the Black bullet movies is: " << safePrice.number << std::endl;
    }

    ErrorInCatalog errorSorting = saveMoviesSorted("movieCatalog.txt", "movieCatalogSorted.txt");
    if (errorSorting == ErrorInCatalog::no_error_occurred) {
        std::cout << "Look the content of the movieCatalogSorted.txt file" << std::endl;
    }
}
