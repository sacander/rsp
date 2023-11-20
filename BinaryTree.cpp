#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main() {
    TreeNode<int>* root = new TreeNode(5);
    TreeNode<int>::addNode(root, 3);
    TreeNode<int>::addNode(root, 9);
    TreeNode<int>::addNode(root, 11);
    TreeNode<int>::addNode(root, 6);
    TreeNode<int>::addNode(root, 1);
    TreeNode<int>::addNode(root, 8);
    TreeNode<int>::addNode(root, 2);

    cout << endl;
    TreeNode<int>::traverse(root);
    cout << endl;

    root = TreeNode<int>::deleteNode(root, 5);

    cout << endl;
    TreeNode<int>::traverse(root);
    cout << endl;

    return 0;
}