#include <iostream>
#include <unity.h>
#include "Element.h"
#include "MinHeap.h"

void test_parent()
{
  TEST_ASSERT_EQUAL(0, parent(1));
  TEST_ASSERT_EQUAL(0, parent(2));
  TEST_ASSERT_EQUAL(1, parent(3));
  TEST_ASSERT_EQUAL(1, parent(4));
  TEST_ASSERT_EQUAL(2, parent(5));
  TEST_ASSERT_EQUAL(2, parent(6));
}

void test_left_child()
{
  TEST_ASSERT_EQUAL(1, leftChild(0));  
  TEST_ASSERT_EQUAL(3, leftChild(1));  
  TEST_ASSERT_EQUAL(5, leftChild(2));  
  TEST_ASSERT_EQUAL(7, leftChild(3));  
  TEST_ASSERT_EQUAL(9, leftChild(4));  
}

void test_right_child()
{
  TEST_ASSERT_EQUAL(2, rightChild(0));  
  TEST_ASSERT_EQUAL(4, rightChild(1));  
  TEST_ASSERT_EQUAL(6, rightChild(2));  
  TEST_ASSERT_EQUAL(8, rightChild(3));  
  TEST_ASSERT_EQUAL(10, rightChild(4));  

}

void test_create()
{
  MinHeap<Element> heap(3);
  TEST_ASSERT_TRUE(heap.isEmpty());
  TEST_ASSERT_FALSE(heap.isFull());
  TEST_ASSERT_EQUAL_UINT16(0, heap.size());
}

void test_insert_one_element()
{
  MinHeap<Element> heap(1);
  Element e(10);
  heap.insert(&e);
  TEST_ASSERT_TRUE(heap.isFull());
  TEST_ASSERT_EQUAL_INT(10, heap.min()->value());
  TEST_ASSERT_EQUAL_UINT16(1, heap.size());
}

void test_extract_min_one_element()
{
  MinHeap<Element> heap(1);
  Element e(10);
  heap.insert(&e);
  TEST_ASSERT_EQUAL(10, heap.removeMin()->value());
  TEST_ASSERT_EQUAL(0, heap.size());
}

void test_insert_many()
{
  MinHeap<Element> heap(10);
  Element e1(16);
  Element e2(8);
  Element e3(4);
  Element e4(12);
  heap.insert(&e1);
  heap.insert(&e2);
  TEST_ASSERT_EQUAL(8, heap.min()->value());
  heap.insert(&e3);
  TEST_ASSERT_EQUAL(4, heap.min()->value());
  heap.insert(&e4);
  TEST_ASSERT_EQUAL(4, heap.min()->value());
  TEST_ASSERT_EQUAL(4, heap.size());
}

void test_remove_many()
{
  MinHeap<Element> heap(10);
  Element e1(16);
  Element e2(8);
  Element e3(4);
  Element e4(12);
  Element e5(100);
  heap.insert(&e1);
  heap.insert(&e2);
  heap.insert(&e3);
  heap.insert(&e4);
  TEST_ASSERT_EQUAL(4, heap.removeMin()->value());
  TEST_ASSERT_EQUAL(3, heap.size());
  heap.insert(&e5);
  TEST_ASSERT_EQUAL(8, heap.removeMin()->value());
  TEST_ASSERT_EQUAL(12, heap.removeMin()->value());
  TEST_ASSERT_EQUAL(16, heap.removeMin()->value());
  TEST_ASSERT_EQUAL(100, heap.removeMin()->value());
  TEST_ASSERT_EQUAL(0, heap.size());
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_parent);
  RUN_TEST(test_left_child);
  RUN_TEST(test_right_child);
  RUN_TEST(test_create);
  RUN_TEST(test_insert_one_element);
  RUN_TEST(test_extract_min_one_element);
  RUN_TEST(test_insert_many);
  RUN_TEST(test_remove_many);
  UNITY_END();
  return 0;
}
