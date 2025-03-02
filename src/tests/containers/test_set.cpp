#include <gtest/gtest.h>

#include "../../s21_containers.h"

class SetTest : public ::testing::Test {
 protected:
  s21::set<int> my_empty_set;
  s21::set<int> my_set;

  void SetUp() override { my_set = {1, 2, 3, 4}; }
};

// Проверка конструктора по умолчанию
TEST_F(SetTest, DefaultConstructor) {
  EXPECT_TRUE(my_empty_set.empty());
  EXPECT_EQ(my_empty_set.size(), 0);
}

// Проверка конструктора с инициализатором
TEST_F(SetTest, InitializerListConstructor) {
  EXPECT_EQ(my_set.size(), 4);
  auto it = my_set.begin();
  EXPECT_EQ(*it, 1);
}

// Проверка копирующего конструктора
TEST_F(SetTest, CopyConstructor) {
  s21::set<int> copy(my_set);
  EXPECT_EQ(copy.size(), my_set.size());
  auto it_copy = copy.begin();
  auto it_orig = my_set.begin();
  for (; it_orig != my_set.end(); ++it_orig, ++it_copy) {
    EXPECT_EQ(*it_copy, *it_orig);
  }
}

// Проверка оператора присваивания
TEST_F(SetTest, AssignmentOperator) {
  s21::set<int> copy;
  copy = my_set;
  EXPECT_EQ(copy.size(), my_set.size());
  auto it_copy = copy.begin();
  auto it_orig = my_set.begin();
  for (; it_orig != my_set.end(); ++it_orig, ++it_copy) {
    EXPECT_EQ(*it_copy, *it_orig);
  }

  copy = copy;
  EXPECT_EQ(copy.size(), my_set.size());
  it_copy = copy.begin();
  it_orig = my_set.begin();
  for (; it_orig != my_set.end(); ++it_orig, ++it_copy) {
    EXPECT_EQ(*it_copy, *it_orig);
  }
}

// Проверка метода insert
TEST_F(SetTest, Insert) {
  auto result = my_empty_set.insert(5);
  EXPECT_TRUE(result.second);
  EXPECT_EQ(my_empty_set.size(), 1);
  EXPECT_EQ(*my_empty_set.begin(), 5);
}

// Проверка метода erase
TEST_F(SetTest, Erase) {
  auto it = my_set.find(2);
  my_set.erase(it);
  EXPECT_EQ(my_set.size(), 3);
  EXPECT_EQ(my_set.contains(2), false);
  EXPECT_EQ(*my_set.begin(), 1);
}

// Проверка выбрасывания исключения при удалении end() итератора
TEST_F(SetTest, EraseEndIterator) {
  EXPECT_THROW(my_set.erase(my_set.end()), std::invalid_argument);
  EXPECT_EQ(my_set.size(), 4);
}

// Проверка выбрасывания исключения при удалении невалидного итератора
TEST_F(SetTest, EraseInvalidIterator) {
  typename s21::set<int>::iterator invalid_it(nullptr);
  EXPECT_THROW(my_set.erase(invalid_it), std::invalid_argument);
  EXPECT_EQ(my_set.size(), 4);
}

// Проверка вставки существующего элемента
TEST_F(SetTest, InsertExistingElement) {
  auto result = my_set.insert(2);
  EXPECT_FALSE(result.second);
  EXPECT_EQ(my_set.size(), 4);
  EXPECT_EQ(*result.first, 2);
}

// Проверка метода find
TEST_F(SetTest, Find) {
  auto it = my_set.find(3);
  EXPECT_NE(it, my_set.end());
  EXPECT_EQ(*it, 3);

  it = my_set.find(10);
  EXPECT_EQ(it, my_set.end());
}

// Проверка метода contains
TEST_F(SetTest, Contains) {
  EXPECT_TRUE(my_set.contains(1));
  EXPECT_FALSE(my_set.contains(10));
}

// Проверка метода swap
TEST_F(SetTest, Swap) {
  s21::set<int> other_set = {10, 20};
  my_set.swap(other_set);
  EXPECT_EQ(my_set.size(), 2);
  EXPECT_EQ(other_set.size(), 4);
}

