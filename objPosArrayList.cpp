#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0; 
    aList[0].pos->x = 0;
    aList[0].pos->y = 0;
    aList[0].symbol = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(const objPosArrayList &o)
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = o.arrayCapacity;
    listSize = o.listSize;
}

objPosArrayList& objPosArrayList::operator=(const objPosArrayList &o){
    if(this != &o){
        arrayCapacity = o.arrayCapacity;
        listSize = o.listSize;
    }
    return *this;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize >= ARRAY_MAX_CAP) return;
    
    for(int i = listSize; i > 0; i--)
    {
        aList[i].pos->x = aList[i - 1].pos->x;
        aList[i].pos->y = aList[i - 1].pos->y;
        aList[i].symbol = aList[i - 1].symbol;
    }
    
    aList[0].pos->x = thisPos.pos->x; 
    aList[0].pos->y = thisPos.pos->y;
    aList[0].symbol = thisPos.symbol;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= arrayCapacity) 
    {
        return;
    }

    aList[listSize].pos->x = thisPos.pos->x; 
    aList[listSize].pos->y = thisPos.pos->y;
    aList[listSize].symbol = thisPos.symbol;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize == 0) return;

    for(int i = 0; i < listSize - 1; i++){
        aList[i].pos->x = aList[i + 1].pos->x;
        aList[i].pos->y = aList[i + 1].pos->y;
        aList[i].symbol = aList[i + 1].symbol;
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize > 0)
        listSize--; 
}

objPos objPosArrayList::getHeadElement() const
{
    objPos returnHead;
    returnHead.pos->x = aList[0].pos->x;
    returnHead.pos->y = aList[0].pos->y;
    returnHead.symbol = aList[0].symbol;
    return returnHead; 
}

objPos objPosArrayList::getTailElement() const
{
    objPos returnTail;
    returnTail.pos->x = aList[listSize - 1].pos->x;
    returnTail.pos->y = aList[listSize - 1].pos->y;
    returnTail.symbol = aList[listSize - 1].symbol;
    return returnTail;  
}

objPos objPosArrayList::getElement(int index) const
{
    objPos returnElement;
  
    if(index >= listSize) index = listSize - 1;
    if(index < 0) index = 0;

    returnElement.pos->x = aList[index].pos->x;
    returnElement.pos->y = aList[index].pos->y;
    returnElement.symbol = aList[index].symbol;

    return returnElement; 
}