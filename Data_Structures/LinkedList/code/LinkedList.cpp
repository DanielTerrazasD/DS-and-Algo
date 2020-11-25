/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: LinkedList.cpp                                                    **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** LinkedList.cpp description.                                             **/
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
#include "LinkedList.hpp"

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

/******************************** Single Node ********************************/
SingleNode::SingleNode()
{
    data = 0;
    next = nullptr;
}

SingleNode::SingleNode(int x)
{
    data = x;
    next = nullptr;
}


/******************************** Double Node ********************************/
DoubleNode::DoubleNode()
{
    data = 0;
    next = prev = nullptr;
}

DoubleNode::DoubleNode(int x)
{
    data = x;
    next = prev = nullptr;
}

/***************************** Singly Linked List ****************************/
SinglyLinkedList::SinglyLinkedList()
{
    head = tail = nullptr;
    size = 0;
}

SinglyLinkedList::SinglyLinkedList(int array[], int size)
{
    SingleNode* tmp;

    this->size = 0;
    head = tail = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    head = new SingleNode(array[0]);
    tail = head;

    for (size_t i = 1; i < size; i++)
    {
        tmp = new SingleNode(array[i]);
        tail->next = tmp;
        tail = tmp;
    }

    this->size = size;
}

SinglyLinkedList::~SinglyLinkedList()
{
    SingleNode* ptr = head;
    while (head != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
}

void SinglyLinkedList::Create(int array[], int size)
{
    SingleNode * tmp;

    if (head != nullptr) return;
    if (this->size != 0) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    head = new SingleNode(array[0]);
    tail = head;

    for (int i = 1; i < size; i++)
    {
        tmp = new SingleNode(array[i]);
        tail->next = tmp;
        tail = tmp;
    }

    this->size = size;
}

void SinglyLinkedList::Display(void)
{
    SingleNode* ptr = head;
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "null" << std::endl;
}

void SinglyLinkedList::Append(int item)
{
    SingleNode* tmp = new SingleNode(item);

    if (head == nullptr)
    {
        head = tmp;
        tail = head;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }

    size++;
}

void SinglyLinkedList::Insert(int item, int index)
{
    SingleNode* tmp, * ptr = head;

    if (index < 0 || index > size) return;

    if (index == size)
    {
        Append(item);
        return;
    }
    else if (index == 0)
    {
        tmp = new SingleNode(item);
        tmp->next = head;
        head = tmp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }

        tmp = new SingleNode(item);
        tmp->next = ptr->next;
        ptr->next = tmp;
    }

    size++;
}

int SinglyLinkedList::Delete(int index)
{
    int data = -1;
    SingleNode* aux_ptr, * ptr = head;

    if (head == nullptr) return -1;
    if (index < 0 || index >= size) return -1;

    if (index == 0)
    {
        tail == head ? tail = nullptr : tail = tail;
        head = head->next;
    }
    else
    {
        aux_ptr = nullptr;
        for (int i = 0; i < index; i++)
        {
            aux_ptr = ptr;
            ptr = ptr->next;
        }

        aux_ptr->next = ptr->next;
        ptr == tail ? tail = aux_ptr : tail = tail;
    }

    data = ptr->data;
    delete ptr;

    size--;
    return data;
}

void SinglyLinkedList::Reverse(void)
{
    SingleNode* ptr = head;
    SingleNode* aux_ptr = nullptr, * reverse = nullptr;

    while (ptr != nullptr)
    {
        aux_ptr = reverse;
        reverse = ptr;
        ptr = ptr->next;

        reverse->next = aux_ptr;
    }

    tail = head;
    head = reverse;
}

/************************ Circular Singly Linked List ************************/
CircularSinglyLinkedList::CircularSinglyLinkedList()
{
    size = 0;
    head = tail = nullptr;
}

CircularSinglyLinkedList::CircularSinglyLinkedList(int array[], int size)
{
    SingleNode* tmp;
    this->size = 0;
    head = tail = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    this->size = size;
    head = new SingleNode(array[0]);
    head->next = head;
    tail = head;

    for (int i = 1; i < size; i++)
    {
        tmp = new SingleNode(array[i]);
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
    }
}

