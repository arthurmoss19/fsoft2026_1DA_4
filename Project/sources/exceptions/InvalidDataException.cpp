//
// Created by pedro on 17/05/2026.
//

#include "InvalidDataException.h"


InvalidDataException::InvalidDataException(const string& data){
    this->data = "Error: ["+ data + "] is not valid!!";;
}

const char* InvalidDataException::what(){
    return data.c_str();
}
