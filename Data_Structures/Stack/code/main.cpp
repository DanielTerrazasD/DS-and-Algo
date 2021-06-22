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

void Test_Stack();

int main(int argc, char* argv[])
{
    Test_Stack();
}

void Test_Stack()
{
    Stack<char> s_char;
    std::vector<char> v_char = { 'e', 't', 'n', 'a', 'D' };
    Stack<int> s_int;
    std::vector<int> v_int = { 1, 2, 3 };
    Stack<float> s_float;
    std::vector<float> v_float = { 6.626070F, 3.141592F, 2.718281F };

    std::cout << "-------------------- Stack<char> Test --------------------";
    std::cout << std::endl;
    s_char.Create(v_char);
    s_char.Display();

    for (int i = 0; i < 5; i++)
    {
        s_char.Pop();
        s_char.Display();
    }

    std::cout << "--------------------- Stack<int> Test --------------------";
    std::cout << std::endl;
    s_int.Create(v_int);
    s_int.Display();

    for (int i = 0; i < 4; i++)
    {
        s_int.Pop();
        s_int.Display();
    }

    std::cout << "-------------------- Stack<float> Test -------------------";
    std::cout << std::endl;
    s_float.Create(v_float);
    s_float.Display();

    for (int i = 0; i < 4; i++)
    {
        s_float.Pop();
        s_float.Display();
    }
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/