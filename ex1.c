 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
  
  int find_optimal_k(int arr1[], int n, int arr2[], int m);
  int find_k(int arr[], int n, int k);
int main(){
    int arr1[4] = {13,15,18,20};
    int arr2[5]={2,3,4,5,7};
    find_optimal_k(arr1,4,arr2,5);
    return 0;

} 
  int find_optimal_k(int arr1[], int n, int arr2[], int m) {
     if(rating(find_k(arr1, n ,0) + 1, n) > rating(find_k(arr2, n ,0) + 1, n)){
                return 0;
     }
    for (int i=0;i<m;i++){
            int k =  arr2[i];
            if(rating(find_k(arr1, n ,k), n) >rating(find_k(arr2, m ,k), m)){
                return arr2[i - 1];
            }
            if(rating(find_k(arr1, n ,k-1), n) > rating(find_k(arr2, m ,k), m)){
                return arr2[i - 1];
            }
            if(rating(find_k(arr1, n ,k+1), n) > rating(find_k(arr2, m ,k), m)){
                return arr2[i - 1];
            }
    }
    return -1;
     
   
 }
int find_k(int arr[], int n, int k){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    } 
    if (k < arr[0]){
        return 0;
    }
    if (k > arr[n - 1]){
        return n;
    }
} 

int rating (int k, int m){
    if (k == 0){
        return ((m - k)*3);
    }
    else{
        return ((k - 1)*2 + (m - k + 1)*3);
    }
}
 
 