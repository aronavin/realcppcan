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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QFrame *framePrimary;
    QGridLayout *gridLayout;
    QGroupBox *groupBoxPrimaryConnect;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPrimaryInterface;
    QLineEdit *lineEditPrimaryInterface;
    QPushButton *pushButtonPrimaryOpen;
    QGroupBox *groupBoxPrimaryReceive;
    QGridLayout *gridLayout_4;
    QTableView *tableViewPrimary;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButtonPrimaryAscii;
    QRadioButton *radioButtonPrimaryHex;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonPrimaryClear;
    QGroupBox *groupBoxPrimaryTransmit;
    QGridLayout *gridLayout_2;
    QLabel *labelPrimaryId;
    QLineEdit *lineEditPrimaryId;
    QCheckBox *checkBoxPrimaryExtended;
    QLabel *labelPrimaryDataAscii;
    QLineEdit *lineEditPrimaryDataAscii;
    QPushButton *pushButtonPrimarySendAscii;
    QLabel *labelPrimaryDataHex;
    QLineEdit *lineEditPrimaryDataHex;
    QPushButton *pushButtonPrimarySendHex;
    QFrame *frameSecondary;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxSecondaryConnect;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelSecondaryInterface;
    QLineEdit *lineEditSecondaryInterface;
    QPushButton *pushButtonSecondaryOpen;
    QGroupBox *groupBoxSecondaryReceive;
    QGridLayout *gridLayout_5;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButtonSecondaryAscii;
    QRadioButton *radioButtonSecondaryHex;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonSecondaryClear;
    QTableView *tableViewSecondary;
    QGroupBox *groupBoxSecondaryTransmit;
    QGridLayout *gridLayout_6;
    QLabel *labelSecondaryId;
    QLineEdit *lineEditSecondaryId;
    QCheckBox *checkBoxSecondaryExtended;
    QLabel *labelSecondaryDataAscii;
    QLineEdit *lineEditSecondaryDataAscii;
    QPushButton *pushButtonSecondarySendAscii;
    QLabel *labelSecondaryDataHex;
    QLineEdit *lineEditSecondaryDataHex;
    QPushButton *pushButtonSecondarySendHex;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1198, 698);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        framePrimary = new QFrame(centralwidget);
        framePrimary->setObjectName(QString::fromUtf8("framePrimary"));
        framePrimary->setFrameShape(QFrame::StyledPanel);
        framePrimary->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(framePrimary);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBoxPrimaryConnect = new QGroupBox(framePrimary);
        groupBoxPrimaryConnect->setObjectName(QString::fromUtf8("groupBoxPrimaryConnect"));
        groupBoxPrimaryConnect->setMinimumSize(QSize(0, 75));
        groupBoxPrimaryConnect->setMaximumSize(QSize(16777215, 75));
        groupBoxPrimaryConnect->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"	color: #5f5290;\n"
"	border: 1px solid black;\n"
"}\n"
"QGroupBox::title {\n"
"\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top centre;\n"
"}\n"
"\n"
"QGroupBox::disabled {\n"
"\n"
"	color: #b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        horizontalLayout = new QHBoxLayout(groupBoxPrimaryConnect);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 0, 15, 9);
        labelPrimaryInterface = new QLabel(groupBoxPrimaryConnect);
        labelPrimaryInterface->setObjectName(QString::fromUtf8("labelPrimaryInterface"));
        labelPrimaryInterface->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        horizontalLayout->addWidget(labelPrimaryInterface);

        lineEditPrimaryInterface = new QLineEdit(groupBoxPrimaryConnect);
        lineEditPrimaryInterface->setObjectName(QString::fromUtf8("lineEditPrimaryInterface"));
        lineEditPrimaryInterface->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(10);
        lineEditPrimaryInterface->setFont(font);
        lineEditPrimaryInterface->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditPrimaryInterface->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEditPrimaryInterface);

        pushButtonPrimaryOpen = new QPushButton(groupBoxPrimaryConnect);
        pushButtonPrimaryOpen->setObjectName(QString::fromUtf8("pushButtonPrimaryOpen"));
        pushButtonPrimaryOpen->setMinimumSize(QSize(100, 35));
        pushButtonPrimaryOpen->setFocusPolicy(Qt::NoFocus);
        pushButtonPrimaryOpen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));
        pushButtonPrimaryOpen->setCheckable(true);

        horizontalLayout->addWidget(pushButtonPrimaryOpen);


        gridLayout->addWidget(groupBoxPrimaryConnect, 0, 0, 1, 1);

        groupBoxPrimaryReceive = new QGroupBox(framePrimary);
        groupBoxPrimaryReceive->setObjectName(QString::fromUtf8("groupBoxPrimaryReceive"));
        groupBoxPrimaryReceive->setEnabled(false);
        groupBoxPrimaryReceive->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"	color: #5f5290;\n"
