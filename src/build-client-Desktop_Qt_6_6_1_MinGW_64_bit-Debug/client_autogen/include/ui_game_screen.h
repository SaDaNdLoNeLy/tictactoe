/********************************************************************************
** Form generated from reading UI file 'game_screen.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_SCREEN_H
#define UI_GAME_SCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game_Screen
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_11;
    QFrame *gridFrame_6;
    QGridLayout *gridLayout_6;
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QFrame *line_6;
    QFrame *gridFrame_7;
    QGridLayout *gridLayout_7;
    QFrame *line;
    QFrame *gridFrame_9;
    QGridLayout *gridLayout_9;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *gridFrame_2;
    QGridLayout *gridLayout_2;
    QFrame *line_5;
    QFrame *gridFrame_3;
    QGridLayout *gridLayout_3;
    QFrame *gridFrame_4;
    QGridLayout *gridLayout_4;
    QFrame *line_7;
    QFrame *gridFrame_5;
    QGridLayout *gridLayout_5;
    QFrame *gridFrame_8;
    QGridLayout *gridLayout_8;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *player1;
    QPushButton *avatar;
    QPushButton *exit;
    QLabel *elo;
    QLabel *name;
    QLabel *win;
    QFrame *player2;
    QPushButton *avatar_2;
    QLabel *elo_2;
    QLabel *name_2;
    QLabel *win_2;
    QLabel *timer;
    QPushButton *readyButton;
    QLabel *notification;
    QFrame *surrenderfr;
    QLabel *label;
    QPushButton *yes;
    QPushButton *no;

    void setupUi(QMainWindow *Game_Screen)
    {
        if (Game_Screen->objectName().isEmpty())
            Game_Screen->setObjectName("Game_Screen");
        Game_Screen->resize(720, 430);
        Game_Screen->setStyleSheet(QString::fromUtf8("#player1, #player2{\n"
"	border: 1px solid black;\n"
"}\n"
"#randomFrame{\n"
"	border: 1px solid black;\n"
"}\n"
"#textRandom{\n"
"	text-align: center;\n"
"}"));
        centralwidget = new QWidget(Game_Screen);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#notification{\n"
"	background: #D3D3D3;\n"
"	color: yellow;\n"
"	font-size: 30px;\n"
"}"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(160, 0, 401, 431));
        gridLayout_11 = new QGridLayout(layoutWidget);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        gridFrame_6 = new QFrame(layoutWidget);
        gridFrame_6->setObjectName("gridFrame_6");
        gridLayout_6 = new QGridLayout(gridFrame_6);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_6, 3, 4, 1, 1);

        gridFrame = new QFrame(layoutWidget);
        gridFrame->setObjectName("gridFrame");
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame, 0, 0, 1, 1);

        line_6 = new QFrame(layoutWidget);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_6, 3, 3, 1, 1);

        gridFrame_7 = new QFrame(layoutWidget);
        gridFrame_7->setObjectName("gridFrame_7");
        gridLayout_7 = new QGridLayout(gridFrame_7);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_7, 6, 0, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line, 1, 0, 1, 5);

        gridFrame_9 = new QFrame(layoutWidget);
        gridFrame_9->setObjectName("gridFrame_9");
        gridLayout_9 = new QGridLayout(gridFrame_9);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_9, 6, 4, 1, 1);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_2, 4, 0, 1, 5);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_3, 0, 1, 1, 1);

        gridFrame_2 = new QFrame(layoutWidget);
        gridFrame_2->setObjectName("gridFrame_2");
        gridLayout_2 = new QGridLayout(gridFrame_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_2, 0, 2, 1, 1);

        line_5 = new QFrame(layoutWidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_5, 3, 1, 1, 1);

        gridFrame_3 = new QFrame(layoutWidget);
        gridFrame_3->setObjectName("gridFrame_3");
        gridLayout_3 = new QGridLayout(gridFrame_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_3, 0, 4, 1, 1);

        gridFrame_4 = new QFrame(layoutWidget);
        gridFrame_4->setObjectName("gridFrame_4");
        gridLayout_4 = new QGridLayout(gridFrame_4);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_4, 3, 0, 1, 1);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_7, 6, 1, 1, 1);

        gridFrame_5 = new QFrame(layoutWidget);
        gridFrame_5->setObjectName("gridFrame_5");
        gridLayout_5 = new QGridLayout(gridFrame_5);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_5, 3, 2, 1, 1);

        gridFrame_8 = new QFrame(layoutWidget);
        gridFrame_8->setObjectName("gridFrame_8");
        gridLayout_8 = new QGridLayout(gridFrame_8);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_11->addWidget(gridFrame_8, 6, 2, 1, 1);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_8, 6, 3, 1, 1);

        line_9 = new QFrame(layoutWidget);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_9, 0, 3, 1, 1);

        player1 = new QFrame(centralwidget);
        player1->setObjectName("player1");
        player1->setGeometry(QRect(-1, -10, 161, 450));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roman")});
        font.setPointSize(18);
        player1->setFont(font);
        player1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-image: url(:/game_bg.jpg);\n"
"}\n"
"\n"
"#avatar{\n"
"	background:white;\n"
"}\n"
"\n"
"#exit{\n"
"	background-color: #880808;\n"
"	border: none;\n"
"	color: yellow;\n"
"	font-size: 24px;\n"
"}\n"
"\n"
"#name{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"#elo{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"#win{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 15px;\n"
"}"));
        player1->setFrameShape(QFrame::StyledPanel);
        player1->setFrameShadow(QFrame::Raised);
        avatar = new QPushButton(player1);
        avatar->setObjectName("avatar");
        avatar->setGeometry(QRect(30, 170, 100, 100));
        avatar->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/user-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        avatar->setIcon(icon);
        avatar->setIconSize(QSize(80, 80));
        avatar->setCheckable(false);
        avatar->setChecked(false);
        avatar->setFlat(false);
        exit = new QPushButton(player1);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(0, 20, 161, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Script MT Bold")});
        exit->setFont(font1);
        elo = new QLabel(player1);
        elo->setObjectName("elo");
        elo->setGeometry(QRect(30, 280, 100, 30));
        QFont font2;
        font2.setBold(true);
        elo->setFont(font2);
        elo->setAlignment(Qt::AlignCenter);
        name = new QLabel(player1);
        name->setObjectName("name");
        name->setGeometry(QRect(0, 130, 161, 30));
        name->setAlignment(Qt::AlignCenter);
        win = new QLabel(player1);
        win->setObjectName("win");
        win->setGeometry(QRect(0, 310, 161, 30));
        win->setFont(font2);
        win->setAlignment(Qt::AlignCenter);
        player2 = new QFrame(centralwidget);
        player2->setObjectName("player2");
        player2->setGeometry(QRect(560, -10, 161, 450));
        player2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-image: url(:/game_bg.jpg);\n"
"}\n"
"\n"
"#avatar_2{\n"
"	background:white;\n"
"}\n"
"\n"
"#name_2{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"#elo_2{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"#win_2{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"#timer{\n"
"	background: none;\n"
"	color: white;\n"
"	text-align: center;\n"
"	font-size: 15px;\n"
"	padding-left: 20px\n"
"}"));
        player2->setFrameShape(QFrame::StyledPanel);
        player2->setFrameShadow(QFrame::Raised);
        avatar_2 = new QPushButton(player2);
        avatar_2->setObjectName("avatar_2");
        avatar_2->setGeometry(QRect(30, 170, 100, 100));
        avatar_2->setFocusPolicy(Qt::NoFocus);
        avatar_2->setAutoFillBackground(false);
        avatar_2->setIcon(icon);
        avatar_2->setIconSize(QSize(80, 80));
        avatar_2->setAutoDefault(false);
        elo_2 = new QLabel(player2);
        elo_2->setObjectName("elo_2");
        elo_2->setGeometry(QRect(30, 280, 100, 30));
        elo_2->setFont(font2);
        elo_2->setAlignment(Qt::AlignCenter);
        name_2 = new QLabel(player2);
        name_2->setObjectName("name_2");
        name_2->setGeometry(QRect(0, 130, 161, 30));
        name_2->setAlignment(Qt::AlignCenter);
        win_2 = new QLabel(player2);
        win_2->setObjectName("win_2");
        win_2->setGeometry(QRect(0, 310, 161, 30));
        win_2->setFont(font2);
        win_2->setAlignment(Qt::AlignCenter);
        timer = new QLabel(player2);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(0, 20, 161, 31));
        timer->setFont(font2);
        readyButton = new QPushButton(player2);
        readyButton->setObjectName("readyButton");
        readyButton->setGeometry(QRect(15, 390, 130, 41));
        notification = new QLabel(centralwidget);
        notification->setObjectName("notification");
        notification->setGeometry(QRect(260, 180, 200, 80));
        notification->setStyleSheet(QString::fromUtf8(""));
        notification->setScaledContents(true);
        notification->setAlignment(Qt::AlignCenter);
        surrenderfr = new QFrame(centralwidget);
        surrenderfr->setObjectName("surrenderfr");
        surrenderfr->setGeometry(QRect(130, 140, 461, 151));
        surrenderfr->setStyleSheet(QString::fromUtf8("background: #D3D3D3;\n"
"font-size: 20px;\n"
"border-radius: 20px;"));
        surrenderfr->setFrameShape(QFrame::StyledPanel);
        surrenderfr->setFrameShadow(QFrame::Raised);
        label = new QLabel(surrenderfr);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 441, 71));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: red;"));
        label->setAlignment(Qt::AlignCenter);
        yes = new QPushButton(surrenderfr);
        yes->setObjectName("yes");
        yes->setGeometry(QRect(260, 80, 131, 41));
        yes->setFont(font2);
        yes->setStyleSheet(QString::fromUtf8("background: red;\n"
"border-radius: 10px;\n"
"color: white;\n"
"font-size: 30px;"));
        no = new QPushButton(surrenderfr);
        no->setObjectName("no");
        no->setGeometry(QRect(60, 80, 131, 41));
        no->setFont(font2);
        no->setStyleSheet(QString::fromUtf8("background: black;\n"
"border-radius: 10px;\n"
"color: white;\n"
"font-size: 30px;"));
        Game_Screen->setCentralWidget(centralwidget);

        retranslateUi(Game_Screen);

        avatar->setDefault(false);
        avatar_2->setDefault(false);


        QMetaObject::connectSlotsByName(Game_Screen);
    } // setupUi

    void retranslateUi(QMainWindow *Game_Screen)
    {
        Game_Screen->setWindowTitle(QCoreApplication::translate("Game_Screen", "MainWindow", nullptr));
        avatar->setText(QString());
        exit->setText(QCoreApplication::translate("Game_Screen", "Exit", nullptr));
        elo->setText(QCoreApplication::translate("Game_Screen", "Elo", nullptr));
        name->setText(QCoreApplication::translate("Game_Screen", "Name", nullptr));
        win->setText(QCoreApplication::translate("Game_Screen", "Win: 384 - 52%", nullptr));
        avatar_2->setText(QString());
        elo_2->setText(QCoreApplication::translate("Game_Screen", "Elo: ", nullptr));
        name_2->setText(QCoreApplication::translate("Game_Screen", "Name", nullptr));
        win_2->setText(QCoreApplication::translate("Game_Screen", "Win: ", nullptr));
        timer->setText(QCoreApplication::translate("Game_Screen", "Time:", nullptr));
        readyButton->setText(QCoreApplication::translate("Game_Screen", "READY", nullptr));
        notification->setText(QCoreApplication::translate("Game_Screen", "Player 1 Wins !", nullptr));
        label->setText(QCoreApplication::translate("Game_Screen", "You are in game. Do you want to surrender?", nullptr));
        yes->setText(QCoreApplication::translate("Game_Screen", "YES", nullptr));
        no->setText(QCoreApplication::translate("Game_Screen", "NO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game_Screen: public Ui_Game_Screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_SCREEN_H
