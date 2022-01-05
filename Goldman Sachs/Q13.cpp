class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string g="";
                while(!st.empty() && st.top()!='[')
                {
                    g=st.top()+g;
                    st.pop();
                }
            
                st.pop();
            
                string m="";
                while(!st.empty() && isdigit(st.top()))
                {
                   m=st.top()+m;
                   st.pop();
                }
            
                int h=stoi(m);
            
                for(int i=0;i<h;i++)
                {
                   for(int j=0;j<g.length();j++)
                       st.push(g[j]);
                }
           }
        }
        
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};