CircularSinglyLinkedList::~CircularSinglyLinkedList()
{
    SingleNode* ptr = head;

    if (head == nullptr || tail == nullptr) return;
    tail->next = nullptr;

    while (head != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
}

void CircularSinglyLinkedList::Create(int array[], int size)
{
    SingleNode* tmp;

    if (head != nullptr) return;
    if (this->size != 0) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    this->size = size;
    head = new SingleNode(array[0]);
    head->next = head;
    tail = head;

    for (int i = 1; i < size; i++)
    {
        tmp = new SingleNode(array[i]);
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
    }
}

void CircularSinglyLinkedList::Display(void)
{
    SingleNode* ptr = head;

    if (head == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    do
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    } while (ptr != head);

    std::cout << "head" << std::endl;
}

void CircularSinglyLinkedList::Append(int item)
{
    SingleNode* tmp = new SingleNode(item);

    if (head == nullptr)
    {
        head = tmp;
        head->next = head;
        tail = head;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
    }

    size++;
}

void CircularSinglyLinkedList::Insert(int item, int index)
{
    SingleNode* tmp, * ptr = head;
    if (index < 0 || index > size) return;

    if (index == size)
    {
        Append(item);
        return;
    }
    else if (index == 0)
    {
        tmp = new SingleNode(item);
        tmp->next = head;
        head = tmp;
        tail->next = head;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }

        tmp = new SingleNode(item);
        tmp->next = ptr->next;
        ptr->next = tmp;
    }

    size++;
}

int CircularSinglyLinkedList::Delete(int index)
{
    SingleNode* aux_ptr, * ptr = head;
    int data = -1;
    if (head == nullptr) return -1;
    if (index < 0 || index >= size) return -1;

    if (index == 0)
    {
        if (tail == head)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            aux_ptr = ptr;
            ptr = ptr->next;
        }

        aux_ptr->next = ptr->next;
        tail == ptr ? tail = aux_ptr : tail = tail;
    }

    data = ptr->data;
    delete ptr;

    size--;
    return data;
}

void CircularSinglyLinkedList::Reverse(void)
{
    SingleNode* ptr = head;
    SingleNode* aux_ptr = nullptr, * reverse = nullptr;

    if (head == nullptr || tail == nullptr) return;
    tail->next = nullptr;

    while (ptr != nullptr)
    {
        aux_ptr = reverse;
        reverse = ptr;
        ptr = ptr->next;
     
        reverse->next = aux_ptr;
    }

    tail = head;
    head = reverse;
    tail->next = head;
}

