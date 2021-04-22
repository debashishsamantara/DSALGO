import java.util.Scanner;
public class binarySearch {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        int key = sc.nextInt();
        System.out.println(bSearch(arr, n, key));
    }   
    public static int  bSearch(int arr[], int n, int key){
        int s = 0;
        int e = n;
        while (s <= e) {
            int mid = (s+e)/2;
            if (arr[mid] == key){
                return mid;
            }
            else if (arr[mid] > key){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return 0;
    }
}
