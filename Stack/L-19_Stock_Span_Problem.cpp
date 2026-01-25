class StockSpanner {
private: stack<pair<int, int>> st; int cntDays;
public:
    StockSpanner() {
        cntDays = 0;
    }
    
    int next(int price) {
        int indx = -1;
        while(!st.empty() && price >= st.top().first) {
            st.pop();
        }
        if(!st.empty()) indx = st.top().second;
        st.push({price, cntDays++});
        return cntDays - 1 - indx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */