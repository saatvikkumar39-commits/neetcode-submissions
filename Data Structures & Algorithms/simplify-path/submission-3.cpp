class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int n=path.size();
        int i=0;
        while(i<n){
            while(i<n && path[i]=='/') i++;
            string name;
            while(i<n && path[i]!='/'){
                name+=path[i];
                i++;
            } 
            if(name==".."){
                if(!st.empty()) st.pop_back();
            }
            else if(!name.empty() && name!="."){
                st.push_back((name));
            }
        }
        stack<string> st2;
        string ans="/";
        while(!st.empty()){
            string name=st.front();
            ans+=name;
            st.pop_front();
            if(!st.empty()) ans+='/';
        }
        return ans;
    }
};