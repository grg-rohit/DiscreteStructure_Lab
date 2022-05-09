// // C program to implement recursive Binary Search
// #include <stdio.h>

// // A recursive binary search function. It returns
// // location of x in given array arr[l..r] is present,
// // otherwise -1
// int binarySearch(int arr[], int l, int r, int x)
// {
// 	if (r >= l) {
// 		int mid = l + (r - l) / 2;

// 		// If the element is present at the middle
// 		// itself
// 		if (arr[mid] == x)
// 			return mid;

// 		// If element is smaller than mid, then
// 		// it can only be present in left subarray
// 		if (arr[mid] > x)
// 			return binarySearch(arr, l, mid - 1, x);

// 		// Else the element can only be present
// 		// in right subarray
// 		return binarySearch(arr, mid + 1, r, x);
// 	}

// 	// We reach here when element is not
// 	// present in array
// 	return -1;
// }

// int main(void)
// {
// 	int arr[] = { 2, 3, 4, 10, 40 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int x = 10;
// 	int result = binarySearch(arr, 0, n - 1, x);
// 	(result == -1)
// 		? printf("Element is not present in array")
// 		: printf("Element is present at index %d", result);
// 	return 0;
// }

#include <stdio.h>

void binarySearch(int arr[], int item, int size);
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    
	int arr[] = { 2, 3, 4, 10, 40, 38, 60, 72, 77, 80, 22, 33};
    
	

	// binarySearch(arr, 4);
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int n = arr_size-1;
	// printf("%d", arr_size);
	printArray(arr, arr_size);
	binarySearch(arr, 77, n);

    return 0;
}

void binarySearch(int arr[], int item, int size){
	int i, j, n, temp;
    int mid_index, first_index, last_index, flag;
	n=size;

	// int size = sizeof(arr) / sizeof(arr[0]);
	//applying bubble sort
	for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
        }
    }

	flag = 0;
    first_index = 0;
    last_index = n;

	while(first_index <= last_index){
    	mid_index = (first_index + last_index)/2;
        if(arr[mid_index] == item){
            flag = 1;
        }
        if (arr[mid_index]<item){
            first_index = mid_index + 1;
        }
        else{
            last_index = mid_index - 1; 
        }
        
    }

    if(flag == 1)
        printf("\n%d found.\n", item);
    else
        printf("\n%d not found\n", item);
}