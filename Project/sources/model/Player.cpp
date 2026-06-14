//
// Created by pedro on 16/05/2026.
//

#include "Player.h"
#include "InvalidDataException.h"
#include "Utils.h"

void Player::setNickname(const string& nickname) {
    string errorMsg;
    if (Utils::isNicknameValid(nickname, errorMsg)) {
        this->nickname = nickname;
    }
    else {
        string msg = "Jogador " + nickname;
        throw InvalidDataException(errorMsg);
    }
}

Player::Player(const string& nickname) {
    setNickname(nickname);
    this->wins = 0;
    this->losses = 0;
    this->totalShots = 0;
    this->hits = 0;
}

Player::Player(const Player& obj) {
    setNickname(obj.nickname);
    this->wins = obj.wins;
    this->losses = obj.losses;
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

