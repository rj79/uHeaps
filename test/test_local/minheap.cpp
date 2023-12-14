#include <unity.h>
#include "MinHeap.h"
#include <iostream>

class Element
{
public:
  Element() : Value(0) {};
  Element(int value): Value(value) {};
  void update(int newValue) {
    Value = newValue;
  }
  bool operator<(const Element& other) {
    return Value < other.Value;
  }
  bool operator>(const Element& other) {
    return Value > other.Value;
  }
  int value() { return Value; };

  friend std::ostream& operator<<(std::ostream& os, const Element& element);
private:
  int Value;
};

std::ostream& operator<<(std::ostream& os, const Element& element)
{
  os << "<Element Value=" << element.Value << ">";
  return os;
}

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
  MinHeap<int> heap(3);
  TEST_ASSERT_TRUE(heap.isEmpty());
  TEST_ASSERT_FALSE(heap.isFull());
  TEST_ASSERT_EQUAL_UINT16(0, heap.size());
}

void test_insert_one_element()
{
  MinHeap<int> heap(1);
  heap.insert(10);
  TEST_ASSERT_TRUE(heap.isFull());
  TEST_ASSERT_EQUAL_INT(10, heap.min());
  TEST_ASSERT_EQUAL_INT(10, heap.get(0));
  TEST_ASSERT_EQUAL_UINT16(1, heap.size());
}

void test_extract_min_one_element()
{
  MinHeap<int> heap(1);
  heap.insert(10);
  TEST_ASSERT_EQUAL(10, heap.removeMin());
  TEST_ASSERT_EQUAL(0, heap.size());
}

void test_insert_many()
{
  MinHeap<int> heap(10);
  heap.insert(16);
  heap.insert(8);
  TEST_ASSERT_EQUAL(8, heap.min());
  heap.insert(4);
  TEST_ASSERT_EQUAL(4, heap.min());
  heap.insert(12);
  TEST_ASSERT_EQUAL(4, heap.min());
  TEST_ASSERT_EQUAL(4, heap.size());
}

void test_remove_many()
{
  MinHeap<int> heap(10);
  heap.insert(16);
  heap.insert(8);
  heap.insert(4);
  heap.insert(12);
  TEST_ASSERT_EQUAL(4, heap.removeMin());
  TEST_ASSERT_EQUAL(3, heap.size());
  heap.insert(100);
  TEST_ASSERT_EQUAL(8, heap.removeMin());
  TEST_ASSERT_EQUAL(12, heap.removeMin());
  TEST_ASSERT_EQUAL(16, heap.removeMin());
  TEST_ASSERT_EQUAL(100, heap.removeMin());
  TEST_ASSERT_EQUAL(0, heap.size());
}

void test_class_template()
{
  MinHeap<Element> heap(7);
  heap.insert(Element(16));
  heap.insert(Element(8));
  heap.insert(Element(4));
  heap.insert(Element(12));
  TEST_ASSERT_EQUAL(4, heap.min().value());
  //heap.min().update(100);
  //heap.heapify(0);
  
  int v = heap.removeMin().value();
  heap.insert(Element(100));
  TEST_ASSERT_EQUAL(8, heap.min().value());
  TEST_ASSERT_EQUAL(100, heap.get(3).value());

  TEST_ASSERT_EQUAL(8, heap.removeMin().value());
  std::cerr << heap << std::endl;
  TEST_ASSERT_EQUAL(12, heap.removeMin().value());
  std::cerr << heap << std::endl;
  TEST_ASSERT_EQUAL(16, heap.removeMin().value());
  std::cerr << heap << std::endl;
  TEST_ASSERT_EQUAL(100, heap.removeMin().value());
  std::cerr << heap << std::endl;
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
  RUN_TEST(test_class_template);
  UNITY_END();
  return 0;
}
