
//Merge sort implementation 

#include <iostream>
#include <stdio.h>
using namespace std;


//merge function to merge the two divide array
void merge(int arr[],int start,int mid,int end){

//getting the size of the left and right array first

int ls = mid-start+1;
int rs = end - mid; 
//now saving the elements in the left and right array
int leftArray[ls],rightArray[rs];

for (int i=0;i<ls;i++){
	leftArray[i] = arr[start+i];
}

for(int i = 0;i<rs;i++){
	rightArray[i] = arr[mid+i+1];
}


//Now code for merging leftArray and rightArray

int i=0,j=0,k=start;

while(i<ls && j<rs){
	if(leftArray[i]<=rightArray[j]){
		arr[k] = leftArray[i];
		i++;
	}
	else{
		arr[k] = rightArray[j];
		j++;
	}
	k++;
}

while(i<ls){
	arr[k] = leftArray[i];
	k++;i++;
}

while(j<rs){
	arr[k] = rightArray[j];
	k++;j++;
}


}



//Function for merge_sort

void merge_sort(int arr[],int start,int end){
	if(start<end){
		int mid = (start+end)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}


//utility function for printing array

void printArray(int arr[],int size){

for(int i = 0;i<size;i++){
	cout<<arr[i]<<" ";
}

cout<<endl;
}

int main()
{

	int arr[] = {3,5,6,2,4,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);

    //calling merge_sort function for sorting array
    
    merge_sort(arr,0,size-1);

    //printing result after the sorting 
    printArray(arr,size);
    return 0;
}
