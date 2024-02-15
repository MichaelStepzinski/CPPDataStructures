/*
* Author: Michael Stepzinski
* Date: 2/5/24
* Purpose: Implement a dynamic array data structure
*/

#ifndef DARRAY_H
#define DARRAY_H

 #include <initializer_list>
#include <iostream>

template <typename T>
class DArray
{
private:
    T* m_elements{};
    std::size_t m_size{};
    std::size_t m_backIndex{};

public:
    // Req 001 This function shall initialize the dynamic array with a size of 0
    DArray()
        : m_elements {new T[2]{} }, m_size{2}, m_backIndex{0}
    {
    }

    // Req 001 This function shall initialize a new dynamic array with the passed in values
    // Req 002 This function shall initialize a new dynamic array with a size of the number of passed in variables
    DArray(std::initializer_list<T> list)
        : m_elements{ new T[list.size()]{} }, m_size{ list.size() }, m_backIndex{ list.size() }
    {
        T* next_element = m_elements;
        for (const auto& element : list)
        {
            *next_element = element;
            next_element++;
        }
    }
    
    // Req 001 This function shall initialize a new dynamic array with the same values as the passed in array
    // Req 002 This function shall initialize a new dynamic array with the same size as the passed in array
    // Req 003 This function shall shallow copy the values of the passed in array
    DArray(DArray& copyArray)
        : m_elements{ new T[copyArray.m_size] }
        , m_size{ copyArray.m_size }
        , m_backIndex{copyArray.m_backIndex}
    {
        // explicitly copy each element
        for (std::size_t i{ 0 }; i < copyArray.m_size; ++i)
        {
            m_elements[i] = copyArray.m_elements[i];
        }
    }

    // No unit tests will be written for this destructor
    ~DArray()
    {
        delete[] m_elements;
    }

    // Req 001 This function shall print all contents to cout
    void Print()
    {
        bool first{ true };
        for (std::size_t i{ 0 }; i < m_backIndex; ++i)
        {
            if (!first)
            {
                std::cout << ' ';
            }
            std::cout << m_elements[i];
            first = false;
        }
        std::cout << '\n';
    }

    // Req 001 This function shall add an element to the end of the calling array
    // Req 002 This function shall add increase the current array size by 1
    void Push(const T& item)
    {
        if (m_backIndex == m_size)
        {
            std::size_t new_size{ m_size * 2 };
            // allocate new array
            T* temp{ new T[new_size] };

            // copy old elements into new array
            for (std::size_t i{ 0 }; i < m_size; ++i)
            {
                temp[i] = m_elements[i];
            }
            // delete old allocated memory
            delete[] m_elements;

            // set m_elements to point to new dynamically allocated array
            m_elements = temp;
            
            // set new size
            m_size = new_size;

        }
        // push to array
        m_elements[m_backIndex++] = item;
        m_size++;
    }

    // Req 001 This function shall remove an element from the end of the calling array
    // Req 002 This function shall throw an exception when the calling array is empty
    T Pop()
    {
        if (m_backIndex == 0)
            throw - 1;
        return m_elements[m_backIndex--];
    }

    // Req 001 This function shall return the current size of the array
    int Size()
    {
        return static_cast<int>(m_backIndex);
    }

    // Req 001 This function shall return the element at the specified index if the specified index is valid
    // Req 002 This function shall throw an exception when the index is not valid
    T& operator[] (int index)
    {
        if ((index >= 0) && (index <= m_backIndex))
        {
            return m_elements[index];
        }
        else
        {
            throw - 1;
        }
    }

};

#endif