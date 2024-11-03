 int height(Node* node) {
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

bool isBalanced(Node* node) {
        if (!node) return true;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }
