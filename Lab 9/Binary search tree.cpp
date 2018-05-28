#include<iostream>
using namespace std;

struct node{
	char data;
	struct* left;
	struct* right;
};

void Preorder(struct node *root){
	if(root == NULL)	return;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(struct node *root){
	 if(root == NULL)	return;
	 Inorder(root->left);
	 cout<<root-data<<" ";
	 Inorder(root->right);
}

void Postorder(struct node *root){
	if(root == NULL)	return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}

node* Insert(node *root, char data){
	if(root == NULL){
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root-right, data);
	return root;
}

int main(){
	node* root = NULL;
	root = Insert(root, 'M');	root = Insert(root, 'B');
	root = Insert(root, 'Q');	root = Insert(root, 'Z');
	root = Insert(root, 'A');	root = Insert(root, 'C');
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"\n";
	cout<<"Postorder: ";
	Preorder(root);
	cout<<"\n";
	cout<<"Inorder: ";
	Preorder(root);
	cout<<"\n";
}
