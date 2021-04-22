//Crux idea -> Repeatedly swap two adjacent elements if they are in wrong order
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int counter = 1;
    while (counter < n){
        for(int i = 0; i < n-counter; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
/*Things to remember*/
/*Here in this algorithm we will get our sorted array after n-1 iterations if we have n elements.*/
//1st iteration -> n-1
//2nd iteration -> n-2.........and so on
//ith iteration -> n-i
//We call this a bubble sort beacuse the maximum element of the array comes to the top like a bubble.