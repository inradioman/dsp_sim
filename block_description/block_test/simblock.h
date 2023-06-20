#ifndef SIMBLOCK_H
#define SIMBLOCK_H

//здесь содержится описание класса блока, используемого в dsp_sim

#include <QObject>
#include <QImage>
#include <QString>
#include <QList>
#include <QDir>

//структура порта
enum class PortDirection {MASTER, SLAVE};
struct SimPort
{
    PortDirection dir; //направление порта (вход и выход)
    QString name; //название порта
};

class SimBlock : public QObject
{
    Q_OBJECT
public:
    explicit SimBlock(QObject *parent = nullptr);

signals:

private:
    //изображение блока
    QImage block_image;
    //порты блока
    QList<SimPort> ports;
    //список файлов, связанных с блоком (список относительных путей к ним)
    QList<QDir> files;
};

#endif // SIMBLOCK_H
