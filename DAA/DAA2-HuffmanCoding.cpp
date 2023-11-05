#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    int freq;
    std::string symbol;
    Node* left;
    Node* right;
    std::string huff;

    Node(int freq_, const std::string& symbol_, Node* left_ = nullptr, Node* right_ = nullptr)
        : freq(freq_), symbol(symbol_), left(left_), right(right_) {}
};

void printNodes(Node* node, const std::string& val = "") {
    std::string new_val = val + node->huff;
    if (node->left) {
        printNodes(node->left, new_val);
    }
    if (node->right) {
        printNodes(node->right, new_val);
    }
    if (!node->left && !node->right) {
        std::cout << node->symbol << " -> " << new_val << std::endl;
    }
}

int main() {
    std::vector<std::string> chars = {"a", "b", "c", "d", "e", "f"};
    std::vector<int> freq = {5, 9, 12, 13, 16, 45};
    std::vector<Node*> nodes;

    for (size_t x = 0; x < chars.size(); ++x) {
        nodes.push_back(new Node(freq[x], chars[x]));
    }

    while (nodes.size() > 1) {
        std::sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) { return a->freq < b->freq; });
        Node* left = nodes[0];
        Node* right = nodes[1];
        left->huff = "0";
        right->huff = "1";
        Node* newNode = new Node(left->freq + right->freq, left->symbol + right->symbol, left, right);
        nodes.erase(nodes.begin(), nodes.begin() + 2);
        nodes.push_back(newNode);
    }

    std::cout << "Characters : [";
    for (size_t i = 0; i < chars.size(); ++i) {
        std::cout << chars[i];
        if (i < chars.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::cout << "Frequency  : [";
    for (size_t i = 0; i < freq.size(); ++i) {
        std::cout << freq[i];
        if (i < freq.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n\nHuffman Encoding:" << std::endl;

    printNodes(nodes[0]);

    // Clean up dynamically allocated nodes
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}
// Output:
// Characters : [a, b, c, d, e, f]
// Frequency  : [5, 9, 12, 13, 16, 45]

// Huffman Encoding:
// f -> 0
// c -> 100
// d -> 101
// a -> 1100
// b -> 1101
// e -> 111