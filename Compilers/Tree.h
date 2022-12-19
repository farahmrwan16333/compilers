#pragma once
#include "Scan.h"

struct Node
{
    Token key;
    vector<Node*>child;
    Node* sibling;
};


Node* newNode(Token key);