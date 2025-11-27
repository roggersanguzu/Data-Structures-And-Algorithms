#include<iostream>
using namespace std;
struct node{
	int data;
	node *left, *right;
};
node *createnode(node *root, int item){
	if(root==NULL){
		root=new node;
		root->data=item;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(item<root->data){
		root->left=createnode(root->left,item);
	}
	else{
		root->right=createnode(root->right,item);
	}
	
}
void InorderTraversal(node *root){
	if(root==NULL){
		return;
	
	}
	else{
			InorderTraversal(root->left);
			cout<<root->data<<" ";
	               InorderTraversal(root->right);
	}
}
int main(){
	node *root=NULL;
	int i,n;
	int item;
	
	cout<<"How many Values are you Entering: ";
	cin>>n;
	cout<<"Enter the Values: ";
	for(i=0;i<n;i++){
		cin>>item;
		root=createnode(root,item);
		
	}
	cout<<"In Order Traversal: \n";
	InorderTraversal(root);
}


