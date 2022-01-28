class Solution {
public:
    int divide(int a1, int b1) {
        long long int a=a1,b=b1;
        int s=0;
        if((a>0 &&b<0)||(a<0 && b>0))s=1;
        a=abs(a);
        b=abs(b);
        long long int t=0,ans=0;
        for(int i=31;i>=0;i--){
            if(t+(b<<i) <=a){
                t+=(b<<i);
                ans+=(1ll <<i);
            }
        }
        if(s==1)ans*=-1;
        if(ans>INT_MAX || ans<INT_MIN)return INT_MAX;
        return ans;
    }
};