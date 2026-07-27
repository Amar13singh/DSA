





//Assign cols....
//first node of every cols...

vector<int> topView(TreeNode* root)
{
    vector<int> ans;

    if(root==nullptr)
        return ans;

    map<int,int> mp;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        auto it=q.front();
        q.pop();

        TreeNode* node=it.first;
        int col=it.second;

        if(mp.find(col)==mp.end())
            mp[col]=node->val;

        if(node->left)
            q.push({node->left,col-1});

        if(node->right)
            q.push({node->right,col+1});
    }

    for(auto x:mp)
        ans.push_back(x.second);

    return ans;
}

