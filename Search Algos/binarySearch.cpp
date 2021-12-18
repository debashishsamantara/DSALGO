#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int s=0;
    int e=n;
    while (s<=e){
        int mid=(s+e)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1; 
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr, n, key);
}
/*Time Compexity*/
//After first iteration, length of array -> n
//After second iteration, length of array -> n/2
//After third iteration, length of array -> (n/2)/2 = n/(2²)
//After n iterations, length of array -> n/(2ᵏ)
//Let the length of array become 1 after k iterations
//=> n/2ᵏ = 1
//=> n = 2ᵏ
//=> log₂(n) = log₂(2ᵏ) (Taking log both sides)
//=> log₂(n) = klog₂(2) (log₂(2) = 1)~
//=> k = log₂(n)
//Therefore, complexity will be O(log₂(n))