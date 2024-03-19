#include <iostream>
#include <fstream>
#include <iomanip>
#include "1_SI_1_6_1MI0600311_2.h"
#pragma warning (disable : 4996)

Time::Time() = default;
Time::Time(unsigned hours, unsigned mins, unsigned seconds) {
    setHours(hours);
    setMins(mins);
    setSeconds(seconds);
}
unsigned Time::getWholeInSec()const {
    return secondsFromMidnight;
}
unsigned Time::getHours() const {
    return secondsFromMidnight / SECONDS_IN_HOURS;
}
unsigned Time::getMins() const {
    return (secondsFromMidnight / 60) % 60;
}
unsigned Time::getSeconds() const {
    return secondsFromMidnight % 60;
}


bool Time::setHours(unsigned hours) {
    return validateAndSet(0, 23, hours, getHours(), SECONDS_IN_HOURS);
}
bool Time::setMins(unsigned mins) {
    return validateAndSet(0, 59, mins, getMins(), SECONDS_IN_MINUTE);
}
bool Time::setSeconds(unsigned seconds) {
    return validateAndSet(0, 59, seconds, getSeconds(), 1);
}


void Time::printTime(unsigned time) const {
    if (time < 10) {
        std::cout << 0 << time;
    }
    else {
        std::cout << time;
    }
}
void Time::printTime()const {
    printTime(getHours());
    std::cout << ":";
    printTime(getMins());
    std::cout << ":";
    printTime(getSeconds());
}

enum Genre: char{
    Rock = 1,
    Pop = 1 << 1,
    Hiphop = 1 << 2,
    ElMusic = 1 << 3,
    Djaz = 1 << 4
};
void printOneGenre(char ch) {
    switch (ch){
    case 1:std::cout << "Rock"; break;
    case 1 << 1:std::cout << "Pop"; break;
    case 1 << 2:std::cout << "Hiphop"; break;
    case 1 << 3:std::cout << "ElMusic"; break;
    case 1 << 4:std::cout << "Djaz"; break;
    }
}


Song::Song()=default;
Song::Song(const char* name, const Time& t, const char* genre, const char* file) {
    setName(name);
    setDuration(t);
    setGenre(genre);
    setContent(file);
}
bool Song::setName(const char* name) {
    if (name) {
        strcpy(this->name, name);
        return true;
    }
    return false;
}
void Song::setDuration(const Time& t) {
    duration = t;
}
bool Song::setGenre(const char* genre) {
    this->genre = 0;
    while (*genre) {
        switch (*genre) {
        case 'r':this->genre |= Genre::Rock; break;
        case 'p':this->genre |= Genre::Pop; break;
        case 'h':this->genre |= Genre::Hiphop; break;
        case 'e':this->genre |= Genre::ElMusic; break;
        case 'd':this->genre |= Genre::Djaz; break;
        default:this->genre = 0; return false;
        }
        genre++;
    }
    return true;
}
bool Song::setContent(const char* file) {
    std::ifstream ifs(file, std::ios::binary);
    if (!ifs.is_open()) {
        return false;
    }

    ifs.read(content, sizeof(char) * SIZE_OF_CONTENT);
    ifs.close();
    return true;
}


const char* Song::getName()const {
    return name;
}
Time Song::getDurationInSeconds()const {
    return duration;
}
char Song::getGenre()const {
    return genre;
}
const char* Song::getContent()const {
    return content;
}


void Song::changeEveryKBit(int k) {
    for (int i = strlen(content) - 1; i >= 0; i--) {
        content[i] |= (1 << (k - 1));
    }
}
void Song::printGenre()const {
    int currentCountOfGenres = COUNT_OF_GENRES;
    char currentGenres = genre;
    while (currentGenres != 0 && currentCountOfGenres > 0) {
        char currentOneGenre = 1 << (currentCountOfGenres - 1);
        if ((currentGenres & currentOneGenre) != 0) {
            printOneGenre(currentOneGenre);
            currentGenres %= currentOneGenre;
            if (currentGenres != 0) {
                std::cout << "&";
            }
        }
        else {
            currentGenres %= currentOneGenre;
        }
        currentCountOfGenres--;
    }
}
void Song::printSong() const {
    std::cout << name << ",";
    duration.printTime();
    std::cout << ",";
    printGenre();
    std::cout << std::endl;
}

void printContentOfSong(const char* str) {
    std::cout << str;
}

void mixTwoSongs(Song& s1, const Song& s2) {
    char newContent[SIZE_OF_CONTENT] = "";
    int s1len = strlen(s1.getContent());
    int s2len = strlen(s2.getContent());
    int min = (s1len < s2len ? s1len : s2len);
    if (min == s1len) {
        for (int i = 0; i < s2len; i++) {
            newContent[i] = s2.getContent()[i];
            if (s1len + i >= s2len) {
                newContent[i] ^= s1.getContent()[i];
            }
        }
    }
    else {
        for (int i = 0; i < s1len; i++) {
            newContent[i] = s1.getContent()[i];
            if (s1len + i >= s1len) {
                newContent[i] ^= s2.getContent()[i];
            }
        }
    }
    s1.setContent(newContent);
}

void save(const Song& s, const char* filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs.is_open()) {
        return;
    }
    ofs.write(filename, SIZE_OF_CONTENT);
    ofs.close();
}


