//
// Created by janku on 21.10.2024.
//

#ifndef CTABLE_H
#define CTABLE_H

#include <string>



class Table {
public:
    Table();
    Table(std::string name, int size);
    Table(Table &other);
    ~Table();
    void setName(std::string name);
    std::string getName();
    bool setNewSize(int newSize);
    int getSize();
    Table *clone();
    //constants
    std::string DEFAULT_NAME = "DefaultName";
    int DEFAULT_LENGTH = 3;

private:
    std::string name;
    int *table;
    int tableSize;
    int* copyTable();
};


#endif //CTABLE_H
