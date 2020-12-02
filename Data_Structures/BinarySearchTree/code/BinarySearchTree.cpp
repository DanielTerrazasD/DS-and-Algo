/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: BinarySearchTree.cpp                                              **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** BinarySearchTree.cpp description.                                       **/
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
#include <queue>
#include <stack>

#include "BinarySearchTree.hpp"

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
Node::Node(int x)
{
    data = x;
    right_child = left_child = nullptr;
}

/***************************** Binary Search Tree ****************************/
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}
BinarySearchTree::~BinarySearchTree()
{
    DeleteTree(root);
}

void BinarySearchTree::DeleteTree(Node* ptr)
{
    if (ptr != nullptr)
    {
        DeleteTree(ptr->left_child);
        DeleteTree(ptr->right_child);
        delete ptr;
    }
}

void BinarySearchTree::Create(int preorder[], int preorder_size)
{
    if (preorder == nullptr) return;
    if (preorder_size <= 0) return;

    for (int i = 0; i < preorder_size; i++)
    {
        Insert(preorder[i]);
    }
}

void BinarySearchTree::InorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    std::cout << "Inorder: ";
    while (ptr != nullptr || !stk.empty())
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();
            std::cout << ptr->data << " ";
            ptr = ptr->right_child;
        }
        else
        {
            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }
    std::cout << std::endl;
}

void BinarySearchTree::PreorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    std::cout << "Preorder: ";
    while (ptr != nullptr || !stk.empty())
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();
            ptr = ptr->right_child;
        }
        else
        {
            stk.push(ptr);
            std::cout << ptr->data << " ";
            ptr = ptr->left_child;
        }
    }
    std::cout << std::endl;
}

void BinarySearchTree::PostorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    std::cout << "Postorder: ";
    while (ptr != nullptr || !stk.empty())
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();
            if (!stk.empty() && ptr->right_child != nullptr && ptr->right_child == stk.top())
            {
                stk.pop();
                stk.push(ptr);
                ptr = ptr->right_child;
            }
            else
            {
                std::cout << ptr->data << " ";
                ptr = nullptr;
            }
        }
        else
        {
            if (ptr->right_child != nullptr)
                stk.push(ptr->right_child);

            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }
    std::cout << std::endl;
}

void BinarySearchTree::LevelorderTraversal(void)
{
    std::queue<Node*> q;
    Node* ptr;

    std::cout << "Levelorder: ";
    if (root == nullptr) return;
    q.push(root);

    while ( !q.empty())
    {
        ptr = q.front();
        q.pop();

        if(ptr->left_child != nullptr)
            q.push(ptr->left_child);
        if(ptr->right_child != nullptr)
            q.push(ptr->right_child);

        std::cout << ptr->data << " ";
    }

    std::cout << std::endl;
}

void BinarySearchTree::Insert(int item)
{
    Node* tmp, * ptr = root;

    if (root == nullptr)
    {
        root = new Node(item);
    }
    else
    {
        while (ptr != nullptr)
        {
            if (ptr->data == item)
            {
                break;
            }
            else if (item < ptr->data)
            {
                if (ptr->left_child == nullptr)
                {
                    tmp = new Node(item);
                    ptr->left_child = tmp;
                    break;
                }
                else
                {
                    ptr = ptr->left_child;
                }
            }
            else
            {
                if (ptr->right_child == nullptr)
                {
                    tmp = new Node(item);
                    ptr->right_child = tmp;
                    break;
                }
                else
                {
                    ptr = ptr->right_child;
                }
            }
        }
    }
}

Node* BinarySearchTree::Search(int item)
{
    Node* ptr = root;
    if (root == nullptr) return nullptr;

    while (ptr != nullptr)
    {
        if (item < ptr->data)
        {
            ptr = ptr->left_child;
        }
        else if (item > ptr->data)
        {
            ptr = ptr->right_child;
        }
        else
        {
            return ptr;
        }
    }

    return ptr;
}

void BinarySearchTree::Delete(int item)
{
    if (root == nullptr) return;

    root = Delete(root, item);
}

Node* BinarySearchTree::Delete(Node* ptr, int item)
{
    int left_subtree_height;
    int right_subtree_height;
    Node* aux_ptr;

    if (ptr == nullptr) return nullptr;

    if (ptr->left_child == nullptr && ptr->right_child == nullptr)
    {
        if (ptr == root)
            root = nullptr;
        delete ptr;
        return nullptr;
    }

    if (item > ptr->data)
    {
        ptr->right_child = Delete(ptr->right_child, item);
    }
    else if (item < ptr->data)
    {
        ptr->left_child = Delete(ptr->left_child, item);
    }
    else
    {
        left_subtree_height = GetHeight(ptr->left_child);
        right_subtree_height = GetHeight(ptr->right_child);

        if (left_subtree_height > right_subtree_height)
        {
            aux_ptr = GetInorderPredecessor(ptr->left_child);
            ptr->data = aux_ptr->data;
            ptr->left_child = Delete(ptr->left_child, aux_ptr->data);
        }
        else
        {
            aux_ptr = GetInorderSuccessor(ptr->right_child);
            ptr->data = aux_ptr->data;
            ptr->right_child = Delete(ptr->right_child, aux_ptr->data);
        }
    }

    return ptr;
}

Node* BinarySearchTree::GetInorderPredecessor(Node* ptr)
{
    while (ptr != nullptr && ptr->right_child != nullptr)
    {
        ptr = ptr->right_child;
    }

    return ptr;
}

Node* BinarySearchTree::GetInorderSuccessor(Node* ptr)
{
    while (ptr != nullptr && ptr->left_child != nullptr)
    {
        ptr = ptr->left_child;
    }

    return ptr;
}

int BinarySearchTree::GetHeight(void)
{
    return GetHeight(root);
}

int BinarySearchTree::GetCount(void)
{
    return GetCount(root);
}

int BinarySearchTree::GetHeight(Node* ptr)
{
    int left_subtree_height = 0;
    int right_subtree_height = 0;

    if (ptr == nullptr) return 0;

    left_subtree_height = GetHeight(ptr->left_child);
    right_subtree_height = GetHeight(ptr->right_child);

    if (left_subtree_height > right_subtree_height)
        return left_subtree_height + 1;
    return right_subtree_height + 1;
}

int BinarySearchTree::GetCount(Node* ptr)
{
    int left_subtree_count = 0;
    int right_subtree_count = 0;

    if (ptr == nullptr) return 0;

    left_subtree_count = GetCount(ptr->left_child);
    right_subtree_count = GetCount(ptr->right_child);

    return left_subtree_count + right_subtree_count + 1;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/