//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_BARCO_H
#define PROJETOFSOFT_BARCO_H

#include <string>
#include <vector>

using namespace std;

class Barco {
private:
    string tipo;
    int tamanho;
    int tirosAtingidos;
    char simbolo;
    bool direcao;
    bool tamanhoValido(int tamanho);
    bool tipoValido(const string& tipo);
    void setTamanho(int tamanho);

public:
    Barco(const string& tipo, int tamanho, char simbolo);
    Barco(const Barco& obj);
    ~Barco() = default;
    const string& getTipo() const;
    void setTipo(const string& tipo);
    int getTamanho() const;
    char getSimbolo() const;
    void setSimbolo(char simbolo);
    bool getDirecao() const;
    void setDirecao(bool direcao);
    bool estaAfundado() const;
    void adicionarTiroAtingido();
    bool operator == (const Barco& obj) const;
    bool operator == (const string& tipo) const;
};

#endif