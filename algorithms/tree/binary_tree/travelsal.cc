#include <iostream>
#include <stack>

typedef struct TNode {
    int val;
    TNode* lchild;
    TNode* rchild;
} TNode;

/********************************* recursive *******************************************/
// 1. pre order
void pre_order(TNode* root)
{
    if (root == NULL) {
        return;
    }

    std::cout<<root->val<<",";
    pre_order(root->lchild);
    pre_order(root->rchild);
}

// 2. mid order
void mid_order(TNode* root)
{
    if (root == NULL) {
        return;
    }

    mid_order(root->lchild);
    std::cout<<root->val<<",";
    mid_order(root->rchild);
}

// 3. post order
void post_order(TNode* root)
{
    if (root == NULL) {
        return;
    }

    post_order(root->lchild);
    post_order(root->rchild);

    std::cout<<root->val<<",";
}

/********************************* non-recursive ***************************************/
// 1. pre order
void pre_order_nonrecursive(TNode* root)
{
    std::stack<TNode*> st;    
    TNode* cur = root; 
    while (cur != NULL || !st.empty()) {
        while (cur != NULL) {
            std::cout << cur->val << ",";
            st.push(cur);
            cur = cur->lchild;
        }

        if (!st.empty()) {
            cur = st.top();
            st.pop();
            cur = cur->rchild;
        }
    }
}

// 2. mid order
void mid_order_nonrecursive(TNode* root)
{
    std::stack<TNode*> st;    
    TNode* cur = root; 
    while (cur != NULL || !st.empty()) {
        while (cur != NULL) {
            st.push(cur);
            cur = cur->lchild;
        }

        if (!st.empty()) {
            cur = st.top();
            std::cout << cur->val << ",";
            st.pop();
            cur = cur->rchild;
        }
    }
}

// 3. post order
void post_order_nonrecursive(TNode* root)
{
    std::stack<TNode*> st;
    TNode *cur;                      //当前结点 
    TNode *pre = NULL;                 //前一次访问的结点 
    st.push(root);
    while(!st.empty())
    {
        cur = st.top();
        if ((cur->lchild == NULL && cur->rchild == NULL) 
         || (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            std::cout << cur->val << ",";
            st.pop();
            pre = cur; 
        } else {
            if (cur->rchild != NULL) {
                st.push(cur->rchild);
            }
            if (cur->lchild != NULL) {
                st.push(cur->lchild);
            }
        }
    }    
}

void build_tree(TNode** root, int a[], int begin, int end)
{
    if (begin > end) {
        return; 
    }

    *root = new TNode();
    (*root)->val = a[begin++];
    (*root)->lchild = NULL;
    (*root)->rchild = NULL;

    int mid = (begin + end)/2;

    build_tree(&((*root)->lchild), a, begin, mid);
    build_tree(&((*root)->rchild), a, mid+1, end);
}

int main()
{
    int size = 10;
    int a[10] = {3,2,5,7,6,10,43,33,25,16};

    TNode* root = NULL; 
    build_tree(&root, a, 0, 9);
    if (root == NULL) {
        std::cout << "root is NULL" << std::endl;
    }

    std::cout << "pre order recursive:" << std::endl;
    pre_order(root);
    std::cout << std::endl << std::endl;

    std::cout << "pre order non-recursive:" << std::endl;
    pre_order_nonrecursive(root);
    std::cout << std::endl << std::endl;

    std::cout << "mid order:" << std::endl;
    mid_order(root);
    std::cout << std::endl << std::endl;

    std::cout << "mid order non-recursive:" << std::endl;
    mid_order_nonrecursive(root);
    std::cout << std::endl << std::endl;

    std::cout << "post order:" << std::endl;
    post_order(root);
    std::cout << std::endl << std::endl;

    std::cout << "post order non-recursive:" << std::endl;
    post_order_nonrecursive(root);
    std::cout << std::endl << std::endl;

    return 0;
}

/********************************* tree graph ***********************************/
/*
*                                3
*                               / \
*                             2    43
*                            / \   /  \
*                           5  6  33  16
*                          /   /  /  
*                         7   10  25
*/
