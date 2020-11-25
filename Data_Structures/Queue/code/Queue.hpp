/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: Queue.hpp                                                         **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** Queue.hpp description.                                                  **/
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
#ifndef FILE_QUEUE_HPP
#define FILE_QUEUE_HPP

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

class Node
{
public:
    int data;
    Node* next;

    Node();
    Node(int x);

};

class Queue
{
private:
    Node* front;
    Node* rear;

public:

    Queue();
    Queue(int array[], int size);
    ~Queue();
};

class CircularQueue
{
private:
    Node* front;
    Node* rear;
    
public:

    CircularQueue();
    CircularQueue(int array[], int size);
    ~CircularQueue();
};

/* Double Ended Queue */
class DEQueue
{
private:
    Node* front;
    Node* rear;

public:

    DEQueue();
    DEQueue(int array[], int size);
    ~DEQueue();
};

class PriorityQueue
{
private:
    Node* front;
    Node* rear;

public:
    PriorityQueue();
    PriorityQueue(int array[], int size);
    ~PriorityQueue();
};



#endif // FILE_QUEUE_HPP

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/