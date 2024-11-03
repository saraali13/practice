#include <iostream>
using namespace std;

class BST {
    // Node structure for BST
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val = 0) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Private helper methods

    // Recursive insert
    Node* insertNode(Node* root, int val) {
        if (root == nullptr) return new Node(val);
        if (val < root->data)
            root->left = insertNode(root->left, val);
        else if (val > root->data)
            root->right = insertNode(root->right, val);
        return root;
    }

    // Recursive search
    bool searchRecursion(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        return (key < node->data) ? searchRecursion(node->left, key) : searchRecursion(node->right, key);
    }

    // Preorder traversal
    void preorder(Node* root) 
{
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
}

    // Inorder traversal
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Postorder traversal
    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // BFS helpers
    int height(Node* root) {
        if (!root) return -1;
        return max(height(root->left), height(root->right)) + 1;
    }

    void printGivenLevel(Node* root, int level) {
        if (!root) return;
        if (level == 0) cout << root->data << " ";
        else {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

    void printLevelOrderBFS(Node* root) {
        int h = height(root);
        for (int i = 0; i <= h; i++) {
            printGivenLevel(root, i);
        }
    }

    // Deletion helper
    Node* minValueNode(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int value) {
        if (!root) return root;
        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Public insert method (iterative)
    void insertNode(int newData) {
        Node* newNode = new Node(newData);
        if (!root) {
            root = newNode;
            return;
        }
        Node* temp = root;
        while (true) {
            if (newData < temp->data) {
                if (!temp->left) {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            } else if (newData > temp->data) {
                if (!temp->right) {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            } else return;
        }
    }

    // Recursive insert method
    void insertNodeRecursively(int val) {
        root = insertNode(root, val);
    }

    // Public search methods
    bool searchNode(int key) {
        Node* temp = root;
        while (temp) {
            if (key == temp->data) return true;
            temp = (key < temp->data) ? temp->left : temp->right;
        }
        return false;
    }

    void searchRecursion(int key) {
        cout << (searchRecursion(root, key) ? "Element found!" : "Element not found!") << endl;
    }

    // Public traversal methods
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    void printLevelOrderBFS() { printLevelOrderBFS(root); cout << endl; }

    // Public delete method
    void deleteNode(int key) {
        root = deleteNode(root, key);
        cout << "Node " << key << (root ? " deleted!" : " not found in tree!") << endl;
    }
};

// Main function to test the BST class
int main() {
    BST bst;

    // Insert nodes
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(15);
    bst.insertNodeRecursively(8);
    bst.insertNodeRecursively(12);

    // Traversal
    cout << "Inorder: "; bst.inorder();
    cout << "Preorder: "; bst.preorder();
    cout << "Postorder: "; bst.postorder();
    cout << "Level Order BFS: "; bst.printLevelOrderBFS();

    // Search nodes
    bst.searchRecursion(8);
    bst.searchRecursion(20);

    // Delete node
    bst.deleteNode(5);
    cout << "Inorder after deletion: "; bst.inorder();

    return 0;
}
