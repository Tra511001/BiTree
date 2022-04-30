#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#define BITREE_H

using namespace std;
typedef string ItemType;
struct NodeType {
	ItemType data;
	NodeType* left;
	NodeType* right;
}; 

class BiTree{
public:
	BiTree();
	void Add(ItemType item);//adds a node to the tree
	void Remove(ItemType item);//removes a node from the tree
	void Print();// Print the contents of the tree in alphabetical order
	void RPrint();//Print in reverse order

private:
	NodeType* rootNode;
};