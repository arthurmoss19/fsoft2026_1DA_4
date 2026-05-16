//
// Created by pedro on 16/05/2026.
//

#include "Player.h"
#include "InvalidDataException.h"

void Player::setWins(int wins) {
    if (wins >= 0) {
        this->wins = wins;
    }
    else {
        string msg = "Player" + nickname;
        throw InvalidDataException(msg);
    }
}

void Player::setLosses(int losses) {
    if (losses >= 0) {
        this->losses = losses;
    }
    else {
        string msg = "Player" + nickname;
        throw InvalidDataException(msg);
    }
}

bool Player::isNicknameValid(const string& nick) {
    if (nick.length() < 3 || nick.length() > 24) {
        return false;
    }
    return true;
}

void Player::setNickname(const string& nickname) {
    if (isNicknameValid(nickname)) {
        this->nickname = nickname;
    }
    else {
        string msg = "Player" + nickname;
        throw InvalidDataException(msg);
    }
}

Player::Player(const string& nickname) {
    setNickname(nickname);
    setWins(0);
    setLosses(0);
    this->totalShots = 0;
    this->hits = 0;
}

Player::Player(const Player& obj) {
    setNickname(obj.nickname);
    setWins(obj.wins);
    setLosses(obj.losses);
    this->totalShots = obj.totalShots;
    this->hits = obj.hits;
}

const string& Player::getNickname() const {
    return nickname;
}

int Player::getWins() const {
    return wins;
}

int Player::getLosses() const {
    return losses;
}

float Player::getAccuracyRate() const {
    if (totalShots == 0) {
        return 0.0f;
    }
    return (static_cast<float>(hits) / totalShots) * 100.0f;
}

void Player::registerShot(bool hit) {
    totalShots++;
    if (hit) {
        hits++;
    }
}

void Player::registerGameOver(bool won) {
    if (won) {
        wins++;
    } else {
        losses++;
    }
}

bool Player::operator == (const Player& obj) const {
    if (this->nickname == obj.nickname) {
        return true;
    }
    return false;
}

bool Player::operator == (const string& nick) const {
    if (this->nickname == nick) {
        return true;
    }
    return false;
}

int Player::getTotalShots() const {
    return totalShots;
}

int Player::getHits() const {
    return hits;
}

