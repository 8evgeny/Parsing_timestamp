#pragma once
#include <QApplication>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QLineEdit>
#include <QMessageBox>
#include <QMimeDatabase>
#include <QMimeType>
#include <QPushButton>
#include <QRegularExpression>
#include <QSettings>
#include <QSpinBox>
#include <QStringList>
#include <QTextEdit>
#include <QUuid>
#include <QValidator>
#include <QWidget>
#include <iostream>

QByteArray data_to_write;
int number;
const QString DateTimeFormat = "dd.MM.yyyy hh:mm:ss";
void start(const QDir&, const QString);
QString Get_time(QString);
