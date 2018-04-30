#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* head = NULL;

void insert(int item){
	node *NewNode = (node*) malloc(sizeof(node));
	NewNode -> data = item;
	NewNode -> next = head;
	head = NewNode;
	cout<<"\n\nData Inserted Successfully!";
	cout<<"\n\nPress any key to continue...";
	getch();
}

void Delete(int n){
	if(head == NULL){
		cout<<"\n\nError: Empty List!";
		cout<<"\n\nPress any key to continue...";
		getch();
		return;
	}
	node* NewNode = (node*)malloc(sizeof(node));
	if(n == 1){
		NewNode = head;
		head = NewNode -> next;
		free(NewNode);
		cout<<"\n\nData Deleted Successfully!";
		cout<<"\n\nPress any key to continue...";
		getch();
		return;
	}
	else{
	NewNode = head;
	for(int i=0; i<n-2; i++)
		NewNode = NewNode -> next;
	node* NewNode2 = (node*)malloc(sizeof(node));
	NewNode2 = NewNode -> next;
	NewNode -> next = NewNode2 -> next;
	free(NewNode2);
	cout<<"\n\nData Deleted Successfully!";
	cout<<"\n\nPress any key to continue...";
	getch();
	return;
	}
}

void display(){
	if(head == NULL){
		cout<<"\n\nError: Empty List!";
		cout<<"\n\nPress any key to continue...";
		getch();
		return;
	}
	node *NewNode = (node*) malloc(sizeof(node));
	NewNode = head;
	cout<<"\n\nData in the List:\n\n";
	while(NewNode != NULL){
		cout<<NewNode -> data<<" ";
		NewNode = NewNode -> next;
	}
	cout<<"\n\nPress any key to continue...";
	getch();
}

int main(){
	int choice, item;
	up:
	system("cls");
	cout<<"\n\n\tCHOOSE FROM THE FOLLOWING:";
	cout<<"\n\n\t1. Insert Data in the List";
	cout<<"\n\t2. Display Data of the List";
	cout<<"\n\t3. Delete Data of the List";
	cout<<"\n\t4. Exit\n\n\t";
	cin>>choice;
	if(choice == 1){
		cout<<"\n\nEnter a value: ";
		cin>>item;
		insert(item);
		goto up;
	}
	else if(choice == 2){
		display();
		goto up;
	}
	else if(choice == 3){
		cout<<"\n\nEnter position to delete item: ";
		cin>>item;
		Delete(item);
		goto up;
	}
	else if(choice == 4){
		exit(0);
	}
	else{
		cout<<"\n\nWRONG CHOICE!";
		cout<<"\n\nPress any key to choose again...";
		getch();
		goto up;
	}
	return 0;
	
}
