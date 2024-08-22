#include <unity.h>
#include "Heap.h"

void test_parent()
{
  TEST_ASSERT_EQUAL(0, PARENT(1));
  TEST_ASSERT_EQUAL(0, PARENT(2));
  TEST_ASSERT_EQUAL(1, PARENT(3));
  TEST_ASSERT_EQUAL(1, PARENT(4));
  TEST_ASSERT_EQUAL(2, PARENT(5));
  TEST_ASSERT_EQUAL(2, PARENT(6));
}

void test_left_child()
{
  TEST_ASSERT_EQUAL(1, LEFT_CHILD(0));  
  TEST_ASSERT_EQUAL(3, LEFT_CHILD(1));  
  TEST_ASSERT_EQUAL(5, LEFT_CHILD(2));  
  TEST_ASSERT_EQUAL(7, LEFT_CHILD(3));  
  TEST_ASSERT_EQUAL(9, LEFT_CHILD(4));  
}

void test_right_child()
{
  TEST_ASSERT_EQUAL(2, RIGHT_CHILD(0));  
  TEST_ASSERT_EQUAL(4, RIGHT_CHILD(1));  
  TEST_ASSERT_EQUAL(6, RIGHT_CHILD(2));  
  TEST_ASSERT_EQUAL(8, RIGHT_CHILD(3));  
  TEST_ASSERT_EQUAL(10, RIGHT_CHILD(4));  

}

void test_is_leaf()
{
  // Test all possibilities in heap of size 1
  TEST_ASSERT_TRUE(IS_LEAF(0, 1));

  // Test all possibilities in heap of size 2
  TEST_ASSERT_FALSE(IS_LEAF(0, 2));
  TEST_ASSERT_TRUE(IS_LEAF(1, 2));
  
  // Test all possibilities in heap of size 3
  TEST_ASSERT_FALSE(IS_LEAF(0, 3));
  TEST_ASSERT_TRUE(IS_LEAF(1, 3));
  TEST_ASSERT_TRUE(IS_LEAF(2, 3));

  // Test all possibilities in heap of size 4
  TEST_ASSERT_FALSE(IS_LEAF(0, 4));
  TEST_ASSERT_FALSE(IS_LEAF(1, 4));
  TEST_ASSERT_TRUE(IS_LEAF(2, 4));
  TEST_ASSERT_TRUE(IS_LEAF(3, 4));

  // Test all possibilities in heap of size 5
  TEST_ASSERT_FALSE(IS_LEAF(0, 5));
  TEST_ASSERT_FALSE(IS_LEAF(1, 5));
  TEST_ASSERT_TRUE(IS_LEAF(2, 5));
  TEST_ASSERT_TRUE(IS_LEAF(3, 5));
  TEST_ASSERT_TRUE(IS_LEAF(4, 5));

  // Test all possibilities in heap of size 6
  TEST_ASSERT_FALSE(IS_LEAF(0, 6));
  TEST_ASSERT_FALSE(IS_LEAF(1, 6));
  TEST_ASSERT_FALSE(IS_LEAF(2, 6));
  TEST_ASSERT_TRUE(IS_LEAF(3, 6));
  TEST_ASSERT_TRUE(IS_LEAF(4, 6));
  TEST_ASSERT_TRUE(IS_LEAF(5, 6));

  // Test all possibilities in heap of size 7
  TEST_ASSERT_FALSE(IS_LEAF(0, 7));
  TEST_ASSERT_FALSE(IS_LEAF(1, 7));
  TEST_ASSERT_FALSE(IS_LEAF(2, 7));
  TEST_ASSERT_TRUE(IS_LEAF(3, 7));
  TEST_ASSERT_TRUE(IS_LEAF(4, 7));
  TEST_ASSERT_TRUE(IS_LEAF(5, 7));
  TEST_ASSERT_TRUE(IS_LEAF(6, 7));

  // Enough...
}

void test_is_root()
{
  TEST_ASSERT_TRUE(IS_ROOT(0));
  TEST_ASSERT_FALSE(IS_ROOT(1));
}

void test_exists()
{
  TEST_ASSERT_TRUE(EXISTS(0, 1));
  TEST_ASSERT_FALSE(EXISTS(1, 1));
  TEST_ASSERT_FALSE(EXISTS(1, 0));
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_parent);
  RUN_TEST(test_left_child);
  RUN_TEST(test_right_child);
  RUN_TEST(test_is_root);
  RUN_TEST(test_is_leaf);
  RUN_TEST(test_exists);
  UNITY_END();
  return 0;
}
