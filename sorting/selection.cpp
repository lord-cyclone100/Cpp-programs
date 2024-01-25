#include<iostream>
using namespace std;

void swap(int a[],int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void print(int a[],int n){
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return;
}

void selection_sort(int a[],int n){
	for (int i = 0;i<n-1;i++){
		int minIndex = i;
		for (int j =i+1;j<n;j++){
			if (a[j]<a[minIndex]){
				minIndex = j;
			}
		}
		if (minIndex != i){
			swap(a,i,minIndex);
			print (a,n);
			cout<<"\n";
		}
	}
}

int main(){
	int a[100],n,choice;
	cout<<"How many elements?:";
	cin>>n;
	cout<<"Enter elements:";
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
    cout<<"The original array:";
	print(a,n);
	cout<<"\n";
	selection_sort(a,n);
	cout<<"\nThe sorted array:";
	print(a,n);
    return 0;
}