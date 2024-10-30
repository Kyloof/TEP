
#include <iostream>
using namespace std;

void allocateTableFill34(int iSize)
{
    if (iSize <= 0)
    {
        cout << "Wrong size value: " << iSize << endl;
        return;
    }

    int *piTable;
    piTable = new int[iSize];

    // Według mnie nie ma niczego złego w umieszczeniu tej zmiennej bezpośrednio w funkcji, ponieważ z nazwy funkcji wynika, iż wypełniamy listę wartościa 34
    const int FILL_34 = 34;
    for (int i = 0; i < iSize; i++)
    {
        //alt wersja
        *(piTable+i) = FILL_34;

        //piTable[i] = FILL_34;
    }

    cout << "Filled tab with size: " << iSize << endl;
    for (int i = 0; i < iSize; i++)
    {
        cout << piTable[i] << " ";
    }
    cout << endl;

    //clean memory
    delete[] piTable;
}



