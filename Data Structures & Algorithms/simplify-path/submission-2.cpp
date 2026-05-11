class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
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
                if(!st.empty()) st.pop();
            }
            else if(!name.empty() && name!="."){
                st.push(name);
            }
        }
        stack<string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        string ans="/";
        while(!st2.empty()){
            string name=st2.top();
            ans+=name;
            st2.pop();
            if(!st2.empty()) ans+='/';
        }
        return ans;
    }
};