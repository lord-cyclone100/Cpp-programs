/*Quick sort is one of the most efficient sorting algorithms. It works on the principle
of divide and conquer rule. The entire array is divided into two sub arrays, each part
is sorted again and again and finally they are combined to form the final sorted array.

Two terms play a key role in this algorithm :- partition and pivot.
Firstly, any element in the array could be taken as pivot. It could be the first,
last or any random element. Here, I have taken the last element as the pivot. The main
job is to place the pivot element at the correct index position in the array. All elements
less than the pivot are placed to the left of the pivot and the ones greater than pivot
are placed to it's right. 

Next, a variable i is initialised to -1 which makes position of all the elements less than
pivot. The array is traversed using a variable j and each element is compared with the
pivot element. If the element is greater than pivot, nothing is done and if the element
is less than pivot, i is incremented by 1 and the element is swapped with the element at 
position i. This process is continued until the entire array is traversed and at the end,
we should get an array with the pivot at the actual correct position, aelements less 
pivot to it's left and the rest to it's right. Thus a partition is created.

The same process is followed for the sub array till the element just before pivot and
the sub array after the pivot and the quick sort function is called recursively to
achieve this. Finally, we get n arrays of unit length (n = length of the actual array)
and we know, an array with a single element is already sorted. These unit arrays are
then combined to form the final sorted array

In this way, we can sort an array using quick sort algorithm
Time complexity analysis:
Worst case - O(n²)
Average case - O(n log n)
Best case - O(n log n)
*/


#include <iostream>
using namespace std;

void print_array(int a[],int n){	//this function is made to avoid the repeatition
	for (int i=0;i<n;i++){			//of the same code. It's optional.
		cout<<a[i]<<" ";
	}
	return;
}

void swap(int a[],int i,int j){		//swap function swaps the values. The reason for
	int temp = a[i];				//making this function is the same as print_array.
	a[i] = a[j];
	a[j] = temp;
	return;
}

int partition(int a[],int low,int high){	//partitions the array into two sub arrays
	int pivot = a[high];					//with the pivot at the middle.
	int i = low - 1;
	
	for (int j=low;j<=high;j++){
		if (a[j]<=pivot){
			i++;
			swap(a,i,j);
		}
	}
	return i;
}


void quick_sort(int a[],int low,int high){	
	if (low<high){		//terminating condition for recursion
		int index = partition(a,low,high);
		
		quick_sort(a,low,index-1);
		quick_sort(a,index+1,high);	//recursive call of quick_sort function.
	}
	return;
}

int main(){
	int a[100],n;
	
	cout<<"How many elements:";
	cin>>n;	//lenght of array
	
	cout<<"Enter "<<n<<" elements:";
	
	for (int i=0;i<n;i++){
		cin>>a[i];	//taking input for the array elements
	}
	
	cout<<"Original array:";
	print_array(a,n);	//calling print_array() to print the unsorted array
	
	int low = 0;
	int high = n-1;	//determining the values of low and high
	
	quick_sort(a,low,high);	//performing quick sort on the unsorted array
	cout<<"\nSorted array:";
	print_array(a,n);	//displaying the sorted array
	
	return 0;
}
