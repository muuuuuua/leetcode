/**
 * 297. Serialize and Deserialize Binary Tree
 */
#include "inc/common.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "[]";
        queue<TreeNode*> q;
        q.push(root);
        vector<string> res;
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if(cur == NULL) {
                res.push_back("null");
            }
            else {
                string temp;
                stringstream ss;
                ss<<cur->val;
                ss>>temp;
                res.push_back(temp);
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        int k = res.size()-1;
        for(;k >= 0;k--) {
            if(res[k] != "null")
                break;
        }
        string r = "[";
        for(int i = 0;i <= k;i++) {
            r += res[i];
            if(i != k)
                r += ",";
        }
        return r+"]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size()-2);
        if(data == "")
            return NULL;
        int pos = -1;
        vector<string> token;
        while((pos=data.find_first_of(",")) != -1) {
            token.push_back(data.substr(0, pos));
            data = data.substr(pos+1, data.size()-pos);
        }
        token.push_back(data);

        queue<TreeNode*> q;
        int i = 1;
        TreeNode *root = new TreeNode(atoi(token[0].c_str()));
        q.push(root);
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if(i < token.size()) {
                TreeNode *left;
                if(token[i] == "null")
                    left = NULL;
                else {
                    left = new TreeNode(atoi(token[i].c_str()));
                    q.push(left);
                }
                cur->left = left;
                i++;
            }
            if(i < token.size()) {
                TreeNode *right;
                if(token[i] == "null")
                    right = NULL;
                else {
                    right = new TreeNode(atoi(token[i].c_str()));
                    q.push(right);
                }
                cur->right = right;
                i++;
            }
        }
        return root;
    }
};

int main() {
    Codec c;
    TreeNode *root = c.deserialize("[1,2,3,null,null,4,5]");
    cout<<c.serialize(root)<<endl;
    return 0;
}