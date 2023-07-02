#include <gtest/gtest.h>

#include "../include/binary_tree.h"

TEST (BST, Insert1ToEmptyTree) {
    testing::internal::CaptureStderr();
    BinarySearchTree* tree = new BinarySearchTree();
    tree->insert(1);
    std::string output_error = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output_error, "");
    delete tree;
}