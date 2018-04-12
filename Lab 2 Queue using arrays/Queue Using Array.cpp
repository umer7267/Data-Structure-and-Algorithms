#include<iostream>
#include<conio.h>
using namespace std;

void insert(int queue[], int n, int& front, int& rear){
	int item;
	if((front == 1 && rear == n) || front == rear + 1){
		cout<<"\n\nError: Queue Overflow!";
		cout<<"\n\nPress any key to continue....";
		getch();
		return;
	}
	cout<<"\n\nEnter a value: ";
	cin>>item;
	if(front == 0){
		front = 1;
		rear = 1;
	}
	else if(rear == n)
		rear = 1;
	else
		++rear;	
	queue[rear] = item;
	cout<<"\n\nValue inserted Successfully";
	cout<<"\n\nPress any key to continue....";
	getch();
}

void deletion(int queue[], int n, int& front, int& rear){
	if(front == 0){
		cout<<"\n\nError: Queue Underflow!";
		cout<<"\n\nPress any key to continue....";
		getch();
		return;
	}
	int item;
	item = queue[front];
	if(front == rear){
		front = 0;
		rear = 0;
	}
	else if(front == n)
		front = 1;
	else
		front++;
	cout<<"\n\nValue deleted Successfully";
	cout<<"\n\nPress any key to continue....";
	getch();
}

void display(int queue[], int n, int& front, int& rear){
	if(front == 0 && rear == 0){
		cout<<"\n\nQueue is Empty!\n\n";
		cout<<"\n\nPress any key to continue....";
		getch();
		return;
	}
	cout<<"\n\nItems in the queue\n\n";
	for(int i=front; i<=rear; i++){
		cout<<queue[i]<<" ";
	}
	cout<<"\n\nPress any key to continue....";
	getch();
}

int main()
{
	int choice, n = 15, queue[n], front = 0, rear = 0,value;
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
		insert(queue, n, front, rear);
		goto up;
	}
	else if(choice == 2){
		deletion(queue, n, front, rear);
		goto up;
	}
	else if(choice == 3){
		display(queue, n, front, rear);
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
