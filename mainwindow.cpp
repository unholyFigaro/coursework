#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <sys/ioctl.h>
#include <termios.h>
#include "mainwindow.h"
#include <iostream>
#include <unistd.h>
#include <unistdio.h>
#include <iomanip>
#include <matrix.h>
#include <QDebug>
#include <string.h>
#include <QKeyEvent>
#include <QThread>
#include <ai.h>
#include <cmath>
#define SIZE 4
GameSquare userInterface;
int gamesCount=0;

int pov(int a, int b){
    for (int i=0; i<b; i++){
        a*=a;
    }
    return a;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_W:
        if(gamesCount==0) {
            startGame();
            up();
        }
        else
        up();
        break;
    case Qt::Key_S:
        if(gamesCount==0) {
            startGame();
            down();
        }
        else
        down();
        break;
    case Qt::Key_D:
        if(gamesCount==0) {
            startGame();
            right();
        }
        else
        right();
        break;
    case Qt::Key_A:
        if(gamesCount==0) {
            startGame();
            left();
        }
        else
        left();
        break;
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(500, 400);
    QFont f;
    f.setBold(true);
    f.setFamily("Tahoma");
    f.setItalic(true);
    f.setPointSize(23);



    ui->textBrowser->hide();
     ui->textBrowser_2->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool isWin(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(userInterface.Ui[i][j]==2048) return true;
        }
    }
    return false;
}
bool isLose(){
bool issLose=true;
for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
        if (userInterface.Ui[i][j]==0) return false;
    }
}
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        if (userInterface.Ui[i][j] != 0) {
            if ((i - 1 > 0 && (userInterface.Ui[i - 1][j] == userInterface.Ui[i][j] || userInterface.Ui[i - 1][j] == 0)) || (i + 1 < SIZE && (userInterface.Ui[i + 1][j] == userInterface.Ui[i][j] ||
                    userInterface.Ui[i + 1][j] == 0)) || (j - 1 > 0 && (userInterface.Ui[i][j - 1] == userInterface.Ui[i][j] || userInterface.Ui[i][j-1] == 0)) ||
                        (j + 1 < SIZE && (userInterface.Ui[i][j + 1] == userInterface.Ui[i][j] || userInterface.Ui[i][j + 1] == 0))) {
                            issLose = false;
                        }
                }
    }
}
if (issLose == true) {
return true;
}
return false;
}

void MainWindow::startGame(){
    gamesCount+=1;
    if(userInterface.game!=0){
     delete *userInterface.Ui;
     delete userInterface.Ui;
    }
        userInterface.createUi();
        int a=userInterface.getter();
        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            }
        }
        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a=userInterface.Ui[i][j];
        if (a == 0)
        qDebug()<< "*";
        else
        qDebug()<< a;
        }
        if (i == 3) {
        }
      }
        cells();
        del();
}

void MainWindow::on_pushButton_clicked()
{
    startGame();
}



void MainWindow::del(){
    ui->pushButton->hide();
}
bool isMove = false;

int generateValue() {
if (isMove == false) return 1;
int startPositionX = 0, startPositionY = 0;
startPositionX = rand() % 4;
startPositionY = rand() % 4;
while

(userInterface.Ui[startPositionY][startPositionX] != 0) {
startPositionX = rand() % 4;
startPositionY = rand() % 4;
}
int chance = rand() % 100;
if(chance<90)
userInterface.Ui[startPositionY][startPositionX] = 2;
else userInterface.Ui[startPositionY][startPositionX] = 4;
return 0;
}

void MainWindow::score(){
    int total_score=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            total_score+=userInterface.Ui[i][j];
        }
    }
    QString qwe=QString::number(total_score);
    ui->total_score->setText(qwe);
    total_score=0;
}

