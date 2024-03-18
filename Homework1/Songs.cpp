#include <iostream>
#include <fstream>


constexpr int MAX_SIZE = 64;
constexpr int SIZE_OF_CONTENT = 256;
constexpr int MAX_SONGS_IN_PLAYLIST = 30;


enum Genre: char{
    Rock = 1,
    Pop = 1 << 1,
    Hiphop = 1 << 2,
    ElMusic = 1 << 3,
    Djaz = 1 << 4
};

class Song {
    char name[MAX_SIZE] = "";
    unsigned int durationInSeconds = 0;
    char genre;
    char content[SIZE_OF_CONTENT] = "";
public:
    Song(){}
    Song(const char* name, unsigned int hours, unsigned int minutes, unsigned int seconds, const char* genre, const char* file) {
        setName(name);
        setDuration(hours, minutes, seconds);
        setGenre(genre);
        setContent(file);
    }
    bool setName(const char* name) {
        if (name) {
            strcpy(this->name, name);
            return true;
        }
        return false;
    }
    bool setDuration(unsigned int hours, unsigned int minutes, unsigned int seconds) {
        if (hours < 24 && minutes < 59 && seconds < 59) {
            durationInSeconds = hours * 3600 + minutes * 60 + seconds;
            return true;
        }
        return false;
    }
    bool setGenre(const char* genre) {
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
    bool setContent(const char* file) {
        std::ifstream ifs(file, std::ios::binary);
        if (!ifs.is_open()) {
            return false;
        }

        ifs.read(content, sizeof(char) * SIZE_OF_CONTENT);
        ifs.close();
        return true;
    }


    const char* getName()const {
        return name;
    }
    unsigned int getDurationInSeconds()const {
        return durationInSeconds;
    }
    char getGenre()const {
        return genre;
    }
    const char* getContent()const {
        return content;
    }
    void changeEveryKBit(int k) {
        for (int i = strlen(content) - 1; i >= 0; i--) {
            content[i] |= (1 << (k - 1));
        }
    }

};
class Playlist {
    Song songsArr[MAX_SONGS_IN_PLAYLIST];
    size_t countOfSongsInThePlaylist = 0;
public:
    Playlist() {}
    Playlist(const Song* songsArr, size_t countOfSongs) {
        setSongsArr(songsArr, countOfSongs);
    }
    bool setSongsArr(const Song* songsArr, size_t countOfSongs) {
        if (countOfSongs <= MAX_SONGS_IN_PLAYLIST) {
            for (int i = 0; i < countOfSongs; i++) {
                this->songsArr[i] = songsArr[i];
            }
            this->countOfSongsInThePlaylist = countOfSongs;
            return true;
        }
        return false;
    }
    size_t getCountOfSongs()const {
        return countOfSongsInThePlaylist;
    }
    Song findSong(const char* name) {
        Song song;
        song.setName(name);
        for (int i = 0; i < countOfSongsInThePlaylist; i++) {
            if (strcmp(songsArr[i].getName(), name) == 0) {
                song = songsArr[i];
                break;
            }
        }
        return song;
    }
    Song* findByGenre(char genre) {
        Song songsByGenre[MAX_SONGS_IN_PLAYLIST];
        int currentIndex = 0;
        for (int i = 0; i < countOfSongsInThePlaylist; i++) {
            if ((songsArr[i].getGenre() & genre) != 0){
                songsByGenre[currentIndex] = songsArr[i];
                currentIndex++;
            }
        }
        return songsByGenre;
    }

    void add(const Song& song) {
        if (countOfSongsInThePlaylist >= MAX_SONGS_IN_PLAYLIST) {
            return;
        }
        if (strcmp(findSong(song.getName()).getName(), song.getName()) == 0) {
            return;
        }
        songsArr[countOfSongsInThePlaylist] = song;
        countOfSongsInThePlaylist++;
    }
};
void mixTwoSongs(Song& s1, const Song& s2) {
    char newContent[SIZE_OF_CONTENT] = "";
    
}
int main()
{

    Song s1;
    Song s2;

}
