 bool isFull(Node* node) {
        if (!node) return true; // An empty tree is full
        if (!node->left && !node->right) return true; // Leaf node
        if (node->left && node->right) return isFull(node->left) && isFull(node->right);
        return false; // One child is missing
    }
