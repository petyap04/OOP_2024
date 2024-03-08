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
    FLYING, 
    UNKNOWN
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

Type readType(unsigned int number) {
    switch (number) {
    case 0:return Type::NORMAL;
    case 1:return Type::FIRE;
    case 2:return Type::WATER;
    case 3:return Type::GRASS;
    case 4:return Type::ELECTRIC;
    case 5:return Type::GHOST;
    case 6:return Type::FLYING;
    default:return Type::UNKNOWN;
    }
}

Pokemon initialize() {
    Pokemon p;
    unsigned int type;
    std::cin >> type;
    Type t = readType(type);

    assert(t != Type::UNKNOWN);

    std::cin >> p.strength >> p.name;
    p.t = t;
    return p;
}

Pokemon initializeFromFile(std::ifstream& ifs) {

    Pokemon p;
    unsigned int type;
    ifs.read((char*)&type, sizeof(type));
    Type t = readType(type);

    assert(t != Type::UNKNOWN);

    ifs.read((char*)&p.strength, sizeof(p.strength));
    ifs.read((char*)&p.name, sizeof(p.name));
    p.t = t;

    return p;
}

void writePokemonInFile(const Pokemon& p, const char* file, int index) {
    std::ofstream ofs(file, std::ios::binary | std::ios::ate);

    if (!ofs.is_open()) {
        return;
    }

    ofs.seekp(index, std::ios::beg);
    unsigned int type = (int)p.t;
    ofs.write((const char*)&type, sizeof(type));
    ofs.write((const char*)&p.strength, sizeof(p.strength));
    ofs.write((const char*)&p.name, sizeof(p.name));

    ofs.close();
}

PokemonHandler newPokemonHandler(const char* filename) {
    PokemonHandler p;
    p.file = filename;
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

    int begOfPokemon = (i / sizeof(Pokemon)) * sizeof(Pokemon);
    ifs.seekg(begOfPokemon, std::ios::beg);
    p = initializeFromFile(ifs);

    ifs.close();
    return p;

}

void swap(const PokemonHandler& ph, int i, int j) {

    int sizef = size(ph);
    assert(sizef < i || i < 0 || sizef < j || j < 0);

    Pokemon p1 = at(ph, i);
    Pokemon p2 = at(ph, j);
    assert(p1.err != ErrorList::the_file_can_not_be_open && p2.err != ErrorList::the_file_can_not_be_open);

    int begOfPokemon1 = (i / sizeof(Pokemon)) * sizeof(Pokemon);
    int begOfPokemon2 = (j / sizeof(Pokemon)) * sizeof(Pokemon);

    writePokemonInFile(p1, ph.file, begOfPokemon2);
    writePokemonInFile(p2, ph.file, begOfPokemon1);

}

void insert(const PokemonHandler& ph, const Pokemon& pokemon) {
    int index = size(ph);
    writePokemonInFile(pokemon, ph.file, index);
}

void textify(const PokemonHandler& ph, const char* filename) {

}

int main()
{
    /*Pokemon p = initializeFromFile("readFile.txt");
    writePokemonInFile(p, "writeFile.txt");*/

}
