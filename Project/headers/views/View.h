//
// Created by arthu on 14/05/2026.
//

#ifndef PROJECT_VIEW_H
#define PROJECT_VIEW_H

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
    void printHelpAndRules();
};

#endif