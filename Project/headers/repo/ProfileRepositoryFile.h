//
// Created by arthu on 17/05/2026.
//

#ifndef PROJECT_PROFILEREPOSITORYFILE_H
#define PROJECT_PROFILEREPOSITORYFILE_H

#include "IProfileRepository.h"
#include <string>

class ProfileRepositoryFile : public IProfileRepository {
private:
    static ProfileRepositoryFile* instance;

    PlayerContainer players;
    std::string filename;

    ProfileRepositoryFile();

    void load();
    void save();

public:
    static ProfileRepositoryFile* getInstance();

    bool exists(const std::string& nickname) override;
    void addProfile(const Player& player) override;
};

#endif