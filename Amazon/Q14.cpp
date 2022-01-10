//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void func(Node* root,map<Node*,Node*> &mp,int &ans){
        queue<Node*>q;
        q.push(root);
        set<Node*>s;
        while(!q.empty()){
            int n=q.size(),f=0;
            while(n--){
            Node* p=q.front();
            q.pop();
            if(p->left && s.count(p->left)==0){
                f=1;
                s.insert(p->left);
                q.push(p->left);
            }
            if(p->right && s.count(p->right)==0){
                f=1;
                s.insert(p->right);
                q.push(p->right);
            }
            if(mp[p]&& s.count(mp[p])==0){
                f=1;
                s.insert(mp[p]);
                q.push(mp[p]);
            }
            }
            if(f)ans++;
        }
    }
    Node* search_find_parent(map<Node*,Node*> &mp,Node* root,int t){
        Node* res;
        queue<Node*>q;
        q.push(root);
        mp[root]=NULL;
        while(!q.empty()){
            Node* p=q.front();
            q.pop();
            if(p->data==t)res=p;
            if(p->left){
                mp[p->left]=p;
                q.push(p->left);
            }
            if(p->right){
                mp[p->right]=p;
                q.push(p->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> mp;
        Node* t= search_find_parent(mp,root,target);
        int ans=0;
        func(t,mp,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends