/*Write a program in C or C++ to sort a given array using Quick sort algorithm.*/

#include<iostream>
using namespace std;

void print_array(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return;
}

void merge(int a[],int start,int mid,int end){
    int i = start;
    int j = mid+1;
    int k = start;
    int b[100];
    while(i<=mid && j<= end){
        if(a[i]>=a[j]){
            b[k] = a[j];
            j++;
        }
        else{
            b[k]=a[i];
            i++;
        }
        k++;
    }
    while(i != mid+1){
        b[k] = a[i];
        k++;
        i++;
    }
    while(j != end+1){
        b[k] = a[j];
        k++;
        j++;
    }
    for(int i=0;i<=end;i++){
        a[i] = b[i];
    }
}

void merge_sort(int a[],int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
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
    int start = 0;
    int end = size-1;
    merge_sort(a,start,end);
    cout<<"\nSorted array:";
    print_array(a,size);

    return 0;
}