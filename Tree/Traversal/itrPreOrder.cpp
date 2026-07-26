#
using namespace std;

void preorderIter(TreeNode* root)
{
    if(root==nullptr)
        return;

    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty())
    {
        TreeNode* cur=st.top();

        st.pop();

        cout<<cur->val<<" ";

        if(cur->right)
            st.push(cur->right);

        if(cur->left)
            st.push(cur->left);
    }
}