
0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{

	// Base Case
	if (n == 0 || W == 0)
		return 0;

	// If weight of the nth item is more
	// than Knapsack capacity W, then
	// this item cannot be included
	// in the optimal solution
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1],
						wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}





/* LCS problem */
#include <bits/stdc++.h>
using namespace std;



/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + lcs(X, Y, m-1, n-1);
	else
		return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}



/* Driver code */
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
	
	return 0;
}





/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// place parenthesis at different places
	// between first and last matrix, recursively
	// calculate count of multiplications for
	// each parenthesis placement and return the
	// minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, 1, n - 1);
}






/* A Naive recursive implementation of
unbounded Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int unboundedKnapsack(int W, int wt[], int val[], int idx)
{

	// Base Case
	// if we are at idx 0.
	if (idx == 0) {
		return (W / wt[0]) * val[0];
	}
	// There are two cases either take element or not take.
	// If not take then
	int notTake
		= 0 + unboundedKnapsack(W, wt, val, idx - 1);
	// if take then weight = W-wt[idx] and index will remain
	// same.
	int take = INT_MIN;
	if (wt[idx] <= W) {
		take = val[idx]
			+ unboundedKnapsack(W - wt[idx], wt, val,
								idx);
	}
	return max(take, notTake);
}

// Driver code
int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);

	cout << unboundedKnapsack(W, wt, val, n - 1);
	return 0;
}



/* A Naive C++ recursive implementation
of LIS problem */
#include <iostream>
using namespace std;

/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
	We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
	an element before arr[n-1] max_ref is
	used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
	/* Base case */
	if (n == 1)
		return 1;

	// 'max_ending_here' is length of LIS
	// ending with arr[n-1]
	int res, max_ending_here = 1;

	/* Recursively get all LIS ending with arr[0],
	arr[1] ... arr[n-2]. If arr[i-1] is smaller
	than arr[n-1], and max ending with arr[n-1]
	needs to be updated, then update it */
	for (int i = 1; i < n; i++) {
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}

	// Compare max_ending_here with the overall
	// max. And update the overall max if needed
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;

	// Return length of LIS ending with arr[n-1]
	return max_ending_here;
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{
	// The max variable holds the result
	int max = 1;

	// The function _lis() stores its result in max
	_lis(arr, n, &max);

	// returns max
	return max;
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout <<"Length of lis is "<< lis(arr, n);
	return 0;
}


