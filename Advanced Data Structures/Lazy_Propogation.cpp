#include<bits/stdc++.h>
using namespace std;

class segmentTree {
  private:
    vector<int> a;
    vector<int> seg;
    vector<int> lazy;

  public:
    segmentTree(int n) {
        a.resize(n);
        seg.resize(4*n);
        lazy.resize(4*n, 0);
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
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r) {
        if(high < l || low > r) return 0;
        if(low >= l && high <= r) return seg[ind];

        int mid = (low + high) / 2;
        return query(2*ind+1, low, mid, l, r) +
               query(2*ind+2, mid+1, high, l, r);
    }

    void pointUpdate(int ind, int low, int high, int node, int val) {
        if(low == high) {
            seg[ind] += val;
            return;
        }
        int mid = (low + high)/2;
        if(node <= mid)
            pointUpdate(2*ind+1, low, mid, node, val);
        else
            pointUpdate(2*ind+2, mid+1, high, node, val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(high < l || low > r) return;

        if(low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            if(low != high) {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }

        int mid = (low + high)/2;
        rangeUpdate(2*ind+1, low, mid, l, r, val);
        rangeUpdate(2*ind+2, mid+1, high, l, r, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int querySumLazy(int ind, int low, int high, int l, int r) {
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(high < l || low > r) return 0;

        if(low >= l && high <= r) {
            return seg[ind];
        }

        int mid = (low + high)/2;
        return querySumLazy(2*ind+1, low, mid, l, r) +
               querySumLazy(2*ind+2, mid+1, high, l, r);
    }
};

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(auto &it: arr) cin >> it;

    segmentTree st(n);
    st.setArray(n, arr);
    st.build(0, 0, n-1);

    cout << st.querySumLazy(0, 0, n-1, 0, n-1);
}
