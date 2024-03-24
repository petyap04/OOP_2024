#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
constexpr int MAX_SIZE = 64;
constexpr int SIZE_OF_CONTENT = 256;
constexpr int MAX_SONGS_IN_PLAYLIST = 30;
constexpr int COUNT_OF_GENRES = 5;
constexpr int SIZE_OF_BIT = 8;

constexpr unsigned SECONDS_IN_HOURS = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;


class Time {
    unsigned secondsFromMidnight;
    bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier)
    {

        if (newValue >= lowerBound && newValue <= upperBound)
        {
            (secondsFromMidnight -= (oldVlaue * multiplier)) += (newValue * multiplier);
            return true;
        }
        else
            return false;
    }
public:
    Time();
    Time(unsigned hours, unsigned mins, unsigned seconds);
    unsigned getWholeInSec()const;
    unsigned getHours() const;
    unsigned getMins() const;
    unsigned getSeconds() const;
    bool setHours(unsigned hours);
    bool setMins(unsigned mins);
    bool setSeconds(unsigned seconds);
    void printTime(unsigned time) const;
    void printTime()const;
};


class Song {
    char name[MAX_SIZE] = "";
    Time duration;
    char genre;
    char content[SIZE_OF_CONTENT] = "";
public:
    Song();
    Song(const char* name, const Time& t, const char* genre, const char* file);
    bool setName(const char* name);
    void setDuration(const Time& t);
    bool setGenre(const char* genre);
    bool setContentFromFile(const char* file);
    bool setContentAfterMix(char* newContent);

    const char* getName()const;
    const Time& getDurationInSeconds()const;
    char getGenre()const;
    const char* getContent()const;

    void changeEveryKBit(int k);
    void printGenre()const;
    void printSong() const;
};

class Playlist {
    Song songsArr[MAX_SONGS_IN_PLAYLIST];
    size_t countOfSongsInThePlaylist = 0;
public:
    Playlist();
    Playlist(const Song* songsArr, size_t countOfSongs);
    bool setSongsArr(const Song* songsArr, size_t countOfSongs);
    size_t getCountOfSongs()const;
    Song findSong(const char* name) const;
    Song* findByGenre(char genre) const;
    void add(const Song& song);
    void printPlaylist()const;
    void sortByDuration();
    void sortByName();
}; 
