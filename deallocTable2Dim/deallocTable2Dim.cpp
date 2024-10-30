//
// Created by janku on 21.10.2024.
//

#include "deallocTable2Dim.h"
#include <iostream>

using namespace std;
//wystarczy int**  bo nie zmieniam wskazinka tylko zwalniam pamiec
bool deallocTable2Dim(int **piTable, int iSizeX)
{
    if (piTable == NULL)
    {
        return false;
    }

    for (int i = 0; i < iSizeX; i++)
    {
        delete[] piTable[i];
    }

    delete[] piTable;

    return true;
}

