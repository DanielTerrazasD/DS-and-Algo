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
    front = rear = nullptr;
}

Queue::~Queue()
{

}

/****************************** Circular Queue *******************************/
CircularQueue::CircularQueue()
{
    front = rear = nullptr;
}

CircularQueue::CircularQueue(int array[], int size)
{
    front = rear = nullptr;
}

CircularQueue::~CircularQueue()
{

}

/**************************** Double Ended Queue *****************************/
DEQueue::DEQueue()
{
    front = rear = nullptr;
}

DEQueue::DEQueue(int array[], int size)
{
    front = rear = nullptr;
}

DEQueue::~DEQueue()
{

}

/****************************** Priority Queue *******************************/
PriorityQueue::PriorityQueue()
{
    front = rear = nullptr;
}

PriorityQueue::PriorityQueue(int array[], int size)
{
    front = rear = nullptr;
}

PriorityQueue::~PriorityQueue()
{

}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/
