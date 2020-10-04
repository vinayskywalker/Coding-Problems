/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> vv;
        if(root==NULL){
            return vv;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int len=q.size();
            while(len--){
                Node* tmp=q.front();
                v.push_back(tmp->val);
                q.pop();
                for(int i=0;i<tmp->children.size();i++){
                    q.push(tmp->children[i]);
                }
            }
            vv.push_back(v);
        }
        return vv;
               
            
    }
};