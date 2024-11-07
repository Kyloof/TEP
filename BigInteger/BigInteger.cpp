//
// Created by janku on 29.10.2024.
//

#include "BigInteger.h"

#include <sstream>
#include <iostream>
#include <string>
#include <ostream>
//Constructors - Start
BigInteger::BigInteger() {
    this->size = 0;
    this->capacity = 0;
    this->negative = false;
    this->numbers = NULL;
}//Finished

BigInteger::BigInteger(int value) {
    this->size = 0;
    this->capacity = 0;
    this->negative = (value < 0) ? true : false;
    this->numbers = NULL;
    allocateNewDigit(value);
}//Finished

BigInteger::BigInteger(const BigInteger &other) {
    size = other.size;
    capacity = other.capacity;
    negative = other.negative;
    numbers = new int[size];
    std::copy(other.numbers, other.numbers + size, numbers);
    /*for (int i = 0; i < size; i++) {
        numbers[i] = other.numbers[i]; // Deep copy
    }*/
}//Finished

BigInteger::~BigInteger() {
    delete[] numbers;
    this->size = 0;
    this->capacity = 0;
    this->negative = false;
}//Finished
//Constructors - End



//Operators - Start
void BigInteger::operator= (const BigInteger &other) {
    if (this != &other) {
        delete[] this->numbers;
        this->size = other.size;
        this->negative = other.negative;
        this->capacity = other.capacity;
        this->numbers = new int[size];
        std::copy(other.numbers, other.numbers + size, numbers);
    }
}// FINISHED

void BigInteger::operator=(int newInt) {
    delete[] this->numbers;
    this->size = 0;
    this->capacity = 0;

    if (newInt == 0) {
        this->negative = false;
        allocateNewDigit(0);
        return;
    }

    this->negative = (newInt < 0) ? true : false;
    if (newInt < 0) newInt = newInt*=-1;
    while (newInt != 0) {
        allocateNewDigit(newInt%10);
        newInt = newInt / 10;
    }//Finished
}

BigInteger BigInteger::operator+(int newInt) {
    //if list is empty
    if (this->size == 0) {
        this->operator=(newInt);
        return *this;
    }
    BigInteger temp = newInt;
    return *this + temp;
} //Finished


BigInteger BigInteger::operator+(const BigInteger &otherBigInt) {
    //left - , right +
    if (otherBigInt.negative && !this->negative) {
        return substract(*this, otherBigInt);
    }

    //left +, right -
    if(!otherBigInt.negative && this->negative) {
        BigInteger result = substract(otherBigInt, *this);
        return result;
    }
    BigInteger result = add(*this,otherBigInt);
    //left -, right -
    if (otherBigInt.negative && this->negative) result.negative = true;
    return result;
}//Finished


BigInteger BigInteger::operator-(int newInt) {
    //if list is empty
    if (this->size == 0) {
        this->operator=(newInt);
        return *this;
    }

    BigInteger temp = newInt;
    return *this - temp;
}//Finished

BigInteger BigInteger::operator-(const BigInteger &otherBigInt) {
    //left-, right+
    if (this->negative && !otherBigInt.negative) {
        BigInteger result = add(*this, otherBigInt);
        result.negative = true;
        return result;
    }
    //left+, right-
    if (!this->negative && otherBigInt.negative) {
        BigInteger result = add(*this, otherBigInt);
        result.negative = false;
        return result;
    }

    BigInteger result = substract(*this, otherBigInt);
    if ((this->negative && otherBigInt.negative) && (result.returnNumber()!=0)) result.negative = !result.negative;
    return result;
}//Finished

BigInteger BigInteger::operator*(int newInt) {
    BigInteger bigInteger;
    if (size == 0) {
        return bigInteger;
    }

    BigInteger other = newInt;
    return *this * other;
}//Finished

BigInteger BigInteger::operator*(const BigInteger &otherBigInt) {
    BigInteger result;
    if ((this->size == 1 || otherBigInt.size == 1) && (this->numbers[0] == 0 || otherBigInt.numbers[0] == 0)) {
        result = 0;
        return result;
    }
    if ((this->negative && !otherBigInt.negative) || (!this->negative && otherBigInt.negative)) {
        result = multiply(*this, otherBigInt);
        result.negative = true;
        return result;
    }
    result = multiply(*this, otherBigInt);
    return result;
}//Finished

