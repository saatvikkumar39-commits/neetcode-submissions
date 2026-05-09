class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;
    int idx;
    StockSpanner() {
        idx=0;
    }
    
    int next(int price) {
        prices.push_back(price);  
        while(!st.empty() && prices[st.top()]<=price){
            st.pop();
        }
        int ans=0;
        if(st.empty()) ans=idx+1;
        else ans= idx-st.top();
        st.push(idx);
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */