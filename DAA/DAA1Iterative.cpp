// // Code for iterative method
#include<iostream>
using namespace std;
typedef long long ll;
void printFibonacciNumbers(int n){
    if(n>=0)cout<<0<<" ";
    if(n>=1)cout<<1<<" ";
    int prev2=0,prev1=1;
    for(int i=2;i<n;i++){
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
        cout<<curr<<" ";
    }
    return;
}
int main(){
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    cout << "Fibonacci Series: ";
    printFibonacciNumbers(n);
    return 0;

}
//Output:
// Enter Number
// 9
// Fibonacci Series: 0 1 1 2 3 5 8 13 21 

//---------------------------------------------------------------------------

// #include <iostream>
// using namespace std;

// void PrintFibonacci(int length) {
//     // Initial variables for the base case.
//     int first = 0;
//     int second = 1;
    
//     // Printing the initial Fibonacci numbers.
//     cout << first << " " << second << " ";
    
//     // Decreasing the length by two because the first 2 Fibonacci numbers
//     // have already been printed.
//     length -= 2;
    
//     // Loop until the length becomes 0.
//     while (length > 0) {
//         // Printing the next Fibonacci number.
//         int next = first + second;
//         cout << next << " ";
        
//         // Updating the first and second variables for finding the next number.
//         int temp = second;
//         second = first + second;
//         first = temp;
        
//         // Decreasing the length that states the Fibonacci numbers to be printed more.
//         length -= 1;
//     }
// }

// int main() {
//     cout << "Fibonacci Series - " << endl;
//     PrintFibonacci(7);
//     return 0;
// }
// // Output:
// // Fibonacci Series - 
// // 0 1 1 2 3 5 8 