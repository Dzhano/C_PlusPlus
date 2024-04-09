/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
int maxval(Node* root) {
    return root->right ? maxval(root->right) : root->data;;
}
int minval(Node* root) {
    return root->left ? minval(root->left) : root->data;
}

bool checkBST(Node* root) {
    if (root == nullptr) return true;
    if (root->left && (!checkBST(root->left) || maxval(root->left) >= root->data)) {
        return false;
    }
    if (root->right && (!checkBST(root->right) || minval(root->right) <= root->data)) {
        return false;
    }
    return true;
}