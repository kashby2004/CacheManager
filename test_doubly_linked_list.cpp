/**
 * author - Kaitlyn Ashby
 * @file test_doubly_linked_list.cpp - Extra credit test file for Google Test.
 * @date 2025-03-12
 */

#include <gtest/gtest.h>
#include "doubly_linked_list.h"

 TEST_A(DoublyLinkedListTest, IsEmptyInitially) {
    DoublyLinkedList list;
    EXPECT_TRUE(list.isEmpty());
}

 TEST_B(DoublyLinkedListTest, InsertAtHead) {
    DoublyLinkedList list;
    DllNode* node = new DllNode(1);
    list.insertAtHead(1, node);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 1);
}

TEST_C(DoublyLinkedListTest, InsertAtTail) {
    DoublyLinkedList list;
    DllNode* node = new DllNode(1);
    list.insertAtTail(1, node);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 1);
}

TEST_D(DoublyLinkedListTest, RemoveElement) {
    DoublyLinkedList list;
    DllNode* node = new DllNode(1);
    list.insertAtHead(1, node);
    list.remove(1);
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
