#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../include/visorcan.h"

#include <QMutexLocker>
#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

    void frameCanPrimaryReceived();

    void frameCanSecondaryReceived();

private slots:

    void on_pushButtonPrimaryOpen_toggled(bool checked);

    void on_pushButtonSecondaryOpen_toggled(bool checked);

    void on_pushButtonPrimaryClear_clicked();

    void on_pushButtonSecondaryClear_clicked();


    void processCanPrimaryFrame();

    void processCanSecondaryFrame();

    void on_pushButtonPrimarySendHex_clicked();

    void on_pushButtonPrimarySendAscii_clicked();

    void on_pushButtonSecondarySendAscii_clicked();

    void on_pushButtonSecondarySendHex_clicked();


    void onIdLineEditChanged(const QString& text);

    void onHexLineEditChanged(const QString& text);

    void onAsciiLineEditChanged(const QString& text);

private:

    void message(const QString &string);

private:
    Ui::MainWindow *ui;

private:

    visor::CanBus canPrimary;

    visor::CanBus canSecondary;

    uint64_t m_counterPrimary;

    uint64_t m_counterSecondary;

    QStandardItemModel *receivePrimaryModel;

    QStandardItemModel *receiveSecondaryModel;

};
#endif // MAINWINDOW_H
