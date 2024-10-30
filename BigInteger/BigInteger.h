//
// Created by janku on 29.10.2024.
//

#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <string>



class BigInteger {
public:
    //Constructors
    BigInteger();
    BigInteger(int value);
    BigInteger(const BigInteger &other);
    ~BigInteger();

    //Operators
    void operator= (int newInt);
    void operator= (const BigInteger &otherBigInt);
    BigInteger operator+ (int newInt);
    BigInteger operator+ (const BigInteger &otherBigInt);
    BigInteger operator- (int newInt);
    BigInteger operator- (const BigInteger &otherBigInt);
    BigInteger operator* (int newInt);
    BigInteger operator* (const BigInteger &otherBigInt);
    BigInteger operator/ (int newInt);
    BigInteger operator/ (const BigInteger &otherBigInt);

    //Fun
    int returnNumber() const;
    std::string toString();



private:
    int *numbers;
    int size;
    int capacity;
    bool negative;


    //Fun
    BigInteger add(const BigInteger &bigInt,const BigInteger &otherBigInt);
    BigInteger substract(const BigInteger &left, const BigInteger &right);
    BigInteger multiply(const BigInteger &left, const BigInteger &right);
    void increaseCapacity();
    void decreaseCapacity();
    void allocateNewDigit(int number);
};



#endif //BIGINTEGER_H
