//
// Created by arthu on 16/05/2026.
//

#ifndef PROJECT_UTILS_H_
#define PROJECT_UTILS_H_

#include <string>

using namespace std;

class Utils {
public:
    static int getNumber(const string&  label, int min, int max);
    static string getString(const string&  label);
    static void pressEnter(const string& message);
    static bool isNicknameValid(const string& nick, string& errorMsg);
};

#endif