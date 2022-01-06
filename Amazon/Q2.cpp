class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n=a.size();
        int ans=0, s=0;
        while (s<n) {
            int e=s;
            if(e<n-1 && a[e]<a[e+1]){
               while(e<n-1 && a[e]<a[e+1])e++;
               if(e<n-1 && a[e]>a[e+1]){
                   while(e<n-1 && a[e]>a[e+1])e++;
                   ans=max(ans,e-s+1);
               }
            }
            s=max(s+1,e);
        }
        return ans;
    }
        
};