BigInteger BigInteger::operator/(int newInt) {
    BigInteger result;
    if (newInt == 0 || size == 0) {
        return result;
    }

    BigInteger other = newInt;
    return *this / other;
}//Finished

BigInteger BigInteger::operator/(const BigInteger &otherBigInt) {
    BigInteger result;
    if (this->size == 1 && this->numbers[0] == 0) {
        result = 0;
        return result;
    }
    if (otherBigInt.size == 1 && otherBigInt.numbers[0] == 0) {
        return result;
    }
    if ((this->negative && !otherBigInt.negative) || (!this->negative && otherBigInt.negative)) {
        result = divide(*this, otherBigInt);
        result.negative = true;
        return result;
    }
    result = divide(*this, otherBigInt);
    return result;
}//Finished
//Operators - End

//Fun - Start
BigInteger BigInteger::add(const BigInteger &bigInt,const BigInteger &otherBigInt) {
    BigInteger result;
    int temp = 0;
    int i = 0;
    int numb = 0;

    //while can add element between 2 lists
    while (i < bigInt.size && i < otherBigInt.size) {

        numb = bigInt.numbers[i] + otherBigInt.numbers[i] + temp;
        temp = numb / 10;
        numb = numb - temp*10;

        result.allocateNewDigit(numb);
        i++;
    }

    //if otherBigInt is larger than the BigInt, add the rest to result
    if (otherBigInt.size > bigInt.size) {
        for(int j = i; j < otherBigInt.size; j++) {

            numb = otherBigInt.numbers[j] + temp;
            temp = numb / 10;
            numb = numb - temp*10;

            result.allocateNewDigit(numb);
        }
    }
    //if BigInt is larger than the otherBigInt, add the rest to result
    else if (bigInt.size > otherBigInt.size) {
        for(int j = i; j < bigInt.size; j++) {

            numb = bigInt.numbers[j] + temp;
            temp = numb / 10;
            numb = numb - temp*10;

            result.allocateNewDigit(numb);
        }
    }
    //add the overload
    while(temp > 0) {
        result.allocateNewDigit(temp % 10);
        temp = temp/10;
    }
    return result;
}//Finished

BigInteger BigInteger::substract(const BigInteger &left, const BigInteger &right) {
    BigInteger result;
    int numb;

    //1 normal substraction left.size>right.size
    if (left.size > right.size) {
        for (int i = 0; i < left.size; i++) {
            if (i < right.size) numb = left.numbers[i] - right.numbers[i];
            else numb = left.numbers[i];
            if (numb < 0) {
                left.numbers[i + 1] -= 1;
                numb += 10;
            }
            result.allocateNewDigit(numb);
        }
    }

    //2 if equal size
    else if (left.size == right.size){
        int i = left.size-1;
        bool leftIsLarger = (numbers[i] > right.numbers[i] ? true : false);
        while (left.numbers[i] == right.numbers[i]) {
            i-=1;
            if (left.numbers[i] != right.numbers[i]) {
                leftIsLarger = (left.numbers[i] >= right.numbers[i] ? true : false);
                break;
            }
            // 2.1 left = right
            if (i == 0 && left.numbers[i] == right.numbers[i]) {
                result = 0;
                result.negative = false;
                return result;
            }
        }
        //2.2 left > right
        if (leftIsLarger) {
            result.negative = false;

            for (i = 0; i < left.size; i++) {
                numb = left.numbers[i] - right.numbers[i];
                if (numb < 0) {
                    left.numbers[i + 1] -= 1;
                    numb += 10;
                }
                result.allocateNewDigit(numb);
            }
        }
        //2.3 right > left = -(right - left) = left-  right
        else {
            result.negative = true;

            for (i = 0; i < left.size; i++) {
                numb = right.numbers[i] - left.numbers[i];
                if (numb < 0) {
                    right.numbers[i + 1] -= 1;
                    numb += 10;
                }
                result.allocateNewDigit(numb);
            }

        }
    }
    // 3. right.size > left.size
    else {
        result.negative = true;
        for (int i = 0; i < right.size; i++) {
            if (i < left.size) numb = right.numbers[i] - left.numbers[i];
            else numb = right.numbers[i];

            if (numb < 0) {
                right.numbers[i + 1] -= 1;
                numb += 10;
            }
            result.allocateNewDigit(numb);
        }
    }
    int i = result.size - 1;
    while (i >= 0 && result.numbers[i] == 0) {
        result.size -= 1;
        i--;
    }
    result.decreaseCapacity();
    return result;
}//Finished

