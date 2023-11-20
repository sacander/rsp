#include <iostream>

template <class T>
struct TreeNode {
    T data;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(T data): data(data) {}
    TreeNode(T data, TreeNode* parent): data(data), parent(parent) {}
    static void traverse(TreeNode* node) {
        if (node->left != nullptr) {
            traverse(node->left);
        }
        std::cout << node->data << " ";
        if (node->right != nullptr) {
            traverse(node->right);
        }
    }
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
    static TreeNode* deleteNode(TreeNode* node, T data) {
        TreeNode* root = node;
        node = search(node, data);
        TreeNode* parent = node->parent;
        if (parent == nullptr) { // if root
            if (node->left == nullptr && node->right == nullptr) { // if leaf node
                delete root;
                return nullptr;
            } else if (node->left == nullptr) { // if only right child
                TreeNode* temp = node->right;
                delete root;
                return temp;
            } else if (node->right == nullptr) { // if only left child
                TreeNode* temp = node->left;
                delete root;
                return temp;
            } else { // if two children
                TreeNode* replacement = node->right;
                if (replacement->left == nullptr) { // special case if right node has no left children
                    replacement->left = node->left;
                    replacement->parent = nullptr;
                } else {
                    while (replacement->left != nullptr) {
                        replacement = replacement->left;
                    }
                    replacement->right->parent = replacement->parent;
                    replacement->parent->left = replacement->right;
                    replacement->left = node->left;
                    replacement->right = node->right;
                    replacement->parent = nullptr;
                }
                delete root;
                return replacement;
            }
        }

        bool left = false;
        if (parent->left != nullptr && parent->left->data == data) {left = true;}
        if (node->left == nullptr && node->right == nullptr) { // if leaf node
            if (left) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else if (node->left == nullptr) { // if only right child
            node->right->parent = parent;
            if (left) {
                parent->left = node->right;
            } else {
                parent->right = node->right;
            }
        } else if (node->right == nullptr) { // if only left child
            node->left->parent = parent;
            if (left) {
                parent->left = node->left;
            } else {
                parent->right = node->left;
            }
        } else { // if two children
            TreeNode* replacement = node->right;
            if (replacement->left == nullptr) { // special case if right node has no left children
                replacement->left = node->left;
                replacement->parent = parent;
            } else {
                while (replacement->left != nullptr) {
                    replacement = replacement->left;
                }
                replacement->right->parent = replacement->parent;
                replacement->parent->left = replacement->right;
                replacement->left = node->left;
                replacement->right = node->right;
                replacement->parent = parent;
            }
            if (left) {
                parent->left = replacement;
            } else {
                parent->right = replacement;
            }
        }
        delete node;
        return root;
    }
};

// binary tree deletions check root still
// dijkstra's priority queue