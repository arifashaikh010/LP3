// 0-1 Knapsack problem 

// Here is the top-down approach of 
// dynamic programming 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the value of maximum profit 
int knapSackRec(int W, int wt[], int val[], int index, int** dp) 
{ 
	// base condition 
	if (index < 0) 
		return 0; 
	if (dp[index][W] != -1) 
		return dp[index][W]; 

	if (wt[index] > W) { 

		// Store the value of function call 
		// stack in table before return 
		dp[index][W] = knapSackRec(W, wt, val, index - 1, dp); 
		return dp[index][W]; 
	} 
	else { 
		// Store value in a table before return 
		dp[index][W] = max(val[index] 
						+ knapSackRec(W - wt[index], wt, val, 
										index - 1, dp), 
					knapSackRec(W, wt, val, index - 1, dp)); 

		// Return value of table after storing 
		return dp[index][W]; 
	} 
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	// double pointer to declare the 
	// table dynamically 
	int** dp; 
	dp = new int*[n]; 

	// loop to create the table dynamically 
	for (int i = 0; i < n; i++) 
		dp[i] = new int[W + 1]; 

	// loop to initially filled the 
	// table with -1 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < W + 1; j++) 
			dp[i][j] = -1; 
	return knapSackRec(W, wt, val, n - 1, dp); 
} 

// Driver Code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 
	cout << knapSack(W, weight, profit, n); 
	return 0; 
}

//220
//-----


// #include <bits/stdc++.h> 
// using namespace std; 

// // A utility function that returns 
// // maximum of two integers 
// int max(int a, int b) { return (a > b) ? a : b; } 

// // Returns the maximum value that 
// // can be put in a knapsack of capacity W 
// int knapSack(int W, int wt[], int val[], int n) 
// { 

// 	// Base Case 
// 	if (n == 0 || W == 0) 
// 		return 0; 

// 	// If weight of the nth item is more 
// 	// than Knapsack capacity W, then 
// 	// this item cannot be included 
// 	// in the optimal solution 
// 	if (wt[n - 1] > W) 
// 		return knapSack(W, wt, val, n - 1); 

// 	// Return the maximum of two cases: 
// 	// (1) nth item included 
// 	// (2) not included 
// 	else
// 		return max( 
// 			val[n - 1] 
// 				+ knapSack(W - wt[n - 1], wt, val, n - 1), 
// 			knapSack(W, wt, val, n - 1)); 
// } 

// // Driver code 
// int main() 
// { 
// 	int profit[] = { 60, 100, 120 }; 
// 	int weight[] = { 10, 20, 30 }; 
// 	int W = 50; 
// 	int n = sizeof(profit) / sizeof(profit[0]); 
// 	cout << knapSack(W, weight, profit, n); 
// 	return 0; 
// } 

// // max value that can be obtained = 220