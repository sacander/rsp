#include <iostream>

template <class T>
struct TreeNode {
    T data;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(T data): data(data) {}
    TreeNode(T data, TreeNode* parent): data(data), parent(parent) {}
    static TreeNode* search(TreeNode* node, T data) {
        std::cout << node->data << " ";
        if (node->data == data) {
            std::cout << std::endl;
            return node;
        }
        if (data < node->data) {
            if (node->left == nullptr) {
                std::cout << std::endl;
                return node;
            } else {
                return search(node->left, data);
            }
        } else {
            if (node->right == nullptr) {
                std::cout << std::endl;
                return node;
            } else {
                return search(node->right, data);
            }
        }
    }
    static void addNode(TreeNode* node, T data) {
        node = search(node, data);
        if (data < node->data) {
            node->left = new TreeNode(data, node);
        } else {
            node->right = new TreeNode(data, node);
        }
    }
};