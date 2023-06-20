#include "simblock.h"

SimBlock::SimBlock(QObject *parent) : QObject(parent)
{
    port.dir = port.MASTER;
}
