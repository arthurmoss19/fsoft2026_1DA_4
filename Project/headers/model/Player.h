//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_PLAYER_H
#define PROJETOFSOFT_PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
private:
    string nickname;
    int wins;
    int losses;
    int totalShots;
    int hits;
    void setWins(int wins);
    void setLosses(int losses);

public:
    Player(const string& nickname);
    Player(const Player& obj);
    ~Player() = default;
    const string& getNickname() const;
    void setNickname(const string& nickname);
    int getWins() const;
    int getLosses() const;
    int getTotalShots() const;
    int getHits() const;
    float getAccuracyRate() const;
    void registerShot(bool hit);
    void registerGameOver(bool won);
    bool operator == (const Player& obj) const;
    bool operator == (const string& nick) const;
};

#endif