/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: LinkedList.hpp                                                    **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** LinkedList.hpp description.                                             **/
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
#ifndef FILE_LINKED_LIST_HPP
#define FILE_LINKED_LIST_HPP

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

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

class SingleNode
{
public:
    int data;
    SingleNode* next;

    SingleNode();
    SingleNode(int x);

};

class DoubleNode
{
public:
    int data;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode();
    DoubleNode(int x);

};

class SinglyLinkedList
{
private:
    SingleNode* head;
    SingleNode* tail;
    int size;

public:
    SinglyLinkedList();
    SinglyLinkedList(int array[], int size);
    ~SinglyLinkedList();
    void Create(int array[], int size);
    void Display(void);
    void Append(int item);
    void Insert(int item, int index);
    int Delete(int index);
    void Reverse(void);
};

class CircularSinglyLinkedList
{
private:
    SingleNode* head;
    SingleNode* tail;
    int size;

public:
    CircularSinglyLinkedList();
    CircularSinglyLinkedList(int array[], int size);
    ~CircularSinglyLinkedList();
    void Create(int array[], int size);
    void Display(void);
    void Append(int item);
    void Insert(int item, int index);
    int Delete(int index);
    void Reverse(void);
};

class DoublyLinkedList
{
private:
    DoubleNode* head;
    DoubleNode* tail;
    int size;

public:
    DoublyLinkedList();
    DoublyLinkedList(int array[], int size);
    ~DoublyLinkedList();
    void Create(int array[], int size);
    void Display(void);
    void Append(int item);
    void Insert(int item, int index);
    int Delete(int index);
    void Reverse(void);
};

class CircularDoublyLinkedList
{
private:
    DoubleNode* head;
    DoubleNode* tail;
    int size;

public:
    CircularDoublyLinkedList();
    CircularDoublyLinkedList(int array[], int size);
    ~CircularDoublyLinkedList();
    void Create(int array[], int size);
    void Display(void);
    void Append(int item);
    void Insert(int item, int index);
    int Delete(int index);
    void Reverse(void);
};

#endif // FILE_LINKED_LIST_HPP

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/