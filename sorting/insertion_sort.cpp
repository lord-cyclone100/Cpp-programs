#include<iostream>
using namespace std;

void print_array(int a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;
}

void insertion_sort(int a[],int n){
	for (int i = 1;i<n;i++){
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = key;
		print_array(a,n);
		cout<<"\n";
	}
}

int main(){

    int a[100],n,x;
    cout<<"Enter the length of the array:";
    cin>>n;

    cout<<"Enter array elements:";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"\nThe original array:";
    print_array(a,n);

    insertion_sort(a,n);

    cout<<"\nThe sorted array:";
    print_array(a,n);

    return 0;
}