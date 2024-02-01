/*(a) Write a program in C or C++ to sort a given array using bubble sort algorithm. Show the
number of comparison required for a given input.
(b) Write a program to find the factorial of a number using tail recursion.*/

#include<iostream>
using namespace std;

void print_array(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return;
}

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

void bubble_sort(int a[],int size){
    for(int i=0;i<size-1;i++){
        int flag = 0;
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a,j,j+1);
                flag = 1;
            }
        }
        print_array(a,size);
        cout<<endl;
        if(flag == 0){
            break;
        }
    }
    print_array(a,size);
}

int factorial(int n, int fact){
    if(n==1){
        return fact;
    }
    return factorial(n-1,n*fact);
}

int main(){

    int a[100],size,n,choice;
    cout<<"\nMenu\n";
    cout<<"1.)Bubble Sort\n";
    cout<<"2.)Factorial using tail recursion\n";
    cout<<"Enter your choice:";
    cin>>choice;

    if(choice == 1){
        cout<<"Enter the size of the array:";
        cin>>size;
        cout<<"Enter array elements:";
        for(int i=0;i<size;i++){
            cin>>a[i];
        }
        cout<<"Original array:";
        print_array(a,size);
        cout<<endl;
        bubble_sort(a,size);
        cout<<"\nSorted array:";
        print_array(a,size);
    }
    else if(choice == 2){
        cout<<"Enter the number:";
        cin>>n;
        if(n == 0){
            cout<<"0! = 1";
        }
        else{
            int f = factorial(n,1);
            cout<<n<<"! = "<<f;
        }
    }
    else{
        cout<<"Invalid choice!";
    }
    return 0;
}