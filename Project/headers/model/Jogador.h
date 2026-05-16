//
// Created by pedro on 14/05/2026.
//

#ifndef HEADERS_MODEL_PLAYER_H_
#define HEADERS_MODEL_PLAYER_H_

#include <string>
#include <iostream>

using namespace std;

class Player {
private:
    string nickname;
    int vitorias;
    int derrotas;
    int totalTiros;
    int tirosAcertados;
    bool isNicknameValid(const string& nick);
    void setVitorias(int vitorias);
    void setDerrotas(int derrotas);

public:
    Player(const string& nickname);
    Player(const Player& obj);
    ~Player() = default;
    const string& getNickname() const;
    void setNickname(const string& nickname);
    int getVitorias() const;
    int getDerrotas() const;

    float getTaxaPrecisao() const;
    void registarTiro(bool acertou);
    void registarFimDeJogo(bool venceu);

    bool operator == (const Player& obj) const;
    bool operator == (const string& nick) const;
};

#endif