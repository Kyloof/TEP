// tests.cpp
#include "cTableTest.h"
#include "cTable.h"
#include <iostream>

void printTable(Table &table) {
    std::cout << "Table Name: " << table.getName() << ", Table Size: " << table.getSize() << std::endl;
}

void testDefaultConstructor() {
    std::cout << "Test: bezp" << std::endl;
    Table table;
    printTable(table);  // Should print DEFAULT_NAME and DEFAULT_LENGTH
}

void testParameterizedConstructor() {
    std::cout << "Test: param" << std::endl;
    Table table("namedTab", 5);
    printTable(table);  // Should print "tab1" and 5
}

void testCopyConstructor() {
    std::cout << "Test: kopiuj" << std::endl;
    Table original("ogTable", 3);
    Table copy = original;
    printTable(copy);  // Should print "ogTable_copy" and 3
}

void testSetName() {
    std::cout << "Test: setName()" << std::endl;
    Table table("tabName", 5);
    table.setName("NewName");
    printTable(table);  // Should print "NewName" and 5
}

void testSetNewSize() {
    std::cout << "Test: setNewSize()" << std::endl;
    Table table("tabName", 3);
    table.setNewSize(5);
    printTable(table);  // Should print "tabName" and 5
    table.setNewSize(2);
    printTable(table);  // Should print "tabName" and 2
}

void testClone() {
    std::cout << "Test: clone()" << std::endl;
    Table original("tabClone", 4);
    Table *clonedTable = original.clone();
    printTable(*clonedTable);  // Should print "tabClone_copy" and 4
    delete clonedTable;
}
