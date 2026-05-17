//
// Created by pedro on 16/05/2026.
//

#include "DuplicatedDataException.h"
#include "NoDataException.h"
#include "PlayerContainer.h"

Player* PlayerContainer::search(const string& nickname) {
    for (list<Player*>::iterator it = this->players.begin(); it != this->players.end(); ++it) {
        if (**it == nickname) {
            return *it;
        }
    }
    return NULL;
}

list<Player*>& PlayerContainer::getAll() {
    return this->players;
}

Player* PlayerContainer::get(const string& nickname) {
    Player* player = search(nickname);
    if (player != NULL) {
        return player;
    } else {
        string msg = "Jogador " + nickname;
        throw NoDataException(msg);
    }
}

void PlayerContainer::add(const string& nickname) {
    Player* player = search(nickname);
    if (player == NULL) {
        Player* newPlayer = new Player(nickname);
        this->players.push_back(newPlayer);
    } else {
        string msg = "Jogador " + nickname;
        throw DuplicatedDataException(msg);
    }
}

Player* PlayerContainer::remove(const string& nickname) {
    Player* player = NULL;
    list<Player*>::iterator it = this->players.begin();
    for (; it != this->players.end(); ++it) {
        if (**it == nickname) {
            break;
        }
    }
    if (it != this->players.end()) {
        player = *it;
        this->players.erase(it);
        delete (*it);
        return player;
    } else {
        string msg = "Jogador " + nickname;
        throw NoDataException(msg);
    }
}

Player* PlayerContainer::update(const string& oldNickname, const string& newNickname) {
    Player* player1 = search(oldNickname);
    if (player1 != NULL) {
        Player* player2 = search(newNickname);
        if (player2 == NULL) {
            player1->setNickname(newNickname);
            return player1;
        } else {
            string msg = "Jogador " + newNickname;
            throw DuplicatedDataException(msg);
        }
    } else {
        string msg = "Jogador " + oldNickname;
        throw NoDataException(msg);
    }
}