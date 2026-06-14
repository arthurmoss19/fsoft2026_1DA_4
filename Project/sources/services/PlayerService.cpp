//
// Created by tiago on 17/05/2026.
//

#include "PlayerService.h"
#include "PlayerMapper.h"
#include "NoDataException.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"

PlayerService::PlayerService(PlayerContainer* container) : container(container) {}

PlayerDTO PlayerService::toDTO(const Player& player) const {
    PlayerDTO dto;
    PlayerMapper::model2DTO(player, dto);
    return dto;
}

void PlayerService::registerPlayer(const PlayerLoginDTO& dto) {
    if (dto.nickname.empty()) {
        throw InvalidDataException("ERRO! Nickname nao pode estar vazio");
    }
    if (playerExists(dto.nickname)) {
        throw DuplicatedDataException("Jogador " + dto.nickname + " ja existe");
    }
    if (dto.nickname.length() < 3 || dto.nickname.length() > 24) {
        throw InvalidDataException("O nickname deve ter entre 3 e 24 caracteres,");
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
