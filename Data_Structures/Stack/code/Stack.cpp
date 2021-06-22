/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
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
template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    next_node = nullptr;
}

/*********************************** Stack ***********************************/
template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
void Stack<T>::Create(const std::vector<T> &v)
{
    size_t size = v.size();

    for (size_t i = 0; i < size; i++)
    {
        Push(v.at(i));
    }
}

template <typename T>
void Stack<T>::Display()
{
    std::shared_ptr<Node<T>> ptr = top;

    if (ptr == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    std::cout << "Top -> ";
    while (ptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next_node;
    }
    std::cout << "Bottom" << std::endl;
}

template <typename T>
void Stack<T>::Push(T data)
{
    std::shared_ptr<Node<T>> ptr = std::make_shared<Node<T>>(data);

    if (top)
    {
        ptr->next_node = top;
        top = ptr;
    }
    else
    {
        top = ptr;
    }
}

template <typename T>
void Stack<T>::Pop()
{
    if (top)
    {
        top = top->next_node;
    }
}

template <typename T>
T Stack<T>::Top() const
{
    T data = T();

    if (top)
    {
        data = top->data;
    }

    return data;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return top == nullptr;
}

// Explicit Instantiation Declaration for 'Stack'
template class Stack<int>::Stack;
template class Stack<char>::Stack;
template class Stack<float>::Stack;

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/