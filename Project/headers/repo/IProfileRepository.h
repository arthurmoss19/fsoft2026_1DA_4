//
// Created by arthu on 17/05/2026.
//

#ifndef PROJECT_IPROFILEREPOSITORY_H
#define PROJECT_IPROFILEREPOSITORY_H

#include "PlayerContainer.h"
#include <string>

class IProfileRepository {
public:
    virtual bool exists(const std::string& nickname) = 0;
    virtual void addProfile(const Player& player) = 0;
};

#endif