"	border: 1px solid black;\n"
"}\n"
"QGroupBox::title {\n"
"\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top centre;\n"
"}\n"
"\n"
"QGroupBox::disabled {\n"
"\n"
"	color: #b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        gridLayout_4 = new QGridLayout(groupBoxPrimaryReceive);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(6);
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        tableViewPrimary = new QTableView(groupBoxPrimaryReceive);
        tableViewPrimary->setObjectName(QString::fromUtf8("tableViewPrimary"));
        tableViewPrimary->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"	border:1px solid black;\n"
"}\n"
"\n"
"QTableView::disabled {\n"
"\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        tableViewPrimary->setShowGrid(false);
        tableViewPrimary->horizontalHeader()->setCascadingSectionResizes(true);

        gridLayout_4->addWidget(tableViewPrimary, 0, 0, 1, 1);

        frame_2 = new QFrame(groupBoxPrimaryReceive);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"\n"
"	border:none;\n"
"}\n"
"\n"
"QFrame::disabled {\n"
"	border:none;\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        radioButtonPrimaryAscii = new QRadioButton(frame_2);
        radioButtonPrimaryAscii->setObjectName(QString::fromUtf8("radioButtonPrimaryAscii"));
        radioButtonPrimaryAscii->setFocusPolicy(Qt::NoFocus);
        radioButtonPrimaryAscii->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QRadioButton::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));
        radioButtonPrimaryAscii->setChecked(true);

        horizontalLayout_6->addWidget(radioButtonPrimaryAscii);

        radioButtonPrimaryHex = new QRadioButton(frame_2);
        radioButtonPrimaryHex->setObjectName(QString::fromUtf8("radioButtonPrimaryHex"));
        radioButtonPrimaryHex->setFocusPolicy(Qt::NoFocus);
        radioButtonPrimaryHex->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QRadioButton::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        horizontalLayout_6->addWidget(radioButtonPrimaryHex);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButtonPrimaryClear = new QPushButton(frame_2);
        pushButtonPrimaryClear->setObjectName(QString::fromUtf8("pushButtonPrimaryClear"));
        pushButtonPrimaryClear->setMinimumSize(QSize(100, 35));
        pushButtonPrimaryClear->setMaximumSize(QSize(100, 16777215));
        pushButtonPrimaryClear->setFocusPolicy(Qt::NoFocus);
        pushButtonPrimaryClear->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));

        horizontalLayout_6->addWidget(pushButtonPrimaryClear);


        gridLayout_4->addWidget(frame_2, 2, 0, 1, 2);


        gridLayout->addWidget(groupBoxPrimaryReceive, 2, 0, 1, 1);

        groupBoxPrimaryTransmit = new QGroupBox(framePrimary);
        groupBoxPrimaryTransmit->setObjectName(QString::fromUtf8("groupBoxPrimaryTransmit"));
        groupBoxPrimaryTransmit->setEnabled(false);
        groupBoxPrimaryTransmit->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"	color: #5f5290;\n"
