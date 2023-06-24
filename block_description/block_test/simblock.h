#ifndef SIMBLOCK_H
#define SIMBLOCK_H

//здесь содержится описание класса блока, используемого в dsp_sim
#include <QImage>
#include <QString>
#include <QList>
#include <QDir>
#include <QPixmap>

//структура порта
enum class PortDirection {MASTER, SLAVE, TWO_DIRECTIONAL};
enum class PortOrientation {LEFT, RIGHT, UP, DOWN};

struct SimPort
{
    PortDirection dir; //направление порта (вход и выход)
    QString name; //название порта
    bool nameIsVisible; //отображается ли имя порта
    PortOrientation orientation; //с какой стороны блока порт располагается
};

class SimBlock //: public QObject
{
    //Q_OBJECT
public:
    //конструкторы
    SimBlock() : SimBlock("default") {}; //конструктор по умолчанию
    SimBlock(QString name); //конструктор по имени
    SimBlock(QString &name, QImage &image, QList<SimPort> &ports, QList<QString> &files); //самый полный конструктор для загрузки из файла

    SimBlock(const SimBlock &block); //конструктор копирования

    //деструктор
    ~SimBlock();

    //основные функции
     //добавить порт
    void addPort(QString &name, PortDirection dir, bool nameIVisible, PortOrientation orientation);
    void addPort(SimPort &port) { addPort(port.name, port.dir, port.nameIsVisible, port.orientation); }
    //добавить файл
    void addFile(QString &file);
    void addFiles(QList<QString> &files);

    //удалить порт
    void deletePort(QString &name);
    void deletePort(int index);
    //удалить привязанный файл
    void deleteFile(QString &name);
    void deleteFile(int index);

    //доступ к параметрам
    QList<SimPort> getAllPorts();
    QList<QString> getAllFiles();

private:
    //название блока
    QString block_name;
    //изображение блока
    QImage block_image;
    //порты блока
    QList<SimPort> block_ports;
    //список файлов, связанных с блоком (список относительных путей к ним)
    QList<QString> block_files;
};

#endif // SIMBLOCK_H
