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
//DAMN!!!!!! THIS IS REALLY A VERY VERY GOOD QUESTION! Try to think in reverse order
int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int mini = 10e8;
    for(int ind = i; ind <= j; ind++) {
        int cost = (cuts[j+1] - cuts[i-1]) + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
        mini = min(cost, mini);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int>& cuts) {
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
    sort(cuts.begin(), cuts.end());


    return f(1, cuts.size()-2, cuts, dp);
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(auto &it: v) {
        cin >> it;
    }

    int ans = minCost(n, v);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
