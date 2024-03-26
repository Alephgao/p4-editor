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

TEST_MAIN()
