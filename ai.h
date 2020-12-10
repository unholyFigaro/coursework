#include <sys/ioctl.h>
#include <termios.h>
#include "mainwindow.h"
#include <iostream>
#include <unistd.h>
#include <unistdio.h>
#include <iomanip>
#include <math.h>

#ifndef AI_H
#define AI_H
#define SIZE 4

//int abs(int a){
//    if(a<0) return -a;
//    else return a;
//}
enum Directions{
    up, down, left, right
};
struct Run{
    Directions initialMove;
    int finalScore;
};

class ai
{
public:
//    int max_step=3;
//    int** Ui = new int* [SIZE];
//    int cpyUi(GameSquare userInterface) {
//        for (int i = 0; i < SIZE; i++) {
//        Ui[i] = new int[SIZE];
//    }

    ai();

};

#endif // AI_H
