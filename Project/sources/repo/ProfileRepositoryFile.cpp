//
// Created by arthu on 17/05/2026.
//

#include "ProfileRepositoryFile.h"
#include <fstream>
#include <sstream>
#include <iostream>

ProfileRepositoryFile* ProfileRepositoryFile::instance = nullptr;

ProfileRepositoryFile::ProfileRepositoryFile(): filename("profiles.csv") {
    load();
}

ProfileRepositoryFile* ProfileRepositoryFile::getInstance() {
    if (!instance) {
        instance = new ProfileRepositoryFile();
    }
    return instance;
}

void ProfileRepositoryFile::load() {
    std::ifstream file(filename);

    if (!file.is_open()) return;

    std::string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        Player p(line);
        players.add(p);
    }

    file.close();
}

void ProfileRepositoryFile::save() {
    std::ofstream file(filename);

    if (!file.is_open()) {
        cerr << "ERRO! nao foi possivel guardar dados em " << filename << endl;
        return;
    }

    for (const Player& p : players.getAll()) {
        file << p.getNickname() << "\n";
    }

    file.close();
}

bool ProfileRepositoryFile::exists(const std::string& nickname) {
    for (const Player& p : players.getAll()) {
        if (p.getNickname() == nickname) {
            return true;
        }
    }
    return false;
}

void ProfileRepositoryFile::addProfile(const Player& player) {
    if (!exists(player.getNickname())) {
        players.add(player);
        save();
    }
}