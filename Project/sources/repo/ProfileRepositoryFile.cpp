//
// Created by arthu on 17/05/2026.
//

#include "ProfileRepositoryFile.h"
#include <fstream>
#include <sstream>
#include <iostream>

ProfileRepositoryFile* ProfileRepositoryFile::instance = nullptr;

ProfileRepositoryFile::ProfileRepositoryFile(): filename("players.txt") {
    load();
}

ProfileRepositoryFile* ProfileRepositoryFile::getInstance() {
    if (!instance) {
        instance = new ProfileRepositoryFile();
    }
    return instance;
}

PlayerContainer* ProfileRepositoryFile::getModel() {
    return &players;
}

void ProfileRepositoryFile::save() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "ERRO: nao foi possivel guardar dados em " << filename << std::endl;
        return;
    }
    for (Player* p : players.getAll()) {
        file << p->getNickname() << ","
             << p->getWins() << ","
             << p->getLosses() << ","
             << p->getTotalShots() << ","
             << p->getHits() << "\n";
    }
    file.close();
}

void ProfileRepositoryFile::load() {
    std::ifstream file(filename);
    if (!file.is_open()) return;

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

                players.add(newPlayer);
            } catch (...) { continue; }
        }
    }
    file.close();
}

bool ProfileRepositoryFile::exists(const std::string& nickname) {
    for (Player* p : players.getAll()) {
        if (p->getNickname() == nickname) {
            return true;
        }
    }
    return false;
}

void ProfileRepositoryFile::addProfile(const Player& player) {
    if (!exists(player.getNickname())) {
        players.add(new Player(player));
        save();
    }
}