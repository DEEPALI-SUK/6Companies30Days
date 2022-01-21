#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s,s1;
	cin>>s>>s1;
	int n=s.length();
	int m=s1.length();
	int i=0,j=0,n1=0,n2=0;
	while(i<n && j<m){
	    while(i<n && s[i]!='.'){
	        n1=(n1*10)+(s[i]-'0');
	        i++;
	    }
	     while(j<m && s1[j]!='.'){
	        n2=(n2*10)+(s1[j]-'0');
	        j++;
	    }
	    if(n1>n2){
	        cout<<"Version 1"<<endl;
	        return 0;
	    }else if(n2>n1){
	        cout<<"Version 2"<<endl;
	        return 0;
	    }
	    i++;
	    j++;
	    n1=0;
	    n2=0;
	}
	if(i<n){
	    cout<<"Version 1"<<endl;
	}else if(j<m){
	    cout<<"Version 2"<<endl;
	}else cout<<"Equal"<<endl;
	return 0;
}