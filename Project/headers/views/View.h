//
// Created by arthu on 14/05/2026.
//

#ifndef PROJECT_VIEW_H
#define PROJECT_VIEW_H

#include "Board.h"

using namespace std;

class View {
public:
    View();
    int menuMain();
    int menuNewGame();
    int menuDifficulty();
    int menuShipPlacement();
    int menuRankingType();
    int menuStatistics();
    int menuSatisfaction();
    void printHelpAndRules();
    void printMessage(const string& msg);
    void ShipPlacement(const string& type, int size, int& row, int& col, bool& horizontal);
    void showBoard(const Board& board, bool hideShips);
    void showPlacementSuccess();
    void showOutOfBoundsError();
    void showOverlapError();
    void showGameTurn(const string& player, const Board& yourBoard, const Board& opponentBoard);
    void showShotResult(bool hit, bool sunk, const string& shipType, const string& coordinate);
    void showGameOver(const string& winnerName, int winnerShots, int winnerHits, const string& loserName, int loserShots, int loserHits);
    bool getShotCoordinate(int& row, int& col);
};

#endif