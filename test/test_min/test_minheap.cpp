#include <iostream>
#include <unity.h>
#include "Element.h"
#include "MinHeap.h"

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

void test_create()
{
  MinHeap<Element> heap(3);
  TEST_ASSERT_TRUE(heap.isEmpty());
  TEST_ASSERT_FALSE(heap.isFull());
  TEST_ASSERT_EQUAL_UINT16(0, heap.size());
  TEST_ASSERT_EQUAL_UINT16(3, heap.capacity());
}

void test_insert_one_element()
{
  MinHeap<Element> heap(1);
  Element e(10);
  heap.insert(&e);
  TEST_ASSERT_FALSE(heap.isEmpty());
  TEST_ASSERT_TRUE(heap.isFull());
  TEST_ASSERT_EQUAL_INT(10, heap.getMin()->value());
  TEST_ASSERT_EQUAL_UINT16(1, heap.size());
}

void test_insert_same_value()
{
  MinHeap<Element> heap(3);
  Element e1(10);
  Element e2(10);
  heap.insert(&e1);
  heap.insert(&e2);
  TEST_ASSERT_EQUAL(&e1, heap.getMin());
}

void test_insert_when_full()
{
  MinHeap<Element> heap(1);
  Element e1(10);
  Element e2(10);
  TEST_ASSERT_EQUAL(&e1, heap.insert(&e1));
  TEST_ASSERT_EQUAL(nullptr, heap.insert(&e2));
  TEST_ASSERT_EQUAL(1, heap.size());
}

void test_remove_when_empty()
{
  MinHeap<Element> heap(1);
  TEST_ASSERT_EQUAL(nullptr, heap.removeMin());
  TEST_ASSERT_EQUAL(0, heap.size());
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
  TEST_ASSERT_EQUAL(8, heap.getMin()->value());
  heap.insert(&e3);
  TEST_ASSERT_EQUAL(4, heap.getMin()->value());
  heap.insert(&e4);
  TEST_ASSERT_EQUAL(4, heap.getMin()->value());
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

void test_update_min()
{
  MinHeap<Element> heap(10);
  Element e1(12);
  Element e2(8);
  Element e3(4);
  heap.insert(&e1);
  heap.insert(&e2);
  heap.insert(&e3);
  TEST_ASSERT_EQUAL(&e3, heap.getMin());

  e3.update(7);
  heap.updateMin();
  TEST_ASSERT_EQUAL(&e3, heap.getMin());

  e3.update(9);
  heap.updateMin();
  TEST_ASSERT_EQUAL(&e2, heap.getMin());

  e2.update(13);
  heap.updateMin();
  TEST_ASSERT_EQUAL(&e3, heap.getMin());
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_parent);
  RUN_TEST(test_left_child);
  RUN_TEST(test_right_child);
  RUN_TEST(test_create);
  RUN_TEST(test_insert_one_element);
  RUN_TEST(test_insert_same_value);
  RUN_TEST(test_extract_min_one_element);
  RUN_TEST(test_insert_many);
  RUN_TEST(test_remove_many);
  RUN_TEST(test_insert_when_full);
  RUN_TEST(test_remove_when_empty);
  RUN_TEST(test_update_min);
  UNITY_END();
  return 0;
}
