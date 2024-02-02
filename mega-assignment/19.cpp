/*Write a program in C or C++ to sort a given array using Quick sort algorithm.*/

#include<iostream>
using namespace std;


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

int partition(int a[],int low,int high){
    int pivot = a[high];
    int i = low-1;
    for(int j=low;j<=high;j++){
        if(a[j]<=pivot){
            i++;
            swap(a,i,j);
        }
    }
    return i;
}

void quick_sort(int a[],int low, int high){
    if(high>=low){
        int y = partition(a,low,high);
        quick_sort(a,low,y-1);
        quick_sort(a,y+1,high);
    }
}

int main(){

    int a[100],size;

    cout<<"Enter the size of the array:";
    cin>>size;
    cout<<"Enter array elements:";
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<"Original array:";
    print_array(a,size);
    cout<<endl;
    int high = size-1;
    int low = 0;
    quick_sort(a,low,high);
    cout<<"\nSorted array:";
    print_array(a,size);



    return 0;
}