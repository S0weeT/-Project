#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>


class Vector {
public:
    int *data;
    size_t size;
    size_t capacity;
    // 默认构造函数
    Vector() : data(nullptr), size(0), capacity(0) {}
    // 析构函数
    ~Vector();
    // 复制构造函数
    Vector(const Vector &other);
    // 用数组构造Vector
    Vector(const int *array, size_t n);

    int empty() const { return size == 0; }
    size_t getcapacity() const { return capacity; }
    size_t getsize() const { return size; }
    void pop();
    void push(int value);
    int &at(size_t index) const;
    //(赋值=)
    Vector &operator=(const Vector &other);
    //([]运算符重载)
    int &operator[](size_t index);
    const int &operator[](size_t index) const;
    //(加法+)
    friend Vector operator+(const Vector &v1, const Vector &v2);
    //(前置,后置递增)
    Vector &operator++();
    Vector operator++(int);
    //(左移，右移运算符重载)
    friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    friend std::istream &operator<<(std::istream &is, Vector &v);
    // 预留内存
    void reserve(size_t new_capacity);
    // 释放内存
    void shrink_to_fit();
    // 某位置插入元素
    void insert(size_t index, int value);
    // 某位置插入某长度的元素
    void insert(size_t index, const int *array, size_t count);
    // 删除某位置的元素
    void erase(size_t index);
    // 删除某位置某长度的元素
    void erase(size_t index, size_t);
    // 交换两个Vector的数据元素
    void swap(Vector &other);
};
#endif //Vector.h