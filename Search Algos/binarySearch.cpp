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
//After third iteration, length of array -> (n/2)/2 = n/(2^2)
//After n iterations, length of array -> n/(2^k)
//Let the length of array become 1 after k iterations
//=> n/2^k = 1
//=> n = 2^k
//=> log2(n) = log2(2^k) (Taking log both sides)
//=> log2(n) = klog2(2) (log2(2) = 1)
//=> k = log2(n)
//Therefore, complexity will be O(log2(n))