// Проверка метода merge
TEST_F(SetTest, Merge) {
  s21::set<int> other_set = {5, 6};
  my_set.merge(other_set);
  EXPECT_EQ(my_set.size(), 6);
  EXPECT_TRUE(other_set.empty());
}

// Проверка метода clear
TEST_F(SetTest, Clear) {
  my_set.clear();
  EXPECT_TRUE(my_set.empty());
  EXPECT_EQ(my_set.size(), 0);
}

// Проверка итераторов
TEST_F(SetTest, Iterators) {
  auto it = my_set.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);

  auto cit = my_set.cbegin();
  EXPECT_EQ(*cit, 1);
}

// Проверка метода max_size
TEST_F(SetTest, MaxSize) { EXPECT_GT(my_set.max_size(), 0); }

// Проверка метода insert_many с несколькими элементами
TEST_F(SetTest, InsertManyMultipleElements) {
  s21::vector<std::pair<typename s21::set<int>::iterator, bool>> results =
      my_set.insert_many(5, 2, 3, 7);

  EXPECT_EQ(results.size(), 4);
  EXPECT_TRUE(results[0].second);
  EXPECT_FALSE(results[1].second);
  EXPECT_FALSE(results[2].second);
  EXPECT_TRUE(results[3].second);

  EXPECT_EQ(my_set.size(), 6);
  EXPECT_TRUE(my_set.contains(5));
  EXPECT_TRUE(my_set.contains(7));
}

// Проверка метода insert_many с одним новым элементом
TEST_F(SetTest, InsertManySingleNewElement) {
  s21::vector<std::pair<typename s21::set<int>::iterator, bool>> results =
      my_set.insert_many(8);

  EXPECT_EQ(results.size(), 1);
  EXPECT_TRUE(results[0].second);

  EXPECT_EQ(my_set.size(), 5);
  EXPECT_TRUE(my_set.contains(8));
}

// Проверка метода insert_many с элементами, которые уже существуют
TEST_F(SetTest, InsertManyExistingElements) {
  s21::vector<std::pair<typename s21::set<int>::iterator, bool>> results =
      my_set.insert_many(1, 2);

  EXPECT_EQ(results.size(), 2);
  EXPECT_FALSE(results[0].second);
  EXPECT_FALSE(results[1].second);

  EXPECT_EQ(my_set.size(), 4);
}

// Проверка перемещающего оператора присваивания
TEST_F(SetTest, MoveAssignmentOperator) {
  s21::set<int> temp_set = {5, 6, 7};
  s21::set<int> moved_set;
  moved_set = std::move(temp_set);

  EXPECT_EQ(moved_set.size(), 3);
  EXPECT_TRUE(moved_set.contains(5));
  EXPECT_TRUE(moved_set.contains(6));
  EXPECT_TRUE(moved_set.contains(7));
  EXPECT_TRUE(temp_set.empty());

  // Проверка самоприсваивания
  moved_set = std::move(moved_set);
  EXPECT_EQ(moved_set.size(), 3);
}

// Проверка перемещающего конструктора
TEST_F(SetTest, MoveConstructor) {
  s21::set<int> temp_set = {5, 6, 7};
  s21::set<int> moved_set(std::move(temp_set));

  EXPECT_EQ(moved_set.size(), 3);
  EXPECT_TRUE(moved_set.contains(5));
  EXPECT_TRUE(moved_set.contains(6));
  EXPECT_TRUE(moved_set.contains(7));
  EXPECT_TRUE(temp_set.empty());
}

// Проверка конструктора с initializer_list
TEST_F(SetTest, InitializerListConstructorFull) {
  s21::set<int> custom_set{5, 3, 7, 2, 8};
  EXPECT_EQ(custom_set.size(), 5);
  EXPECT_TRUE(custom_set.contains(5));
  EXPECT_TRUE(custom_set.contains(3));
  EXPECT_TRUE(custom_set.contains(7));
  EXPECT_TRUE(custom_set.contains(2));
  EXPECT_TRUE(custom_set.contains(8));

  auto it = custom_set.begin();
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 7);
  ++it;
  EXPECT_EQ(*it, 8);
}
