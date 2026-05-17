//
// Created by pedro on 17/05/2026.
//

#ifndef FSOFT2026_1DA_4_NODATAEXCEPTION_H_
#define FSOFT2026_1DA_4_NODATAEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class NoDataException :public exception{
private:
    string data;
public:
    NoDataException(const string& data);
    const char* what();
};




#endif
