#include <iostream>
using namespace std;

// AVL Tree Node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    TreeNode* root;

    // Helper function to get the height of a node
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Helper function to calculate the balance factor of a node
    int getBalance(TreeNode* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right Rotation (for Left-Left case)
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left Rotation (for Right-Right case)
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Left-Right Rotation (for Left-Right case)
    TreeNode* leftRightRotate(TreeNode* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Rotation (for Right-Left case)
    TreeNode* rightLeftRotate(TreeNode* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Recursive function to insert a node
    TreeNode* insert(TreeNode* node, int value) {
        // 1. Perform the normal BST insert
        if (node == nullptr) return new TreeNode(value);

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node; // Duplicate values are not allowed
        }

        // 2. Update the height of the current node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Check the balance factor to see if the node is unbalanced
        int balance = getBalance(node);

        // If the node is unbalanced, then there are 4 cases

        // Left-Left Case
        if (balance > 1 && value < node->left->value) {
            return rightRotate(node);
        }

        // Right-Right Case
        if (balance < -1 && value > node->right->value) {
            return leftRotate(node);
        }

        // Left-Right Case
        if (balance > 1 && value > node->left->value) {
            return leftRightRotate(node);
        }

        // Right-Left Case
        if (balance < -1 && value < node->right->value) {
            return rightLeftRotate(node);
        }

        return node;
    }

    // Helper function to find the node with the minimum value (for deletion)
    TreeNode* minNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    // Recursive function to delete a node
    TreeNode* deleteNode(TreeNode* root, int value) {
        // Step 1: Perform standard BST delete
        if (root == nullptr) return root;

        if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr || root->right == nullptr) {
                TreeNode* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                TreeNode* temp = minNode(root->right);

                // Copy the inorder successor's content to this node
                root->value = temp->value;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->value);
            }
        }

        // If the tree has only one node, return it
        if (root == nullptr) return root;

        // Step 2: Update the height of the current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Step 3: Check for imbalance
        int balance = getBalance(root);

        // Left-Left Case
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        // Left-Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            return leftRightRotate(root);
        }

        // Right-Right Case
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }

        // Right-Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            return rightLeftRotate(root);
        }

        return root;
    }

    // Helper function to print the tree (in-order traversal)
    void inOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            cout << root->value << " ";
            inOrderTraversal(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // Public functions to interact with the tree
    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void printTree() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    cout << "In-order traversal after insertion: ";
    tree.printTree();

    tree.deleteNode(10);
    cout << "In-order traversal after deletion of 10: ";
    tree.printTree();

    return 0;
}
