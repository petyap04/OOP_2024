#include <iostream>
#include <assert.h>
#include <fstream>

enum class ErrorList {
    the_file_can_not_be_open,
    there_is_no_such_index
};

enum class Type {
    NORMAL, 
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    GHOST,
    FLYING
};

struct Pokemon {
    unsigned int strength;
    Type t;
    char name[50]; 
    ErrorList err;
};

struct PokemonHandler {
    const char* file;
};

Pokemon initialize() {
    Pokemon p;
    unsigned int type;
    std::cin >> type >> p.strength >> p.name;
    p.t = (Type)type;
    return p;
}

Pokemon initializeFromBinaryFile(std::ifstream& ifs) {

    Pokemon p;
    unsigned int type;
    ifs.read((char*)&p, sizeof(p));
   
    return p;
}

Pokemon initializeFromTextFile(std::ifstream& ifs) {
    Pokemon p;
    unsigned int type;
    ifs >> type>> p.strength >> p.name;
    p.t  = (Type)type;
    return p;
}

void writePokemonInBinatyFile(const Pokemon& p, const char* file, int index) {
    std::ofstream ofs(file, std::ios::binary | std::ios::ate);

    if (!ofs.is_open()) {
        return;
    }

    ofs.seekp(index, std::ios::beg);
    ofs.write((const char*)&p, sizeof(p));

    ofs.close();
}

void writePokemonInTextFile(const Pokemon& p, std::ofstream& ofs) {
    ofs << p.strength << (int)p.t << p.name;
}

PokemonHandler newPokemonHandler(const char* filename) {
    PokemonHandler p;
    strcpy(filename, p.file);
    return p;
}

int size(const PokemonHandler& ph) {
    std::ifstream ifs(ph.file, std::ios::binary);

    if (!ifs.is_open()) {
        return -1;
    }

    ifs.seekg(0, std::ios::end);
    int index = ifs.tellg();
    ifs.close();
    return index / sizeof(Pokemon);
}

Pokemon at(const PokemonHandler& ph, int i) {
  
    Pokemon p;
    if (size(ph) < i || i < 0) {
        p.err = ErrorList::there_is_no_such_index;
    }
    std::ifstream ifs(ph.file, std::ios::binary);

    if (!ifs.is_open()) {
        p.err = ErrorList::the_file_can_not_be_open;
        return p;
    }

    ifs.seekg(i * sizeof(Pokemon), std::ios::beg);
    p = initializeFromBinaryFile(ifs);

    ifs.close();
    return p;

}

void swap(const PokemonHandler& ph, int i, int j) {

    int sizef = size(ph);
    assert(sizef < i || i < 0 || sizef < j || j < 0);

    Pokemon p1 = at(ph, i);
    Pokemon p2 = at(ph, j);
    assert(p1.err != ErrorList::the_file_can_not_be_open && p2.err != ErrorList::the_file_can_not_be_open);

    writePokemonInBinatyFile(p1, ph.file, j * sizeof(Pokemon));
    writePokemonInBinatyFile(p2, ph.file, i * sizeof(Pokemon));

}

void insert(const PokemonHandler& ph, const Pokemon& pokemon) {
    int index = size(ph);
    writePokemonInBinatyFile(pokemon, ph.file, index);

    Pokemon p1 = at(ph, index);

    while (p1.strength > pokemon.strength) {
        swap(ph, index, index + 1);
        p1 = at(ph, --index);
    }
}

void textify(const PokemonHandler& ph, const char* filename) {
    std::ifstream ifs(ph.file, std::ios::binary);
    std::ofstream ofs(filename, std::ios::app);

    if (!ifs.is_open() || !ofs.is_open()) {
        return;
    }

    while (!ifs.eof()) {
        Pokemon p = initializeFromBinaryFile(ifs);
        writePokemonInTextFile(p, ofs);
    }
    ifs.close();
    ofs.close();
}

void untextify(const PokemonHandler& ph, const char* filename) {
    std::ifstream ifs(filename, std::ios::app);

    if (!ifs.is_open()) {
        return;
    }

    int index = 0;
    while (!ifs.eof()) {
        Pokemon p = initializeFromTextFile(ifs);
        writePokemonInBinatyFile(p, ph.file, index);
        index += sizeof(Pokemon);
    }

    ifs.close();
}

int main()
{
    
}
