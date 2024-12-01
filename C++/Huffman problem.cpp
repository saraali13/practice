#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for the Huffman Tree
struct HuffmanNode {
    char data;                  // Character
    int frequency;              // Frequency of the character
    HuffmanNode* left;          // Pointer to the left child
    HuffmanNode* right;         // Pointer to the right child

    HuffmanNode(char d, int f) : data(d), frequency(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency; // Min-heap based on frequency
    }
};

// Recursive function to generate the Huffman codes
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root)
        return;

    // If this is a leaf node, add the character and its code to the map
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman Tree and generate the codes
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& entry : frequencies) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    // Build the Huffman Tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        // Create a new internal node with children as the two nodes
        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top(); // The root of the Huffman Tree
}

// Function to encode a string using Huffman codes
string encode(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedText;
    for (char c : text) {
        encodedText += huffmanCodes.at(c);
    }
    return encodedText;
}

// Function to decode a string using the Huffman Tree
string decode(const string& encodedText, HuffmanNode* root) {
    string decodedText;
    HuffmanNode* currentNode = root;

    for (char bit : encodedText) {
        if (bit == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        // If a leaf node is reached, append the character to the result
        if (!currentNode->left && !currentNode->right) {
            decodedText += currentNode->data;
            currentNode = root; // Reset to root for the next character
        }
    }

    return decodedText;
}

int main() {
    // Input string
    string text = "huffman coding example";

    // Count the frequency of each character
    unordered_map<char, int> frequencies;
    for (char c : text) {
        frequencies[c]++;
    }

    // Build the Huffman Tree
    HuffmanNode* root = buildHuffmanTree(frequencies);

    // Generate the Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Display the codes
    cout << "Huffman Codes:\n";
    for (const auto& entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Encode the input text
    string encodedText = encode(text, huffmanCodes);
    cout << "\nEncoded Text: " << encodedText << endl;

    // Decode the encoded text
    string decodedText = decode(encodedText, root);
    cout << "\nDecoded Text: " << decodedText << endl;

    return 0;
}
