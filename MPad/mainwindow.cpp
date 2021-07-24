#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resume.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

   FileName="";
   ui->textEdit->setPlainText("");
}


void MainWindow::on_actionOpen_triggered()
{

    QString FilePath = QFileDialog::getOpenFileName(this);

    if(!FilePath.isEmpty())
    {
        QFile newFile = FilePath;
        if(newFile.open(QFile::ReadOnly | QFile::Text ) )
        {
            FileName=FilePath;
            QTextStream Mstream(&newFile);
            QString text = Mstream.readAll();
            newFile.close();

            ui->textEdit->setText(text);
        }
    }
}


void MainWindow::on_actionSave_triggered()
{

    if(FileName == "")
    {
        on_actionSave_As_triggered();
    }

   QFile SFile = FileName;

   if(SFile.open(QFile::WriteOnly | QFile::Text))
   {
       QTextStream Qs(&SFile);
       Qs<<ui->textEdit->toPlainText();
       SFile.close();
       SFile.flush();
   }
}

void MainWindow::on_actionSave_As_triggered()
{

    QString Qfp = QFileDialog::getSaveFileName(this);

    if(!Qfp.isEmpty())
      {
        FileName = Qfp;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionUndo_triggered()
{
  ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
  ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
  ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
   ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
   ui->textEdit->paste();
}

void MainWindow::on_actionBold_triggered()
{

     QTextCursor cursor= ui->textEdit->textCursor();

 //    cursor.movePosition(QTextCursor::StartOfLine);
 //    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);

    if(cursor.charFormat().fontWeight() == 400 )

   {
        QTextCharFormat format = cursor.charFormat();
        format.setFontWeight(QFont::Bold);
        cursor.mergeCharFormat(format);
    }
    if(cursor.charFormat().fontWeight() ==  700 )
       {
        QTextCharFormat unbold = cursor.charFormat();
        unbold.setFontWeight(400);
        cursor.mergeCharFormat(unbold);
  }

}

void MainWindow::on_actionSuperscript_triggered()
{

   QTextCursor cursor= ui->textEdit->textCursor();

   if(cursor.charFormat().verticalAlignment() == 0 )
   {
       QTextCharFormat sup;
       sup.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
       cursor.mergeCharFormat(sup);
   }
   if(cursor.charFormat().verticalAlignment() == 1)
   {
       QTextCharFormat normal;
       normal.setVerticalAlignment(QTextCharFormat::AlignNormal);
       cursor.mergeCharFormat(normal);
   }

}

void MainWindow::on_actionSubscript_triggered()
{
    QTextCursor cursor= ui->textEdit->textCursor();

    if(cursor.charFormat().verticalAlignment() == 0 )
    {
        QTextCharFormat sub;
        sub.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        cursor.mergeCharFormat(sub);
    }
    if(cursor.charFormat().verticalAlignment() == 2)
    {
        QTextCharFormat normal;
        normal.setVerticalAlignment(QTextCharFormat::AlignNormal);
        cursor.mergeCharFormat(normal);
    }

}

void MainWindow::on_actionAbout_Creator_triggered()
{
     Resume dialog;
     dialog.setModal(true);
     dialog.exec();
}

