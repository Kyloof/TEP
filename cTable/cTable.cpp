//
// Created by janku on 21.10.2024.
//
#include "cTable.h"
#include <iostream>

Table::Table() {
    name = DEFAULT_NAME;
    table = new int[DEFAULT_LENGTH];
    tableSize = DEFAULT_LENGTH;
    std::cout << "bezp: " << name << std::endl;
}

Table::Table(std::string name, int size) {
    this->name = name;
    table = new int[size];
    tableSize = size;
    std::cout << "param: " << name << std::endl;
}

Table::Table(Table &other) {
    name = other.name + "_copy";
    table = other.copyTable();
    tableSize = other.tableSize;
    std::cout << "kopia: " << name << std::endl;
}

int *Table::copyTable() {
    int *copy = new int[tableSize];
    for (int i = 0; i < tableSize; i++) {
        copy[i] = table[i];
    }
    return copy;
}

Table::~Table() {
    delete [] table;
    std::cout << "usuwam: " << name << std::endl;
}

void Table::setName(std::string name) {
    this->name = name;
}

int Table::getSize() {
    return tableSize;
}

std::string Table::getName() {
    return name;
}

bool Table::setNewSize(int newSize) {
    if (newSize <= 0) {
        return false;
    }

    int* newTable = new int[newSize];
    for (int i = 0; i < (tableSize < newSize ? tableSize : newSize); i++)
    {
        newTable[i] = table[i];
    }
    delete[] table;
    table = newTable;
    tableSize = newSize;
    return true;
}

Table *Table::clone() { return new Table(*this); }