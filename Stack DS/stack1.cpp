#include<bits/stdc++.h>
using namespace std;

#define n 100

class stack1{
    int* arr;
    int top;
    public:
        stack1(){
            arr = new int [n];
            top = -1;
        }

        void push(int x){
            if(top == n - 1){
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            arr[top] = x;
        }

        void pop(){
            if(top == -1){
                cout << "No value to Pop";
                return;
            }
            top--;
        }

        int Top(){
            if(top == -1){
                cout << "No element in Stack" << endl;
                return -1;
            }
            return arr[top];
        }

        bool empty(){
            return top == -1;
        }

};
  
int main(){
    stack1 st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.Top() << endl;
    st.empty();
    return 0;
}