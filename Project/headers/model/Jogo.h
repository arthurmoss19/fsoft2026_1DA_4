//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_JOGO_H
#define PROJETOFSOFT_JOGO_H

#include "Jogador.h"
#include "Tabuleiro.h"

using namespace std;

class Jogo {
private:
    Jogador* jogador1;
    Jogador* jogador2;
    Tabuleiro tabuleiro1;
    Tabuleiro tabuleiro2;
    int turnoAtual;
    bool contraComputador;
    int dificuldadeIA;
    bool jogoTerminado;
    void alternarTurno();
    bool verificarFimDeJogo();

public:
    Jogo(Jogador* j1, Jogador* j2, bool isVsAI, int dificuldade);
    ~Jogo() = default;
    void prepararPartida();
    bool executarJogada(int linha, int coluna);
    void jogadaComputador();
    Tabuleiro& getTabuleiroAtivo();
    Tabuleiro& getTabuleiroAdversario();
    Jogador* getJogadorAtual() const;
    bool estaTerminado() const;
};

#endif

