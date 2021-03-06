#ifndef WBMODEL_H
#define WBMODEL_H

#include <QAbstractListModel>
#include <QCamera>
#include <QPair>

class WbModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum WbRoles {
        WbName = Qt::UserRole + 1,
        WbValue
    };

    WbModel();

    virtual QHash<int, QByteArray> roleNames() const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void setCamera(QObject *camera);

private:
    QMap<int, QString> m_wbModes;
    QCamera *m_camera = nullptr;

    QString wbName(QCameraImageProcessing::WhiteBalanceMode wb) const;
};

#endif // EFFECTSMODEL_H
