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

ll countSquares(vector<vector<ll>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
    for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}
void solve() {
    vector<vector<ll>> arr = {
        {0, 1, 1, 1}, {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    ll n = 3, m = 4;
    ll squares = countSquares(arr);
    cout<<squares<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
}