"	border: 1px solid black;\n"
"}\n"
"QGroupBox::title {\n"
"\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top centre;\n"
"}\n"
"\n"
"QGroupBox::disabled {\n"
"\n"
"	color: #b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        groupBoxPrimaryTransmit->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBoxPrimaryTransmit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(15);
        gridLayout_2->setContentsMargins(15, 0, 15, 9);
        labelPrimaryId = new QLabel(groupBoxPrimaryTransmit);
        labelPrimaryId->setObjectName(QString::fromUtf8("labelPrimaryId"));
        labelPrimaryId->setMinimumSize(QSize(80, 0));
        labelPrimaryId->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_2->addWidget(labelPrimaryId, 0, 0, 1, 1);

        lineEditPrimaryId = new QLineEdit(groupBoxPrimaryTransmit);
        lineEditPrimaryId->setObjectName(QString::fromUtf8("lineEditPrimaryId"));
        lineEditPrimaryId->setMinimumSize(QSize(160, 35));
        lineEditPrimaryId->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditPrimaryId->setMaxLength(32767);
        lineEditPrimaryId->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditPrimaryId, 0, 1, 1, 1);

        checkBoxPrimaryExtended = new QCheckBox(groupBoxPrimaryTransmit);
        checkBoxPrimaryExtended->setObjectName(QString::fromUtf8("checkBoxPrimaryExtended"));
        checkBoxPrimaryExtended->setMinimumSize(QSize(0, 35));
        checkBoxPrimaryExtended->setFocusPolicy(Qt::NoFocus);
        checkBoxPrimaryExtended->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QCheckBox::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_2->addWidget(checkBoxPrimaryExtended, 0, 2, 1, 1);

        labelPrimaryDataAscii = new QLabel(groupBoxPrimaryTransmit);
        labelPrimaryDataAscii->setObjectName(QString::fromUtf8("labelPrimaryDataAscii"));
        labelPrimaryDataAscii->setMinimumSize(QSize(80, 0));
        labelPrimaryDataAscii->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_2->addWidget(labelPrimaryDataAscii, 1, 0, 1, 1);

        lineEditPrimaryDataAscii = new QLineEdit(groupBoxPrimaryTransmit);
        lineEditPrimaryDataAscii->setObjectName(QString::fromUtf8("lineEditPrimaryDataAscii"));
        lineEditPrimaryDataAscii->setMinimumSize(QSize(160, 35));
        lineEditPrimaryDataAscii->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditPrimaryDataAscii->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditPrimaryDataAscii, 1, 1, 1, 1);

        pushButtonPrimarySendAscii = new QPushButton(groupBoxPrimaryTransmit);
        pushButtonPrimarySendAscii->setObjectName(QString::fromUtf8("pushButtonPrimarySendAscii"));
        pushButtonPrimarySendAscii->setMinimumSize(QSize(100, 35));
        pushButtonPrimarySendAscii->setMaximumSize(QSize(100, 35));
        pushButtonPrimarySendAscii->setFocusPolicy(Qt::NoFocus);
        pushButtonPrimarySendAscii->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));

        gridLayout_2->addWidget(pushButtonPrimarySendAscii, 1, 2, 1, 1);

        labelPrimaryDataHex = new QLabel(groupBoxPrimaryTransmit);
        labelPrimaryDataHex->setObjectName(QString::fromUtf8("labelPrimaryDataHex"));
        labelPrimaryDataHex->setMinimumSize(QSize(80, 0));
        labelPrimaryDataHex->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_2->addWidget(labelPrimaryDataHex, 2, 0, 1, 1);

        lineEditPrimaryDataHex = new QLineEdit(groupBoxPrimaryTransmit);
        lineEditPrimaryDataHex->setObjectName(QString::fromUtf8("lineEditPrimaryDataHex"));
        lineEditPrimaryDataHex->setMinimumSize(QSize(160, 35));
        lineEditPrimaryDataHex->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditPrimaryDataHex->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditPrimaryDataHex, 2, 1, 1, 1);

        pushButtonPrimarySendHex = new QPushButton(groupBoxPrimaryTransmit);
        pushButtonPrimarySendHex->setObjectName(QString::fromUtf8("pushButtonPrimarySendHex"));
        pushButtonPrimarySendHex->setMinimumSize(QSize(100, 35));
        pushButtonPrimarySendHex->setMaximumSize(QSize(100, 35));
        pushButtonPrimarySendHex->setFocusPolicy(Qt::NoFocus);
        pushButtonPrimarySendHex->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));

        gridLayout_2->addWidget(pushButtonPrimarySendHex, 2, 2, 1, 1);


        gridLayout->addWidget(groupBoxPrimaryTransmit, 1, 0, 1, 1);

        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 4);

        gridLayout_7->addWidget(framePrimary, 0, 0, 1, 1);

        frameSecondary = new QFrame(centralwidget);
        frameSecondary->setObjectName(QString::fromUtf8("frameSecondary"));
        frameSecondary->setFrameShape(QFrame::StyledPanel);
        frameSecondary->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frameSecondary);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxSecondaryConnect = new QGroupBox(frameSecondary);
        groupBoxSecondaryConnect->setObjectName(QString::fromUtf8("groupBoxSecondaryConnect"));
        groupBoxSecondaryConnect->setMinimumSize(QSize(0, 75));
        groupBoxSecondaryConnect->setMaximumSize(QSize(16777215, 75));
        groupBoxSecondaryConnect->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"	color: #5f5290;\n"
