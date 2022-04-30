#include "BiTree.h"
#include <iostream>


BiTree::BiTree() {
	rootNode == NULL;
}

void Insert(NodeType*& tree, ItemType item);
void BiTree::Add(ItemType item) {
	Insert(rootNode, item);
}
void Insert(NodeType*& tree, ItemType item) {
	if (tree == NULL) {
		tree = new NodeType;
		tree->right = NULL;
		tree->left =NULL;
		tree->data = item;
	}
	else if (toupper(item[0]) < toupper(tree->data[0])) {
		Insert(tree->left, item);
	}
	else if (toupper(item[0]) > toupper(tree->data[0])) {
		Insert(tree->right, item);
	}
}




void GetPredecessor(NodeType*& tree, ItemType& item);
void DeleteNode(NodeType*& tree);
// post: the node that was pointed to by tree is deleted

void Delete(NodeType*& tree, ItemType item);
void BiTree::Remove(ItemType item) {
	Delete(rootNode, item);
}
void GetPredecessor(NodeType*& tree, ItemType& item) {
	while (tree->right != NULL)
		tree = tree->right;
	item = tree->data;
}
void DeleteNode(NodeType*& tree) {
	ItemType data;
	NodeType* tempPtr;
	tempPtr = tree;
	if (tree->left == NULL) {
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL) {
		tree = tree->left;
		delete tempPtr;
	}
	else {
		GetPredecessor(tree->left, data);
		tree->data = data;
		Delete(tree->left, data);
	}
}
void Delete(NodeType*& tree, ItemType item) {
	if (item[0] < tree->data[0])
		Delete(tree->left, item);
	else if (item[0] > tree->data[0])
		Delete(tree->right, item);
	else
		DeleteNode(tree);
}


void PrintTree(NodeType* tree);
void BiTree::Print() {
	PrintTree(rootNode);
}
void PrintTree(NodeType* tree) {
	if (tree != NULL) {
		PrintTree(tree->left);
		cout <<"\n"<< tree->data << "\t";
		PrintTree(tree->right);
	}
}

void PrintRTree(NodeType* tree);
void BiTree::RPrint() {
	PrintRTree(rootNode);
}
void PrintRTree(NodeType* tree) {
	if (tree != NULL) {
		PrintRTree(tree->right);
		cout << "\n" << tree->data << "\t";
		PrintRTree(tree->left);
	}
}