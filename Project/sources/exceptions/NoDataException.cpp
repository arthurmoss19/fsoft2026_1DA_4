//
// Created by pedro on 17/05/2026.
//

#include "NoDataException.h"


NoDataException::NoDataException(const string& data){
    this->data = "ERRO! "+ data + " nao existe!\n";
}

const char* NoDataException::what(){
    return data.c_str();
}