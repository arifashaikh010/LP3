//Code for recurrsive method
#include <iostream>
using namespace std;

void PrintFibonacci(int first, int second, int length) {
    // Stop the recursion when length reaches 0.
    if (length == 0) {
        return;
    }

    // Print the next Fibonacci number.
    int next = first + second;
    cout << next << " ";

    // Recursively call the function with updated values and decremented length.
    PrintFibonacci(second, next, length - 1);
}

int main() {
    // Print the initial 2 values.
    cout<<"Fibonacci Series : ";
    cout << 0 << " " << 1 << " ";

    // Calling the function to print the remaining Fibonacci series.

    PrintFibonacci(0, 1, 7 - 2);

    return 0;
}
//Output :
//Fibonacci Series : 0 1 1 2 3 5 8 

//--------------------------------------------

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int func(int n,vector<int>&dp){
//     if(dp[n]!=-1)return dp[n];
//     if(n==0 || n==1)return n;
//     int num=func(n-1,dp)+func(n-2,dp);
//     return dp[n]=num;
// }
// int main(){
//     int n;
//     cout<<"Enter Number"<<endl;
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     for(int i=0;i<n;i++){
//         int num=func(i,dp);
//         cout<<num<<" ";
//     }
//     return 0;
// }