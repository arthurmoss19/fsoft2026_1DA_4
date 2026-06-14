//
// Created by pedro on 16/05/2026.
//

#include "DuplicatedDataException.h"
#include "NoDataException.h"
#include "PlayerContainer.h"
#include <fstream>
#include <sstream>

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

void PlayerContainer::saveToFile(const string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        cout << "ERRO: nao foi possivel abrir o ficheiro " << filename << endl;
        return;
    }

    for (list<Player*>::iterator it = this->players.begin(); it != this->players.end(); ++it) {
        if (*it == nullptr) continue;
        file << (*it)->getNickname() << ","
             << (*it)->getWins() << ","
             << (*it)->getLosses() << ","
             << (*it)->getTotalShots() << ","
             << (*it)->getHits() << "\n";
    }
    file.close();
}

void PlayerContainer::loadFromFile(const string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    for (Player* p : players) {
        delete p;
    }
    players.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string nick, winsStr, lossesStr, totalShotsStr, hitsStr;

        if (std::getline(ss, nick, ',') &&
            std::getline(ss, winsStr, ',') &&
            std::getline(ss, lossesStr, ',') &&
            std::getline(ss, totalShotsStr, ',') &&
            std::getline(ss, hitsStr, ',')) {

            try {
                Player* newPlayer = new Player(nick);

                int wins = std::stoi(winsStr);
                int losses = std::stoi(lossesStr);
                int totalShots = std::stoi(totalShotsStr);
                int hits = std::stoi(hitsStr);

                for (int i = 0; i < wins; i++) newPlayer->registerGameOver(true);
                for (int i = 0; i < losses; i++) newPlayer->registerGameOver(false);

                int misses = totalShots - hits;
                for (int i = 0; i < hits; i++) newPlayer->registerShot(true);
                for (int i = 0; i < misses; i++) newPlayer->registerShot(false);

                this->players.push_back(newPlayer);
            } catch (...) {
                continue;
            }
            }
    }
    file.close();
}

void PlayerContainer::add(Player* player) {
    this->players.push_back(player);
}

void PlayerContainer::clear() {
    for (Player* p : this->players) {
        delete p;
    }
    this->players.clear();
}