//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_TABULEIRO_H
#define PROJETOFSOFT_TABULEIRO_H

#include <vector>
#include "Barco.h"

using namespace std;

class Tabuleiro {
private:
    static const int TAMANHO = 10;
    char grelha[TAMANHO][TAMANHO];
    vector<Barco> frota;
    static const char AGUA = '~';
    static const char NAVIO = '#';
    static const char ATINGIDO = 'X';
    static const char TIRO_AGUA = '0';

public:
    Tabuleiro();
    ~Tabuleiro() = default;
    bool validarPosicao(int linha, int coluna, int tamanho, bool horizontal) const;
    bool colocarNavio(const Barco& navio, int linha, int coluna, bool horizontal);
    char registarDisparo(int linha, int coluna);
    void imprimir(bool esconderNavios) const;
    bool todosOsBarcosAfundados() const;
    int getTamanho() const;
    const vector<Barco>& getFrota() const;
};

#endif