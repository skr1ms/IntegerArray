#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

class bad_range : public std::exception {
public:
    const char* what() const noexcept override;
};

class bad_length : public std::exception {
public:
    const char* what() const noexcept override;
};

using namespace std;

class IntegerArray {
private:
    int _length{};
    int* _arr{};
    int size;
public:
    IntegerArray() = default;

    IntegerArray(int length);

    IntegerArray(const IntegerArray& a);

    void erase();

    void reallocate(int newLength);

    void resize(int newLength);
   
    int getLength() const { return _length; }

    void insertBefore(int value, int index);

    void remove(int index);

    //void pushBack(int value);

    //void pushFront(int value);

    IntegerArray copy() const;

    int find(int value);

    void pushFront(int value) { insertBefore(value, 0); }

    void pushBack(int value) { insertBefore(value, _length); }

    IntegerArray& operator=(const IntegerArray& a);

    int& operator[](int index);

    ~IntegerArray();
};