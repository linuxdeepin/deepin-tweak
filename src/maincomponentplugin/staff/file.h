# SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

# SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <memory>
#include <optional>
#include <QByteArray>
#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QStringList>
#include <QtQml>

class FileMode : public QObject
{
    Q_OBJECT
    Q_ENUMS(Mode);

public:
    enum Mode {
        NotOpen = QFile::NotOpen,
        ReadOnly = QFile::ReadOnly,
        WriteOnly = QFile::WriteOnly,
        ReadWrite = ReadOnly | WriteOnly,
        Append = QFile::Append,
        Truncate = QFile::Truncate,
        Text = QFile::Text,
        Unbuffered = QFile::Unbuffered,
        NewOnly = QFile::NewOnly,
        ExistingOnly = QFile::ExistingOnly
    };
};

class FileBackend : public QObject
{
    Q_OBJECT
public:
    FileBackend(const QString &file, QObject *parent = nullptr)
        : QObject(parent)
        , file(new QFile(file))
    {
        qDebug() << "[File] create object.";
    }
    ~FileBackend() override { qDebug() << "[File] delete object."; }

    Q_INVOKABLE bool open(const QVariant &mode);
    Q_INVOKABLE QByteArray read(qint64 maxSize);
    Q_INVOKABLE QByteArray readAll();
    Q_INVOKABLE qint64 write(const QByteArray &data);
    Q_INVOKABLE bool rename(const QString &newName);
    Q_INVOKABLE bool remove();
    Q_INVOKABLE bool flush();
    Q_INVOKABLE static bool exists(const QString &file);

private:
    std::unique_ptr<QFile> file;
};

class File : public QObject
{
    Q_OBJECT
public:
    File(QQmlEngine *engine, QJSEngine *scriptEngine)
        : m_engine(engine)
        , m_scriptEngine(scriptEngine)
    {}
    ~File() {}

    static void registerType()
    {
        qmlRegisterSingletonType<File>("org.deepin.tweak",
                                       1,
                                       0,
                                       "File",
                                       [=](QQmlEngine *engine, QJSEngine *scriptEngine) {
                                           return new File(engine, scriptEngine);
                                       });
        qmlRegisterUncreatableType<FileBackend>("org.deepin.tweak",
                                                1,
                                                0,
                                                "FileBackend",
                                                "cannot create filebackend object.");
        qmlRegisterType<FileMode>("org.deepin.tweak", 1, 0, "FileMode");
    }

    Q_INVOKABLE FileBackend *create(const QString &file) { return new FileBackend(file); }
    Q_INVOKABLE inline bool exists(const QString &file) { return FileBackend::exists(file); }

private:
    QQmlEngine *m_engine;
    QJSEngine *m_scriptEngine;
};
