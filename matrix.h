#ifndef MATRIXH_H
#define MATRIXH_H
#include <sys/ioctl.h>
#include <termios.h>
#include "mainwindow.h"
#include <iostream>
#include <unistd.h>
#include <unistdio.h>
#include <iomanip>

class GameSquare {
protected:
    int SIZE = 4;
public:
    int game=0;
    int** Ui = new int* [SIZE];

    int** get_Ui() {
        return Ui;
    }

    int createUi() {
        game++;
        for (int i = 0; i < SIZE; i++) {
        Ui[i] = new int[SIZE];
    }

       for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Ui[i][j] = 0;
        }
    }
    int startPositionX;
    startPositionX = rand() % SIZE - 1;

    int startPositionY;
    startPositionY = rand() % SIZE - 1;

    Ui[startPositionY][startPositionX] = 2;
    Ui[0][0] = 8;
    Ui[0][1] = 16;
    Ui[0][2] = 4;
    Ui[0][3] = 2;
   Ui[1][0] = 2;
    Ui[1][1] = 64;
    Ui[1][2] = 1024;
    Ui[1][3] = 8;
    Ui[2][0] = 2;
    Ui[2][1] = 4;
    Ui[2][2] = 1024;
    Ui[2][3] = 4;
    Ui[3][0] = 4;
    Ui[3][1] = 2;
    Ui[3][2] = 256;
    Ui[3][3] = 2;
    return 0;
    }
    int getter(){
        return Ui[1][2];
    }

};
class matrixh
{
public:
    matrixh();
};

#endif // MATRIXH_H
