/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: Stack.cpp                                                         **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** Stack.cpp description.                                                  **/
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
#include "Stack.hpp"

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

/*********************************** Stack ***********************************/
Stack::Stack()
{
    top = nullptr;
}

Stack::Stack(int array[], int size)
{
    Node* last, * tmp;
    top = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    top = new Node(array[0]);
    last = top;

    for (int i = 1; i < size; i++)
    {
        tmp = new Node(array[i]);
        last->next = tmp;
        last = tmp;
    }
}

Stack::~Stack()
{
    Node* ptr = top;
    while (top != nullptr)
    {
        top = top->next;
        delete ptr;
        ptr = top;
    }
}

void Stack::Create(int array[], int size)
{
    Node* last, * tmp;

    if (top != nullptr) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    top = new Node(array[0]);
    last = top;

    for (int i = 1; i < size; i++)
    {
        tmp = new Node(array[i]);
        last->next = tmp;
        last = tmp;
    }
}

void Stack::Display(void)
{
    Node* ptr = top;
    if (top == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    std::cout << "Top -> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "Bottom" << std::endl;
}

void Stack::Push(int item)
{
    Node* tmp = new Node(item);
    tmp->next = top;
    top = tmp;
}

int Stack::Pop(void)
{
    int data = -1;
    if (IsEmpty()) return -1;

    data = top->data;
    top = top->next;
    return data;
}

int Stack::Top(void)
{
    if (IsEmpty()) return -1;
    return top->data;
}

bool Stack::IsEmpty(void)
{
    return top == nullptr;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/
