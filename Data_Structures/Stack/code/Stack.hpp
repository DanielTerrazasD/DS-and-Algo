/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: Stack.hpp                                                         **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** Stack.hpp description.                                                  **/
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

// Guard to prevent recursive inclusion
#ifndef FILE_STACK_HPP
#define FILE_STACK_HPP

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <iostream>
#include <memory>
#include <vector>

/*****************************************************************************/
/**                               Public Macros                             **/
/*****************************************************************************/

/*****************************************************************************/
/**                             Public Data Types                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Constants                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Variables                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Functions                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Public Classes                            **/
/*****************************************************************************/

template <typename T>
class Node
{
public:
    Node(T data);

    T data;
    std::shared_ptr<Node<T>> next_node;
};

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();

    void Create(const std::vector<T> &v);
    void Display();
    void Push(T data);
    void Pop();
    T Top() const;
    bool IsEmpty();

private:
    std::shared_ptr<Node<T>> top;
};

#endif // FILE_STACK_HPP

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/