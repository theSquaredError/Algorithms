/*
Problem - Given a tree T, write a program to print the elements of T in level order traversal using
			queue data-structure.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct bNode
{
	int data;
	struct bNode* left;
	struct bNode* right;
};

bNode* createNode(int value){
	bNode *p;

	 p = new bNode;
	 p->data = value;
	 p->left = p->right = NULL;

	 return p;
}

void printLevelOrderTraversal(bNode* root){
	queue<bNode*>q;
	q.push(root);
	while(q.front()){
		bNode* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		q.push(temp->left);
		q.push(temp->right);
	}
}


/*
Example tree:      5
				 /   \
				6     8
			   / \   / \
			  3   4 7   2

*/
int main(){
	bNode* root = createNode(5);
	
	root->left = createNode(6);
	root->right = createNode(8);
	
	root->left->left = createNode(3);
	root->left->right = createNode(4);

	root->right->left = createNode(7);
	root->right->right = createNode(2);

	printLevelOrderTraversal(root);

	return 0;
}