BigInteger BigInteger::multiply(const BigInteger &left, const BigInteger &right) {
    BigInteger result;
    BigInteger* results = new BigInteger[right.size];
    int numb;
    int temp = 0;
    int power = 0;
    for (int i = 0; i < right.size; i++) {
        for(int j = 0; j < power; j++) {
            results[i].allocateNewDigit(0);
        }
        for (int j = 0; j < left.size; j++) {
            numb = right.numbers[i] * left.numbers[j] + temp;
            temp = numb/10;
            numb -= temp * 10;
            results[i].allocateNewDigit(numb);
        }
        while (temp!=0) {
            results[i].allocateNewDigit(temp);
            temp = temp/10;
        }
        power++;
    }

    for(int i = 0; i < right.size - 1; i++) {
        results[i+1] = add(results[i],results[i+1]);
    }


    result = results[right.size-1];
    delete[] results;
    return result;
}//Finished

BigInteger BigInteger::divide(const BigInteger &left, const BigInteger &right) {
    BigInteger result;
    BigInteger temp;
    int multi;
    int showvalueresult;
    for (int i = left.size - 1; i >= 0; i--) {
        temp = temp * 10 + left.numbers[i];
        int showvaluetemp = temp.returnNumber();
        int showValueRight = right.returnNumber();

        multi = 0;
        while (compareAbs(temp,right)) {
            temp = substract(temp,right);
            showvaluetemp = temp.returnNumber();
            multi++;
        }
        showvaluetemp = temp.returnNumber();
        result = result * 10 + multi;
        showvalueresult = result.returnNumber();
    }

    return result;
}//Finished

BigInteger BigInteger::operator>=(BigInteger &otherBigInt) {
    otherBigInt.operator=(*this);
    return *this;
}

BigInteger operator>=(int left, BigInteger &right) {
    right = left;
    return right;
}

bool BigInteger::compareAbs(const BigInteger &left, const BigInteger &right) {


    // if different size
    if (left.size != right.size) {
        if (left.size > right.size) {
            return true;
        }
        else{
            return false;
        }
    }
    //if equal
    int i = left.size-1;
    bool leftIsLargerOrEq = (numbers[i] >= right.numbers[i] ? true : false);
    while (left.numbers[i] == right.numbers[i]) {
        i-=1;
        if (left.numbers[i] != right.numbers[i]) {
            return (left.numbers[i] >= right.numbers[i] ? true : false);
            break;
        }
        // left == right
        if (i == 0 && left.numbers[i] == right.numbers[i]) {
            return true;
        }
    }
    return leftIsLargerOrEq;
}//Finished

void BigInteger::increaseCapacity() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    int *newNumbers = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newNumbers[i] = this->numbers[i];
    }
    delete[] this->numbers;
    this->numbers = newNumbers;
    this->capacity = newCapacity;
}//Finished


void BigInteger::decreaseCapacity() {
    int newCapacity = 1;
    if (size == 0) {
        this -> capacity = 0;
    }
    else {
        while (newCapacity < size) {
            newCapacity *= 2;
        }
    }
    if (newCapacity == capacity) return;

    this->capacity = newCapacity;
    int *newNumbers = new int[capacity];
    for (int i = 0; i < size; i++) {
        newNumbers[i] = this->numbers[i];
    }
    delete[] this->numbers;
    this->numbers = newNumbers;
}//Finished


void BigInteger::allocateNewDigit(int digit) {
    if(capacity == 0) {
        this->numbers = new int[1];
        this->numbers[0] = digit;
        this->size = 1;
        this->capacity = 1;

    }
    else if (size + 1 >= capacity) {
        increaseCapacity();

        numbers[size] = digit;
        this->size = size + 1;
    }
    else {
        this->numbers[size] = digit;
        this->size = size + 1;
    }
}//Finished

int BigInteger::returnNumber() const {
    int result = 0;
    int power = 1;
    for (int i = 0; i < size; i++) {
        result += numbers[i]*power;
        power*=10;
    }
    return result;
}//Finished

std::string BigInteger::toString() {
    std::string result;
    if (negative) {
        result = "-";
    }
    for (int i = size - 1; i >= 0; i--) {
        result += (numbers[i] + '0');
    }
    return result;
}//Finished




