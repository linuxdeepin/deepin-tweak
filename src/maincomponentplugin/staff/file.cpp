// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: GPL-3.0-or-later

#include "file.h"

bool FileBackend::open(const QVariant &mode)
{
    return file->open(static_cast<QFile::OpenModeFlag>(mode.toInt()));
}

const QByteArray FileBackend::read(qint64 maxSize)
{
    return file->read(maxSize);
}

const QByteArray FileBackend::readAll()
{
    return file->readAll();
}

qint64 FileBackend::write(const QByteArray &data)
{
    return file->write(data);
}

bool FileBackend::flush()
{
    return file->flush();
}

bool FileBackend::rename(const QString &newName)
{
    return file->rename(newName);
}

bool FileBackend::remove()
{
    return file->remove();
}

bool FileBackend::exists()
{
  return file->exists();
}
