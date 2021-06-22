/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: Queue.cpp                                                         **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** Queue.cpp description.                                                  **/
/** ----------------------------------------------------------------------- **/
/**                                                                         **/
/** Permission is hereby granted, free of charge, to any person obtaining a **/
/** copy of this software and associated documentation files                **/
/** (the "Software") to deal in the Software without restriction, including **/
/** without limitation the rights to use, copy, modify, merge, publish,     **/
/** distribute, sublicense, and/or sell copies of the Software, and to      **/
/** permit persons to whom the Software is furnished to do so, subject to   **/
/** the following conditions:                                               **/
/**                                                                         **/
/** The above copyright notice and this permission notice shall be included **/
/** in all copies or substantial portions of the Software.                  **/
/**                                                                         **/
/** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS **/
/** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              **/
/** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  **/
/** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    **/
/** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    **/
/** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       **/
/** SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  **/
/**                                                                         **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Preprocessors                             **/
/*****************************************************************************/

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <iostream>
#include "Queue.hpp"

/*****************************************************************************/
/**                                   Macros                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Data Types                              **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Constants                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Variables                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                  Classes                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                            Function Prototypes                          **/
/*****************************************************************************/

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

/************************************ Node ***********************************/
template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
}

/**************************** Double Ended Queue *****************************/
template <typename T>
DEQueue<T>::DEQueue()
{

}

template <typename T>
DEQueue<T>::~DEQueue()
{

}

template <typename T>
void DEQueue<T>::Create(const std::vector<T> &v)
{
    size_t size = v.size();

    for (size_t i = 0; i < size; i++)
    {
        EnqueueRear(v.at(i));
    }
}

template <typename T>
void DEQueue<T>::Display()
{
    std::shared_ptr<Node<T>> ptr = front;
    if (front == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    std::cout << "Front -> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next_node;
    }
    std::cout << "Rear" << std::endl;
}

template <typename T>
void DEQueue<T>::EnqueueFront(T data)
{
    std::shared_ptr<Node<T>> ptr;

    if (front != nullptr)
    {
        ptr = std::make_shared<Node<T>>(data);
        ptr->next_node = front;
        front = ptr;
    }
    else
    {
        front = std::make_shared<Node<T>>(data);
        rear = front;
    }
}

template <typename T>
void DEQueue<T>::EnqueueRear(T data)
{
    std::shared_ptr<Node<T>> ptr;

    if (rear != nullptr)
    {
        ptr = std::make_shared<Node<T>>(data);
        rear->next_node = ptr;
        rear = ptr;
    }
    else
    {
        rear = std::make_shared<Node<T>>(data);
        front = rear;
    }
}

template <typename T>
void DEQueue<T>::DequeueFront()
{
    if (front == nullptr || rear == nullptr) { return; }

    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next_node;
    }
}

template <typename T>
void DEQueue<T>::DequeueRear()
{
    std::shared_ptr<Node<T>> ptr = front;
    if (front == nullptr || rear == nullptr) { return; }
    
    if (rear == front)
    {
        rear = front = nullptr;
    }
    else
    {
        while (ptr->next_node != rear)
        {
            ptr = ptr->next_node;
        }

        ptr->next_node = nullptr;
        rear = ptr;
    }
}

template <typename T>
T DEQueue<T>::GetFront()
{
    T data = T();
    
    if (front != nullptr)
    {
        data = front->data;
    }

    return data;
}

template <typename T>
T DEQueue<T>::GetRear()
{
    T data = T();

    if (rear != nullptr)
    {
        data = rear->data;
    }

    return data;
}

template <typename T>
bool DEQueue<T>::IsEmpty()
{
    return (front == nullptr) || (rear == nullptr);
}

/****************************** Priority Queue *******************************/
template <typename T>
PriorityQueue<T>::PriorityQueue(bool priority)
{
    this->priority = priority;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{

}

template <typename T>
void PriorityQueue<T>::Create(const std::vector<T> &v)
{
    size_t size = v.size();

    for (size_t i = 0; i < size; i++)
    {
        Enqueue(v.at(i));
    }
}

template <typename T>
void PriorityQueue<T>::Display()
{
    std::shared_ptr<Node<T>> ptr = front;

    if (front == nullptr)
    {
        std::cout << "Empty" << std::endl;
    }

    std::cout << "Front -> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next_node;
    }
    std::cout << "Rear" << std::endl;
}

template <typename T>
void PriorityQueue<T>::Enqueue(T data)
{
    std::shared_ptr<Node<T>> qtr, ptr = front;
    std::shared_ptr<Node<T>> aux_ptr = std::make_shared<Node<T>>(data);

    if (priority == false)
    {
        while (ptr != nullptr)
        {
            qtr = ptr;
            ptr = ptr->next_node;
        }
    }
    else
    {
        while (ptr != nullptr && data > ptr->data)
        {
            qtr = ptr;
            ptr = ptr->next_node;
        }
    }

    if (ptr == front)
    {
        aux_ptr->next_node = front;
        front = aux_ptr;
    }
    else
    {
        aux_ptr->next_node = qtr->next_node;
        qtr->next_node = aux_ptr;
    }
}

template <typename T>
void PriorityQueue<T>::Dequeue()
{
    if (front == nullptr) { return; }
    front = front->next_node;
}

template <typename T>
T PriorityQueue<T>::GetFront()
{
    T data = T();

    if (front != nullptr)
    {
        data = front->data;
    }

    return data;
}

template <typename T>
bool PriorityQueue<T>::IsEmpty()
{
    return front == nullptr;
}

// Explicit Initialization Declaration
template class DEQueue<int>::DEQueue;
template class DEQueue<char>::DEQueue;
template class DEQueue<float>::DEQueue;

template class PriorityQueue<int>::PriorityQueue;
template class PriorityQueue<char>::PriorityQueue;
template class PriorityQueue<float>::PriorityQueue;

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/