class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for(string log:logs){
            if(log=="../"){
                if(!st.empty()) st.pop();
            }
            else if(log!="./"){
                st.push(0);
            }
        }
        return st.size();
    }
};