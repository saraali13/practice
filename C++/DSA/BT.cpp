#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // Helper function to find and delete the deepest node
bool insertHelper(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        // Check if the left child is empty, if so insert there
        if (node->left == nullptr) {
            node->left = new TreeNode(value);
            return true;
        }
        // Otherwise, move to the left subtree to continue searching
        if (insertHelper(node->left, value)) {
            return true;
        }

        // Check if the right child is empty, if so insert there
        if (node->right == nullptr) {
            node->right = new TreeNode(value);
            return true;
        }
        // Otherwise, move to the right subtree to continue searching
        return insertHelper(node->right, value);
    }



    void deleteDeepest(Node* delNode) {
        if (root == nullptr) return;

        Node* temp = root;
        Node* parent = nullptr;

        // Traverse to find the deepest rightmost node
        while (temp != nullptr) {
            if (temp->left) {
                parent = temp;
                temp = temp->left;
            } else if (temp->right) {
                parent = temp;
                temp = temp->right;
            } else {
                break;
            }
        }
        
        // Delete the deepest node
        if (parent->right == temp) {
            parent->right = nullptr;
        } else {
            parent->left = nullptr;
        }
    }

    // Find the node to delete and replace its value
    Node* deleteNodeBT(Node* root, int key) {
        if (root == nullptr) return nullptr;

        Node* target = nullptr;
        Node* temp = root;

        // Locate the node with the key
        while (temp != nullptr) {
            if (temp->data == key) {
                target = temp;
                break;
            }

            if (temp->left) temp = temp->left;
            else if (temp->right) temp = temp->right;
            else break;
        }

        // If the node with the key is found, replace and delete
        if (target) {
            int deepestValue = temp->data;
            deleteDeepest(temp);
            target->data = deepestValue;
        }

        return root;
    }

public:
    BinaryTree() : root(nullptr) {}
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value); // If tree is empty, create the root
        } else {
            insertHelper(root, value); // Use helper to find the correct position
        }
    }


        Node* temp = root;
        while (true) {
            if (data < temp->data) {
                if (!temp->left) {
                    temp->left = new Node(data);
                    break;
                }
                temp = temp->left;
            } else {
                if (!temp->right) {
                    temp->right = new Node(data);
                    break;
                }
                temp = temp->right;
            }
        }
    }

    void deleteNode(int key) {
        root = deleteNodeBT(root, key);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.insert(50);

    cout << "Original Tree (Inorder): ";
    bt.displayInorder();

    bt.deleteNode(20);

    cout << "After deleting 20 (Inorder): ";
    bt.displayInorder();

    return 0;
}
