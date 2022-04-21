#ifndef MEMORYHANDLER_H
#define MEMORYHANDLER_H

#include <QImage>

class MemoryHandler
{
    QImage  memoryData [4];
    QString memoryKey [4];
    int lastInserted;
public:
    MemoryHandler();
    QImage GetFromMemory(QString fileName);
    QString getMemoryKey(int idx);
    void Randomize();
};

#endif // MEMORYHANDLER_H
