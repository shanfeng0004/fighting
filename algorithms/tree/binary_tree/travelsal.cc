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

    printf("%d,", root);
    pre_order(root->lchild);
    pre_order(root->rchild);
}

// 2. mid order
void mid_order(TNode* root)
{
    if (root == NULL) {
        return;
    }

    pre_order(root->lchild);
    printf("%d,", root);
    pre_order(root->rchild);
}

// 3. post order
void post_order(TNode* root)
{
    if (root == NULL) {
        return;
    }

    pre_order(root->lchild);
    pre_order(root->rchild);
    printf("%d,", root);
}

/********************************* non-recursive ***************************************/
// 1. pre order
//void pre_order_nonrecursive(TNode* root)
//{
//    if (root == NULL) {
//        return;
//    }
//    stack<TNode*> sk;
//    sk.push_back(root);
//
//    while (!sk.empty()) {
//        TNode* cur = sk.pop_back();
//        printf("%d,", cur->);
//        if (root)
//    }
//
//}

void build_tree(TNode* root, int a[], int begin, int end)
{
    if (begin > end) {
        return; 
    }

    TNode* root = new TNode();
    root->val = a[begin++];
    root->lchild = NULL;
    root->rchild = NULL;
    if (begin == end) {
        return;
    } 
    int mid = (begin + end)/2

    build_tree(root->lchild, begin, mid);
    build_tree(root->rchild, mid+1, end);
}

int main()
{
    int size = 10;
    int a[10] = {3,2,5,7,6,10,43,33,25,16};

    TNode* root = NULL; 
    build_tree(root, a, 0, 9);
}

