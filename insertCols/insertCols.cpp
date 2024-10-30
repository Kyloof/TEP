//
// Created by janku on 21.10.2024.
//

#include "insertCols.h"
#include <iostream>


using namespace std;

void insertCols(int index, int numberOfColumns, int** table, int rowSize, int columnSize){
    int newSize = columnSize + numberOfColumns;
    for (int i = 0; i < rowSize; i++){
        int* newTab = new int[newSize];

        for (int j = 0; j < index; j++){
            newTab[j] = table[i][j];
        }


        for (int j = index + numberOfColumns; j < newSize; j++){
            newTab[j] = table[i][j - numberOfColumns];
        }

        delete[] table[i];
        table[i] = newTab;
    }
}

void showTab(int** table, int rowSize, int columnSize){
    cout << "Table: " << endl;
    for (int i = 0; i < rowSize; i++){
        for (int j = 0; j < columnSize; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

