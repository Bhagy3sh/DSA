#include <stdio.h>
#include <stdlib.h>
int size; // declared size as global since we will be using it alot.
void swap(int* num1,int* num2){ //Used for swapping 2 int values
	int temp;
	temp=*num1;
	*num1=*num2;
	*num2=temp;
}
void getarr(int* arr){ // To input array, needs size allocated beforehand if working with pointers
	int i;
	for(i=0;i<size;i++){
		scanf("%d",arr+i);
	}
}
void putarr(int* arr){ // To display array
	int i;
	for(i=0;i<size;i++){
		printf("%d,",arr[i]);
	}
}
int issorted(int* arr){ // To check if array is sorted
	for(int i=0;i<size-1;i++){
		if(arr[i]>arr[i+1]){ // if previous element is greater than the next, returns 0 aka false
			return 0;
		}
	}
	return 1; // returns 1 aka true at end since theres no element that is greater than the next as if there was, the condition in the loop would have been satisfied and 0 would have been returned. This indicates
  //that the array is sorted
}
void bubsort(int* arr){ //bubble sort function
	int i,j;
	printf("\n"); // to add space for clean visiblity
	for(i=0;i<size-1;i++){ // till size-1 since iterating i till end will cause segmentation fault as I am checking the element at ith and the immidiate next element
		for(j=0;j<size-i-1;j++){
		// here, since once the element is pushed to right position, we dont need to consider it again for iteration, so we iterate till size-i.
		// As for the extra 1, we try to avoid segmentation fault since we are
		// also accesing j+1th element.
			if(arr[j]>arr[j+1]){
				swap(arr+j,arr+j+1); // element swapped if it is greater than the immidiate next element
			}
		}
		printf("\nPass %d: ",i+1); // to show the passes, aka steps after each element is shifted to the right place, for debug purposes
		putarr(arr);
    
		if(issorted(arr)){
		// since we know the condition remains true if the return value is a non-zero number, so if
		// the array is sorted it returns 1, making the condition true and so we break from the loop as we do not need to interate again 
		// if the array is already sorted.
			break;
		}
	}
}
int main(){
	int *arr;
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	arr=(int*) malloc(size*sizeof(int));
	printf("\nEnter elements of array: ");
	getarr(arr);
	printf("\nArray-");
	putarr(arr);
	bubsort(arr);
	printf("\nSorted Array: ");
	putarr(arr);
	return 0;
}
