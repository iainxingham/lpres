#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QDesktopServices>
#include <QClipboard>
#include <QUrl>

#include <memory>

#include "utils.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&barcodeScene);

    m_Barcode = new Code128Item();
    m_Barcode->setWidth( 300 );
    m_Barcode->setHeight( 120 );
    m_Barcode->setPos(0,0);
    barcodeScene.addItem( m_Barcode );
    barcodeScene.update();
    m_Barcode->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}


void MainWindow::on_barcodeButton_clicked()
{
    if(validate_rxr(ui->rxrBox->text())) {
        m_Barcode->setText(clean_rxr(ui->rxrBox->text()));
    }

    else {
        QMessageBox msg(this);

        msg.setWindowTitle("Error");
        msg.setText("Invalid RXR number");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();

        m_Barcode->setText("");
    }

    barcodeScene.update();
    m_Barcode->update();
}


void MainWindow::on_clearButton_clicked()
{
    ui->rxrBox->setText("");
    m_Barcode->setText("");
    barcodeScene.update();
    m_Barcode->update();
}


void MainWindow::on_lpresButton_clicked()
{
    if(validate_rxr(ui->rxrBox->text())) {
        QDesktopServices::openUrl(QUrl("http://elht-app-web1/lpres/openviewer/?rxr=&person=" + clean_rxr(ui->rxrBox->text()), QUrl::StrictMode));
    }

    else {
        QMessageBox msg(this);

        msg.setWindowTitle("Error");
        msg.setText("Invalid RXR number - check this first");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}


void MainWindow::on_pacsButton_clicked()
{
    if(validate_rxr(ui->rxrBox->text())) {
        QDesktopServices::openUrl(QUrl("http://rxrsv0uniview.xelht.nhs.uk/uinview/#/search?searchQuery=" + clean_mrn(ui->rxrBox->text()), QUrl::StrictMode));
    }

    else {
        QMessageBox msg(this);

        msg.setWindowTitle("Error");
        msg.setText("Invalid RXR number - check this first");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}


void MainWindow::on_clipboardButton_clicked()
{
    if(validate_rxr(ui->rxrBox->text())) {
        QClipboard *clip = QGuiApplication::clipboard();
        clip->setText(clean_rxr(ui->rxrBox->text()));
    }

    else {
        QMessageBox msg(this);

        msg.setWindowTitle("Error");
        msg.setText("Invalid RXR number - check this first");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}


void MainWindow::on_actionAbout_triggered()
{
    std::unique_ptr<About> about = std::make_unique<About>(this);

    about->exec();
}

