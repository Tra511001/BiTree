#include <iostream>
#include "BiTree.h"
#include <string>
#include <iomanip>

using namespace std;

int main() {
	BiTree tree1;
	ItemType web1 = "Facebook.com";
	ItemType web2 = "Google.com";
	ItemType web3 = "J.com";
	ItemType web4 = "a.com";
	tree1.Add(web1);
	tree1.Add(web2);
	tree1.Add(web3);
	tree1.Add(web4);
	tree1.Print();
	cout << "\n\n\n";
	tree1.RPrint();
	cout << "\n\n\n";

	tree1.Remove(web1);
	tree1.Print();

	return 0;
}