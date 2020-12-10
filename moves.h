#ifndef MOVES_H
#define MOVES_H
#include <sys/ioctl.h>
#include <termios.h>
#include "mainwindow.h"
#include <iostream>
#include <unistd.h>
#include <unistdio.h>
#include <iomanip>
#include <matrix.h>

class moves : GameSquare
{
public:
    bool isMove = false;
    int** mainUi;
    void set_Ui(int** mainUi) {
        this->mainUi = mainUi;
    }

    void right() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE-1; j >=0; j--) {
                if (j + 1 < SIZE && mainUi[i][j] != 0) {
                    int k = i, l=j;
                    int cellValue=mainUi[i][j];
                        while (l + 1 < SIZE && mainUi[k][l + 1] == 0) {
                            mainUi[k][l + 1] = cellValue;
                            mainUi[k][l] = 0;
                            l++;
                            isMove = true;
                        }
                if (l + 1 < SIZE && mainUi[k][l] == mainUi[k][l + 1]) {
                    mainUi[k][l + 1] *= 2;
                    mainUi[k][l + 1]++;
                    mainUi[k][l] = 0;
                }
            }
        }
        for (int t = 0; t < SIZE; t++) {
            if (mainUi[i][t] % 2 == 1)
                mainUi[i][t]--;
            }
        }
        generateValue();
        isMove = false;
        }

    void left() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (j - 1 > -1 && mainUi[i][j] != 0) {
                    int k = i, l = j;
                    int cellValue = mainUi[i][j];
                        while (l - 1 > -1 && mainUi[k][l - 1] == 0) {
                            mainUi[k][l - 1] = cellValue;
                            mainUi[k][l] = 0;
                            l--;
                            isMove = true;
                        }
                    if (l -1>-1 && mainUi[k][l] == mainUi[k][l - 1]) {
                    mainUi[k][l - 1] *= 2;
                    mainUi[k][l - 1]++;
                    mainUi[k][l] = 0;
                    }
                    }
        }
        for (int t = 0; t < SIZE; t++) {
            if (mainUi[i][t] % 2 == 1)
                    mainUi[i][t]--;
                    }
                        }
    generateValue();
    isMove = false;
    }

    void down() {
    for (int j = 0; j < SIZE;j++) {
    for (int i = SIZE - 1; i >= 0; i--) {
    if (mainUi[i][j] != 0 && i + 1 < SIZE) {
    int k = i, l = j;
    int cellValue = mainUi[i][j];
    while (k + 1 < SIZE && mainUi[k + 1][l] == 0) {
    mainUi[k + 1][l] = cellValue;
    mainUi[k][l] = 0;
    k++;
    isMove = true;
    }
    if (k + 1 < SIZE && mainUi[k][l] == mainUi[k + 1][l]) {
    mainUi[k + 1][l] *= 2;
    mainUi[k + 1][l]++;
    mainUi[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < SIZE; t++) {
    if (mainUi[t][j] % 2 == 1)
    mainUi[t][j]--;
    }
    }
    generateValue();
    isMove = false;
    }

    void up() {
    for (int j = 0; j < SIZE; j++) {
    for (int i = 0; i < SIZE; i++) {
    if (mainUi[i][j] != 0 && i - 1 > -1) {
    int k = i, l = j;
    int cellValue = mainUi[i][j];
    while (k - 1 > -1 && mainUi[k - 1][l] == 0) {
    mainUi[k - 1][l] = cellValue;
    mainUi[k][l] = 0;
    k--;
    isMove = true;
    }
    if (k - 1 > -1 && mainUi[k][l] == mainUi[k - 1][l]) {
    mainUi[k - 1][l] *= 2;
    mainUi[k - 1][l]++;
    mainUi[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < SIZE; t++) {
    if (mainUi[t][j] % 2 == 1)
    mainUi[t][j]--;
    }
    }
    generateValue();
    isMove = false;
    }

    int generateValue() {
    if (isMove == false) return 1;
    int startPositionX = 0, startPositionY = 0;
    startPositionX = rand() % SIZE;
    startPositionY = rand() % SIZE;
    while

    (mainUi[startPositionY][startPositionX] != 0) {
    startPositionX = rand() % SIZE;
    startPositionY = rand() % SIZE;
    }
    int chance = rand() % 100;
    if(chance<90)
    mainUi[startPositionY][startPositionX] = 2;
    else mainUi[startPositionY][startPositionX] = 4;
    return 0;
    }

};

#endif // MOVES_H
