//
// Created by koppany on 5/15/2024.
//

#include "string.h"

#ifndef BME_PROG2_TICKETS_EXEPTIONS_H
#define BME_PROG2_TICKETS_EXEPTIONS_H


class Exeption {
    String msg;
public:
    Exeption(const char* msg) : msg(msg) {}
    String getMsg() const {
        return msg;
    }
    struct InvalidInput {
        InvalidInput(const char* msg) {
            msg = msg;
        }
    };
    struct OutOfRange {
        OutOfRange(const char* msg) {
            msg = msg;
        }
    };
    struct EndOfLine {
        EndOfLine(const char* msg) {
            msg = msg;
        }
    };
};

#endif //BME_PROG2_TICKETS_EXEPTIONS_H