"	border: 1px solid black;\n"
"}\n"
"QGroupBox::title {\n"
"\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top centre;\n"
"}\n"
"\n"
"QGroupBox::disabled {\n"
"\n"
"	color: #b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(groupBoxSecondaryConnect);
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(15, 0, 15, 9);
        labelSecondaryInterface = new QLabel(groupBoxSecondaryConnect);
        labelSecondaryInterface->setObjectName(QString::fromUtf8("labelSecondaryInterface"));
        labelSecondaryInterface->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"}"));

        horizontalLayout_3->addWidget(labelSecondaryInterface);

        lineEditSecondaryInterface = new QLineEdit(groupBoxSecondaryConnect);
        lineEditSecondaryInterface->setObjectName(QString::fromUtf8("lineEditSecondaryInterface"));
        lineEditSecondaryInterface->setMinimumSize(QSize(0, 35));
        lineEditSecondaryInterface->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditSecondaryInterface->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEditSecondaryInterface);

        pushButtonSecondaryOpen = new QPushButton(groupBoxSecondaryConnect);
        pushButtonSecondaryOpen->setObjectName(QString::fromUtf8("pushButtonSecondaryOpen"));
        pushButtonSecondaryOpen->setMinimumSize(QSize(100, 35));
        pushButtonSecondaryOpen->setFocusPolicy(Qt::NoFocus);
        pushButtonSecondaryOpen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));
        pushButtonSecondaryOpen->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonSecondaryOpen);


        gridLayout_3->addWidget(groupBoxSecondaryConnect, 0, 0, 1, 1);

        groupBoxSecondaryReceive = new QGroupBox(frameSecondary);
        groupBoxSecondaryReceive->setObjectName(QString::fromUtf8("groupBoxSecondaryReceive"));
        groupBoxSecondaryReceive->setEnabled(false);
        groupBoxSecondaryReceive->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"	color: #5f5290;\n"
"	border: 1px solid black;\n"
"}\n"
"QGroupBox::title {\n"
"\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top centre;\n"
"}\n"
"\n"
"QGroupBox::disabled {\n"
"\n"
"	color: #b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        gridLayout_5 = new QGridLayout(groupBoxSecondaryReceive);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 5, 5, 5);
        frame_3 = new QFrame(groupBoxSecondaryReceive);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"\n"
"	border:none;\n"
"}\n"
"\n"
"QFrame::disabled {\n"
"	border:none;\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioButtonSecondaryAscii = new QRadioButton(frame_3);
        radioButtonSecondaryAscii->setObjectName(QString::fromUtf8("radioButtonSecondaryAscii"));
        radioButtonSecondaryAscii->setFocusPolicy(Qt::NoFocus);
        radioButtonSecondaryAscii->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QRadioButton::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));
        radioButtonSecondaryAscii->setChecked(true);

        horizontalLayout_7->addWidget(radioButtonSecondaryAscii);

        radioButtonSecondaryHex = new QRadioButton(frame_3);
        radioButtonSecondaryHex->setObjectName(QString::fromUtf8("radioButtonSecondaryHex"));
        radioButtonSecondaryHex->setFocusPolicy(Qt::NoFocus);
        radioButtonSecondaryHex->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QRadioButton::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        horizontalLayout_7->addWidget(radioButtonSecondaryHex);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        pushButtonSecondaryClear = new QPushButton(frame_3);
        pushButtonSecondaryClear->setObjectName(QString::fromUtf8("pushButtonSecondaryClear"));
        pushButtonSecondaryClear->setMinimumSize(QSize(100, 35));
        pushButtonSecondaryClear->setMaximumSize(QSize(100, 16777215));
        pushButtonSecondaryClear->setFocusPolicy(Qt::NoFocus);
        pushButtonSecondaryClear->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));

        horizontalLayout_7->addWidget(pushButtonSecondaryClear);


        gridLayout_5->addWidget(frame_3, 1, 0, 1, 2);

        tableViewSecondary = new QTableView(groupBoxSecondaryReceive);
        tableViewSecondary->setObjectName(QString::fromUtf8("tableViewSecondary"));
        tableViewSecondary->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"	border:1px solid black;\n"
"}\n"
"\n"
"QTableView::disabled {\n"
"\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        tableViewSecondary->setShowGrid(false);
        tableViewSecondary->horizontalHeader()->setCascadingSectionResizes(true);

        gridLayout_5->addWidget(tableViewSecondary, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxSecondaryReceive, 2, 0, 1, 1);

        groupBoxSecondaryTransmit = new QGroupBox(frameSecondary);
        groupBoxSecondaryTransmit->setObjectName(QString::fromUtf8("groupBoxSecondaryTransmit"));
        groupBoxSecondaryTransmit->setEnabled(false);
        groupBoxSecondaryTransmit->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"\n"
