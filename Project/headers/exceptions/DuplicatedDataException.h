//
// Created by pedro on 17/05/2026.
//

#ifndef FSOFT2026_1DA_4_DUPLICATEDDATAEXCEPTION_H
#define FSOFT2026_1DA_4_DUPLICATEDDATAEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class DuplicatedDataException :public exception{
private:
    string data;
public:
    DuplicatedDataException(string data);
    const char* what();
};


#endif

