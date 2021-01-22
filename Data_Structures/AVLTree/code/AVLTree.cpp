/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: AVLTree.cpp                                                       **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** AVLTree.cpp description.                                                **/
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

#include "AVLTree.hpp"

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
    left_child = right_child = nullptr;
    height = 0;
    data = x; 
}

/***************************** Binary Search Tree ****************************/
AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::~AVLTree()
{
    DeleteTree(root);
}

void AVLTree::DeleteTree(Node* ptr)
{
    if (ptr != nullptr)
    {
        DeleteTree(ptr->left_child);
        DeleteTree(ptr->right_child);
        delete ptr;
    }
}

Node* AVLTree::PerformLLRotation(Node* ptr)
{
    Node* ptr_left = ptr->left_child;

    ptr->left_child = ptr_left->right_child;
    ptr_left->right_child = ptr;

    ptr->height = GetHeight(ptr);
    ptr_left->height = GetHeight(ptr_left);

    if (ptr == root) root = ptr_left;
    return ptr_left;
}

Node* AVLTree::PerformLRRotation(Node* ptr)
{
    Node* ptr_left = ptr->left_child;
    Node* ptr_left_right = ptr_left->right_child;

    ptr->left_child = ptr_left_right->right_child;
    ptr_left->right_child = ptr_left_right->left_child;
    ptr_left_right->left_child = ptr_left;
    ptr_left_right->right_child = ptr;

    ptr->height = GetHeight(ptr);
    ptr_left->height = GetHeight(ptr_left);
    ptr_left_right->height = GetHeight(ptr_left_right);

    if (ptr == root) root = ptr_left_right;
    return ptr_left_right;
}

Node* AVLTree::PerformRLRotation(Node* ptr)
{
    Node* ptr_right = ptr->right_child;
    Node* ptr_right_left = ptr_right->left_child;

    ptr->right_child = ptr_right_left->left_child;
    ptr_right->left_child = ptr_right_left->right_child;

    ptr_right_left->right_child = ptr_right;
    ptr_right_left->left_child = ptr;

    ptr->height = GetHeight(ptr);
    ptr_right->height = GetHeight(ptr_right);
    ptr_right_left->height = GetHeight(ptr_right_left);

    if (ptr == root) root = ptr_right_left;
    return ptr_right_left;
}

Node* AVLTree::PerformRRRotation(Node* ptr)
{
    Node* ptr_right = ptr->right_child;

    ptr->right_child = ptr_right->left_child;
    ptr_right->left_child = ptr;

    ptr->height = GetHeight(ptr);
    ptr_right->height = GetHeight(ptr_right);

    if (ptr == root) root = ptr_right;
    return ptr_right;
}

int AVLTree::GetCount(Node* ptr)
{
    int left_subtree = 0;
    int right_subtree = 0;

    if (ptr == nullptr) return 0;

    left_subtree = GetCount(ptr->left_child);
    right_subtree = GetCount(ptr->right_child);

    return left_subtree + right_subtree + 1;
}

int AVLTree::GetHeight(Node* ptr)
{
    int height_left;
    int height_right;

    if (ptr == nullptr) return 0;

    height_left = (ptr != nullptr && ptr->left_child != nullptr ) ? ptr->left_child->height : 0;
    height_right = (ptr != nullptr && ptr->right_child != nullptr ) ? ptr->right_child->height : 0;

    return (height_left > height_right) ? height_left + 1 : height_right + 1;
}

int AVLTree::GetBalanceFactor(Node* ptr)
{
    int height_left;
    int height_right;

    if (ptr == nullptr) return 0;

    height_left = (ptr != nullptr && ptr->left_child != nullptr ) ? ptr->left_child->height : 0;
    height_right = (ptr != nullptr && ptr->right_child != nullptr ) ? ptr->right_child->height : 0;

    return height_left - height_right;
}

Node* AVLTree::Insert(Node* ptr, int item)
{
    if (ptr == nullptr)
    {
        ptr = new Node(item);
        ptr->height = 1;
        return ptr;
    }

    if (item < ptr->data)
    {
        ptr->left_child = Insert(ptr->left_child, item);
    }
    else if (item > ptr->data)
    {
        ptr->right_child = Insert(ptr->right_child, item);
    }
    else
    {
        return ptr;
    }

    // Update height
    ptr->height = GetHeight(ptr);

    // Left-Left Rotation
    if (GetBalanceFactor(ptr) == 2 && GetBalanceFactor(ptr->left_child) == 1)
    {
        return PerformLLRotation(ptr);
    }
    // Left-Right Rotation
    else if (GetBalanceFactor(ptr) == 2 && GetBalanceFactor(ptr->left_child) == -1)
    {
        return PerformLRRotation(ptr);
    }
    // Right-Left Rotation
    else if (GetBalanceFactor(ptr) == -2 && GetBalanceFactor(ptr->right_child) == 1)
    {
        return PerformRLRotation(ptr);
    }
    // Right-Right Rotation
    else if (GetBalanceFactor(ptr) == -2 && GetBalanceFactor(ptr->right_child) == -1)
    {
        return PerformRRRotation(ptr);
    }

    return ptr;
}

