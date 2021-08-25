/*
Problem:- finding largest and second largest element in A,
using minimum number of comparisons.
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


int main(){
	vector<int> v = {10,20,30,40,50,60,70,80,90};

	//n-1 comparison required for finding largest element
	//using queue we can find largest element

	queue<bNode*> q;

	
	for(int num: v){
		q.push(createNode(num));
	}

	bNode* root_node;
	bNode *node1, *node2;
	
	while(q.size()>1){
		node1 = q.front();
		q.pop();
		node2 = q.front();
		q.pop();

		int num3 = node1->data > node2->data ? node1->data:node2->data;

		//creating nodes for the tree

		root_node = createNode(num3);
		root_node->left = node1;
		root_node->right = node2;

		q.push(root_node);
	}

	int largest = q.front()->data;
	cout<<"largest element is : "<< largest<<endl;
	
	root_node = q.front();
	
	//extracting required integers for finding second largest element
	queue<int> q2;
	while(root_node->left!=NULL and root_node->right!=NULL){
		
		if(root_node->left->data == largest){
			q2.push(root_node->right->data);
			root_node = root_node->left;
		}else{
			q2.push(root_node->left->data);
			root_node = root_node->right;
		}

	}

	while(q2.size()>1){
		int num1 = q2.front();
		q2.pop();
		int num2 = q2.front();
		q2.pop();
		int num3 = num1>num2?num1:num2;
		q2.push(num3);
	}
	cout<<"second largest: "<<q2.front();
	return 0;

}