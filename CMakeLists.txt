cmake_minimum_required(VERSION 3.29)
project(C__)

set(CMAKE_CXX_STANDARD 98)

add_executable(C__ main.cpp
        CTable/cTable.cpp
        CTable/cTable.h
        cTable/cTableTest.cpp
        cTable/cTableTest.h
        allocateTableFill34/allocateTableFill34.cpp
        allocateTableFill34/allocateTableFill34.h
        allocTable2Dim/allocTable2Dim.cpp
        allocTable2Dim/allocTable2Dim.h
        deallocTable2Dim/deallocTable2Dim.cpp
        deallocTable2Dim/deallocTable2Dim.h
        insertCols/insertCols.cpp
        insertCols/insertCols.h
        BigInteger/BigInteger.cpp
        BigInteger/BigInteger.h
)
