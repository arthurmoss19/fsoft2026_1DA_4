//
// Created by tiago on 17/05/2026.
//

#ifndef FSOFT_PLAYERSERVICE_H
#define FSOFT_PLAYERSERVICE_H

#include <list>
#include <string>
#include "../dto/PlayerDTO.h"
#include "../dto/PlayerLoginDTO.h"
#include "../model/PlayerContainer.h"

using namespace std;

class PlayerService {
private:
    PlayerContainer* container;

    PlayerDTO toDTO(const Player& player) const;

public:
    explicit PlayerService(PlayerContainer* container);
    ~PlayerService() = default;

    void registerPlayer(const PlayerLoginDTO& dto);
    bool playerExists(const string& nickname) const;
    PlayerDTO getPlayer(const string& nickname);
    list<PlayerDTO> getRankingByWins();
    list<PlayerDTO> getRankingByAccuracy();
    void updateStats(const string& nickname, bool won, int shots, int hits);
};

#endif //FSOFT_PLAYERSERVICE_H