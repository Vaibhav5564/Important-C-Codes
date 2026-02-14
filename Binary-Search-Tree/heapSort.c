#include<stdlib.h>
#include <stdio.h>

void heapSort(int arr[] , int n , int i){
      
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n &&  arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != i){
        int temp;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapSort(arr, n, largest);
    }
}

void heap(int arr[] , int n){
    int i;
    for(i=n/2-1 ; i>=0 ; i--){
        heapSort(arr, n, i);
    }
    
    for(i=n-1 ; i>0 ; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapSort(arr,i,0);
    }
}

void print(int arr[] , int n){
    int i;
    for(i=0 ; i<n ; i++){
        printf("%d\t",arr[i]);
    }     
 }
int main() {
   
   int n , i ;
   
   printf("Enter Size of the Array ");
   scanf("%d",&n);
   
    int arr[n];
    
   for(i=0 ; i<n ; i++){
   printf("Enter Element - ");
   scanf("%d",&arr[i]);
   }
   printf("\n--------------------------------------------------------------\n");
   printf("\nArray Before Sort - \n");
   print(arr,n);
   
   printf("\n--------------------------------------------------------------\n");
   printf("\nArray After Sort - \n");
   heap(arr,n);
   print(arr,n);
    return 0;
}