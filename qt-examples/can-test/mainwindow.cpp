#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <string>
#include <atomic>
#include <functional>
#include <QTimerEvent>
#include <QMessageBox>
#include <QRegularExpression>

QStandardItemModel *prepareModel();
QStandardItem *prepareItem(const QString& data);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_counterPrimary(0), m_counterSecondary(0)
{
    ui->setupUi(this);

    this->setWindowTitle("CAN TEST");

    connect(this, &MainWindow::frameCanPrimaryReceived, this, &MainWindow::processCanPrimaryFrame);
    connect(this, &MainWindow::frameCanSecondaryReceived, this, &MainWindow::processCanSecondaryFrame);

    connect(ui->lineEditPrimaryId, &QLineEdit::textChanged, this, &MainWindow::onIdLineEditChanged);
    connect(ui->lineEditSecondaryId, &QLineEdit::textChanged, this, &MainWindow::onIdLineEditChanged);

    connect(ui->lineEditPrimaryDataHex, &QLineEdit::textChanged, this, &MainWindow::onHexLineEditChanged);
    connect(ui->lineEditSecondaryDataHex, &QLineEdit::textChanged, this, &MainWindow::onHexLineEditChanged);

    connect(ui->lineEditPrimaryDataAscii, &QLineEdit::textChanged, this, &MainWindow::onAsciiLineEditChanged);
    connect(ui->lineEditSecondaryDataAscii, &QLineEdit::textChanged, this, &MainWindow::onAsciiLineEditChanged);

    receivePrimaryModel = prepareModel();

    ui->tableViewPrimary->setModel(receivePrimaryModel);
    ui->tableViewPrimary->verticalHeader()->hide();
    ui->tableViewPrimary->horizontalHeader()->setStretchLastSection(true);

    receiveSecondaryModel = prepareModel();

    ui->tableViewSecondary->setModel(receiveSecondaryModel);
    ui->tableViewSecondary->verticalHeader()->hide();
    ui->tableViewSecondary->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QStandardItemModel *prepareModel() {

    QStandardItemModel *model = new QStandardItemModel(0, 4);

    model->setHeaderData(0, Qt::Horizontal, QVariant("NO."));
    model->setHeaderData(1, Qt::Horizontal, QVariant("ID"));
    model->setHeaderData(2, Qt::Horizontal, QVariant("LENGHT"));
    model->setHeaderData(3, Qt::Horizontal, QVariant("DATA"));

    return model;
}

QStandardItem *prepareItem(const QString& data) {

    auto item = new QStandardItem(data);
    item->setTextAlignment(Qt::AlignCenter);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

    return item;
}

void MainWindow::message(const QString &string)
{
    QMessageBox::warning(this, this->windowTitle(), string);
}


void MainWindow::on_pushButtonPrimaryOpen_toggled(bool checked)
{
    if (checked) {

        canPrimary.setDeviceName(ui->lineEditPrimaryInterface->text().toStdString());

        if (canPrimary.open()) {

            canPrimary.setReceiveCallback( [this] {

                emit this->frameCanPrimaryReceived();

            } );

            ui->pushButtonPrimaryOpen->setText("CLOSE");

            ui->groupBoxPrimaryReceive->setEnabled(true);
            ui->groupBoxPrimaryTransmit->setEnabled(true);

            ui->lineEditPrimaryInterface->setEnabled(false);
        }
        else {

            message(canPrimary.errorString().c_str());
        }
    }
    else {

        canPrimary.close();

        ui->pushButtonPrimaryOpen->setText("OPEN");


        ui->groupBoxPrimaryReceive->setEnabled(false);
        ui->groupBoxPrimaryTransmit->setEnabled(false);

        ui->lineEditPrimaryInterface->setEnabled(true);
    }
}

void MainWindow::on_pushButtonSecondaryOpen_toggled(bool checked)
{
    if (checked) {

        canSecondary.setDeviceName(ui->lineEditSecondaryInterface->text().toStdString());

        if (canSecondary.open()) {

            canSecondary.setReceiveCallback( [this] {

                emit this->frameCanSecondaryReceived();

            } );

            ui->pushButtonSecondaryOpen->setText("CLOSE");

            ui->groupBoxSecondaryReceive->setEnabled(true);
            ui->groupBoxSecondaryTransmit->setEnabled(true);

            ui->lineEditSecondaryInterface->setEnabled(false);
        }
        else {

            message(canSecondary.errorString().c_str());
        }
    }
    else {

        canSecondary.close();

        ui->pushButtonSecondaryOpen->setText("OPEN");


        ui->groupBoxSecondaryReceive->setEnabled(false);
        ui->groupBoxSecondaryTransmit->setEnabled(false);

        ui->lineEditSecondaryInterface->setEnabled(true);
    }
}

void MainWindow::on_pushButtonPrimarySendAscii_clicked()
{
    visor::frameid_t id = ui->lineEditPrimaryId->text().toInt(nullptr, 16);

    std::string data = ui->lineEditPrimaryDataAscii->text().toStdString();

    bool isExtended = ui->checkBoxPrimaryExtended->isChecked();

    try {

        visor::CanFrame frame (id, data, isExtended);

        if (canPrimary.writeFrame(frame) == false) {

            message(canPrimary.errorString().c_str());
        }
    }
    catch (std::length_error& e) {

        message(e.what());
    }
}

void MainWindow::on_pushButtonSecondarySendAscii_clicked()
{
    visor::frameid_t id = ui->lineEditSecondaryId->text().toInt(nullptr, 16);

    std::string data = ui->lineEditSecondaryDataAscii->text().toStdString();

    bool isExtended = ui->checkBoxSecondaryExtended->isChecked();

    try {

        if (canSecondary.writeFrame(visor::CanFrame(id, data, isExtended)) == false) {

            message(canSecondary.errorString().c_str());
        }
    }
    catch (std::length_error& e) {

        message(e.what());
    }
}

std::vector<uint8_t> getVector(const QString& data) {

    std::vector<uint8_t> store;

    int counter = 0;

    QString temp;

    for (auto& it : data) {

        temp += it;

        if (counter % 2 != 0) {

            store.push_back(static_cast<uint8_t>(temp.toInt(nullptr, 16)));

            temp.clear();
        }

        counter++;
    }

    if (!temp.isEmpty()) {

        store.push_back(static_cast<uint8_t>(temp.toInt(nullptr, 16)));
    }

    return store;
}

void MainWindow::on_pushButtonPrimarySendHex_clicked()
{
    visor::frameid_t id = ui->lineEditPrimaryId->text().toInt(nullptr, 16);

    std::vector<uint8_t> data = getVector(ui->lineEditPrimaryDataHex->text());

    bool isExtended = ui->checkBoxPrimaryExtended->isChecked();

    try {

        if (canPrimary.writeFrame(visor::CanFrame(id, data, isExtended)) == false) {

            message(canPrimary.errorString().c_str());
        }
    }
    catch (std::length_error& e) {

        message(e.what());
    }
}

void MainWindow::on_pushButtonSecondarySendHex_clicked()
{
    visor::frameid_t id = ui->lineEditSecondaryId->text().toInt(nullptr, 16);

    std::vector<uint8_t> data = getVector(ui->lineEditSecondaryDataHex->text());

    bool isExtended = ui->checkBoxSecondaryExtended->isChecked();

    try {

        if (canSecondary.writeFrame(visor::CanFrame(id, data, isExtended)) == false) {

            message(canSecondary.errorString().c_str());
        }
    }
    catch (std::length_error& e) {

        message(e.what());
    }
}

void MainWindow::onHexLineEditChanged(const QString& text)
{
    auto *lineEdit = qobject_cast<QLineEdit*>(sender());

    if (lineEdit == nullptr) {

        return;
    }

    QRegularExpression reg("^[0-9A-F]{0,16}$");

    auto regMatch = reg.match(text);

    auto set = text;

    if(!regMatch.hasMatch()) {

        lineEdit->setText(set.remove(text.length() - 1, 1));
    }
}

void MainWindow::onAsciiLineEditChanged(const QString& text)
{
    auto *lineEdit = qobject_cast<QLineEdit*>(sender());

    if (lineEdit == nullptr) {

        return;
    }

    auto set = text;

    if (text.length() > 8) {

        lineEdit->setText(set.remove(text.length() - 1, 1));
    }
}

void MainWindow::onIdLineEditChanged(const QString& text)
{
    auto *lineEdit = qobject_cast<QLineEdit*>(sender());

    if (lineEdit == nullptr) {

        return;
    }

    QRegularExpression reg("^[0-9A-F]{0,8}$");

    auto regMatch = reg.match(text);

    auto set = text;

    if(!regMatch.hasMatch()) {

        lineEdit->setText(set.remove(text.length() - 1, 1));
    }
}

void MainWindow::on_pushButtonPrimaryClear_clicked()
{
    m_counterPrimary = 0;

    receivePrimaryModel->removeRows(0, receivePrimaryModel->rowCount());
}

void MainWindow::on_pushButtonSecondaryClear_clicked()
{
    m_counterSecondary = 0;

    receiveSecondaryModel->removeRows(0, receiveSecondaryModel->rowCount());
}


QString convertVectorToString(const std::vector<uint8_t> &vect, bool hexMode) {

    QString result;

    for (const uint8_t& byte : vect) {

        if (hexMode) {

            result.append(QString::number(byte, 16).toUpper().rightJustified(2, '0'));
        }
        else {

            result.append(QChar(byte));
        }
    }

    return result;
}

void MainWindow::processCanPrimaryFrame()
{
    visor::CanFrame frame;

    if (canPrimary.readFrame(frame) == false) {

        qDebug() << canPrimary.errorString().c_str();

        return;
    }

    auto isHex = ui->radioButtonPrimaryHex->isChecked();

    auto&& count = QString::number(++m_counterPrimary);

    auto&& id = QString::number(frame.frameId(), 16).toUpper().rightJustified(frame.isExtendedFrame() ? 8 : 3, '0');

    auto&& size = QString::number(frame.length());

    auto&& data = convertVectorToString(frame.data(), isHex);

    QList<QStandardItem*> items;

    items << prepareItem(count) << prepareItem(id) << prepareItem(size) << prepareItem(data);

    receivePrimaryModel->appendRow(items);

    ui->tableViewPrimary->scrollToBottom();
}

void MainWindow::processCanSecondaryFrame()
{
    visor::CanFrame frame;

    if (canSecondary.readFrame(frame) == false) {

        qDebug() << canSecondary.errorString().c_str();

        return;
    }

    auto isHex = ui->radioButtonSecondaryHex->isChecked();

    auto&& count = QString::number(++m_counterSecondary);

    auto&& id = QString::number(frame.frameId(), 16).toUpper().rightJustified(frame.isExtendedFrame() ? 8 : 3, '0');

    auto&& size = QString::number(frame.length());

    auto&& data = convertVectorToString(frame.data(), isHex);

    QList<QStandardItem*> items;

    items << prepareItem(count) << prepareItem(id) << prepareItem(size) << prepareItem(data);

    receiveSecondaryModel->appendRow(items);

    ui->tableViewSecondary->scrollToBottom();

}
