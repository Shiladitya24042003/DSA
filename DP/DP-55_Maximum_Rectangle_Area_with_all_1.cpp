#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

//finding primes
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) { //if it hits NULL or p or q then return root
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q); //go to the left
    TreeNode* right = lowestCommonAncestor(root->right, p, q); // go to the right

    if(left == NULL) { //if left returns a null then return right
        return right;
    }
    else if(right == NULL) { //if right returns a null then return left
        return left;
    }
    else { //if both the above tconditions donot pass then return root as it holds the answer
        return root;
    }
}

//sieve algorithm
vector<ll> sieve(ll n) {
    
    vector<bool> prime(n + 1, true);
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<ll> res;
    for (ll p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

//Prime Factorization of n
// Function that returns prime factors of n in a vector
vector<ll> primeFactors(ll n) {
    vector<ll> result;

    // Count the number of 2s that divide n
    while (n % 2 == 0) {
        result.push_back(2);
        n /= 2;
    }

    // Check for all odd numbers up to sqrt(n)
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            result.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        result.push_back(n);
    }

    return result;
}


bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


bool isAscending(const vector<ll>& v) {
    for (ll i = 1; i < (ll)v.size(); i++) {
        if (v[i] < v[i-1]) 
            return false;
    }
    return true;
}

struct Triplet {
    ll first;
    ll second;
    char third;

    Triplet(ll a, ll b, char c) {
        first = a;
        second = b;
        third = c;
    }

    // Custom comparator: compare by first, then second, then third
    bool operator>(const Triplet &other) const {
        if (first != other.first) return first > other.first;
        if (second != other.second) return second > other.second;
        return third > other.third;
    }
    bool operator<(const Triplet &other) const {
        if (first != other.first) return first < other.first;
        if (second != other.second) return second < other.second;
        return third < other.third;
    }

};
ll power(ll A, ll B)
{
    if (B == 0)
        return 1;

    ll res = power(A, B / 2);

    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
//------------------------------------------------------------------------------------------------------------
//CODE STARTS FROM HERE
/**
 * -1
 * 1 2 2 3 3 3 
 * 1 1 1 1 1 1 
 * 1 2 3 4 5 
 * */
#include <bits/stdc++.h>
using namespace std;

// Class containing the solution functions
class Solution {
public:

    // Function to calculate largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {

        // Stack to store indices of histogram bars
        stack<int> st;

        // Variable to store the max area
        int maxArea = 0;

        // Add a sentinel zero height at the end
        heights.push_back(0);

        // Iterate through all bars
        for (int i = 0; i < heights.size(); i++) {

            // While current bar is smaller than the bar at stack top
            while (!st.empty() && heights[i] < heights[st.top()]) {

                // Pop the top height
                int height = heights[st.top()];
                st.pop();

                // Calculate width
                int width = st.empty() ? i : i - st.top() - 1;

                // Update max area
                maxArea = max(maxArea, height * width);
            }

            // Push current index
            st.push(i);
        }

        return maxArea;
    }

    // Function to find maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Return 0 if matrix is empty
        if (matrix.empty()) return 0;

        // Get number of columns
        int m = matrix[0].size();

        // Height array to build histogram row-wise
        vector<int> height(m, 0);

        // Variable to track max rectangle area
        int maxArea = 0;

        // Traverse each row of the matrix
        for (auto& row : matrix) {

            // Update histogram based on current row
            for (int i = 0; i < m; i++) {
                if (row[i] == '1') height[i]++;
                else height[i] = 0;
            }

            // Compute area for this histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};

// Main driver function
int main() {

    // Sample matrix input
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution sol;

    // Call the function and print result
    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}