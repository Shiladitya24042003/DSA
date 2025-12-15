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
int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
    if(i == text1.size() || j == text2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int len = 0;
    if(text1[i] == text2[j]) {
        len = max(len, 1 + f(i+1, j+1, text1, text2, dp));
    }
    else {
        len = max(len, max(f(i+1, j, text1, text2, dp), f(i, j+1, text1, text2, dp)));
    }

    return dp[i][j] = len;
}
void longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(text1[i] == text2[j]) dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
            else dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j+1]));
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout<<dp[i][j];
        }
        cout<<endl;
    }

    int i = 0, j = 0;
    string ans = "";
    while(i < n && j < m) {
        if(text1[i] == text2[j]) {
            ans += text1[i];
            i++;
            j++;
        }
        else if(dp[i+1][j] > dp[i][j+1]) {
            i++;
        }
        else j++;
    }
    cout<<ans<<endl;
    // return dp[0][0];
}
void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    longestCommonSubsequence(s1, s2);
    // cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
