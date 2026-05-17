//
// Created by pedro on 17/05/2026.
//

#include "DuplicatedDataException.h"


DuplicatedDataException::DuplicatedDataException(string data){
    this->data = "Error: ["+ data + "] duplicated!!";
}

const char* DuplicatedDataException::what(){
    return this->data.c_str();
}