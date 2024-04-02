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

    list.pop_front();

    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 3);
}

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

TEST(test_list_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    auto it = list.begin();
    ++it;
    list.insert(it, 2);

    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 3);
    it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
}

struct Character {
    string name;
    string role;
};

TEST(test_TOM_and_JERRY) {
    List<Character> Tom;
    Tom.push_back({"Tom", "Cat"});
    Tom.push_back({"Jerry", "Mouse"});
    Tom.push_back({"Spike", "Dog"});

    auto it = Tom.begin();
    ASSERT_EQUAL(it->name, "Tom");
    ASSERT_EQUAL((*it).role, "Cat");

    ++it;
    ASSERT_EQUAL(it->name, "Jerry");
    ASSERT_EQUAL((*it).role, "Mouse");
    it--;
    ASSERT_EQUAL(it->name, "Tom");
    ASSERT_EQUAL((*it).role, "Cat");
    ASSERT_TRUE(it != Tom.end());
    ASSERT_FALSE(it == Tom.end());
    ASSERT_EQUAL(it->name, "Tom");
    ASSERT_EQUAL(it->role, "Cat");
}

TEST(test_iterator_assignment) {
    List<int> list;
    list.push_back(100);
    list.push_back(22938920);
    list.push_back(39284);

    List<int>::Iterator it1 = list.begin();
    List<int>::Iterator it2 = list.end();

    ASSERT_TRUE(it1 != it2);  

    it2 = it1; 

    ASSERT_TRUE(it1 == it2);  
    ASSERT_EQUAL(*it1, *it2); 

    
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
