//
// Created by pedro on 16/05/2026.
//

#ifndef PROJETOFSOFT_PLAYERCONTAINER_H
#define PROJETOFSOFT_PLAYERCONTAINER_H

#include <list>
#include "Player.h"

class PlayerContainer {
private:
    list<Player*> players;
    Player* search(const string& nickname);

public:
    list<Player*>& getAll();
    Player* get(const string& nickname);
    void add(const string& nickname);
    Player* remove(const string& nickname);
    Player* update(const string& oldNickname, const string& newNickname);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

#endif // PROJETOFSOFT_PLAYERCONTAINER_H