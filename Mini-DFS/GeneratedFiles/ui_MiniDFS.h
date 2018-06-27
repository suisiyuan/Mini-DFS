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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniDFSClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QTreeWidget *fileTree;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_upload;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *uploadPathEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *uploadBtn;
    QPushButton *createDirBtn;
    QWidget *tab_download;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *downloadBtn;
    QPushButton *downloadChunkBtn;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *downloadIdEdit;
    QLabel *label_5;
    QLineEdit *downloadNameEdit;
    QLineEdit *downloadPathEdit;
    QLabel *label;
    QSpinBox *offsetSpin;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_server1;
    QGridLayout *gridLayout_2;
    QTreeWidget *chunkTree_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *deleteBtn_1;
    QPushButton *recoverBtn_1;
    QWidget *tab_server2;
    QGridLayout *gridLayout_5;
    QTreeWidget *chunkTree_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *deleteBtn_2;
    QPushButton *recoverBtn_2;
    QWidget *tab_server3;
    QGridLayout *gridLayout_6;
    QTreeWidget *chunkTree_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *deleteBtn_3;
    QPushButton *recoverBtn_3;
    QWidget *tab_server4;
    QGridLayout *gridLayout_7;
    QTreeWidget *chunkTree_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *deleteBtn_4;
    QPushButton *recoverBtn_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MiniDFSClass)
    {
        if (MiniDFSClass->objectName().isEmpty())
            MiniDFSClass->setObjectName(QStringLiteral("MiniDFSClass"));
        MiniDFSClass->resize(1188, 745);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        MiniDFSClass->setFont(font);
        centralWidget = new QWidget(MiniDFSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(7);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fileTree = new QTreeWidget(groupBox);
        new QTreeWidgetItem(fileTree);
        fileTree->setObjectName(QStringLiteral("fileTree"));

        horizontalLayout_3->addWidget(fileTree);


        gridLayout_4->addWidget(groupBox, 0, 0, 2, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget_2 = new QTabWidget(groupBox_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_upload = new QWidget();
        tab_upload->setObjectName(QStringLiteral("tab_upload"));
        verticalLayout = new QVBoxLayout(tab_upload);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(tab_upload);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        uploadPathEdit = new QLineEdit(tab_upload);
        uploadPathEdit->setObjectName(QStringLiteral("uploadPathEdit"));
        uploadPathEdit->setReadOnly(true);

        gridLayout->addWidget(uploadPathEdit, 0, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        uploadBtn = new QPushButton(tab_upload);
        uploadBtn->setObjectName(QStringLiteral("uploadBtn"));

        horizontalLayout_4->addWidget(uploadBtn);

        createDirBtn = new QPushButton(tab_upload);
        createDirBtn->setObjectName(QStringLiteral("createDirBtn"));

        horizontalLayout_4->addWidget(createDirBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        tabWidget_2->addTab(tab_upload, QString());
        tab_download = new QWidget();
        tab_download->setObjectName(QStringLiteral("tab_download"));
        gridLayout_3 = new QGridLayout(tab_download);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        downloadBtn = new QPushButton(tab_download);
        downloadBtn->setObjectName(QStringLiteral("downloadBtn"));

        horizontalLayout_7->addWidget(downloadBtn);

        downloadChunkBtn = new QPushButton(tab_download);
        downloadChunkBtn->setObjectName(QStringLiteral("downloadChunkBtn"));

        horizontalLayout_7->addWidget(downloadChunkBtn);


        gridLayout_3->addLayout(horizontalLayout_7, 4, 0, 1, 3);

        label_6 = new QLabel(tab_download);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        label_2 = new QLabel(tab_download);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        downloadIdEdit = new QLineEdit(tab_download);
        downloadIdEdit->setObjectName(QStringLiteral("downloadIdEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(downloadIdEdit->sizePolicy().hasHeightForWidth());
        downloadIdEdit->setSizePolicy(sizePolicy4);
        downloadIdEdit->setReadOnly(true);

        gridLayout_3->addWidget(downloadIdEdit, 2, 1, 1, 2);

        label_5 = new QLabel(tab_download);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        downloadNameEdit = new QLineEdit(tab_download);
        downloadNameEdit->setObjectName(QStringLiteral("downloadNameEdit"));
        sizePolicy4.setHeightForWidth(downloadNameEdit->sizePolicy().hasHeightForWidth());
        downloadNameEdit->setSizePolicy(sizePolicy4);
        downloadNameEdit->setReadOnly(true);

        gridLayout_3->addWidget(downloadNameEdit, 1, 1, 1, 2);

        downloadPathEdit = new QLineEdit(tab_download);
        downloadPathEdit->setObjectName(QStringLiteral("downloadPathEdit"));
        downloadPathEdit->setReadOnly(true);

        gridLayout_3->addWidget(downloadPathEdit, 0, 1, 1, 2);

        label = new QLabel(tab_download);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 3, 0, 1, 1);

        offsetSpin = new QSpinBox(tab_download);
        offsetSpin->setObjectName(QStringLiteral("offsetSpin"));
        offsetSpin->setMaximum(0);

        gridLayout_3->addWidget(offsetSpin, 3, 1, 1, 1);

        tabWidget_2->addTab(tab_download, QString());

        horizontalLayout_2->addWidget(tabWidget_2);


        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);

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
        gridLayout_2 = new QGridLayout(tab_server1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        chunkTree_1 = new QTreeWidget(tab_server1);
        chunkTree_1->setObjectName(QStringLiteral("chunkTree_1"));

        gridLayout_2->addWidget(chunkTree_1, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        deleteBtn_1 = new QPushButton(tab_server1);
        deleteBtn_1->setObjectName(QStringLiteral("deleteBtn_1"));
        deleteBtn_1->setEnabled(false);

        gridLayout_2->addWidget(deleteBtn_1, 1, 1, 1, 1);

        recoverBtn_1 = new QPushButton(tab_server1);
        recoverBtn_1->setObjectName(QStringLiteral("recoverBtn_1"));
        recoverBtn_1->setEnabled(false);

        gridLayout_2->addWidget(recoverBtn_1, 1, 2, 1, 1);

        tabWidget->addTab(tab_server1, QString());
        tab_server2 = new QWidget();
        tab_server2->setObjectName(QStringLiteral("tab_server2"));
        gridLayout_5 = new QGridLayout(tab_server2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        chunkTree_2 = new QTreeWidget(tab_server2);
        chunkTree_2->setObjectName(QStringLiteral("chunkTree_2"));

        gridLayout_5->addWidget(chunkTree_2, 0, 0, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        deleteBtn_2 = new QPushButton(tab_server2);
        deleteBtn_2->setObjectName(QStringLiteral("deleteBtn_2"));
        deleteBtn_2->setEnabled(false);

        gridLayout_5->addWidget(deleteBtn_2, 1, 1, 1, 1);

        recoverBtn_2 = new QPushButton(tab_server2);
        recoverBtn_2->setObjectName(QStringLiteral("recoverBtn_2"));
        recoverBtn_2->setEnabled(false);

        gridLayout_5->addWidget(recoverBtn_2, 1, 2, 1, 1);

        tabWidget->addTab(tab_server2, QString());
        tab_server3 = new QWidget();
        tab_server3->setObjectName(QStringLiteral("tab_server3"));
        gridLayout_6 = new QGridLayout(tab_server3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        chunkTree_3 = new QTreeWidget(tab_server3);
        chunkTree_3->setObjectName(QStringLiteral("chunkTree_3"));

        gridLayout_6->addWidget(chunkTree_3, 0, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        deleteBtn_3 = new QPushButton(tab_server3);
        deleteBtn_3->setObjectName(QStringLiteral("deleteBtn_3"));
        deleteBtn_3->setEnabled(false);

        gridLayout_6->addWidget(deleteBtn_3, 1, 1, 1, 1);

        recoverBtn_3 = new QPushButton(tab_server3);
        recoverBtn_3->setObjectName(QStringLiteral("recoverBtn_3"));
        recoverBtn_3->setEnabled(false);

        gridLayout_6->addWidget(recoverBtn_3, 1, 2, 1, 1);

        tabWidget->addTab(tab_server3, QString());
        tab_server4 = new QWidget();
        tab_server4->setObjectName(QStringLiteral("tab_server4"));
        gridLayout_7 = new QGridLayout(tab_server4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        chunkTree_4 = new QTreeWidget(tab_server4);
        chunkTree_4->setObjectName(QStringLiteral("chunkTree_4"));

        gridLayout_7->addWidget(chunkTree_4, 0, 0, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        deleteBtn_4 = new QPushButton(tab_server4);
        deleteBtn_4->setObjectName(QStringLiteral("deleteBtn_4"));
        deleteBtn_4->setEnabled(false);

        gridLayout_7->addWidget(deleteBtn_4, 1, 1, 1, 1);

        recoverBtn_4 = new QPushButton(tab_server4);
        recoverBtn_4->setObjectName(QStringLiteral("recoverBtn_4"));
        recoverBtn_4->setEnabled(false);

        gridLayout_7->addWidget(recoverBtn_4, 1, 2, 1, 1);

        tabWidget->addTab(tab_server4, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout_4->addWidget(groupBox_3, 1, 1, 1, 1);

        MiniDFSClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MiniDFSClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1188, 26));
        MiniDFSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MiniDFSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MiniDFSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MiniDFSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MiniDFSClass->setStatusBar(statusBar);

        retranslateUi(MiniDFSClass);

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
        ___qtreewidgetitem->setText(1, QApplication::translate("MiniDFSClass", "Directory?", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MiniDFSClass", "File", nullptr));

        const bool __sortingEnabled = fileTree->isSortingEnabled();
        fileTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = fileTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("MiniDFSClass", "True", nullptr));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MiniDFSClass", "/", nullptr));
        fileTree->setSortingEnabled(__sortingEnabled);

        groupBox_2->setTitle(QApplication::translate("MiniDFSClass", "Client", nullptr));
        label_4->setText(QApplication::translate("MiniDFSClass", "Path: ", nullptr));
        uploadPathEdit->setText(QApplication::translate("MiniDFSClass", "/", nullptr));
        uploadPathEdit->setPlaceholderText(QString());
        uploadBtn->setText(QApplication::translate("MiniDFSClass", "Upload", nullptr));
        createDirBtn->setText(QApplication::translate("MiniDFSClass", "Create Folder", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_upload), QApplication::translate("MiniDFSClass", "Upload", nullptr));
        downloadBtn->setText(QApplication::translate("MiniDFSClass", "Download", nullptr));
        downloadChunkBtn->setText(QApplication::translate("MiniDFSClass", "Download Chunk", nullptr));
        label_6->setText(QApplication::translate("MiniDFSClass", "Name: ", nullptr));
        label_2->setText(QApplication::translate("MiniDFSClass", "Path: ", nullptr));
        label_5->setText(QApplication::translate("MiniDFSClass", "ID: ", nullptr));
        downloadPathEdit->setText(QApplication::translate("MiniDFSClass", "/", nullptr));
        label->setText(QApplication::translate("MiniDFSClass", "Offset: ", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_download), QApplication::translate("MiniDFSClass", "Download", nullptr));
        groupBox_3->setTitle(QApplication::translate("MiniDFSClass", "DataServer", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = chunkTree_1->headerItem();
        ___qtreewidgetitem2->setText(1, QApplication::translate("MiniDFSClass", "MD5", nullptr));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MiniDFSClass", "File/Chunk ID", nullptr));
        deleteBtn_1->setText(QApplication::translate("MiniDFSClass", "Delete", nullptr));
        recoverBtn_1->setText(QApplication::translate("MiniDFSClass", "Recover", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server1), QApplication::translate("MiniDFSClass", "Server 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = chunkTree_2->headerItem();
        ___qtreewidgetitem3->setText(1, QApplication::translate("MiniDFSClass", "MD5", nullptr));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MiniDFSClass", "File/Chunk ID", nullptr));
        deleteBtn_2->setText(QApplication::translate("MiniDFSClass", "Delete", nullptr));
        recoverBtn_2->setText(QApplication::translate("MiniDFSClass", "Recover", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server2), QApplication::translate("MiniDFSClass", "Server 2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = chunkTree_3->headerItem();
        ___qtreewidgetitem4->setText(1, QApplication::translate("MiniDFSClass", "MD5", nullptr));
        ___qtreewidgetitem4->setText(0, QApplication::translate("MiniDFSClass", "File/Chunk ID", nullptr));
        deleteBtn_3->setText(QApplication::translate("MiniDFSClass", "Delete", nullptr));
        recoverBtn_3->setText(QApplication::translate("MiniDFSClass", "Recover", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server3), QApplication::translate("MiniDFSClass", "Server 3", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = chunkTree_4->headerItem();
        ___qtreewidgetitem5->setText(1, QApplication::translate("MiniDFSClass", "MD5", nullptr));
        ___qtreewidgetitem5->setText(0, QApplication::translate("MiniDFSClass", "File/Chunk ID", nullptr));
        deleteBtn_4->setText(QApplication::translate("MiniDFSClass", "Delete", nullptr));
        recoverBtn_4->setText(QApplication::translate("MiniDFSClass", "Recover", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_server4), QApplication::translate("MiniDFSClass", "Server 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiniDFSClass: public Ui_MiniDFSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIDFS_H
