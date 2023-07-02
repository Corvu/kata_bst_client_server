// Node of a binary search tree
class BinarySearchTreeNode {

private:
    int number;
    BinarySearchTreeNode* leftChild;
    BinarySearchTreeNode* rightChild;

public:
    // Constructors
    BinarySearchTreeNode(int number, BinarySearchTreeNode* left, BinarySearchTreeNode* right);
    BinarySearchTreeNode(int number);
    
    // Destructor
    ~BinarySearchTreeNode();

    // Set pointer for the left child
    void setLeftChild(BinarySearchTreeNode *child);

    // Set pointer for the right child
    void setRightChild(BinarySearchTreeNode *child);

    // Get the node's value
    int getValue();

    // Get the left child
    BinarySearchTreeNode* getLeftChild();

    // Get the right child
    BinarySearchTreeNode* getRightChild();
};




// Binary search tree
// 
// Tree cannot have two nodes with the same value
class BinarySearchTree {
private:
    BinarySearchTreeNode* root;

    // Delete node and all its children recursively
    void deleteNodesRecursive(BinarySearchTreeNode* node);

public:

    // Default constructor
    BinarySearchTree();

    // Destructor
    ~BinarySearchTree();
    
    // Insert a new value to the tree
    // Returns true if insertion succeeded and false is element already exists in BST
    bool insert(int number);

    // Delete a value from the tree
    // Returns true if removal succeeded and false is element doesn't exist in BST
    bool remove(int number);

    // Check whether given value is in the tree
    bool find(int number);
};