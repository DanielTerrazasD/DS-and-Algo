/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
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
Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int x)
{
    data = x;
    next = nullptr;
}

/*********************************** Queue ***********************************/
Queue::Queue()
{
    front = rear = nullptr;
}

Queue::Queue(int array[], int size)
{
    Node* tmp;
    front = rear = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    front = new Node(array[0]);
    rear = front;

    for (int i = 1; i < size; i++)
    {
        tmp = new Node(array[i]);
        rear->next = tmp;
        rear = tmp;
    }
}

Queue::~Queue()
{
    Node* ptr = front;

    while (front != nullptr)
    {
        front = front->next;
        delete ptr;
        ptr = front;
    }
}

void Queue::Create(int array[], int size)
{
    Node* tmp;

    if (front != nullptr || rear != nullptr) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    front = new Node(array[0]);
    rear = front;

    for (int i = 1; i < size; i++)
    {
        tmp = new Node(array[i]);
        rear->next = tmp;
        rear = tmp;
    }
}

void Queue::Display(void)
{
    Node* ptr = front;

    if (front == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    std::cout << "front -> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "rear" << std::endl;
}

void Queue::Enqueue(int item)
{
    Node* tmp = new Node(item);

    if (rear == nullptr)
    {
        front = rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }
}

void Queue::Dequeue(void)
{
    Node* ptr = front;

    if (front == nullptr) return;
    if (front == rear)
        rear = rear->next;

    front = front->next;
    delete ptr;
}

int Queue::GetFront(void)
{
    if (front == nullptr) return -1;
    return front->data;
}

int Queue::GetRear(void)
{
    if (rear == nullptr) return -1;
    return rear->data;
}

bool Queue::IsEmpty(void)
{
    return front == nullptr;
}

/**************************** Double Ended Queue *****************************/
DEQueue::DEQueue()
{
    front = rear = nullptr;
}

DEQueue::DEQueue(int array[], int size)
{
    Node* tmp;

    front = rear = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    front = new Node(array[0]);
    rear = front;

    for (int i = 1; i < size; i++)
    {
        tmp = new Node(array[i]);
        rear->next = tmp;
        rear = tmp;
    }
}

DEQueue::~DEQueue()
{
    Node* ptr = front;

    while (ptr != nullptr)
    {
        front = front->next;
        delete ptr;
        ptr = front;
    }
}

void DEQueue::Create(int array[], int size)
{
    Node* tmp;

    if (front != nullptr || rear != nullptr) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    front = new Node(array[0]);
    rear = front;

    for (int i = 1; i < size; i++)
    {
        tmp = new Node(array[i]);
        rear->next = tmp;
        rear = tmp;
    }
}

void DEQueue::Display(void)
{
    Node* ptr = front;

    if (front == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    std::cout << "front -> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "rear" << std::endl;

}

void DEQueue::EnqueueFront(int item)
{
    Node* tmp = new Node(item);
    tmp->next = front;
    front = tmp;

    if(rear == nullptr)
        rear = front;
}

void DEQueue::EnqueueRear(int item)
{
    Node* tmp = new Node(item);

    if (rear == nullptr)
    {
        front = rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }
}

void DEQueue::DequeueFront(void)
{
    Node* ptr = front;

    if (front == nullptr) return;
    if (rear == front)
        rear = rear->next;

    front = front->next;
    delete ptr;
}

void DEQueue::DequeueRear(void)
{
    Node* ptr = front;

    if (front == nullptr) return;
    if (rear == front)
    {
        front = rear = nullptr;
        delete ptr;
    }
    else
    {
        while (ptr->next != rear)
        {
            ptr = ptr->next;
        }

        rear = ptr;
        rear->next = nullptr;
        delete ptr->next;
    }
}

int DEQueue::GetFront(void)
{
    if (front == nullptr) return -1;
    return front->data;
}

int DEQueue::GetRear(void)
{
    if (rear == nullptr) return -1;
    return rear->data;
}

bool DEQueue::IsEmpty(void)
{
    return front == nullptr;
}

/****************************** Priority Queue *******************************/
PriorityQueue::PriorityQueue()
{
    front = rear = nullptr;
    priority = false;
}

PriorityQueue::PriorityQueue(int array[], int size, bool priority)
{

    front = rear = nullptr;
    this->priority = priority;

    if (front != nullptr) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    front = new Node(array[0]);
    rear = front;

    for (int i = 1; i < size; i++)
    {
        Enqueue(array[i]);
    }
}

PriorityQueue::~PriorityQueue()
{
    Node* ptr = front;

    while (front != nullptr)
    {
        front = front->next;
        delete ptr;
        ptr = front;
    }
}

void PriorityQueue::Display(void)
{
    Node* ptr = front;

    if (front == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    std::cout << "front -> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "rear" << std::endl;
}

void PriorityQueue::Enqueue(int item)
{
    Node* tmp, * aux_ptr, * ptr;
    ptr = aux_ptr = front;

    tmp = new Node(item);

    if (priority == false)
    {
        while (ptr !=nullptr && item > ptr->data)
        {
            aux_ptr = ptr;
            ptr = ptr->next;
        }
    }
    else
    {
        while (ptr !=nullptr && item < ptr->data)
        {
            aux_ptr = ptr;
            ptr = ptr->next;
        }
    }

    if (ptr == front)
    {
        tmp->next = front;
        front = tmp;
    }
    else
    {
        tmp->next = aux_ptr->next;
        aux_ptr->next = tmp;

        if (aux_ptr == rear)
            rear = tmp;
    }
}

void PriorityQueue::Dequeue(void)
{
    Node* ptr = front;

    if (front == nullptr) return;
    if (front == rear)
        rear = rear->next;

    front = front->next;
    delete ptr;
}

int PriorityQueue::GetFront(void)
{
    if (front == nullptr) return -1;
    return front->data;
}

int PriorityQueue::GetRear(void)
{
    if (rear == nullptr) return -1;
    return rear->data;
}

bool PriorityQueue::IsEmpty(void)
{
    return front == nullptr;
}


/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/
