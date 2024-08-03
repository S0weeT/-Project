#include"stdio.h"
#include"vector.h"
#include"iostream"

Vector::Vector(const Vector &other) 
{
    reserve(other.capacity);
    memcpy(data, other.data, size * sizeof(int));
    size = other.size;
}

Vector::Vector(const int *array, size_t n) 
{
    reserve(n);
    memcpy(data, array, n * sizeof(int));
    size = n;
}

Vector::~Vector(){
    delete[] data;
}


void Vector::pop(){
    if(size>0){
        --size;
    }
}


void Vector::push(int value){
    if(size>=capacity){
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity);
    }
    data[size++] = value;
}


int& Vector::at(size_t index)const{
    return const_cast<int &>(data[index]);
}


Vector& Vector::operator=(const Vector& other){
    if(this !=&other){
        delete[] data;
        reserve(other.capacity);
        memcpy(data, other.data, other.size * sizeof(int));
        size = other.size;
    }
    return *this;
}


int& Vector::operator[](size_t index){
    return data[index];
}


const int& Vector::operator[](size_t index)const{
    return data[index];
}

Vector  operator+(const Vector&v1,const
Vector& v2){
    Vector result;
    result.reserve(v1.size + v2.size);
    memcpy(result.data, v1.data, v1.size * sizeof(int));
    memcpy(static_cast<int *>(result.data) + v1.size, v2.data, v2.size * sizeof(int));
    result.size = v1.size + v2.size;
    return result;
}


Vector& Vector::operator++(){
    push(0);
    return *this;
}


Vector Vector::operator++(int){
    Vector temp = *this;
    ++(*this);
    return temp;
}


std::ostream& operator <<(std::ostream& os,const Vector& v){
    for (size_t i = 0; i < v.size;++i){
        os << v.data[i] << (i < v.size - 1 ? " " : "");
    }
    return os;
}


std::istream& operator>>(std::istream& is,Vector& v){
    int value;
    while(is>>value){
        v.push(value);
    }
    return is;
}


void Vector::reserve(size_t new_capacity){
if(new_capacity>capacity){
    int *new_data = new int[new_capacity];
    memcpy(new_data, data, size * sizeof(int));
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
}


void Vector::shrink_to_fit(){
   if(capacity>size){
       int *new_data = new int[size];
       memcpy(new_data, data, size * sizeof(int));
       delete[] data;
       data = new_data;
       capacity = size;
   }
}


void Vector::insert(size_t index,int value){
    if(index>size){
        index = size;
    }
    if(size>=capacity){
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity);
    }
    for (size_t i = size; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}


void Vector::insert(size_t index,const int* array,size_t count){
    for (size_t i = 0; i < count;++i){
        insert(index + i, array[i]);
    }
}


void Vector::erase(size_t index){
    if(index<size){
        for (size_t i = index; i < size - 1;++i){
            data[i] = data[i + 1];
        }
        size--;
    }
}


void Vector::erase(size_t index, size_t count){
    for (size_t i = index; i < size && count > 0;++i,--count){
        erase(index);
    }
}


void Vector::swap(Vector& other){
    using std::swap;
    swap(data, other.data);
    swap(size, other.size);
    swap(capacity, other.capacity);
}