/**************************** Doubly Linked List *****************************/
DoublyLinkedList::DoublyLinkedList()
{
    size = 0;
    head = tail = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int array[], int size)
{
    DoubleNode* tmp;
    this->size = 0;
    head = tail = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    this->size = size;
    head = new DoubleNode(array[0]);
    tail = head;

    for (int i = 1; i < size; i++)
    {
        tmp = new DoubleNode(array[i]);
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    DoubleNode* ptr = head;
    while (head != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
}

void DoublyLinkedList::Create(int array[], int size)
{
    DoubleNode* tmp;

    if (head != nullptr) return;
    if (this->size != 0) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    this->size = size;
    head = new DoubleNode(array[0]);
    tail = head;
    
    for (size_t i = 1; i < size; i++)
    {
        tmp = new DoubleNode(array[0]);
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
}

void DoublyLinkedList::Display(void)
{
    DoubleNode* ptr = head;

    if (head == nullptr)
    {
        std::cout << "null";
        return;
    }

    std::cout << "null <-> ";
    while (ptr != nullptr)
    {
        std::cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    std::cout << "null\r\n";
}

void DoublyLinkedList::Append(int item)
{
    DoubleNode* tmp = new DoubleNode(item);

    if (head == nullptr)
    {
        head = tmp;
        tail = head;
    }
    else
    {
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }

    size++;
}

void DoublyLinkedList::Insert(int item, int index)
{
    DoubleNode* tmp, * ptr = head;
    if (index < 0 || index > size) return;
    
    if (index == size)
    {
        Append(item);
        return;
    }
    else if (index == 0)
    {
        tmp = new DoubleNode(item);
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        
        tmp = new DoubleNode(item);
        tmp->next = ptr->next;
        ptr->next = tmp;
    }

    size++;
}

int DoublyLinkedList::Delete(int index)
{
    DoubleNode* ptr = head;
    int data = -1;
    if (head == nullptr) return - 1;
    if (index < 0 || index >= size) return - 1;

    if (index == 0)
    {
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        
        if (tail == ptr)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
    }

    data = ptr->data;
    delete ptr;

    size--;
    return data;
}

void DoublyLinkedList::Reverse(void)
{
    DoubleNode* tmp, * ptr = head;

    if (head == nullptr) return;

    while (ptr != nullptr)
    {
        tmp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = tmp;
        ptr = ptr->prev;
    }

    tmp = head;
    head = tail;
    tail = tmp;
}

/************************ Circular Doubly Linked List ************************/
CircularDoublyLinkedList::CircularDoublyLinkedList()
{
    size = 0;
    head = tail = nullptr;
}

CircularDoublyLinkedList::CircularDoublyLinkedList(int array[], int size)
{
    DoubleNode* tmp;
    this->size = 0;
    head = tail = nullptr;

    if (array == nullptr) return;
    if (size <= 0) return;

    this->size = size;
    head = new DoubleNode(array[0]);
    head->next = head;
    head->prev = head;
    tail = head;

    for (size_t i = 1; i < size; i++)
    {
        tmp = new DoubleNode(array[i]);
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
        head->prev = tail;
    }
}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    DoubleNode* ptr = head;

    if (head == nullptr || tail == nullptr) return;
    tail->next = nullptr;

    while (head != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
}

void CircularDoublyLinkedList::Create(int array[], int size)
{
    DoubleNode* tmp;

    if (head != nullptr) return;
    if (this->size != 0) return;
    if (array == nullptr) return;
    if (size <= 0) return;

    this->size = size;
    head = new DoubleNode(array[0]);
    head->next = head;
    head->prev = head;
    tail = head;

    for (size_t i = 1; i < size; i++)
    {
        tmp = new DoubleNode(array[i]);
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
        head->prev = tail;
    }
}

void CircularDoublyLinkedList::Display(void)
{
    DoubleNode* ptr = head;

    if (head == nullptr)
    {
        std::cout << "null" << std::endl;
        return;
    }

    std::cout << "tail <-> ";
    do
    {
        std::cout << ptr->data << " <-> ";
        ptr = ptr->next;
    } while (ptr != head);

    std::cout << "head" << std::endl;
}

void CircularDoublyLinkedList::Append(int item)
{
    DoubleNode* tmp = new DoubleNode(item);
    if (head == nullptr)
    {
        head = tmp;
        head->next = head;
        head->prev = head;
        tail = head;
    }
    else
    {
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
        head->prev = tail;
    }

    size++;
}

void CircularDoublyLinkedList::Insert(int item, int index)
{
    DoubleNode* tmp, * ptr = head;

    if (index < 0 || index > size) return;
    tmp = new DoubleNode(item);

    if (index == size)
    {
        Append(item);
        return;
    }
    else if (index == 0)
    {
        if (head == nullptr)
        {
            head = tmp;
            head->next = head;
            head->prev = head;
            tail = head;
        }
        else
        {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
            head->prev = tail;
            tail->next = head;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        tmp->prev = ptr;
        tmp->next = ptr->next;
        ptr->next->prev = tmp;
        ptr->next = tmp;
    }

    size++;
}

int CircularDoublyLinkedList::Delete(int index)
{
    int data = -1;
    DoubleNode* ptr = head;

    if (head == nullptr) return -1;
    if (index < 0 || index >= size) return -1;

    if (index == 0)
    {
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }

        if (tail == ptr)
        {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
    }

    data = ptr->data;
    delete ptr;

    size--;
    return data;
}

void CircularDoublyLinkedList::Reverse(void)
{
    DoubleNode* tmp, * ptr = head;
    if (head == nullptr) return;

    do
    {
        tmp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = tmp;
        ptr = ptr->prev;

    } while (ptr != head);
    
    tmp  = head;
    head = tail;
    tail = tmp;
}
/************************ Circular Doubly Linked List ************************/


/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/