void MainWindow::cells(){
    qDebug()<< "qwe";
    QString qwe=QString::number(userInterface.Ui[0][0]);
    ui->cell_1->setText(qwe);
    QString qwe2=QString::number(userInterface.Ui[0][1]);
    ui->cell_2->setText(qwe2);
    QString qwe3=QString::number(userInterface.Ui[0][2]);
    ui->cell_3->setText(qwe3);
    QString qwe4=QString::number(userInterface.Ui[0][3]);
    ui->cell_4->setText(qwe4);
    QString qwe5=QString::number(userInterface.Ui[1][0]);
    ui->cell_5->setText(qwe5);
    QString qwe6=QString::number(userInterface.Ui[1][1]);
    ui->cell_6->setText(qwe6);
    QString qwe7=QString::number(userInterface.Ui[1][2]);
    ui->cell_7->setText(qwe7);
    QString qwe8=QString::number(userInterface.Ui[1][3]);
    ui->cell_8->setText(qwe8);
    QString qwe9=QString::number(userInterface.Ui[2][0]);
    ui->cell_9->setText(qwe9);
    QString qwe10=QString::number(userInterface.Ui[2][1]);
    ui->cell_10->setText(qwe10);
    QString qwe11=QString::number(userInterface.Ui[2][2]);
    ui->cell_11->setText(qwe11);
    QString qwe12=QString::number(userInterface.Ui[2][3]);
    ui->cell_12->setText(qwe12);
    QString qwe13=QString::number(userInterface.Ui[3][0]);
    ui->cell_13->setText(qwe13);
    QString qwe14=QString::number(userInterface.Ui[3][1]);
    ui->cell_14->setText(qwe14);
    QString qwe15=QString::number(userInterface.Ui[3][2]);
    ui->cell_15->setText(qwe15);
    QString qwe16=QString::number(userInterface.Ui[3][3]);
    ui->cell_16->setText(qwe16);
}
void MainWindow::up(){
    for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 4; i++) {
    if (userInterface.Ui[i][j] != 0 && i - 1 > -1) {
    int k = i, l = j;
    int cellValue = userInterface.Ui[i][j];
    while (k - 1 > -1 && userInterface.Ui[k - 1][l] == 0) {
    userInterface.Ui[k - 1][l] = cellValue;
    userInterface.Ui[k][l] = 0;
    k--;
    isMove = true;
    }
    if (k - 1 > -1 && userInterface.Ui[k][l] == userInterface.Ui[k - 1][l]) {
    userInterface.Ui[k - 1][l] *= 2;
    userInterface.Ui[k - 1][l]++;
    userInterface.Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (userInterface.Ui[t][j] % 2 == 1)
    userInterface.Ui[t][j]--;
    }
    }
    generateValue();
    isMove = false;
    cells();
    score();
    if(isLose()==true) ui->textBrowser->show();
    if(isWin()==true) ui->textBrowser_2->show();
}
void MainWindow::down(){
    for (int j = 0; j < 4;j++) {
    for (int i = 4 - 1; i >= 0; i--) {
    if (userInterface.Ui[i][j] != 0 && i + 1 < 4) {
    int k = i, l = j;
    int cellValue = userInterface.Ui[i][j];
    while (k + 1 < 4 && userInterface.Ui[k + 1][l] == 0) {
    userInterface.Ui[k + 1][l] = cellValue;
    userInterface.Ui[k][l] = 0;
    k++;
    isMove = true;
    }
    if (k + 1 < 4 && userInterface.Ui[k][l] == userInterface.Ui[k + 1][l]) {
    userInterface.Ui[k + 1][l] *= 2;
    userInterface.Ui[k + 1][l]++;
    userInterface.Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (userInterface.Ui[t][j] % 2 == 1)
    userInterface.Ui[t][j]--;
    }
    }
    generateValue();
    isMove = false;
    cells();
    score();
    if(isLose()==true) ui->textBrowser->show();
    if(isWin()==true) ui->textBrowser_2->show();
}
void MainWindow::left(){
    for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
    if (j - 1 > -1 && userInterface.Ui[i][j] != 0) {
    int k = i, l = j;
    int cellValue = userInterface.Ui[i][j];
    while (l - 1 > -1 && userInterface.Ui[k][l - 1] == 0) {
    userInterface.Ui[k][l - 1] = cellValue;
    userInterface.Ui[k][l] = 0;
    l--;
    isMove = true;
    }
    if (l -1>-1 && userInterface.Ui[k][l] == userInterface.Ui[k][l - 1]) {
    userInterface.Ui[k][l - 1] *= 2;
    userInterface.Ui[k][l - 1]++;
    userInterface.Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (userInterface.Ui[i][t] % 2 == 1)
    userInterface.Ui[i][t]--;
    }
    }
    generateValue();
    isMove = false;
    cells();
    score();
    if(isLose()==true) ui->textBrowser->show();
    if(isWin()==true) ui->textBrowser_2->show();
}
void MainWindow::right(){
    for (int i = 0; i < 4; i++) {
    for (int j = 4-1; j >=0; j--) {
    if (j + 1 < 4 && userInterface.Ui[i][j] != 0) {
    int k = i, l=j;
    int cellValue=userInterface.Ui[i][j];
    while (l + 1 < 4 && userInterface.Ui[k][l + 1] == 0) {
    userInterface.Ui[k][l + 1] = cellValue;
    userInterface.Ui[k][l] = 0;
    l++;
    isMove = true;
    }
    if (l + 1 < 4 && userInterface.Ui[k][l] == userInterface.Ui[k][l + 1]) {
    userInterface.Ui[k][l + 1] *= 2;
    userInterface.Ui[k][l + 1]++;
    userInterface.Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (userInterface.Ui[i][t] % 2 == 1)
    userInterface.Ui[i][t]--;
    }
    }
    generateValue();
    isMove = false;
    cells();
    score();
    if(isLose()==true) ui->textBrowser->show();
    if(isWin()==true) ui->textBrowser_2->show();
}

/////////////////////

void MainWindow::generateValue1(int** Ui) {
if (isMove == false) return;
int startPositionX = 0, startPositionY = 0;
startPositionX = rand() % 4;
startPositionY = rand() % 4;
while

(Ui[startPositionY][startPositionX] != 0) {
startPositionX = rand() % 4;
startPositionY = rand() % 4;
}
int chance = rand() % 100;
if(chance<90)
Ui[startPositionY][startPositionX] = 2;
else Ui[startPositionY][startPositionX] = 4;
return;
}

void MainWindow::up1(int** Ui){
    for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 4; i++) {
    if (Ui[i][j] != 0 && i - 1 > -1) {
    int k = i, l = j;
    int cellValue = Ui[i][j];
    while (k - 1 > -1 && Ui[k - 1][l] == 0) {
    Ui[k - 1][l] = cellValue;
    Ui[k][l] = 0;
    k--;
    isMove = true;
    }
    if (k - 1 > -1 && Ui[k][l] == Ui[k - 1][l]) {
    Ui[k - 1][l] *= 2;
    Ui[k - 1][l]++;
    Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (Ui[t][j] % 2 == 1)
    Ui[t][j]--;
    }
    }
    generateValue1(Ui);
    isMove = false;

}
void MainWindow::down1(int** Ui){
    for (int j = 0; j < 4;j++) {
    for (int i = 4 - 1; i >= 0; i--) {
    if (Ui[i][j] != 0 && i + 1 < 4) {
    int k = i, l = j;
    int cellValue = Ui[i][j];
    while (k + 1 < 4 && Ui[k + 1][l] == 0) {
    Ui[k + 1][l] = cellValue;
    Ui[k][l] = 0;
    k++;
    isMove = true;
    }
    if (k + 1 < 4 && Ui[k][l] == Ui[k + 1][l]) {
    Ui[k + 1][l] *= 2;
    Ui[k + 1][l]++;
    Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (Ui[t][j] % 2 == 1)
    Ui[t][j]--;
    }
    }
    generateValue1(Ui);
    isMove = false;
}
void MainWindow::left1(int** Ui){
    for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
    if (j - 1 > -1 && Ui[i][j] != 0) {
    int k = i, l = j;
    int cellValue = Ui[i][j];
    while (l - 1 > -1 && Ui[k][l - 1] == 0) {
    Ui[k][l - 1] = cellValue;
    Ui[k][l] = 0;
    l--;
    isMove = true;
    }
    if (l -1>-1 && Ui[k][l] == Ui[k][l - 1]) {
    Ui[k][l - 1] *= 2;
    Ui[k][l - 1]++;
    Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (Ui[i][t] % 2 == 1)
    Ui[i][t]--;
    }
    }
    generateValue1(Ui);
    isMove = false;
}
void MainWindow::right1(int** Ui){
    for (int i = 0; i < 4; i++) {
    for (int j = 4-1; j >=0; j--) {
    if (j + 1 < 4 && Ui[i][j] != 0) {
    int k = i, l=j;
    int cellValue=Ui[i][j];
    while (l + 1 < 4 && Ui[k][l + 1] == 0) {
    Ui[k][l + 1] = cellValue;
    Ui[k][l] = 0;
    l++;
    isMove = true;
    }
    if (l + 1 < 4 && Ui[k][l] == Ui[k][l + 1]) {
    Ui[k][l + 1] *= 2;
    Ui[k][l + 1]++;
    Ui[k][l] = 0;
    }
    }
    }
    for (int t = 0; t < 4; t++) {
    if (Ui[i][t] % 2 == 1)
    Ui[i][t]--;
    }
    }
    generateValue1(Ui);
    isMove = false;

}
bool isPosMove(int** Ui, int side){
    if(side == 0){
        for(int i=0; i<SIZE; i++){
            for(int j=SIZE-1; j>-1; j--){
                if(Ui[j][i]!=0 && j!=0){
                    for(int u=j;u>-1;u--){
                        if(Ui[u][i]==0) return true;
                    }
                }
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=SIZE-1;j>0; j--){
                if(Ui[j][i]==Ui[j-1][i] && Ui[j][i]!=0) return true;
            }
        }
        return false;
    }
    if(side == 1){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(Ui[j][i]!=0 && j!=0){
                    for(int u=j;u<SIZE;u++){
                        if(Ui[u][i]==0) return true;
                    }
                }
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE-1; j++){
                if(Ui[j][i]==Ui[j+1][i] && Ui[j][i]!=0) return true;
            }
        }
        return false;
    }
    if(side == 2){
        for(int i=0; i<SIZE; i++){
            for(int j=SIZE-1; j>-1; j--){
                if(Ui[i][j]!=0 && j!=0){
                    for(int u=j;u>-1;u--){
                        if(Ui[i][u]==0) return true;
                    }
                }
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=SIZE-1;j>0; j--){
                if(Ui[i][j]==Ui[i][j-1] && Ui[i][j]!=0) return true;
            }
        }
        return false;
    }
    if(side == 3){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(Ui[i][j]!=0 && j!=0){
                    for(int u=j;u<SIZE;u++){
                        if(Ui[i][u]==0) return true;
                    }
                }
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE-1; j++){
                if(Ui[i][j]==Ui[i][j+1] && Ui[i][j]!=0) return true;
            }
        }
        return false;
    }
    else
        return false;
}
/////////////////////
void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->hide();
    ui->textBrowser_2->hide();
    bool isWasTwo=false;
    int chance=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            userInterface.Ui[i][j]=0;
            chance=rand() % 1 + 100;
            if(isWasTwo==false && chance>=94)
            {
                userInterface.Ui[i][j]=2;
                isWasTwo=true;
            }
            cells();
        }
    }
    if(isWasTwo==false)  userInterface.Ui[3][3]=2;
    score();
}



