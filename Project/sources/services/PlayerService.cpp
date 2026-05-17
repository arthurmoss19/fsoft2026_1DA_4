//
// Created by tiago on 17/05/2026.
//

#include "../../headers/services/PlayerService.h"
#include "../../headers/mappers/PlayerMapper.h"
#include "../../headers/exceptions/NoDataException.h"
#include "../../headers/exceptions/DuplicatedDataException.h"
#include "../../headers/exceptions/InvalidDataException.h"

PlayerService::PlayerService(PlayerContainer* container) : container(container) {}

PlayerDTO PlayerService::toDTO(const Player& player) const {
    PlayerDTO dto;
    PlayerMapper::model2DTO(player, dto);
    return dto;
}

void PlayerService::registerPlayer(const PlayerLoginDTO& dto) {
    if (dto.nickname.empty()) {
        throw InvalidDataException("Nickname cannot be empty.");
    }
    if (playerExists(dto.nickname)) {
        throw DuplicatedDataException("Player '" + dto.nickname + "' already exists.");
    }
    container->add(dto.nickname);
}

bool PlayerService::playerExists(const string& nickname) const {
    try {
        container->get(nickname);
        return true;
    } catch (const NoDataException&) {
        return false;
    }
}

PlayerDTO PlayerService::getPlayer(const string& nickname) {
    Player* player = container->get(nickname);
    return toDTO(*player);
}

list<PlayerDTO> PlayerService::getRankingByWins() {
    list<Player*> all = container->getAll();

    all.sort([](const Player* a, const Player* b) {
        if (a->getWins() != b->getWins())
            return a->getWins() > b->getWins();
        return a->getAccuracyRate() > b->getAccuracyRate();
    });

    list<PlayerDTO> result;
    for (const Player* p : all) {
        result.push_back(toDTO(*p));
    }
    return result;
}

list<PlayerDTO> PlayerService::getRankingByAccuracy() {
    list<Player*> all = container->getAll();

    all.sort([](const Player* a, const Player* b) {
        if (a->getAccuracyRate() != b->getAccuracyRate())
            return a->getAccuracyRate() > b->getAccuracyRate();
        return a->getTotalShots() > b->getTotalShots();
    });

    list<PlayerDTO> result;
    for (const Player* p : all) {
        result.push_back(toDTO(*p));
    }
    return result;
}

void PlayerService::updateStats(const string& nickname, bool won, int shots, int hits) {
    if (shots < 0 || hits < 0 || hits > shots) {
        throw InvalidDataException("Invalid shot statistics provided.");
    }

    Player* player = container->get(nickname);

    for (int i = 0; i < shots; i++) {
        player->registerShot(i < hits);
    }
    player->registerGameOver(won);
}
