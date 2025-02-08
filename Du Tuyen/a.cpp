#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, priority, sz;
    Node *left, *right;
    Node(int _val) : val(_val), priority(rand()), sz(1), left(nullptr), right(nullptr) {}
};

int getSize(Node* root) {
    return root ? root->sz : 0;
}

void updateSize(Node* root) {
    if(root)
        root->sz = getSize(root->left) + getSize(root->right) + 1;
}

// Split treap 'root' thành 2 cây: 'left' chứa pos phần tử đầu tiên, 'right' chứa phần còn lại.
void split(Node* root, int pos, Node*& left, Node*& right) {
    if(!root) {
        left = right = nullptr;
        return;
    }
    int currPos = getSize(root->left);
    if(pos <= currPos) {
        split(root->left, pos, left, root->left);
        right = root;
    } else {
        split(root->right, pos - currPos - 1, root->right, right);
        left = root;
    }
    updateSize(root);
}

// Nối 2 treap 'left' và 'right'
Node* merge(Node* left, Node* right) {
    if(!left || !right)
        return left ? left : right;
    if(left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

// Chèn giá trị 'val' vào vị trí 'pos' (0-indexed)
Node* insert(Node* root, int pos, int val) {
    Node* newNode = new Node(val);
    Node *L, *R;
    split(root, pos, L, R);
    return merge(merge(L, newNode), R);
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Node* treap = nullptr;
    
    // Ví dụ: chèn dần các giá trị 1,2,3,4,5 theo thứ tự từ vị trí 0 đến 4
    for (int i = 0; i < 5; i++) {
        treap = insert(treap, i, i+1);
    }
    
    inorder(treap); // Kết quả: 1 2 3 4 5
    cout << "\n";
    return 0;
}

// implicit treap