void MainWindow::on_pushButton_3_clicked()
{
//    double scoreGrid[4][4]={pow(4,15), pow(4,14), pow(4,13), pow(4,12),
//                                 pow(4,8), pow(4,9), pow(4,10), pow(4,11),
//                                 pow(4,7), pow(4,6), pow(4,5), pow(4,4),
//                                 pow(4,0), pow(4,1), pow(4,2), pow(4,3)};
    double scoreGrid[4][4]={50, 30, 20, 20,
                                 30, 20, 15, 15,
                                 15, 5, 0, 0,
                                 -5, -5, -10, -15};

    int** gridUp=new int*[4];
    for(int i=0; i<4; i++)
        gridUp[i]=new int[4];

    gridUp[0][0]=2;
    int** gridDown=new int*[4];
    for(int i=0; i<4; i++)
        gridDown[i]=new int[4];
    int** gridLeft=new int*[4];
    for(int i=0; i<4; i++)
        gridLeft[i]=new int[4];
    int** gridRight=new int*[4];
    for(int i=0; i<4; i++)
        gridRight[i]=new int[4];
    qDebug()<<"rrrrr";
        int *v_moves=new int[4];
        int** gridPrev=new int*[4];
        for(int i=0; i<4; i++)
            gridPrev[i]=new int[4];
    for(int i=0; i<SIZE; i++){
        for(int j=0;j<SIZE; j++){
            int a=userInterface.Ui[i][j];
            gridUp[i][j]=a;
            gridDown[i][j]=userInterface.Ui[i][j];
            gridLeft[i][j]=userInterface.Ui[i][j];
            gridRight[i][j]=userInterface.Ui[i][j];
        }
    }
    up1(gridUp);
    down1(gridDown);
    left1(gridLeft);
    right1(gridRight);
    double scoreUp=0, scoreDown=0, scoreRight=0, scoreLeft=0;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            scoreUp+=gridUp[i][j]*scoreGrid[i][j];
            scoreDown+=gridDown[i][j]*scoreGrid[i][j];
            scoreLeft+=gridLeft[i][j]*scoreGrid[i][j];
            scoreRight+=gridRight[i][j]*scoreGrid[i][j];
        }
    }
    qDebug()<< scoreUp<<"***"<<scoreDown<<"***"<<scoreLeft<<"***"<<scoreRight;

    v_moves[0]=scoreUp;
    v_moves[1]=scoreDown;
    v_moves[2]=scoreLeft;
    v_moves[3]=scoreRight;
    int i_moves[4]={0, 1, 2, 3};
    int max_score = scoreUp;
    int i_move=0;
    int a, b;
    for(int i =0;i<SIZE; i++){
        for(int j=0; j<SIZE-1; j++){
            if(v_moves[i]>v_moves[i+1]){
                a=v_moves[i+1];
                b=i_moves[i+1];
                v_moves[i+1]=v_moves[i];
                i_moves[i+1]=i_moves[i];
                v_moves[i]=a;
                i_moves[i]=b;
            }
        }
    }

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            gridPrev[i][j]=0;
        }
    }
    for(int i = 0; i<SIZE; i++){
    i_move = i_moves[i];
    bool isSimilar=true;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            gridPrev[i][j]=userInterface.Ui[i][j];
        }
    }
    if(i_moves[i]==0){
        up();
    }
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(gridPrev[i][j]!=userInterface.Ui[i][j]) isSimilar=false;
        }
    }
    if(isSimilar==false) break;
    else if(i_moves[i]==1){
        down();
    }
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(gridPrev[i][j]!=userInterface.Ui[i][j]) isSimilar=false;
        }
    }
    if(isSimilar==false) break;
    else if(i_moves[i]==2){
        left();
    }
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(gridPrev[i][j]!=userInterface.Ui[i][j]) isSimilar=false;
        }
    }
    if(isSimilar==false) break;
    else if(i_moves[i]==3) {
        right();
    }
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(gridPrev[i][j]!=userInterface.Ui[i][j]) isSimilar=false;
        }
    }
    if(isSimilar==false) break;
 }
    /*cells();
    score();
    if(isLose()==true) ui->textBrowser->show();
    if(isWin()==true) ui->textBrowser_2->show()*/;
}
