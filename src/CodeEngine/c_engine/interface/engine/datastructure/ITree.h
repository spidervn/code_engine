#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_DATASTRUCTURE_ITREE_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_DATASTRUCTURE_ITREE_H_

#include <stdio.h>
#include <stdlib.h>


template<typename T>
class Tree
{
protected:
    T arr[100];
    int arrMark[1000];  // Data structure? 
                        // 

public:
    Tree() {};

    int addRoot(T node)
    {
        arr[0] = node;
        return 0;
    }

    int addNode(T parentNode, T newNode)
    {
                
    }

    int find_node() = 0;

    virtual int isSameNode(T node1, T node2) = 0;   // Comparing function
};

#endif