/*Merge sort is one of the most popular sorting algorithms which works on the principle
of divide and conquer. 

Here, the unsorted array is first divided into two parts about the mid element. Then, the
sub arrays are again divided into two equal parts each about their mid elements. This
division continues until we are left with n number of unit length arrays where n is the
length of the array.

The merge() function is responsible for combining all the unit length arrays into a
single sorted array. The merge() function is responsible for combining all the unit length arrays into a
single sorted array.It is called inside the merge_sort() function.  First a new array
is created. Then few variables are initialized: -i and k are initialised to the
starting index, j is initialized to the index of mid+1.
Our main  aim  is to compare the sub arrys and append those values to the newly created
array. A single element is already sorted so the first two elements are just compared 
and accordingly pushed into the array. Since, the merge_sort() is a recursive function,
a larger size array is returned to the calling function. The comarison process now
takes place for larger sized arrays and acordingly elements are pushed inside the
new array.

After all the comparisons are done, one case may arrive that one of the two
sub arrays may have some elements which remain even after the comparison process
is complete. In  such case, a while loop is used to push those elements in the new
array without comparison since, they are already sorted from the previous comparison.
Finally, all the elements are assigned to the previous array and in this way, the array
gets sorted.
*/


#include <iostream>
using namespace std;

void print_array(int a[],int n){
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return;
}

void merge(int a[],int s,int mid,int e){
	int b[100];		//new array initialized
	int i = s;
	int j = mid + 1;
	int k = s;
	
	while (i <= mid && j <= e){		//comparing each element of the individual sub arrays
		if (a[i] <= a[j]){			//and pushing them into the new array b[]
			b[k] = a[i];
			i ++;
		}
		else{
			b[k] = a[j];
			j ++;
		}
		k ++;
	}
	while (i <= mid){	//checking whether any element is left in either of the sub
		b[k] = a[i];	//arrays and pushing them into the new array
		k ++;
		i ++;
	}
	while (j <= e){
		b[k] = a[j];
		k ++;
		j ++;
	}
	
	for (int i=s;i<=e;i++){		//reassigning all the values of the new array to the
        a[i] = b[i];			//previous array
    }
	return;
}

void merge_sort(int a[],int s,int e){
	if (s < e){
		int mid = (s + e) / 2;	//dividing the array about the mid element
		merge_sort(a,s,mid);		//repeated continuous division until we get arrays
		merge_sort(a,mid + 1,e);	//of single elements
		merge(a,s,mid,e);	//combines those sub arrays into a single sorted array
	}
	return;
}

int main(){
	
	int a[100],n;
	
	cout<<"How many elements:";
	cin>>n;
	
	cout<<"Enter "<<n<<" elements:";
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<"Original array:";
	print_array(a,n);
	
	int s = 0;
	int e = n - 1;
	
	merge_sort(a,s,e);
	
	cout<<"\nSorted array:";
	print_array(a,n);
	
	return 0;
}
