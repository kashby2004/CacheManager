/**
 * @author - Kaitlyn Ashby
 * @file test_cache_manager.cpp - Extra credit test file for Google Test.
 * @date 2025-03-12
 */

#include "cache_manager.h"
#include <gtest/gtest.h>

TEST(CacheManagerTest, IsEmptyInitially) {
    CacheManager cacheManager(10, 11);
    EXPECT_TRUE(cacheManager.isEmpty());
}

TEST(CacheManagerTest, AddElement) {
    CacheManager cacheManager(10, 11);
    DllNode* node = new DllNode(1, "John Doe", "1234 Main St", "City", "State", "12345");
    cacheManager.add(1, node);
    EXPECT_FALSE(cacheManager.isEmpty());
    EXPECT_EQ(cacheManager.getSize(), 1);
}

TEST(CacheManagerTest, RemoveElement) {
    CacheManager cacheManager(10, 11);
    DllNode* node = new DllNode(1, "John Doe", "1234 Main St", "City", "State", "12345");
    cacheManager.add(1, node);
    cacheManager.remove(1);
    EXPECT_TRUE(cacheManager.isEmpty());
    EXPECT_EQ(cacheManager.getSize(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
