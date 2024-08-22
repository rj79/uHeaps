#include <iostream>
#include <unity.h>
#include "Element.h"
#include "MaxHeap.h"

void test_max_parent()
{
  TEST_ASSERT_EQUAL(0, parent(1));
  TEST_ASSERT_EQUAL(0, parent(2));
  TEST_ASSERT_EQUAL(1, parent(3));
  TEST_ASSERT_EQUAL(1, parent(4));
  TEST_ASSERT_EQUAL(2, parent(5));
  TEST_ASSERT_EQUAL(2, parent(6));
}

void test_max_left_child()
{
  TEST_ASSERT_EQUAL(1, leftChild(0));  
  TEST_ASSERT_EQUAL(3, leftChild(1));  
  TEST_ASSERT_EQUAL(5, leftChild(2));  
  TEST_ASSERT_EQUAL(7, leftChild(3));  
  TEST_ASSERT_EQUAL(9, leftChild(4));  
}

void test_max_right_child()
{
  TEST_ASSERT_EQUAL(2, rightChild(0));  
  TEST_ASSERT_EQUAL(4, rightChild(1));  
  TEST_ASSERT_EQUAL(6, rightChild(2));  
  TEST_ASSERT_EQUAL(8, rightChild(3));  
  TEST_ASSERT_EQUAL(10, rightChild(4));  

}

void test_max_create()
{
  MaxHeap<Element> heap(3);
  TEST_ASSERT_TRUE(heap.isEmpty());
  TEST_ASSERT_FALSE(heap.isFull());
  TEST_ASSERT_EQUAL_UINT16(0, heap.size());
  TEST_ASSERT_EQUAL_UINT16(3, heap.capacity());
}

void test_max_insert_one_element()
{
  MaxHeap<Element> heap(1);
  Element e(10);
  heap.insert(&e);
  TEST_ASSERT_FALSE(heap.isEmpty());
  TEST_ASSERT_TRUE(heap.isFull());
  TEST_ASSERT_EQUAL_INT(10, heap.getMax()->value());
  TEST_ASSERT_EQUAL_UINT16(1, heap.size());
}

void test_insert_same_value()
{
  MaxHeap<Element> heap(3);
  Element e1(10);
  Element e2(10);
  heap.insert(&e1);
  heap.insert(&e2);
  TEST_ASSERT_EQUAL(&e1, heap.getMax());
}

void test_insert_when_full()
{
  MaxHeap<Element> heap(1);
  Element e1(10);
  Element e2(10);
  TEST_ASSERT_EQUAL(&e1, heap.insert(&e1));
  TEST_ASSERT_EQUAL(nullptr, heap.insert(&e2));
  TEST_ASSERT_EQUAL(1, heap.size());
}

void test_remove_when_empty()
{
  MaxHeap<Element> heap(1);
  TEST_ASSERT_EQUAL(nullptr, heap.removeMax());
  TEST_ASSERT_EQUAL(0, heap.size());
}

void test_max_extract_max_one_element()
{
  MaxHeap<Element> heap(1);
  Element e(10);
  heap.insert(&e);
  TEST_ASSERT_EQUAL(10, heap.removeMax()->value());
  TEST_ASSERT_EQUAL(0, heap.size());
}

void test_max_insert_many()
{
  MaxHeap<Element> heap(10);
  Element e1(12);
  Element e2(8);
  Element e3(4);
  Element e4(16);
  heap.insert(&e1);
  heap.insert(&e2);
  TEST_ASSERT_EQUAL(12, heap.getMax()->value());
  heap.insert(&e3);
  TEST_ASSERT_EQUAL(12, heap.getMax()->value());
  heap.insert(&e4);
  TEST_ASSERT_EQUAL(16, heap.getMax()->value());
  TEST_ASSERT_EQUAL(4, heap.size());
}

void test_max_remove_many()
{
  MaxHeap<Element> heap(10);
  Element e1(12);
  Element e2(8);
  Element e3(4);
  Element e4(16);
  Element e5(100);
  heap.insert(&e1);
  heap.insert(&e2);
  heap.insert(&e3);
  heap.insert(&e4);
  TEST_ASSERT_EQUAL(16, heap.removeMax()->value());
  TEST_ASSERT_EQUAL(3, heap.size());
  heap.insert(&e5);
  TEST_ASSERT_EQUAL(100, heap.removeMax()->value());
  TEST_ASSERT_EQUAL(12, heap.removeMax()->value());
  TEST_ASSERT_EQUAL(8, heap.removeMax()->value());
  TEST_ASSERT_EQUAL(4, heap.removeMax()->value());
  TEST_ASSERT_EQUAL(0, heap.size());
}

void test_update_max()
{
  MaxHeap<Element> heap(10);
  //std::cerr << heap << std::endl;
  Element e1(12);
  Element e2(8);
  Element e3(4);
  heap.insert(&e1);
  heap.insert(&e2);
  heap.insert(&e3);
  TEST_ASSERT_EQUAL(&e1, heap.getMax());

  e1.update(9);
  heap.updateMax();
  TEST_ASSERT_EQUAL(&e1, heap.getMax());

  e1.update(7);
  heap.updateMax();
  TEST_ASSERT_EQUAL(&e2, heap.getMax());

  e2.update(3);
  heap.updateMax();
  TEST_ASSERT_EQUAL(&e1, heap.getMax());
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_max_parent);
  RUN_TEST(test_max_left_child);
  RUN_TEST(test_max_right_child);
  RUN_TEST(test_max_create);
  RUN_TEST(test_max_insert_one_element);
  RUN_TEST(test_insert_same_value);
  RUN_TEST(test_max_extract_max_one_element);
  RUN_TEST(test_max_insert_many);
  RUN_TEST(test_max_remove_many);
  RUN_TEST(test_insert_when_full);
  RUN_TEST(test_remove_when_empty);
  RUN_TEST(test_update_max);
  UNITY_END();
  return 0;
}
