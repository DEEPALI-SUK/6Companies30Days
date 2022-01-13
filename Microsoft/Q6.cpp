class Solution {
public:
    void func(int i,string g,unordered_map<int,string> &mp,vector<string> &ans, string &digits){
        if(g.length()==digits.length()){
            ans.push_back(g);
            return ;
        }
        for(int j=0;j<mp[digits[i]-'0'].length();j++){
            func(i+1,g+mp[digits[i]-'0'][j],mp,ans,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits=="")return ans;
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        func(0,"",mp,ans,digits);
        return ans;
    }
};