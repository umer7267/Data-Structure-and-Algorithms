#include<iostream>
#include<conio.h>
using namespace std;
void travers_array(int array[], int n){
	cout<<"\n\n";
	for(int x=0; x<n; x++)
	{
		cout<<array[x]<<" ";
	}
	cout<<"\n\nPRESS ANY KEY TO CONTINUE...";
	getch();
}

void insert(int array[],int& n, int k, int item){
	for(int j=n; j>=k; j--){
		array[j+1] = array[j];
	}
	array[k] = item;
	n = n+1;
	cout<<"\nVALUE ADDED SUCCESSFULLY";
	cout<<"\n\nPRESS ANY KEY TO CONTINUE...";
	getch();
}

void delete_value(int array[], int& n, int k){
	for(int j=k; j<=sizeof(array); j++){
		array[j] = array[j+1];
	}
	n = n-1;
	cout<<"\nVALUE DELETED SUCCESSFULLY";
	cout<<"\n\nPRESS ANY KEY TO CONTINUE...";
	getch();
}
int main()
{
	int choice,n = 5,arr[n],location,value;
	cout<<"\t\t\tENTER 5 ELEMENTS\n\n";
	for(int i=0; i<5; i++)
	{
		cout<<"Enter "<<i+1<<" Value: ";
		cin>>arr[i];
	}
	up:
	system("cls");
	cout<<"\t\t\tMAIN MENU\n\n";
	cout<<"\tPRESS 1 FOR TRAVERSING THE ARRAY\n\n";
	cout<<"\tPRESS 2 FOR INSERTING DATA INTO ARRAY\n\n";
	cout<<"\tPRESS 3 FOR DELETING DATA FROM ARRAY\n\n";
	cout<<"\tPRESS 4 TO EXIT\n\n";
	cout<<"PLEASE ENTER YOUR CHOICE\n\n";
	cin>>choice;
	if(choice == 1){
		travers_array(arr, n);
		goto up;
	}
	else if(choice == 2){
		cout<<"\n\nENTER LOCATION TO INSERT: ";
		cin>>location;
		cout<<"\nENTER VALUE TO INSERT: ";
		cin>>value;
		insert(arr, n, location-1, value);
		goto up;
	}
	else if(choice == 3){
		cout<<"\n\nENTER LOCATION TO DELETE: ";
		cin>>location;
		delete_value(arr, n, location-1);
		goto up;
	}
	else if(choice == 4){
		exit(0);
	}
	else{
		cout<<"\n\nWRONG CHOICE!";
		cout<<"\n\nPRESS ANY KEY TO CHOOSE AGAIN...";
		getch();
		goto up;
	}
	return 0;
}
