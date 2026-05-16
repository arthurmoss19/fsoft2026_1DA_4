//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_JOGADOR_H
#define PROJETOFSOFT_JOGADOR_H

#include <string>
#include <iostream>

using namespace std;

class Jogador {
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
    Jogador(const string& nickname);
    Jogador(const Jogador& obj);
    ~Jogador() = default;
    const string& getNickname() const;
    void setNickname(const string& nickname);
    int getVitorias() const;
    int getDerrotas() const;
    float getTaxaPrecisao() const;
    void registarTiro(bool acertou);
    void registarFimDeJogo(bool venceu);
    bool operator == (const Jogador& obj) const;
    bool operator == (const string& nick) const;
};

#endif