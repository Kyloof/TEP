#include "allocTable2Dim.h"

#include <iostream>

using namespace std;
//*** - wskaźnik na wskaźnik do wskaźnika
bool allocTable2Dim(int ***piTable, int iSizeX, int iSizeY)
{
    if (iSizeX <= 0 || iSizeY <= 0)
    {
        cout << "Wrong value!" << endl;
        return false;
    }

    *piTable = new int*[iSizeX];
    if (*piTable == NULL)
    {
        return false;
    }

    for (int i = 0; i < iSizeX; i++)
    {
        (*piTable)[i] = new int[iSizeY];

        if ((*piTable)[i] == NULL)
        {
            //WARTO PAMIETAC o zwolnieniu poprzednich wartosci (tabela 2d! patrz przyklad)
            for (int j = 0; j < i; j++)
            {
                delete[] (*piTable)[j];
            }
            delete[] *piTable;
            return false;
        }
    }

    return true;
}