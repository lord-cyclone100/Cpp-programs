#include <iostream>
using namespace std;

void print_array(int a[],int n){
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return;
}

void heapadjust(int a[],int i,int n){
	int key = a[i];
	int j = 2*i;
	while (j<=n){
		if (j<n && a[j]<a[j+1]){
			j++;
		}
		if (key>=a[j]){
			break;
		}
		a[j/2]=a[j];
		j=j*2;
	}
	a[j/2]=key;
}

void makeheap(int a[],int n){
	for (int i=n/2;i>=1;i--){
		heapadjust(a,i,n);
	}
}

void heapsort(int a[],int n){
	makeheap(a,n);
	for (int i=n;i>=2;i--){
		int temp = a[1];
		a[1]=a[i];
		a[i]=temp;
		heapadjust(a,1,i-1);
	}
}

int main(){
	
	int a[100],n;
	
	cout<<"How many elements:";
	cin>>n;
	
	cout<<"Enter "<<n<<" elements:";
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<"Original array:";
	print_array(a,n);
	
	
	heapsort(a,n);
	
	cout<<"\nSorted array:";
	print_array(a,n);
	
	return 0;
}