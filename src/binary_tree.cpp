#include <iostream>

#include "binary_tree.h"




BinarySearchTreeNode::BinarySearchTreeNode(int number, BinarySearchTreeNode* left, BinarySearchTreeNode* right) {
    this->number = number;
    leftChild = left;
    rightChild = right;
}
BinarySearchTreeNode::BinarySearchTreeNode(int number) {
    this->number = number;
}

BinarySearchTreeNode::~BinarySearchTreeNode() {
    number = 0;
    leftChild = NULL;
    rightChild = NULL;
    //if (leftChild != NULL) delete leftChild;
    //if (rightChild != NULL) delete rightChild;
}

void BinarySearchTreeNode::setLeftChild(BinarySearchTreeNode *child) {
    leftChild = child;
}

void BinarySearchTreeNode::setRightChild(BinarySearchTreeNode *child) {
    rightChild = child;
}

int BinarySearchTreeNode::getValue() {
    return this->number;
}

BinarySearchTreeNode* BinarySearchTreeNode::getLeftChild() {
    return leftChild;
}

BinarySearchTreeNode* BinarySearchTreeNode::getRightChild() {
    return rightChild;
}




// A binary search tree
// 
// Tree cannot have two nodes with the same value
    
void BinarySearchTree::deleteNodesRecursive(BinarySearchTreeNode* node) {
    if (node != NULL) {
        deleteNodesRecursive(node->getLeftChild());
        deleteNodesRecursive(node->getRightChild());
        delete node;
        node = NULL;
    }
}

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    deleteNodesRecursive(root);
}

bool BinarySearchTree::insert(int number) {
    if (root == NULL) {
        root = new BinarySearchTreeNode(number);
        return true;
    }

    // Add a new value to the tree
    BinarySearchTreeNode* currentNode = root;
    while (true) {
        if (number < currentNode->getValue()) {
            if (currentNode->getLeftChild() == NULL) {
                BinarySearchTreeNode* newNode = new BinarySearchTreeNode(number);
                currentNode->setLeftChild(newNode);
                return true;
            } else {
                currentNode = currentNode->getLeftChild();
            }
        } else if (number > currentNode->getValue()) {
            if (currentNode->getRightChild() == NULL) {
                BinarySearchTreeNode* newNode = new BinarySearchTreeNode(number);
                currentNode->setRightChild(newNode);
                return true;
            } else {
                currentNode = currentNode->getRightChild();
            }
        } else {
            std::cerr << "ERROR: can't insert " << number << " -- element already exists in BST" << std::endl;
            return false;
        }
    }
    
}

bool BinarySearchTree::remove(int number) {

    // Tree is empty
    if (root == NULL) {
        std::cerr << "ERROR: can't remove " << number << " -- element doesn't exist in BST" << std::endl;
        return false;
    }

    // Tree is not empty; traverse
    BinarySearchTreeNode* previousNode = NULL;
    bool currentNodeIsLeftToPrevious = true;
    BinarySearchTreeNode* currentNode = root;
    BinarySearchTreeNode* left = currentNode->getLeftChild();
    BinarySearchTreeNode* right = currentNode->getRightChild();
    while (true) {
        // Node not found; no more to search
        if (currentNode == NULL) {
            std::cerr << "ERROR: can't remove " << number << " -- element doesn't exist in BST" << std::endl;
            return false;
        }

        // Node found
        if (currentNode->getValue() == number) {
            BinarySearchTreeNode* nodeToDelete = currentNode;
            BinarySearchTreeNode* parentOfNodeToDelete = previousNode;
            if (left == NULL && right == NULL) {
                delete currentNode;
                currentNode = NULL;
            } else if (left == NULL && right != NULL) {
                delete currentNode;
                currentNode = right;
            } else if (left != NULL && right == NULL) {
                delete currentNode;
                currentNode = left;
            } else {
                // Find a successor
                if (right->getLeftChild() == NULL) {
                    delete currentNode;
                    currentNode = right;
                    right->setLeftChild(left);
                    return true;
                }
                // Traverse
                previousNode = currentNode;
                currentNode = right;
                while (true) {
                    if (currentNode->getLeftChild() == NULL) {
                        previousNode->setLeftChild(currentNode->getRightChild());
                        delete nodeToDelete;
                        nodeToDelete = currentNode;
                        nodeToDelete->setRightChild(right);
                        return true;
                    } else {
                        previousNode = currentNode;
                        currentNode = currentNode->getLeftChild();
                    }
                }
            }
            return true;
            
        }
        // Node not found; continue search
        else if (number > currentNode->getValue()) {
            previousNode = currentNode;
            currentNode = currentNode->getRightChild();
            currentNodeIsLeftToPrevious = false;
        } else if (number < currentNode->getValue()) {
            previousNode = currentNode;
            currentNode = currentNode->getLeftChild();
            currentNodeIsLeftToPrevious = true;
        }
    }
    
}

bool BinarySearchTree::find(int number) {
    BinarySearchTreeNode* currentNode = root;
    while (true) {
        if (currentNode->getValue() == number) {
            return true;
        }
        else if (number < currentNode->getValue()) {
            if (currentNode->getLeftChild() == NULL) {
                return false;
            } else {
                currentNode = currentNode->getLeftChild();
            }
        } else if (number > currentNode->getValue()) {
            if (currentNode->getRightChild() == NULL) {
                return false;
            } else {
                currentNode = currentNode->getRightChild();
            }
        }
    }
}

// This function can be used for initial testing
/*int main() {
    BinarySearchTree* tree = new BinarySearchTree();
    tree->insert(1);
    if (tree->find(1) == true) {
        std::cout << "found" << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
    tree->insert(1);
    tree->remove(1);
    if (tree->find(1) == true) {
        std::cout << "found" << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
    delete tree;
    tree = NULL;
}*/