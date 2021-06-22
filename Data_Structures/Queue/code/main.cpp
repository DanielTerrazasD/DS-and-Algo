/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: main.cpp                                                          **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** main.cpp description.                                                   **/
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
#include <vector>
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

void Test_DoubleEndedQueue();
void Test_PriorityQueue();

int main(int argc, char const* argv[])
{
    Test_DoubleEndedQueue();
    Test_PriorityQueue();
    return 0;
}

void Test_DoubleEndedQueue()
{
    DEQueue<char> deq_char;
    std::vector<char> v_char{ 'D', 'a', 'n', 't', 'e' };
    DEQueue<int> deq_int;
    std::vector<int> v_int{ 55, 56, 57, 58, 59 };
    DEQueue<float> deq_float;
    std::vector<float> v_float{ 6.626070F, 3.141592F, 2.718281F };

    std::cout << "------------------- DEQueue<char> Test -------------------";
    std::cout << std::endl;
    deq_char.Create(v_char);
    deq_char.Display();
    deq_char.EnqueueFront('D');
    deq_char.EnqueueFront('a');
    deq_char.EnqueueFront('n');
    deq_char.EnqueueFront('t');
    deq_char.EnqueueFront('e');
    deq_char.Display();

    for (size_t i = 0; i < 5; i++)
    {
        deq_char.DequeueRear();
    }
    deq_char.Display();

    std::cout << "------------------- DEQueue<int> Test -------------------";
    std::cout << std::endl;
    deq_int.Create(v_int);
    deq_int.Display();
    deq_int.DequeueFront();
    deq_int.DequeueRear();
    deq_int.Display();
    deq_int.EnqueueFront(59);
    deq_int.EnqueueRear(55);
    deq_int.Display();

    for (size_t i = 0; i < 100; i++)
    {
        deq_int.DequeueFront();
    }
    deq_int.Display();

    std::cout << "------------------- DEQueue<float> Test -------------------";
    std::cout << std::endl;
    deq_float.Create(v_float);
    deq_float.Display();
    for (size_t i = 0; i < 15; i++)
    {
        deq_float.EnqueueRear(static_cast<float>(i));
    }

    deq_float.Display();

    for (size_t i = 0; i < 15; i++)
    {
        deq_float.DequeueRear();
    }

    deq_float.Display();
}

void Test_PriorityQueue()
{
    PriorityQueue<int> pq_int(true);
    std::vector<int> v_int{ 60, 59, 57, 56, 55 };
    PriorityQueue<char> pq_char(true);
    std::vector<char> v_char{ 'E', 'D', 'B', 'A' };
    PriorityQueue<float> pq_float(true);
    std::vector<float> v_float{ 15.3254F, 175.7816F, 3.6842F, 844.8464F };

    std::cout << "------------------- PriorityQueue<char> Test -------------------";
    std::cout << std::endl;
    pq_char.Create(v_char);
    pq_char.Display();
    pq_char.Enqueue('C');
    pq_char.Display();

    std::cout << "------------------- PriorityQueue<int> Test -------------------";
    std::cout << std::endl;
    pq_int.Create(v_int);
    pq_int.Display();
    pq_int.Enqueue(58);
    pq_int.Display();

    std::cout << "------------------- PriorityQueue<float> Test -------------------";
    std::cout << std::endl;
    pq_float.Create(v_float);
    pq_float.Display();
    pq_float.Enqueue(7.4154F);
    pq_float.Display();
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/