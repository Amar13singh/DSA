


// Longest root-to-leaf path

int height(TreeNode* root){
    if(root==nullptr) return 0;

    return 1+max(height(root->left),height(root->right));

}

//Number of nodes
int size(TreeNode* root)
{
    if(root==nullptr)
        return 0;

    return 1 + size(root->left) + size(root->right);
}


//count leaves..
int countLeaves(TreeNode* root)
{
    if(root==nullptr)
        return 0;

    if(root->left==nullptr &&
        root->right==nullptr)
        return 1;

    return countLeaves(root->left)
            + countLeaves(root->right);
}


//count internal nodes...
int countInternal(TreeNode* root)
{
    if(root==nullptr)
        return 0;

    if(root->left==nullptr &&
        root->right==nullptr)
        return 0;

    return 1+
            countInternal(root->left)+
            countInternal(root->right);
}


//maximum value..
int maximum(TreeNode* root)
{
    if(root==nullptr)
        return INT_MIN;

    return max(root->val,
                max(maximum(root->left),
                    maximum(root->right)));
}

//min value...
int minimum(TreeNode* root)
{
    if(root==nullptr)
        return INT_MAX;

    return min(root->val,
                min(minimum(root->left),
                    minimum(root->right)));
}


//mirror tree...
void mirror(TreeNode* root)
{
    if(root==nullptr)
        return;

    swap(root->left,root->right);

    mirror(root->left);

    mirror(root->right);
}


//copy tree
TreeNode* clone(TreeNode* root)
{
    if(root==nullptr)
        return nullptr;

    TreeNode* node=new TreeNode(root->val);

    node->left=clone(root->left);

    node->right=clone(root->right);

    return node;
}


//check identical tree...

bool same(TreeNode* a,
            TreeNode* b)
{
    if(a==nullptr && b==nullptr)
        return true;

    if(a==nullptr || b==nullptr)
        return false;

    return a->val==b->val &&
            same(a->left,b->left) &&
            same(a->right,b->right);
}