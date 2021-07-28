#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QMainWindow;
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionSave_As_triggered();

    void on_actionBold_triggered();

    void on_actionSuperscript_triggered();

    void on_actionSubscript_triggered();

    void on_actionAbout_Creator_triggered();

private:
    Ui::MainWindow *ui;
    QString FileName;
};
#endif // MAINWINDOW_H
