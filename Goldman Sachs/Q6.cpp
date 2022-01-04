class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n=s1.length(),m=s2.length(),mx=0;
        int g=__gcd(n,m);
        string s=s1.substr(0,g);
        for(int j=0;j<n;j+=g)if(s1.substr(j,g)!=s)return "";
        for(int j=0;j<m;j+=g)if(s2.substr(j,g)!=s)return "";
        return s;
    }
};