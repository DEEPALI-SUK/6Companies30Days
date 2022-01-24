class Solution {
public:
    int findInMountainArray(int t, MountainArray &a) {
        int n=a.length();
        int l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(a.get(m-1)<a.get(m))l=m+1;
            else r=m;
            
        }
        int p=l;
        l=0;
        r=p;
        while(l<=r){
            int m=l+(r-l)/2;
            int mv=a.get(m);
            if(mv>t){
                r=m-1;
            }else if(mv<t){
                l=m+1;
            }else return m;
            
        }
        l=p;
        r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int mv=a.get(m);
            if(mv>t){
                l=m+1;
            }else if(mv<t){
                r=m-1;
            }else return m;
            
        }
        return -1;
    }
};