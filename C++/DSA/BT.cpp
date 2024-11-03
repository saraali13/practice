#include <iostream>
using namespace std;

//no specific order
struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node in binary tree
bool insertAtLevel(Node* root, int value, int level) 
{
    if (!root) return false;

    if (level == 1) {
        if (!root->left) {
            root->left = new Node(value);
            return true;
        } else if (!root->right) {
            root->right = new Node(value);
            return true;
        }
        return false;
    }

    return insertAtLevel(root->left, value, level - 1) || insertAtLevel(root->right, value, level - 1);
}

void insert(Node* root, int value) {
    int level = 1;
    while (!insertAtLevel(root, value, level)) {
        level++;
    }
}

// Function to find the deepest node
Node* getDeepestNode(Node* root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) return root;

    Node* left = getDeepestNode(root->left);
    Node* right = getDeepestNode(root->right);

    return right ? right : left;
}

// Function to delete the deepest node
bool deleteDeepest(Node* root, Node* dNode) {
    if (!root) return false;

    if (root->left == dNode) {
        delete root->left;
        root->left = nullptr;
        return true;
    }
    if (root->right == dNode) {
        delete root->right;
        root->right = nullptr;
        return true;
    }

    return deleteDeepest(root->left, dNode) || deleteDeepest(root->right, dNode);
}

// Function to delete a node
void deleteNode(Node* root, int value) {
    if (!root) return;

    if (root->data == value && !root->left && !root->right) {
        delete root;
        root = nullptr;
        return;
    }

    Node* targetNode = nullptr;
    Node* dNode = getDeepestNode(root);

    // Find the node to delete
    function<void(Node*)> findTarget = [&](Node* node) {
        if (!node) return;
        if (node->data == value) targetNode = node;
        findTarget(node->left);
        findTarget(node->right);
    };
    findTarget(root);

    if (targetNode) {
        targetNode->data = dNode->data;
        deleteDeepest(root, dNode);
    }
}

// Function to search for a node
bool search(Node* root, int value) {
    if (!root) return false;
    if (root->data == value) return true;
    return search(root->left, value) || search(root->right, value);
}

// Traversal Functions
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Searching for 4: " << (search(root, 4) ? "Found" : "Not Found") << endl;

    cout << "Deleting 3" << endl;
    deleteNode(root, 3);

    cout << "Inorder Traversal after Deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
