#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    ASSERT_TRUE(true);
}

TEST(test_list_empty) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}
TEST(test_list_push_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 3);
    ASSERT_EQUAL(list.back(), 1);
}

TEST(test_list_push_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

// Test case for popping elements from the front of the list
TEST(test_list_pop_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();

    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 3);
}

// Test case for popping elements from the back of the list
TEST(test_list_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();

    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);
}

TEST(test_list_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.clear();

    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_list_assignment_operator_with_previous_elements) {
    // Create two lists
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);

    List<int> list2;
    list2.push_back(3);
    list2.push_back(4);

    // Assign list2 to list1, where list1 already contains elements
    list1 = list2;

    // Check if list1 contains the same elements as list2
    ASSERT_EQUAL(list1.size(), list2.size());
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        ASSERT_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_list_copy_constructor_bug) {
    // Create a list with some elements
    List<int> originalList;
    originalList.push_back(1);
    originalList.push_back(2);
    originalList.push_back(3);

    // Create a copy of the original list using the copy constructor
    List<int> copiedList(originalList);

    // Check if the size of the copied list is the same as the original
    ASSERT_EQUAL(originalList.size(), copiedList.size());

    // Iterate over both lists and compare each element
    List<int>::Iterator originalIt = originalList.begin();
    List<int>::Iterator copiedIt = copiedList.begin();
    while (originalIt != originalList.end() && copiedIt != copiedList.end()) {
        ASSERT_EQUAL(*originalIt, *copiedIt);
        ++originalIt;
        ++copiedIt;
    }
}

TEST(test_list_iterator_dereferencing) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test dereferencing
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
}

TEST(test_list_iterator_prefix_increment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test prefix increment
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
}

TEST(test_list_iterator_postfix_increment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test postfix increment
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it++, 1);
    ASSERT_EQUAL(*it++, 2);
    ASSERT_EQUAL(*it++, 3);
}

TEST(test_list_iterator_prefix_decrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test prefix decrement
    List<int>::Iterator it = list.end();
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
}

TEST(test_list_iterator_postfix_decrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test postfix decrement
    List<int>::Iterator it = list.end();
    ASSERT_EQUAL(*it--, 3);
    ASSERT_EQUAL(*it--, 2);
    ASSERT_EQUAL(*it--, 1);
}

TEST(test_list_iterator_comparison) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test iterator comparison
    List<int>::Iterator it1 = list.begin();
    List<int>::Iterator it2 = list.begin();
    List<int>::Iterator it3 = list.end();
    ASSERT_EQUAL(it1, it2);
    ASSERT_NOT_EQUAL(it1, it3);
    ASSERT_NOT_EQUAL(it2, it3);
}

TEST(test_list_iterator_assignment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test iterator assignment
    List<int>::Iterator it1 = list.begin();
    List<int>::Iterator it2 = it1;
    ++it1;
    ASSERT_NOT_EQUAL(it1, it2);
}

TEST(test_list_iterator_validity_after_modifications) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Test iterator validity after modifications
    List<int>::Iterator it = list.begin();
    ++it; // Move iterator to the second element
    list.pop_front(); // Remove the first element
    ASSERT_EQUAL(*it, 2); // Check if iterator is still valid
}


TEST_MAIN()
