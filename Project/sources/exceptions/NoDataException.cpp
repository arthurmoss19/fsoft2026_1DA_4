//
// Created by pedro on 17/05/2026.
//

#include "NoDataException.h"


NoDataException::NoDataException(const string& data){
    this->data = "Error: ["+ data + "] not found!!";;
}

const char* NoDataException::what(){
    return data.c_str();
}