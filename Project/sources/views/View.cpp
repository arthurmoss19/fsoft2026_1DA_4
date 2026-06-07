//
// Created by arthu on 14/05/2026.
//

#include<iostream>
#include "View.h"
#include "Utils.h"

using namespace std;

View::View() {
}

int View::menuMain() {
    int op = -1;

    do {
        cout <<"\n\n********** Menu Principal **********\n";
        cout <<"1. Novo Jogo\n";
        cout <<"2. Ranking\n";
        cout <<"3. Estatisticas\n";
        cout <<"4. Ajuda e Regras\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 4);
    } while (op < 0 || op > 4);

    return op;
}

int View::menuNewGame() {
    int op = -1;

    do {
        cout <<"\n\n********** Novo Jogo **********\n";
        cout <<"1. Jogador vs. Computador\n";
        cout <<"2. Jogador vs. Jogador\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 2);
    } while (op < 0 || op > 2);

    return op;
}

int View::menuDifficulty() {
    int op = -1;

    do {
        cout <<"\n\n********** Dificuldade **********\n";
        cout <<"1. Facil\n";
        cout <<"2. Dificil\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 2);
    } while (op < 0 || op > 2);

    return op;
}

int View::menuShipPlacement() {
    int op = -1;

    do {
        cout <<"\n\n********** Posicionamento dos Navios **********\n";
        cout <<"1. Posicionamento manual\n";
        cout <<"2. Posicionamento automatico\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 2);
    } while (op < 0 || op > 2);

    return op;
}

int View::menuRankingType() {
    int op = -1;

    do {
        cout << "\n\n********** Tipo de Ranking **********\n";
        cout << "1. Numero de vitorias\n";
        cout << "2. Taxa de precisao\n";
        cout << "\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 2);
    } while (op < 0 || op > 2);

    return op;
}

int View::menuStatistics() {
    int op = -1;
    do {
        cout << "\n\n********** Estatisticas *********\n";
        cout <<"1. Ver minhas estatisticas\n";
        cout <<"2. Ver estatisticas de outro jogador\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 2);
    } while (op < 0 || op > 2);

    return op;
}

void View::printHelpAndRules() {
    cout << "\n\n********** Ajuda e Regras **********\n";

    cout << "\nObjetivo do jogo:\n";
    cout << "- Afundar todos os navios do adversario antes que ele afunde os seus\n";

    cout << "\nComo jogar:\n";
    cout << "- Cada jogador possui 5 navios e um tabuleiro 10x10\n";
    cout << "- Cada jogador posiciona os navios no tabuleiro em segredo\n";
    cout << "- O jogo comeca!\n";

    cout << "\nExemplo de turno:\n";
    cout << "- Jogador 1 escolhe a coordenada B4\n";
    cout << "- Se houver navio em B4, e um tiro certo\n";
    cout << "- Caso contrario, e um tiro falhado\n";

    cout << "\nLegenda do Tabuleiro:\n";
    cout << " ~ Agua\n";
    cout << " # Navio\n";
    cout << " X Navio atingido (tiro certo)\n";
    cout << " O Tiro na agua (tiro falhado)\n";
    cout << "\nOutras Regras\n";

    cout << "- Nao pode mudar os navios de lugar durante o jogo\n";
    cout << "- Cada jogador joga uma vez por turno\n";
    cout << "- Ganha quem destruir todos os navios inimigos\n";

    cout << "\nAgora voce ja esta pronto para jogar Batalha Naval!\n";
    cout << "Boa sorte e bom jogo!\n\n";
}

void View::printMessage(const string& msg) {
    cout << msg << endl;
}

void View::ShipPlacement(const string& type, int size, int& row, int& col, bool& horizontal) {
    cout << "\nPosicionar " << type << " (Tamanho " << size << ")\n\n";

    bool validPosition = false;

    while (!validPosition) {
        string position = Utils::getString("Introduza a posicao inicial do navio (ex: A1)");

        if (position.length() < 2) {
            cout << "Posicao invalida! Use o formato letra + numero (ex: A1)\n";
            continue;
        }

        char letter = toupper(position[0]);
        row = letter - 'A';

        string number = position.substr(1);
        col = stoi(number);

        if (row < 0 || row > 9 || col < 0 || col > 9) {
            cout << "Posicao fora do tabuleiro! Linha de A-J, Coluna de 0-9\n";
            continue;
        }

        validPosition = true;
    }

    string orientation = Utils::getString("Introduza a orientacao (H - Horizontal, V - Vertical)");
    horizontal = (orientation == "H" || orientation == "h");
}

void View::showOutOfBoundsError() {
    cout << "Posicao fora dos limites do tabuleiro! Escolha outra posiçao.\n";
}

void View::showOverlapError() {
    cout << "Navios sobrepostos! Escolha outra posicao.\n";
}

void View::showPlacementSuccess() {
    cout << "\nTodos os teus navios foram posicionados!\n\n";
}

void View::showBoard(const Board& board, bool hideShips) {
    cout << "\n--- Seu Tabuleiro ---\n\n";
    board.print(hideShips);
}

int View::menuSatisfaction() {
    int op = -1;
    do {
        cout << "\n********** Esta satisfeito com a distribuicao dos navios? **********\n";
        cout << "1. Sim, comecar jogo\n";
        cout << "2. Nao, gerar distribuicao automatica\n";
        cout << "3. Nao, posicionar manualmente\n";
        cout << "\n0. Sair\n";

        op = Utils::getNumber("Opcao", 0, 3);
    } while (op < 0 || op > 3);

    return op;
}

bool View::getShotCoordinate(int& row, int& col) {
    string shot = Utils::getString("\nIntroduza a coordenada de ataque (ex: A1)");

    if (shot == "0") {
        return false;
    }

    char letter = toupper(shot[0]);

    row = letter - 'A';
    col = stoi(shot.substr(1));

    return (row >= 0 && row <= 9 && col >= 0 && col <= 9);
}

void View::showGameTurn(const string& player, const Board& yourBoard, const Board& opponentBoard) {
    cout << "\n********** Turno de: " << player << " **********\n\n";

    cout << "--- Seu Tabuleiro ---\n";
    yourBoard.print(false);

    cout << "\n--- Tabuleiro do Adversario ---\n";
    opponentBoard.print(true);
}

void View::showShotResult(bool hit, const string& coordinate) {
    cout << "\nTiro em " << coordinate << (hit ? ": NAVIO!\n" : ": AGUA!\n") << '\n';
}
void View::showGameOver(const string& winnerName, int shots, int hits) {
    cout << "\n**********************************\n";
    cout << "********** FIM DE JOGO **********\n";
    cout << "**********************************\n";
    cout << "\n>>> VENCEDOR: " << winnerName << " <<<\n";
    cout << "Tiros: " << shots << " | Acertos: " << hits
         << " | Precisao: " << (shots > 0 ? hits * 100 / shots : 0) << "%\n\n";
}