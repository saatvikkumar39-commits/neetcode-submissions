class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size(); int n2=b.size();
        int i=n1-1;int j=n2-1;
        int carry=0;string ans="";
        while(i>=0 && j>=0){
            int x=a[i]-'0'; int y=b[j]-'0';
            int temp=x+y+carry;
            int digit=temp&1;
            carry=temp>>1;
            ans+=digit+'0';
            i--;j--;
        }
        while(i>=0){
            int temp=a[i]-'0'+carry;
            int digit=temp&1;
            carry=temp>>1;
            ans+=digit+'0';
            i--;
        }
        while(j>=0){
            int temp=b[j]-'0'+carry;
            int digit=temp&1;
            carry=temp>>1;
            ans+=digit+'0';
            j--;
        }
        while(carry>0){
            ans+=carry+'0';
            carry=carry>>1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};