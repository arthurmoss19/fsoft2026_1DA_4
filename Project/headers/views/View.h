//
// Created by arthu on 14/05/2026.
//

#ifndef HEADERS_VIEWS_VIEW_H_
#define HEADERS_VIEWS_VIEW_H_

using namespace std;

class View {
public:
    View();
    int menuMain();
    int menuNewGame();
    int menuDifficulty();
    int menuShipPlacement();
    int menuRankingType();
    void printHelpAndRules();
};

#endif /* HEADERS_VIEWS_VIEW_H_ */