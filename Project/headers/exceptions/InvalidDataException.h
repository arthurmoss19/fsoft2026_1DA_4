//
// Created by pedro on 16/05/2026.
//

#ifndef FSOFT2026_1DA_4_INVALIDDATAEXCEPTION_H
#define FSOFT2026_1DA_4_INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class InvalidDataException : public exception {
private:
    string data;
public:
    InvalidDataException(const string& data);
    const char* what();
};

#endif // FSOFT2026_1DA_4_INVALIDDATAEXCEPTION_H