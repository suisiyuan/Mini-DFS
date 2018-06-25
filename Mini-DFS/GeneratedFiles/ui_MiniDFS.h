/********************************************************************************
** Form generated from reading UI file 'MiniDFS.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIDFS_H
#define UI_MINIDFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniDFSClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget_3;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTreeWidget *fileTree;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *createDirBtn;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_upload;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *uploadFileEdit;
    QToolButton *getFileBtn;
    QLabel *label_4;
    QLineEdit *uploadPathEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *uploadBtn;
    QWidget *tab_download;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_server1;
    QWidget *tab_server2;
    QWidget *tab_server3;
    QWidget *tab_server4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MiniDFSClass)
    {
        if (MiniDFSClass->objectName().isEmpty())
            MiniDFSClass->setObjectName(QStringLiteral("MiniDFSClass"));
        MiniDFSClass->resize(939, 618);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        MiniDFSClass->setFont(font);
        centralWidget = new QWidget(MiniDFSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tabWidget_3 = new QTabWidget(groupBox);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        fileTree = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(fileTree);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        fileTree->setObjectName(QStringLiteral("fileTree"));

        gridLayout_2->addWidget(fileTree, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        createDirBtn = new QPushButton(tab);
        createDirBtn->setObjectName(QStringLiteral("createDirBtn"));

        gridLayout_2->addWidget(createDirBtn, 1, 1, 1, 1);

        tabWidget_3->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_3->addTab(tab_2, QString());

        horizontalLayout_3->addWidget(tabWidget_3);


        gridLayout_6->addWidget(groupBox, 0, 0, 2, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget_2 = new QTabWidget(groupBox_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_upload = new QWidget();
        tab_upload->setObjectName(QStringLiteral("tab_upload"));
        gridLayout_4 = new QGridLayout(tab_upload);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(tab_upload);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        uploadFileEdit = new QLineEdit(tab_upload);
        uploadFileEdit->setObjectName(QStringLiteral("uploadFileEdit"));
        uploadFileEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(uploadFileEdit, 0, 1, 1, 2);

        getFileBtn = new QToolButton(tab_upload);
        getFileBtn->setObjectName(QStringLiteral("getFileBtn"));
        getFileBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(getFileBtn, 0, 3, 1, 1);

        label_4 = new QLabel(tab_upload);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        uploadPathEdit = new QLineEdit(tab_upload);
        uploadPathEdit->setObjectName(QStringLiteral("uploadPathEdit"));
        uploadPathEdit->setReadOnly(true);

        gridLayout->addWidget(uploadPathEdit, 1, 1, 1, 3);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        uploadBtn = new QPushButton(tab_upload);
        uploadBtn->setObjectName(QStringLiteral("uploadBtn"));

        gridLayout_4->addWidget(uploadBtn, 1, 1, 1, 1);

        tabWidget_2->addTab(tab_upload, QString());
        tab_download = new QWidget();
        tab_download->setObjectName(QStringLiteral("tab_download"));
        gridLayout_5 = new QGridLayout(tab_download);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(tab_download);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_download);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 0, 1, 1, 2);

        label_5 = new QLabel(tab_download);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(tab_download);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab_download);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_3->addWidget(lineEdit_6, 1, 1, 1, 2);

        lineEdit_5 = new QLineEdit(tab_download);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_3->addWidget(lineEdit_5, 2, 1, 1, 2);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(tab_download);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_5->addWidget(pushButton_2, 1, 1, 1, 1);

        tabWidget_2->addTab(tab_download, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 72, 15));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 20, 113, 21));
        tabWidget_2->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget_2);


        gridLayout_6->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(groupBox_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_server1 = new QWidget();
        tab_server1->setObjectName(QStringLiteral("tab_server1"));
        tabWidget->addTab(tab_server1, QString());
        tab_server2 = new QWidget();
        tab_server2->setObjectName(QStringLiteral("tab_server2"));
        tabWidget->addTab(tab_server2, QString());
        tab_server3 = new QWidget();
        tab_server3->setObjectName(QStringLiteral("tab_server3"));
        tabWidget->addTab(tab_server3, QString());
        tab_server4 = new QWidget();
        tab_server4->setObjectName(QStringLiteral("tab_server4"));
        tabWidget->addTab(tab_server4, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout_6->addWidget(groupBox_3, 1, 1, 1, 1);

        MiniDFSClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MiniDFSClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 939, 21));
        MiniDFSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MiniDFSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MiniDFSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MiniDFSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MiniDFSClass->setStatusBar(statusBar);

        retranslateUi(MiniDFSClass);

        tabWidget_3->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MiniDFSClass);
    } // setupUi

    void retranslateUi(QMainWindow *MiniDFSClass)
    {
        MiniDFSClass->setWindowTitle(QApplication::translate("MiniDFSClass", "MiniDFS", nullptr));
        groupBox->setTitle(QApplication::translate("MiniDFSClass", "NameServer", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = fileTree->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("MiniDFSClass", "Chunks", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("MiniDFSClass", "Size", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("MiniDFSClass", "ID", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("MiniDFSClass", "Is Directory", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MiniDFSClass", "File", nullptr));

        const bool __sortingEnabled = fileTree->isSortingEnabled();
        fileTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = fileTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("MiniDFSClass", "True", nullptr));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MiniDFSClass", "/", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(1, QApplication::translate("MiniDFSClass", "True", nullptr));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MiniDFSClass", "/data", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(1, QApplication::translate("MiniDFSClass", "False", nullptr));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MiniDFSClass", "text.pdf", nullptr));
        fileTree->setSortingEnabled(__sortingEnabled);

        createDirBtn->setText(QApplication::translate("MiniDFSClass", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab), QApplication::translate("MiniDFSClass", "File List", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_2), QApplication::translate("MiniDFSClass", "Tab 2", nullptr));
        groupBox_2->setTitle(QApplication::translate("MiniDFSClass", "Client", nullptr));
        label->setText(QApplication::translate("MiniDFSClass", "File: ", nullptr));
        getFileBtn->setText(QApplication::translate("MiniDFSClass", "...", nullptr));
        label_4->setText(QApplication::translate("MiniDFSClass", "Path: ", nullptr));
        uploadPathEdit->setText(QApplication::translate("MiniDFSClass", "/", nullptr));
        uploadPathEdit->setPlaceholderText(QString());
        uploadBtn->setText(QApplication::translate("MiniDFSClass", "Upload", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_upload), QApplication::translate("MiniDFSClass", "Upload", nullptr));
        label_2->setText(QApplication::translate("MiniDFSClass", "Path: ", nullptr));
        label_5->setText(QApplication::translate("MiniDFSClass", "ID: ", nullptr));
        label_6->setText(QApplication::translate("MiniDFSClass", "Name: ", nullptr));
        pushButton_2->setText(QApplication::translate("MiniDFSClass", "Download", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_download), QApplication::translate("MiniDFSClass", "Download", nullptr));
        label_3->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MiniDFSClass", "Location", nullptr));
        groupBox_3->setTitle(QApplication::translate("MiniDFSClass", "DataServer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server1), QApplication::translate("MiniDFSClass", "Server 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server2), QApplication::translate("MiniDFSClass", "Server 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server3), QApplication::translate("MiniDFSClass", "Server 3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server4), QApplication::translate("MiniDFSClass", "Server 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiniDFSClass: public Ui_MiniDFSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIDFS_H
