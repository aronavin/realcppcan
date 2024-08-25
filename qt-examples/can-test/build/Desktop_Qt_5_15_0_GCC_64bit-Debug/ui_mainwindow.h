/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditTransmitCan1;
    QLabel *label_3;
    QPushButton *buttonSendCan1;
    QTextEdit *textEditReceiveCan1;
    QPushButton *buttonClearCan1;
    QLabel *label_5;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEditTransmitCan0;
    QPushButton *buttonSendCan0;
    QTextEdit *textEditReceiveCan0;
    QPushButton *buttonClearCan0;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(0, 45));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 1, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEditTransmitCan1 = new QLineEdit(frame_2);
        lineEditTransmitCan1->setObjectName(QString::fromUtf8("lineEditTransmitCan1"));
        lineEditTransmitCan1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditTransmitCan1, 0, 1, 1, 3);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        buttonSendCan1 = new QPushButton(frame_2);
        buttonSendCan1->setObjectName(QString::fromUtf8("buttonSendCan1"));

        gridLayout_2->addWidget(buttonSendCan1, 0, 4, 1, 1);

        textEditReceiveCan1 = new QTextEdit(frame_2);
        textEditReceiveCan1->setObjectName(QString::fromUtf8("textEditReceiveCan1"));

        gridLayout_2->addWidget(textEditReceiveCan1, 1, 1, 1, 4);

        buttonClearCan1 = new QPushButton(frame_2);
        buttonClearCan1->setObjectName(QString::fromUtf8("buttonClearCan1"));

        gridLayout_2->addWidget(buttonClearCan1, 2, 4, 1, 1);


        gridLayout_3->addWidget(frame_2, 1, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(0, 45));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEditTransmitCan0 = new QLineEdit(frame);
        lineEditTransmitCan0->setObjectName(QString::fromUtf8("lineEditTransmitCan0"));
        lineEditTransmitCan0->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditTransmitCan0, 0, 1, 1, 2);

        buttonSendCan0 = new QPushButton(frame);
        buttonSendCan0->setObjectName(QString::fromUtf8("buttonSendCan0"));

        gridLayout->addWidget(buttonSendCan0, 0, 3, 1, 1);

        textEditReceiveCan0 = new QTextEdit(frame);
        textEditReceiveCan0->setObjectName(QString::fromUtf8("textEditReceiveCan0"));

        gridLayout->addWidget(textEditReceiveCan0, 1, 1, 1, 3);

        buttonClearCan0 = new QPushButton(frame);
        buttonClearCan0->setObjectName(QString::fromUtf8("buttonClearCan0"));

        gridLayout->addWidget(buttonClearCan0, 3, 3, 1, 1);


        gridLayout_3->addWidget(frame, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "CAN 1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Received : ", nullptr));
        lineEditTransmitCan1->setInputMask(QCoreApplication::translate("MainWindow", "HHHHHHHH", nullptr));
        lineEditTransmitCan1->setText(QCoreApplication::translate("MainWindow", "12345678", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Transmit : ", nullptr));
        buttonSendCan1->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        buttonClearCan1->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CAN 0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Transmit : ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Received : ", nullptr));
        lineEditTransmitCan0->setInputMask(QCoreApplication::translate("MainWindow", "HHHHHHHH", nullptr));
        lineEditTransmitCan0->setText(QCoreApplication::translate("MainWindow", "12345678", nullptr));
        buttonSendCan0->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        buttonClearCan0->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
