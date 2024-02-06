/*(a) Write a program in C or C++ to sort a given array using selection sort algorithm. Show
the number of comparison required for a given input.
(b) Write a program to find the nth Fibonacci number using tail recursion.*/

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

int nth_fibo(int n,int a,int b){
    if(n==0){
        return a;
    }
    else if(n==1){
        return b;
    }
    else{
        return nth_fibo(n-1,b,b+a);
    }
}

void selection_sort(int a[],int size){
    for(int i=0;i<size-1;i++){
        int min_index = i;
        for(int j=i+1;j<size;j++){
            if(a[j]<a[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            swap(a,i,min_index);
        }
        print_array(a,size);
        cout<<"\n";
    }
    print_array(a,size);
}

int main(){

    int a[100],size,n,choice;

    cout<<"\nMenu\n";
    cout<<"1.)Selection Sort\n";
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
        selection_sort(a,size);
        cout<<"\nSorted array:";
        print_array(a,size);
    }
    else if(choice == 2){
        cout<<"Enter the value of n:";
        cin>>n;
        int v = nth_fibo(n,0,1);
        cout<<"The "<<n<<"th fibonacci number is:"<<v;
    }
    else{
        cout<<"Invalid choice!";
    }
    

    return 0;
}