"	color: #5f5290;\n"
"	border: 1px solid black;\n"
"}\n"
"QGroupBox::title {\n"
"\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top centre;\n"
"}\n"
"\n"
"QGroupBox::disabled {\n"
"\n"
"	color: #b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"	border: 1px solid grey;\n"
"}"));
        groupBoxSecondaryTransmit->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBoxSecondaryTransmit);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(15);
        gridLayout_6->setContentsMargins(15, 0, 15, -1);
        labelSecondaryId = new QLabel(groupBoxSecondaryTransmit);
        labelSecondaryId->setObjectName(QString::fromUtf8("labelSecondaryId"));
        labelSecondaryId->setMinimumSize(QSize(80, 0));
        labelSecondaryId->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_6->addWidget(labelSecondaryId, 0, 0, 1, 1);

        lineEditSecondaryId = new QLineEdit(groupBoxSecondaryTransmit);
        lineEditSecondaryId->setObjectName(QString::fromUtf8("lineEditSecondaryId"));
        lineEditSecondaryId->setMinimumSize(QSize(160, 35));
        lineEditSecondaryId->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditSecondaryId->setMaxLength(32767);
        lineEditSecondaryId->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEditSecondaryId, 0, 1, 1, 1);

        checkBoxSecondaryExtended = new QCheckBox(groupBoxSecondaryTransmit);
        checkBoxSecondaryExtended->setObjectName(QString::fromUtf8("checkBoxSecondaryExtended"));
        checkBoxSecondaryExtended->setMinimumSize(QSize(0, 35));
        checkBoxSecondaryExtended->setFocusPolicy(Qt::NoFocus);
        checkBoxSecondaryExtended->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QCheckBox::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_6->addWidget(checkBoxSecondaryExtended, 0, 2, 1, 1);

        labelSecondaryDataAscii = new QLabel(groupBoxSecondaryTransmit);
        labelSecondaryDataAscii->setObjectName(QString::fromUtf8("labelSecondaryDataAscii"));
        labelSecondaryDataAscii->setMinimumSize(QSize(80, 0));
        labelSecondaryDataAscii->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_6->addWidget(labelSecondaryDataAscii, 1, 0, 1, 1);

        lineEditSecondaryDataAscii = new QLineEdit(groupBoxSecondaryTransmit);
        lineEditSecondaryDataAscii->setObjectName(QString::fromUtf8("lineEditSecondaryDataAscii"));
        lineEditSecondaryDataAscii->setMinimumSize(QSize(160, 35));
        lineEditSecondaryDataAscii->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditSecondaryDataAscii->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEditSecondaryDataAscii, 1, 1, 1, 1);

        pushButtonSecondarySendAscii = new QPushButton(groupBoxSecondaryTransmit);
        pushButtonSecondarySendAscii->setObjectName(QString::fromUtf8("pushButtonSecondarySendAscii"));
        pushButtonSecondarySendAscii->setMinimumSize(QSize(100, 35));
        pushButtonSecondarySendAscii->setMaximumSize(QSize(100, 35));
        pushButtonSecondarySendAscii->setFocusPolicy(Qt::NoFocus);
        pushButtonSecondarySendAscii->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));

        gridLayout_6->addWidget(pushButtonSecondarySendAscii, 1, 2, 1, 1);

        labelSecondaryDataHex = new QLabel(groupBoxSecondaryTransmit);
        labelSecondaryDataHex->setObjectName(QString::fromUtf8("labelSecondaryDataHex"));
        labelSecondaryDataHex->setMinimumSize(QSize(80, 0));
        labelSecondaryDataHex->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5f5290;\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"\n"
"	color:#b6b6b6;\n"
"	background-color: #e7e7e7;\n"
"}"));

        gridLayout_6->addWidget(labelSecondaryDataHex, 2, 0, 1, 1);

        lineEditSecondaryDataHex = new QLineEdit(groupBoxSecondaryTransmit);
        lineEditSecondaryDataHex->setObjectName(QString::fromUtf8("lineEditSecondaryDataHex"));
        lineEditSecondaryDataHex->setMinimumSize(QSize(160, 35));
        lineEditSecondaryDataHex->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"\n"
