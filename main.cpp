// main.cpp

#include "cTable/cTableTest.h"
#include "cTable/cTable.h"
#include <iostream>

#include "allocateTableFill34/allocateTableFill34.h"
#include "allocTable2Dim/allocTable2Dim.h"
#include "deallocTable2Dim/deallocTable2Dim.h"
#include "insertCols/insertCols.h"
#include "BigInteger/BigInteger.h"

int main() {
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for allocateTableFill34" << std::endl;
    std::cout << std::endl;

    allocateTableFill34(13);
    std::cout << std::endl;

    allocateTableFill34(3);
    std::cout << std::endl;

    allocateTableFill34(-2);
    std::cout << std::endl;

    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for allocTable2Dim" << std::endl;
    std::cout << std::endl;

    int **piTable;
    std::cout << allocTable2Dim(&piTable, 5, 3);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for deallocTable2Dim" << std::endl;
    std::cout << std::endl;

    int **piTable2;
    piTable2 = new int *[5];

    for (int i = 0; i < 5; i++) {
        piTable2[i] = new int[3];
    }

    std::cout << deallocTable2Dim(piTable2, 5);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for cTable" << std::endl;
    std::cout << std::endl;


    testDefaultConstructor();
    std::cout << std::endl;

    testParameterizedConstructor();
    std::cout << std::endl;

    testCopyConstructor();
    std::cout << std::endl;

    testSetName();
    std::cout << std::endl;

    testSetNewSize();
    std::cout << std::endl;

    testClone();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for insertCols" << std::endl;
    std::cout << std::endl;


    int rowSize = 3;
    int columnSize = 5;
    int numberOfColumns = 4;

    int **tab = new int *[rowSize];
    for (int i = 0; i < rowSize; i++) {
        tab[i] = new int[columnSize];
        for (int j = 0; j < columnSize; j++) {
            tab[i][j] = i * j + j;
        }
    }

    showTab(tab, rowSize, columnSize);

    insertCols(2, numberOfColumns, tab, rowSize, columnSize);
    std::cout << std::endl;

    showTab(tab, rowSize, columnSize + numberOfColumns);

    for (int i = 0; i < rowSize; i++) {
        delete[] tab[i];
    }
    delete[] tab;

    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;


    std::cout << "Tests for BigInteger" << std::endl;

    BigInteger bigInteger;
    BigInteger bigInteger2;

    std::cout << "Addition tests" << std::endl << std::endl;
    std::cout << "1. both positive" << std::endl << std::endl;
    std::cout << "1.1.1 size1 > size2" << std::endl;
    bigInteger = 105;
    bigInteger2 = 10;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 115 << std::endl;

    std::cout << "1.1.2 size1 = size2" << std::endl;
    bigInteger = 105;
    bigInteger2 = 120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 225 << std::endl;

    std::cout << "1.1.3 size1 < size2" << std::endl;
    bigInteger = 15;
    bigInteger2 = 120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 135 << std::endl << std::endl;

    std::cout << "1.2. both negative" << std::endl << std::endl;
    std::cout << "1.2.1 size1 > size2" << std::endl;
    bigInteger = -105;
    bigInteger2 = -10;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -115 << std::endl;

    std::cout << "1.2.2 size1 = size2" << std::endl;
    bigInteger = -105;
    bigInteger2 = -120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -225 << std::endl;

    std::cout << "1.2.3 size1 < size2" << std::endl;
    bigInteger = -15;
    bigInteger2 = -120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -135 << std::endl << std::endl;

    std::cout << "1.3. no1 positive, no2 negative" << std::endl << std::endl;
    std::cout << "1.3.1 size1 > size2" << std::endl;
    bigInteger = 105;
    bigInteger2 = -10;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 95 << std::endl;

    std::cout << "1.3.2 size1 = size2, no1 > no2" << std::endl;
    bigInteger = 125;
    bigInteger2 = -120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 5 << std::endl;

    std::cout << "1.3.3 size1 = size2, no1 < no2" << std::endl;
    bigInteger = 115;
    bigInteger2 = -120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -5 << std::endl;

    std::cout << "1.3.4 size1 < size2" << std::endl;
    bigInteger = 15;
    bigInteger2 = -120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -105 << std::endl << std::endl;

    std::cout << "1.4. no1 negative, no2 positive" << std::endl << std::endl;
    std::cout << "1.4.1 size1 > size2" << std::endl;
    bigInteger = -105;
    bigInteger2 = 10;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -95 << std::endl;

    std::cout << "1.4.2 size1 = size2, no1 > no2" << std::endl;
    bigInteger = -125;
    bigInteger2 = 120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -5 << std::endl;

    std::cout << "1.4.3 size1 = size2, no1 < no2" << std::endl;
    bigInteger = -115;
    bigInteger2 = 120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 5 << std::endl;


    std::cout << "1.4.4 size1 < size2" << std::endl;
    bigInteger = -15;
    bigInteger2 = 120;
    bigInteger = bigInteger + bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 105 << std::endl << std::endl;

    std::cout << "Substraction tests" << std::endl << std::endl;
    std::cout << "2. both positive" << std::endl << std::endl;
    std::cout << "2.1.1 size1 > size2" << std::endl;
    bigInteger = 105;
    bigInteger2 = 10;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 95 << std::endl;

    std::cout << "2.1.2 size1 = size2, no1>no2" << std::endl;
    bigInteger = 120;
    bigInteger2 = 105;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 15 << std::endl;

    std::cout << "2.1.3 size1 = size2, no1<no2" << std::endl;
    bigInteger = 105;
    bigInteger2 = 120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -15 << std::endl;

    std::cout << "2.1.4 size1 < size2" << std::endl;
    bigInteger = 15;
    bigInteger2 = 120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -105 << std::endl << std::endl;

    std::cout << "2.2. both negative" << std::endl << std::endl;

    std::cout << "2.2.1 size1 > size2" << std::endl;
    bigInteger = -105;
    bigInteger2 = -10;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -95 << std::endl;

    std::cout << "2.2.2 size1 = size2, no1>no2" << std::endl;
    bigInteger = -105;
    bigInteger2 = -120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 15 << std::endl;

    std::cout << "2.2.3 size1 = size2, no1<no2" << std::endl;
    bigInteger = -120;
    bigInteger2 = -105;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -15 << std::endl;

    std::cout << "2.2.4 size1 < size2" << std::endl;
    bigInteger = -15;
    bigInteger2 = -120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 105 << std::endl << std::endl;

    std::cout << "2.3. no1 positive, no2 negative" << std::endl << std::endl;

    std::cout << "2.3.1 size1 > size2" << std::endl;
    bigInteger = 105;
    bigInteger2 = -10;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 115 << std::endl;

    std::cout << "2.3.2 size1 = size2, no1 > no2" << std::endl;
    bigInteger = 125;
    bigInteger2 = -120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 245 << std::endl;

    std::cout << "2.3.3 size1 = size2, no1 < no2" << std::endl;
    bigInteger = 115;
    bigInteger2 = -120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 235 << std::endl;

    std::cout << "2.3.4 size1 < size2" << std::endl;
    bigInteger = 15;
    bigInteger2 = -120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 135 << std::endl << std::endl;

    std::cout << "2.4. no1 negative, no2 positive" << std::endl << std::endl;
    std::cout << "2.4.1 size1 > size2" << std::endl;
    bigInteger = -105;
    bigInteger2 = 10;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -115 << std::endl;

    std::cout << "2.4.2 size1 = size2, no1 > no2" << std::endl;
    bigInteger = -125;
    bigInteger2 = 120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -245 << std::endl;

    std::cout << "2.4.3 size1 = size2, no1 < no2" << std::endl;
    bigInteger = -115;
    bigInteger2 = 120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -235 << std::endl;

    std::cout << "2.4.4 size1 < size2" << std::endl;
    bigInteger = -15;
    bigInteger2 = 120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -135 << std::endl;


    std::cout << "2.4. equal" << std::endl << std::endl;

    std::cout << "2.5.1 no1 = no2" << std::endl;
    bigInteger = 120;
    bigInteger2 = 120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 0 << std::endl;
    std::cout << "2.5.2 -no1 = -no2" << std::endl;
    bigInteger = -120;
    bigInteger2 = -120;
    bigInteger = bigInteger - bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 0 << std::endl;


    std::cout << "Multiplication tests" << std::endl << std::endl;

    std::cout << "3.1. both positive" << std::endl << std::endl;
    std::cout << "3.1.1 size1 > size2" << std::endl;
    bigInteger = 12;
    bigInteger2 = 10;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 120 << std::endl;

    std::cout << "3.1.2 size1 = size2" << std::endl;
    bigInteger = 15;
    bigInteger2 = 15;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 225 << std::endl << std::endl;

    std::cout << "3.2. both negative" << std::endl << std::endl;
    std::cout << "3.2.1 size1 > size2" << std::endl;
    bigInteger = -12;
    bigInteger2 = -10;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 120 << std::endl;

    std::cout << "3.2.2 size1 = size2" << std::endl;
    bigInteger = -15;
    bigInteger2 = -15;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 225 << std::endl << std::endl;

    std::cout << "3.3. no1 positive, no2 negative" << std::endl << std::endl;
    std::cout << "3.3.1 size1 > size2" << std::endl;
    bigInteger = 12;
    bigInteger2 = -10;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -120 << std::endl;

    std::cout << "3.3.2 size1 = size2" << std::endl;
    bigInteger = 15;
    bigInteger2 = -15;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -225 << std::endl << std::endl;

    std::cout << "3.4. no1 negative, no2 positive" << std::endl << std::endl;
    std::cout << "3.4.1 size1 > size2" << std::endl;
    bigInteger = -12;
    bigInteger2 = 10;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -120 << std::endl;

    std::cout << "3.4.2 size1 = size2" << std::endl;
    bigInteger = -15;
    bigInteger2 = 15;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -225 << std::endl << std::endl;

    std::cout << "3.4. one of no = 0" << std::endl << std::endl;
    std::cout << "3.4.2 no1 = 0" << std::endl;
    bigInteger = 0;
    bigInteger2 = 15;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 0 << std::endl;

    std::cout << "3.4.2 no2 = 0" << std::endl;
    bigInteger = 15;
    bigInteger2 = 0;
    bigInteger = bigInteger * bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 0 << std::endl;

    std::cout << "Division tests" << std::endl << std::endl;

    std::cout << "4.1. both positive" << std::endl << std::endl;
    std::cout << "4.1.1 size1 > size2" << std::endl;
    bigInteger = 120;
    bigInteger2 = 10;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 12 << std::endl;

    std::cout << "4.1.2 size1 = size2" << std::endl;
    bigInteger = 228;
    bigInteger2 = 15;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 15 << std::endl << std::endl;

    std::cout << "4.2. both negative" << std::endl << std::endl;
    std::cout << "4.2.1 size1 > size2" << std::endl;
    bigInteger = -120;
    bigInteger2 = -10;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 12 << std::endl;

    std::cout << "4.2.2 size1 = size2" << std::endl;
    bigInteger = -225;
    bigInteger2 = -15;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 15 << std::endl << std::endl;

    std::cout << "4.3. no1 positive, no2 negative" << std::endl << std::endl;
    std::cout << "4.3.1 size1 > size2" << std::endl;
    bigInteger = 120;
    bigInteger2 = -10;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -12 << std::endl;

    std::cout << "4.3.2 size1 = size2" << std::endl;
    bigInteger = 225;
    bigInteger2 = -15;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -15 << std::endl << std::endl;

    std::cout << "4.4. no1 negative, no2 positive" << std::endl << std::endl;
    std::cout << "4.4.1 size1 > size2" << std::endl;
    bigInteger = -120;
    bigInteger2 = 10;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -12 << std::endl;

    std::cout << "4.4.2 size1 = size2" << std::endl;
    bigInteger = -225;
    bigInteger2 = 15;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << -15 << std::endl << std::endl;

    std::cout << "4.5. one of no = 0" << std::endl << std::endl;
    std::cout << "4.5.1 no1 = 0" << std::endl;
    bigInteger = 0;
    bigInteger2 = 15;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: " << 0 << std::endl;

    std::cout << "4.5.2 no2 = 0" << std::endl;
    bigInteger = 15;
    bigInteger2 = 0;
    bigInteger = bigInteger / bigInteger2;
    std::cout << "result: " << bigInteger.toString() << " expected: "  << std::endl;
    return 0;
}











