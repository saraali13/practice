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

    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
            return;
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
