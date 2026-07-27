




// BFS
// Instead of first node
// Take last node.


vector<int> rightView(TreeNode* root)
{
    vector<int> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int n=q.size();

        for(int i=0;i<n;i++)
        {
            TreeNode* cur=q.front();
            q.pop();

            if(i==n-1)
                ans.push_back(cur->val);

            if(cur->left)
                q.push(cur->left);

            if(cur->right)
                q.push(cur->right);
        }
    }

    return ans;
}



//dfs method...
//  just reverse recursion...


void dfs(TreeNode* root,int level,vector<int>&ans)
{
    if(root==nullptr)
        return;

    if(level==ans.size())
        ans.push_back(root->val);

    dfs(root->right,level+1,ans);

    dfs(root->left,level+1,ans);
}

