#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <matrix.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class GameSquare;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void cells();
    void score();
    void up();
    void down();
    void left();
    void right();
    void del();
    void keyPressEvent(QKeyEvent *e);
    void startGame();
    void up1(int** Ui);
    void down1(int** UI);
    void left1(int** UI);
    void right1(int** UI);
    void on_pushButton_2_clicked();
    void generateValue1(int** UI);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