void AVLTree::Create(int array[], int size)
{
    if ( array == nullptr ) return;
    if ( size <= 0 ) return;
    if ( root != nullptr ) return;

    root = new Node(array[0]);

    for (int i = 1; i < size; i++)
    {
        root = Insert(root, array[i]);
    }
}

void AVLTree::InorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    if (root == nullptr) return;

    std::cout << "Inorder: ";

    while (!stk.empty() || ptr != nullptr)
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

void AVLTree::PreorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    if (root == nullptr) return;

    std::cout << "Preorder: ";

    while (!stk.empty() || ptr != nullptr)
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();
            ptr = ptr->right_child;
        }
        else
        {
            std::cout << ptr->data << " ";
            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }

    std::cout << std::endl;
}

void AVLTree::PostorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    if (root == nullptr) return;

    std::cout << "Postorder: ";

    while (!stk.empty() || ptr != nullptr)
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
            {
                stk.push(ptr->right_child);
            }

            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }

    std::cout << std::endl;
}

void AVLTree::LevelorderTraversal(void)
{
    std::queue<Node*> q;
    Node* ptr;

    if (root == nullptr) return;

    std::cout << "Levelorder: ";

    q.push(root);
    while (!q.empty())
    {
        ptr = q.front();
        q.pop();

        std::cout << ptr->data << " ";
        
        if (ptr->left_child != nullptr)
        {
            q.push(ptr->left_child);
        }

        if (ptr->right_child != nullptr)
        {
            q.push(ptr->right_child);
        }
    }

    std::cout << std::endl;
}

void AVLTree::Insert(int item)
{
    root = Insert(root, item);
}

Node* AVLTree::Search(int item)
{
    return nullptr;
}

Node* AVLTree::GetInorderPredecessor(Node* ptr)
{
    while (ptr != nullptr && ptr->right_child != nullptr)
    {
        ptr = ptr->right_child;
    }
    return ptr;
}

Node* AVLTree::GetInorderSuccessor(Node* ptr)
{
    while (ptr != nullptr && ptr->left_child != nullptr)
    {
        ptr = ptr->left_child;
    }
    return ptr;
}

Node* AVLTree::Delete(Node* ptr, int item)
{
    Node* aux_ptr;
    if (ptr == nullptr) return nullptr;

    if (ptr->left_child == nullptr && ptr->right_child == nullptr)
    {
        // Leaf node reached, if it's not the desired item return ptr;
        if (ptr->data != item) return ptr;
        if (ptr == root) root = nullptr;
        delete ptr;
        return nullptr;
    }

    if(item < ptr->data)
    {
        ptr->left_child = Delete(ptr->left_child, item);
    }
    else if (item > ptr->data)
    {
        ptr->right_child = Delete(ptr->right_child, item);
    }
    else
    {
        if (GetHeight(ptr->left_child) > GetHeight(ptr->right_child))
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

    // Update height
    ptr->height = GetHeight(ptr);

    // Left-Left Rotation.
    if (GetBalanceFactor(ptr) == 2 && GetBalanceFactor(ptr->left_child) == 1)
    {
        return PerformLLRotation(ptr);
    }
    // Left-Right Rotation.
    else if (GetBalanceFactor(ptr) == 2 && GetBalanceFactor(ptr->left_child) == -1)
    {
        return PerformLRRotation(ptr);
    }
    // Either Left-Left or Left-Right Rotation.
    else if (GetBalanceFactor(ptr) == 2 && GetBalanceFactor(ptr->left_child) == 0)
    {
        return PerformLLRotation(ptr);
    }
    // Right-Left Rotation.
    else if (GetBalanceFactor(ptr) == -2 && GetBalanceFactor(ptr->right_child) == 1)
    {
        return PerformRLRotation(ptr);
    }
    // Right-Right Rotation.
    else if (GetBalanceFactor(ptr) == -2 && GetBalanceFactor(ptr->right_child) == -1)
    {
        return PerformRRRotation(ptr);
    }
    // Either Right-Right or Right-Left Rotation.
    else if (GetBalanceFactor(ptr) == -2 && GetBalanceFactor(ptr->right_child) == 0)
    {
        return PerformRRRotation(ptr);
    }

    return ptr;
}

void AVLTree::Delete(int item)
{
    Delete(root, item);
}

int AVLTree::GetHeight(void)
{
    return GetHeight(root);
}

int AVLTree::GetCount(void)
{
    return GetCount(root);
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/