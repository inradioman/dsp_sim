#include "simblock.h"

SimBlock::SimBlock(QString name)
{
    //конструктор по имени
    //задаем имя
    block_name = name;
    //присваиваем изображение по умолчанию
    block_image.load(":/rsc/default_block.jpg");

    //создаем порты : In и Out
    SimPort port;
    port.dir = PortDirection::SLAVE;
    port.name = "In";
    port.nameIsVisible = true;
    port.orientation = PortOrientation::LEFT;

    block_ports.append(port);

    port.dir = PortDirection::MASTER;
    port.name = "Out";
    port.nameIsVisible = true;
    port.orientation = PortOrientation::RIGHT;

    block_ports.append(port);
}

SimBlock::SimBlock(QString &name, QImage &image, QList<SimPort> &ports, QList<QString> &files) : block_name(name), block_image(image)
{
    //самый полный конструктор
    //добавляем порты
    for (int i = 0; i < ports.length(); i++)
    {
        SimPort port = ports[i];
        //проверка имени порта на уникальность
        bool check = true;
        for (int j = 0; j < block_ports.length(); j++)
        {
            if (block_ports[j].name.compare(port.name) == 0)
            {
                //не уникально - не добавляем
                check = false;
                break;
            }
        }
        if (check)
            block_ports.append(ports[i]);
    }
    //добавляем файлы
    for (int i = 0; i < files.length(); i++)
    {
        QString file = files[i];
        bool check = true;
        for (int j = 0; j < block_files.length(); j++)
        {
            if (block_files[j].compare(file) == 0)
            {
                check = false;
                break;
            }
        }

        if (check)
            block_files.append(files[i]);
    }
}

SimBlock::SimBlock(const SimBlock &block)
{
    block_files.clear();
    block_ports.clear();

    block_name = block.block_name;
    block_image = block.block_image;
    for (int i = 0; i < block.block_ports.length(); i++)
        block_ports.append(block.block_ports[i]);
    for (int i = 0; i < block.block_files.length(); i++)
        block_files.append(block.block_files[i]);
}

SimBlock::~SimBlock()
{

}

void SimBlock::addPort(QString &name, PortDirection dir, bool nameIVisible, PortOrientation orientation)
{
    //добавление порта
    SimPort port = {dir, name, nameIVisible, orientation};
    block_ports.append(port);
}

void SimBlock::addFile(QString &file)
{
    //добавление одного файла
    block_files.append(file);
}

void SimBlock::addFiles(QList<QString> &files)
{
    //добавление нескольких файлов
    for (int i = 0; i < files.length(); i++)
    {

        QString file = files[i];
        bool check = true;
        for (int j = 0; j < block_files.length(); j++)
        {
            if (block_files[j].compare(file) == 0)
            {
                check = false;
                break;
            }
        }

        if (check)
            block_files.append(files[i]);
    }
}

void SimBlock::deletePort(QString &name)
{
    //удаление порта по имени
    for (int i = 0; i < block_ports.length(); i++)
    {
        if (block_ports[i].name.compare(name) == 0)
        {
            block_ports.removeAt(i);
            break;
        }
    }
}

void SimBlock::deletePort(int index)
{
    //удаление порта по индексу
    block_ports.removeAt(index);
}

void SimBlock::deleteFile(QString &name)
{
    //удаление файла по имени
    for (int i = 0; i < block_files.length(); i++)
    {
        if (block_files[i].compare(name) == 0)
        {
            block_files.removeAt(i);
            break;
        }
    }
}

void SimBlock::deleteFile(int index)
{
    //удаление файла по номеру
    block_files.removeAt(index);
}

QList<SimPort> SimBlock::getAllPorts()
{
    //вывести список всех портов
    QList<SimPort> result;

    for (int i = 0; i < block_ports.length(); i++)
        result.append(block_ports[i]);

    return result;
}

QList<QString> SimBlock::getAllFiles()
{
    //вывести список всех файлов
    QList<QString> result;

    for (int i = 0; i < block_files.length(); i++)
        result.append(block_files[i]);

    return result;
}