Playlist::Playlist() = default;
Playlist::Playlist(const Song* songsArr, size_t countOfSongs) {
    setSongsArr(songsArr, countOfSongs);
}
bool Playlist::setSongsArr(const Song* songsArr, size_t countOfSongs) {
    if (countOfSongs <= MAX_SONGS_IN_PLAYLIST) {
        for (int i = 0; i < countOfSongs; i++) {
            this->songsArr[i] = songsArr[i];
        }
        this->countOfSongsInThePlaylist = countOfSongs;
        return true;
    }
    return false;
}
size_t Playlist::getCountOfSongs()const {
    return countOfSongsInThePlaylist;
}
Song Playlist::findSong(const char* name) const {
    Song song;
    song.setName(name);
    for (int i = 0; i < countOfSongsInThePlaylist; i++) {
        if (strcmp(songsArr[i].getName(), name) == 0) {
            song = songsArr[i];
            break;
        }
    }
    song.setName("Unknown");
    return song;
}
Song* Playlist::findByGenre(char genre) const {
    Song songsByGenre[MAX_SONGS_IN_PLAYLIST];
    int currentIndex = 0;
    for (int i = 0; i < countOfSongsInThePlaylist; i++) {
        if ((songsArr[i].getGenre() & genre) != 0) {
            songsByGenre[currentIndex] = songsArr[i];
            currentIndex++;
        }
    }
    return songsByGenre;
}
void Playlist::add(const Song& song) {
    if (countOfSongsInThePlaylist >= MAX_SONGS_IN_PLAYLIST) {
        return;
    }
    if (strcmp(findSong(song.getName()).getName(), song.getName()) == 0) {
        return;
    }
    songsArr[countOfSongsInThePlaylist] = song;
    countOfSongsInThePlaylist++;
}
void Playlist::printPlaylist()const {
    for (int i = 0; i < countOfSongsInThePlaylist; i++) {
        songsArr[i].printSong();
    }
}
void Playlist::sortByDuration() {
    for (int i = 0; i < countOfSongsInThePlaylist - 1; i++) {
        int currElWithMinDuration = i;
        for (int j = i + 1; j < countOfSongsInThePlaylist; j++) {
            if (songsArr[j].getDurationInSeconds().getWholeInSec() < songsArr[currElWithMinDuration].getDurationInSeconds().getWholeInSec()) {
                currElWithMinDuration = j;
            }
        }
        std::swap(songsArr[i], songsArr[currElWithMinDuration]);
    }
}
void Playlist::sortByName() {
    for (int i = 0; i < countOfSongsInThePlaylist - 1; i++) {
        int currElWithMinName = i;
        for (int j = i + 1; j < countOfSongsInThePlaylist; j++) {
            if (strcmp(songsArr[j].getName(),songsArr[currElWithMinName].getName())<0) {
                currElWithMinName = j;
            }
        }
        std::swap(songsArr[i], songsArr[currElWithMinName]);
    }
}



int main()
{
    Time t1(0, 2, 12);
    Time t2(0, 3, 41);
    Time t3(0, 3, 10);
    
    Song s1("PREADTEL",t1, "er", "rithem.txt");
    Song s2("ZABRAVEN", t2, "prhr", "rithem1.txt");
    Song s3("KAMUNITE PADAT", t3, "ph", "rithem.txt");
    Song s4("CENTROFUGAa", t3, "ph", "rithem.txt");
    Song s5("SHOPSKATA SALATA", t3, "ph", "rithem.txt");
    Song s6("FILM ZA NAS", t3, "ph", "rithem.txt");
    Song s7("TVOITE OCHI", t3, "ph", "rithem.txt");
    Song s8("PEY, SARTSE", t3, "ph", "rithem.txt");
    Song s9("BEZ CHUVSTVA", t3, "ph", "rithem.txt");
    Song s10("100 ZHIVOTA", t3, "ph", "rithem.txt");
    Song s11("ZA POSLEDNO", t3, "ph", "rithem.txt");
    Song s12("ROKLYATA TI PADA", t3, "ph", "rithem.txt");
    Song s13("HAVANA TROPICANA", t3, "ph", "rithem.txt");
    Song s14("TOI", t3, "ph", "rithem.txt");
    Song s15("VARTELEZHKATA", t3, "ph", "rithem.txt");
    Song s16("STARA KARAVANA ", t3, "ph", "rithem.txt");
    Song s17("FENOMENALEN ", t3, "ph", "rithem.txt");
    Song s18("DA TE BYAH ZARYAZALA ", t3, "ph", "rithem.txt");
    Song s19("ZNAM DIAGNOZATA", t3, "ph", "rithem.txt");
    Song s20("YAKA E ZHENA TI ", t3, "ph", "rithem.txt");
    Song s21("NEKA ZABRAVYA", t3, "ph", "rithem.txt");
    Song s22("USTNITE TI MRASNI", t3, "ph", "rithem.txt");
    Song s23("ZOOPARK", t3, "ph", "rithem.txt");
    Song s24("RAYSKI GAZ", t3, "ph", "rithem.txt");
    Song s25("KUPIH TI SARTSE", t3, "ph", "rithem.txt");
    Song s26("KRASIVI LAJI", t3, "ph", "rithem.txt");
    Song s27("TURBULENCE", t3, "ph", "rithem.txt");
    Song s28("OT UTRE SHTE E DRUGO", t3, "ph", "rithem.txt");
    Song s29("NE SE IZTRIVASH", t3, "ph", "rithem.txt");
    Song s[30] = { s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16,s17,s18,s19,s20,s21,s22,s23,s24,s25,s26,s27,s28,s29 };
    Playlist p(s, 29);
    Song s30("LUBOV LI E", t3, "ph", "rithem.txt");
    p.add(s30);
    p.sortByName();
    p.printPlaylist();
    printContentOfSong(s1.getContent());
    printContentOfSong(s2.getContent());
    mixTwoSongs(s1, s2);
  

}
