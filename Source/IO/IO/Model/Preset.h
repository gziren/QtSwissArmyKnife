/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QTimer>

#include "../../xIO.h"
#include "AbstractModelIO.h"

namespace xTools {

class Preset : public AbstractModelIO
{
    Q_OBJECT
public:
    explicit Preset(QObject *parent = nullptr);

    QVariantMap saveItem(const int row) const override;
    void loadItem(const int row, const QVariantMap &item) override;
    void inputBytes(const QByteArray &bytes) override;

protected:
    void run() override;

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    struct Item
    {
        QString description{"Demo"};
        xIO::TextItem textContext;
    };

private:
    QList<Item> m_items;
};

} // namespace xTools
