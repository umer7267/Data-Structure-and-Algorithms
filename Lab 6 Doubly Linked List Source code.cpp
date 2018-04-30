#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node* pre;
	node* next;
};

node* head = NULL;

node* getNewNode(int item){
	node* newNode = (node*)malloc(sizeof(node));
	(*newNode).data = item;
	(*newNode).pre = NULL;
	(*newNode).next = NULL;
	return newNode;
}

void insert(node* newNode){
	node* last_node = (node*)malloc(sizeof(node));
	last_node = head;
	head = newNode;
	newNode -> pre = NULL;
	newNode -> next = last_node;
	cout<<"\n\nData inserted successfully..\n\n";
	cout<<"\n\nPress any key to continue..";
	getch();
	return;
}

void display(){
	node* newNode = (node*)malloc(sizeof(node));
	newNode = head;
	cout<<"\n\nData in the list\n\n";
	while(newNode != NULL){
		cout<<newNode -> data<<" ";
		newNode = newNode -> next;
	}
	cout<<"\n\nPress any key to continue..";
	getch();
	return;
}

int main(){
	int choice, item;
	node* newNode;
	up:
	system("cls");
	cout<<"\n\n\tPRESS\n";
	cout<<"\t1. Insert Data\n";
	cout<<"\t2. Display Data\n";
	cout<<"\t3. Exit\n\n\t";
	cin>>choice;
	if(choice == 1){
		cout<<"\n\nEnter data to insert: ";
		cin>>item;
		newNode = getNewNode(item);
		insert(newNode);
		goto up;
	}
	else if(choice == 2){
		display();
		goto up;
	}
	else if(choice == 3){
		exit(0);
	}
	else{
		cout<<"\n\nWRONG CHOICE!";
		cout<<"\n\nPress any key to continue..";
		getch();
		goto up;
	}
	return 0;
}


