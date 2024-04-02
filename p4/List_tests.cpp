#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here


struct Person {
    string name;
    string field; // Author, Mathematician, or ML Expert
};


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

struct Author {
    string name;
    string genre;
};

TEST(test_list_authors) {
    List<Author> authors;
    authors.push_back({"Fyodor Dostoevsky", "Philosophical fiction"});
    authors.push_back({"Jane Austen", "Romance"});
    authors.push_back({"George Orwell", "Dystopian"});

    ASSERT_FALSE(authors.empty());
    ASSERT_EQUAL(authors.size(), 3);
    ASSERT_EQUAL(authors.front().name, "Fyodor Dostoevsky");
    ASSERT_EQUAL(authors.back().name, "George Orwell");

    authors.pop_back();
    ASSERT_EQUAL(authors.size(), 2);
    ASSERT_EQUAL(authors.back().name, "Jane Austen");
}

TEST(test_list_authors_copy_constructor) {
    List<Author> original;
    original.push_back({"Leo Tolstoy", "Realist fiction"});
    original.push_back({"Mark Twain", "Humor"});

    List<Author> copy(original);

    ASSERT_EQUAL(copy.size(), 2);
    ASSERT_EQUAL(copy.front().name, "Leo Tolstoy");
    ASSERT_EQUAL(copy.back().name, "Mark Twain");

    original.push_back({"Kurt Vonnegut", "Satire"});
    ASSERT_EQUAL(original.size(), 3);
    ASSERT_EQUAL(copy.size(), 2);
}

TEST(test_list_authors_assignment_operator) {
    List<Author> original;
    original.push_back({"Hemingway", "Fiction"});
    original.push_back({"Fitzgerald", "Novel"});

    List<Author> assigned;
    assigned = original;

    ASSERT_EQUAL(assigned.size(), 2);
    ASSERT_EQUAL(assigned.front().name, "Hemingway");
    ASSERT_EQUAL(assigned.back().name, "Fitzgerald");

    original.push_front({"Steinbeck", "Novel"});
    ASSERT_EQUAL(original.size(), 3);
    ASSERT_EQUAL(assigned.size(), 2);
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
struct MLExpert {
    string name;
    string specialty;
};

TEST(test_ml_experts_iterator) {
    List<MLExpert> experts;
    experts.push_back({"Ian Goodfellow", "Generative Adversarial Nets"});
    experts.push_back({"Sebastian Thrun", "Robotics"});

    auto it = experts.begin();
    ASSERT_EQUAL(it->name, "Ian Goodfellow");
    ++it;
    ASSERT_EQUAL(it->name, "Sebastian Thrun");
}


 TEST(test_list_iterator_postfix_increment) {
     List<int> list;
     list.push_back(1);
     list.push_back(2);
     list.push_back(3);

     List<int>::Iterator it = list.begin();
     ASSERT_EQUAL(*it++, 1);
     ASSERT_EQUAL(*it++, 2);
     ASSERT_EQUAL(*it++, 3);
 }

 TEST(test_list_iterator_comparison) {
     List<int> list;
     list.push_back(1);
     list.push_back(2);
     list.push_back(3);

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
     List<int>::Iterator it = list.begin();
     ++it; 
     list.pop_front(); 
     ASSERT_EQUAL(*it, 2); 
 }

TEST(test_scientists_copy_constructor) {
    List<string> original;
    original.push_back("Copernicus");
    original.push_back("Archimedes");
    original.push_back("Pythagoras");

    List<string> copy(original); 

    ASSERT_EQUAL(copy.size(), 3);
    ASSERT_EQUAL(copy.front(), "Copernicus");
    ASSERT_EQUAL(copy.back(), "Pythagoras");

    original.push_back("Euclid");
    ASSERT_EQUAL(original.size(), 4);
    ASSERT_EQUAL(copy.size(), 3);
    ASSERT_EQUAL(copy.back(), "Pythagoras");  
}

TEST(test_scientists_assignment_operator) {
    List<string> original;
    original.push_back("Planck");
    original.push_back("Heisenberg");
    original.push_back("Schrodinger");

    List<string> assigned;
    assigned.push_back("Bohr"); 
    assigned = original; 
    
    ASSERT_EQUAL(assigned.size(), 3);
    ASSERT_EQUAL(assigned.front(), "Planck");
    ASSERT_EQUAL(assigned.back(), "Schrodinger");

    original.push_back("Pauli");
    ASSERT_EQUAL(original.size(), 4);
    ASSERT_EQUAL(assigned.size(), 3);
    ASSERT_EQUAL(assigned.back(), "Schrodinger"); 
}


TEST(test_list_assignment_to_from_empty) {
    List<int> non_empty;
    non_empty.push_back(1);
    non_empty.push_back(2);

    List<int> empty;

    empty = non_empty;
    ASSERT_EQUAL(empty.size(), 2);
    ASSERT_EQUAL(empty.front(), 1);
    ASSERT_EQUAL(empty.back(), 2);
    non_empty.clear();
    non_empty = empty;
    ASSERT_FALSE(non_empty.empty());
}

TEST(test_iterator_increment_decrement_reverse) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i + 1);
    }

    auto it = list.end();
    --it;

    ASSERT_EQUAL(*it, 5);
    it--; 
    ASSERT_EQUAL(*it, 4);
    ++it; 
    ASSERT_EQUAL(*it, 5);
}


TEST(test_copy_empty_list) {
    List<int> empty_list;
    List<int> copied_list = empty_list; 

    ASSERT_TRUE(copied_list.empty());
    ASSERT_EQUAL(copied_list.size(), 0);
}

TEST(test_self_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    ++it; 
    list.erase(it); 

    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_list_front_back_modify) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);

    list.front() = 10;
    list.back() = 30;

    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 30);
}

TEST(test_list_front_back_2) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(313298);
    list.push_back(4);
    list.push_back(5);

    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 5);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);

    list.pop_back();
    ASSERT_EQUAL(list.back(), 4);
}

TEST(test_list_empty_and_edge_cases) {
    List<int> list;

    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);

    list.push_front(1);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 1);

    list.push_back(2);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);

    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 2);

    list.pop_back();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);

    list.push_back(3);
    list.push_back(4);

    auto it = list.begin();
    it = list.erase(it);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(*it, 4);

    it = list.insert(it, 3);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(*it, 3);
    ASSERT_EQUAL(list.front(), 3);
    ASSERT_EQUAL(list.back(), 4);

    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);

    list.push_back(5);
    it = list.begin();
    ASSERT_EQUAL(*it, 5);
    it++;
    ASSERT_TRUE(it == list.end());

    it--;
    ASSERT_EQUAL(*it, 5);
    ASSERT_TRUE(it == list.begin());

    list.clear();
    it = list.begin();
    ASSERT_TRUE(it == list.end());
}
TEST(test_list_erase_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.end();
    --it;  // Move to the last element
    it = list.erase(it);  // Erase the last element

    ASSERT_EQUAL(list.size(), 2);
    ASSERT_TRUE(it == list.end());  // Iterator should now be at the end
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);
}


TEST(test_list_erase_until_empty) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    auto it = list.begin();
    it = list.erase(it);  
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.size(), 1);

    it = list.erase(it);  
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(it == list.end());
}


TEST_MAIN()
