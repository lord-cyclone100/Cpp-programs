#include<iostream>
using namespace std;

void print_array(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return;
}


void insertion_sort(int a[],int size){
    for(int i=1;i<size;i++){
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        print_array(a,size);
        cout<<endl;
    }
    print_array(a,size);
}

void tower_of_hanoi(int n, char source,char auxiliary,char target){
    if (n == 1){
        cout<<"Move disk 1 from "<<source<<" to "<<target<<endl;
        return;
    }  
    tower_of_hanoi(n - 1, source, target, auxiliary);
    cout<<"Move disk " <<n<<" from "<<source<<" to "<<target<<endl;
    tower_of_hanoi(n - 1, auxiliary, source, target);
}

int main(){

    int a[100],size,choice,n;
    cout<<"\nMenu\n";
    cout<<"1.)Insertion Sort\n";
    cout<<"2.)Tower of Hanoi\n";
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
        insertion_sort(a,size);
        cout<<"\nSorted array:";
        print_array(a,size);
    }
    else if(choice == 2){
        cout<<"Enter the number of disks:";
        cin>>n;
        tower_of_hanoi(n,'A','B','C');
    }
    else{
        cout<<"Invalid choice!";
    }
    

    return 0;
}