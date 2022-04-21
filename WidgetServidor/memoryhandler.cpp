#include "memoryhandler.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



MemoryHandler::MemoryHandler()
{
    lastInserted = 0;
}

QImage MemoryHandler::GetFromMemory(QString fileName)
{
    for(int x = 0;x<4;x++){
        if(fileName == memoryKey[x]){
            return memoryData[x];
        }
    }

    QString ImgPath(fileName);

    int ridx = lastInserted % 4;
    lastInserted++;
    memoryKey[ridx] = fileName;
    memoryData[ridx] = QImage (ImgPath);
    return QImage (ImgPath);

}

QString MemoryHandler::getMemoryKey(int idx)
{
    return memoryKey[idx];
}
