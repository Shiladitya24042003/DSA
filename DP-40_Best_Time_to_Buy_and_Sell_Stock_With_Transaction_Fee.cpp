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
int f(int indx, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp) {
    if(indx >= prices.size()) return 0;
    if(dp[indx][buy] != -1) return dp[indx][buy];

    int profit = INT_MIN;
    if(buy) {
        profit = max(profit, max(-prices[indx] + f(indx+1, 0, fee, prices, dp),
                                0 + f(indx+1, buy, fee, prices, dp)));
    }
    else {
        profit = max(profit, max(prices[indx] - fee + f(indx+1, 1, fee, prices, dp),
                            0 + f(indx+1, 0, fee, prices, dp)));
    }

    return dp[indx][buy] = profit;
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, fee, prices, dp);
}
void solve() {
    int n, fee;
    cin >> n >> fee;
    vector<int> v(n);
    for(auto &it: v) {
        cin >> it;
    }

    int ans = maxProfit(v, fee);
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
