#include<bits/stdc++.h>
using namespace std;

class segmentTree {
  private:
    vector<int> a;
    vector<int> seg;

  public:
    segmentTree(int n) {
        a.resize(n);
        seg.resize(4*n);
    }
    void setArray(int n, int arr[]) {
        for(int i = 0; i < n; i++) a[i] = arr[i];
    }

    void build(int ind, int low, int high) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind+1, low, mid);
        build(2*ind+2, mid+1, high);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if(low >= l && high <= r) return seg[ind];
        if(high < l || low > r) return INT_MIN;

        int mid = (low + high) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return max(left, right);
    }
};

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(auto &it: arr) cin>> it;

    segmentTree st(n);
    st.setArray(n, arr);
    st.build(0, 0, n-1);

    cout << st.query(0, 0, n-1, 0, n-1);
}
