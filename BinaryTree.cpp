#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main() {
    TreeNode<int>* root = new TreeNode(5);
    TreeNode<int>::addNode(root, 3);
    TreeNode<int>::addNode(root, 9);
    TreeNode<int>::addNode(root, 6);
    TreeNode<int>::addNode(root, 1);
    TreeNode<int>::addNode(root, 8);
    TreeNode<int>::addNode(root, 2);

    cout << endl;
    TreeNode<int>* current = TreeNode<int>::search(root, 8);
    cout << current->data << endl;

    return 0;
}