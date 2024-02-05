#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using namespace std;


// User defined Container
template <typename T>
class Container
{
private:
    T* data;
    size_t size;
    size_t capacity;

public:

    class iterator
    {
    private:
        T* ptr_;
    public:
        iterator(T* pointer ): ptr_(pointer) {}
        iterator(): ptr_(nullptr) {}

        bool operator== (const iterator& other)
        {
            return ptr_ == other.ptr_;
        }

        bool operator!= (const iterator& other)
        {
            return ptr_ != other.ptr_;
        }

        iterator& operator++()
        {
            ptr_++;
            return *this;
        }

        iterator& operator++(int junk)
        {
            iterator temp = *this;
            ++*this;
            return temp;
        }

        T& operator* ()
        {
            return *ptr_;
        }

        T* operator->()
        {
            return ptr_;
        }

        bool operator>=(const iterator& other)
        {
            return ptr_ >= other.ptr_;
        }

        bool operator< (const iterator& other)
        {
            return ptr_ < other.ptr_;
        }

        T* operator+(const Container<T>::iterator& other)
        {
            return ptr_ + other.ptr_;
        }

        T* get_ptr()
        {
            return ptr_;
        }

    };

    // Default constructor
    Container(): data(NULL), capacity(0), size(0)
    {
        data = new T[capacity];
    }

    // Destructor
    ~Container()
    {
        delete[] data;
        data = NULL;
    }

    iterator begin()
    {
        return iterator(data);
    }

    iterator end()
    {
        return iterator(data + size);
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");

        return data[index];
    }

    T& operator[](iterator index)
    {
        if(index >= end() || index < begin())
            throw std::out_of_range("Iterator out of range");

        return *index;
    }

    // Resizing the array depending on current situation
    void resize()
    {
        capacity = capacity == 0 ? 2 : max(2 * size,(size_t)2);
        T* new_data = new T[capacity];
        copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
    }

    // Insert At 0 and shift
    void AddAtBegin(T element)
    {
        if (size == capacity)   resize();

        copy(data, data+ size+ 1, data+ 1);

        data[0] = element;
        size++;
    }

    //Insert At some index and shift the rest
    void AddAtMiddle(T element, int index)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");

        if (size == capacity)   resize();

        copy(data+ index, data+ size + 1, data+ index+ 1);

        data[index] = element;
        size++;
    }

    // Insert at the end (Push)
    void AddAtEnd(T element)
    {
        if (size == capacity)   resize();

        data[size] = element;
        size++;
    }

    // Remove based on values
    void RemoveValue(T element)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == element)
            {
                copy(data+ i + 1, data+ size, data+ i);
                size--;
                break;
            }
        }

        if(size >= 3 * capacity) resize();

    }

    // Remove based on index
    void RemovePosition(size_t index)
    {
        if(index < 0 || index > size)
            throw::invalid_argument("Position Out Of Range");

        copy(data+ index + 1, data+ size, data + index);
        size--;

        if(size >= 3 * capacity) resize();
    }

    size_t IndexGetter(iterator index)
    {
        for(size_t i = 0; i < size; i++)
        {
            if(*(index.get_ptr()) == data[i])
                return i;
        }

        return -1;
    }

    // Remove based on iterator
    void RemovePosition(iterator index)
    {
        if(index >= end() || index < begin())
            throw::invalid_argument("Position Out Of Range");

        copy(data+ IndexGetter(index)+ 1, data+ size, data + IndexGetter(index));
        size--;

        if(size >= 3 * capacity) resize();
    }

    // Function returns the reference of search element
    T& find(const T& search)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] == search)
            {
                return &data[i];
            }
        }

        // Return nullptr if the search element is not found.
        return nullptr;
    }

    // Sorting elements ascendingly
    void sort()
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                if (data[i] > data[j])
                {
                    swap(data[i], data[j]);
                }
            }
        }
    }

    int get_size() const
    {
        return size;
    }

    int get_capacity() const
    {
        return capacity;
    }
};


#endif // CONTAINER_H
