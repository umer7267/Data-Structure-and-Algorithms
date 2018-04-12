#include<iostream>
#include<conio.h>
#define SIZE 101
using namespace std;
int stack[SIZE];
int top = -1;

void push(){
	if(top == SIZE-1){
		cout<<"\n\nError: Stack Overflow!";
		cout<<"\n\nPress any key to continue....";
		getch();
		return;
	}
	else
		top++;
	int item;
	cout<<"\n\nEnter value to insert: ";
	cin>>item;
	stack[top] = item;
	cout<<"\n\nValue inserted Successfully";
	cout<<"\n\nPress any key to continue....";
	getch();
}

void pop(){
	int item;
	if(top == -1){
		cout<<"\n\nError: Stack Underflow!";
		cout<<"\n\nPress any key to continue....";
		getch();
		return;
	}
	else{
		item = stack[top];
		top--;
		cout<<"\n\n"<<item<<" is removed from stack!";
	}
	cout<<"\n\nPress any key to continue....";
	getch();
}

void display(){
	if(top == -1){
		cout<<"\n\nError: Stack is Empty!";
		cout<<"\n\nPress any key to continue....";
		getch();
		return;
	}
	cout<<"\n\nItems in stack\n\n";
	for(int i=0; i<=top; i++){
		cout<<stack[i]<<" ";
	}
	cout<<"\n\nPress any key to continue....";
	getch();
}

int main(){
	int choice;
	up:
	system("cls");
	cout<<"\t\t\tMAIN MENU\n\n";
	cout<<"\tPRESS\n\n";
	cout<<"\t1 FOR INSERTION\n\n";
	cout<<"\t2 FOR DELETION\n\n";
	cout<<"\t3 FOR DISPLAY\n\n";
	cout<<"\t4 TO EXIT\n\n";
	cout<<"PLEASE ENTER YOUR CHOICE\n\n";
	cin>>choice;
	if(choice == 1){
		push();
		goto up;
	}
	else if(choice == 2){
		pop();
		goto up;
	}
	else if(choice == 3){
		display();
		goto up;
	}
	else if(choice == 4)
		exit(0);
	else{
		cout<<"\n\nWRONG CHOICE!";
		cout<<"\n\nPRESS ANY KEY TO CHOOSE AGAIN...";
		getch();
		goto up;
	}
	return 0;
}
