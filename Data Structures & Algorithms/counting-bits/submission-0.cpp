class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int cnt=0;
            int x=i;
            while(x>0){
                cnt++;
                x=x&(x-1);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