"	border:1px solid black;\n"
"	color: #000000;\n"
"}\n"
"\n"
"QLineEdit::disabled{\n"
"\n"
"	color:#b6b6b6;\n"
"	border: 1px solid #b6b6b6;\n"
"	\n"
"}"));
        lineEditSecondaryDataHex->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEditSecondaryDataHex, 2, 1, 1, 1);

        pushButtonSecondarySendHex = new QPushButton(groupBoxSecondaryTransmit);
        pushButtonSecondarySendHex->setObjectName(QString::fromUtf8("pushButtonSecondarySendHex"));
        pushButtonSecondarySendHex->setMinimumSize(QSize(100, 35));
        pushButtonSecondarySendHex->setMaximumSize(QSize(100, 35));
        pushButtonSecondarySendHex->setFocusPolicy(Qt::NoFocus);
        pushButtonSecondarySendHex->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#5f5290;\n"
"	color:#ffffff;\n"
"	border:2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#3f3761;\n"
"	color:#ffffff;\n"
"	border: 2px solid #3f3761;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:transparent;\n"
"	color:#000000;\n"
"	border: 2px solid #5f5290;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-color:#cccccc;\n"
"	color:#959595;\n"
"	border: 2px solid #cccccc;\n"
"}"));

        gridLayout_6->addWidget(pushButtonSecondarySendHex, 2, 2, 1, 1);


        gridLayout_3->addWidget(groupBoxSecondaryTransmit, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 4);

        gridLayout_7->addWidget(frameSecondary, 0, 1, 1, 1);

        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxPrimaryConnect->setTitle(QCoreApplication::translate("MainWindow", "CONNECT", nullptr));
        labelPrimaryInterface->setText(QCoreApplication::translate("MainWindow", "INTERFACE ", nullptr));
        lineEditPrimaryInterface->setText(QCoreApplication::translate("MainWindow", "vcan0", nullptr));
        pushButtonPrimaryOpen->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        groupBoxPrimaryReceive->setTitle(QCoreApplication::translate("MainWindow", "RECEIVE", nullptr));
        radioButtonPrimaryAscii->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        radioButtonPrimaryHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        pushButtonPrimaryClear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        groupBoxPrimaryTransmit->setTitle(QCoreApplication::translate("MainWindow", "TRANSMIT", nullptr));
        labelPrimaryId->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEditPrimaryId->setInputMask(QString());
        lineEditPrimaryId->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        checkBoxPrimaryExtended->setText(QCoreApplication::translate("MainWindow", "EXTENDED", nullptr));
        labelPrimaryDataAscii->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        lineEditPrimaryDataAscii->setInputMask(QString());
        lineEditPrimaryDataAscii->setText(QCoreApplication::translate("MainWindow", "hellocan", nullptr));
        pushButtonPrimarySendAscii->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        labelPrimaryDataHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        lineEditPrimaryDataHex->setInputMask(QString());
        lineEditPrimaryDataHex->setText(QCoreApplication::translate("MainWindow", "FFFFFFFFFFFFFFFF", nullptr));
        pushButtonPrimarySendHex->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        groupBoxSecondaryConnect->setTitle(QCoreApplication::translate("MainWindow", "CONNECT", nullptr));
        labelSecondaryInterface->setText(QCoreApplication::translate("MainWindow", "INTERFACE ", nullptr));
        lineEditSecondaryInterface->setText(QCoreApplication::translate("MainWindow", "vcan1", nullptr));
        pushButtonSecondaryOpen->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        groupBoxSecondaryReceive->setTitle(QCoreApplication::translate("MainWindow", "RECEIVE", nullptr));
        radioButtonSecondaryAscii->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        radioButtonSecondaryHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        pushButtonSecondaryClear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        groupBoxSecondaryTransmit->setTitle(QCoreApplication::translate("MainWindow", "TRANSMIT", nullptr));
        labelSecondaryId->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEditSecondaryId->setInputMask(QString());
        lineEditSecondaryId->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        checkBoxSecondaryExtended->setText(QCoreApplication::translate("MainWindow", "EXTENDED", nullptr));
        labelSecondaryDataAscii->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        lineEditSecondaryDataAscii->setInputMask(QString());
        lineEditSecondaryDataAscii->setText(QCoreApplication::translate("MainWindow", "hellocan", nullptr));
        pushButtonSecondarySendAscii->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        labelSecondaryDataHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        lineEditSecondaryDataHex->setInputMask(QString());
        lineEditSecondaryDataHex->setText(QCoreApplication::translate("MainWindow", "FFFFFFFFFFFFFFFF", nullptr));
        pushButtonSecondarySendHex->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
