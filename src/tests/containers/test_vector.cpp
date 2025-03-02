#include <gtest/gtest.h>

#include "../../s21_containers.h"

class VectorTest : public ::testing::Test {
 protected:
  s21::vector<int> vector1;
  s21::vector<int> vector2;

  void SetUp() override {
    vector1 = s21::vector<int>({1, 2, 3, 4, 5});
    vector2 = s21::vector<int>({6, 7, 8, 9, 10});
  }
};

// Проверка конструктора по умолчанию
TEST_F(VectorTest, DefaultConstructor) {
  s21::vector<int> vec;
  EXPECT_TRUE(vec.empty());
  EXPECT_EQ(vec.size(), 0);
}

// Проверка конструктора с размером
TEST_F(VectorTest, SizeConstructor) {
  s21::vector<int> vec(5);
  EXPECT_EQ(vec.size(), 5);
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(vec[i], 0);
  }
}

// Проверка конструктора с инициализатором
TEST_F(VectorTest, InitializerListConstructor) {
  s21::vector<int> vec = {1, 2, 3};
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
}

// Проверка копирующего конструктора
TEST_F(VectorTest, CopyConstructor) {
  s21::vector<int> copy(vector1);
  EXPECT_EQ(copy.size(), vector1.size());
  for (size_t i = 0; i < vector1.size(); ++i) {
    EXPECT_EQ(copy[i], vector1[i]);
  }
}

// Проверка оператора присваивания
TEST_F(VectorTest, AssignmentOperator) {
  s21::vector<int> copy;
  copy = vector1;
  EXPECT_EQ(copy.size(), vector1.size());
  for (size_t i = 0; i < vector1.size(); ++i) {
    EXPECT_EQ(copy[i], vector1[i]);
  }
}

// Проверка метода push_back
TEST_F(VectorTest, PushBack) {
  vector1.push_back(6);
  EXPECT_EQ(vector1.back(), 6);
  EXPECT_EQ(vector1.size(), 6);
}

// Проверка метода pop_back
TEST_F(VectorTest, PopBack) {
  vector1.pop_back();
  EXPECT_EQ(vector1.back(), 4);
  EXPECT_EQ(vector1.size(), 4);
}

// Проверка метода clear
TEST_F(VectorTest, Clear) {
  vector1.clear();
  EXPECT_TRUE(vector1.empty());
  EXPECT_EQ(vector1.size(), 0);
}

// Проверка метода swap
TEST_F(VectorTest, Swap) {
  vector1.swap(vector2);
  EXPECT_EQ(vector1.front(), 6);
  EXPECT_EQ(vector2.front(), 1);
}

// Проверка метода insert
TEST_F(VectorTest, Insert) {
  vector1.insert(vector1.begin() + 2, 10);
  EXPECT_EQ(vector1[2], 10);
  EXPECT_EQ(vector1.size(), 6);
}

// Проверка метода erase
TEST_F(VectorTest, Erase) {
  vector1.erase(vector1.begin() + 1);
  EXPECT_EQ(vector1.size(), 4);
  EXPECT_EQ(vector1[0], 1);
  EXPECT_EQ(vector1[1], 3);
}

// Проверка метода at
TEST_F(VectorTest, At) {
  EXPECT_EQ(vector1.at(0), 1);
  EXPECT_THROW(vector1.at(5), std::out_of_range);
}

// Проверка метода front
TEST_F(VectorTest, Front) { EXPECT_EQ(vector1.front(), 1); }

// Проверка метода back
TEST_F(VectorTest, Back) { EXPECT_EQ(vector1.back(), 5); }

// Проверка метода data
TEST_F(VectorTest, Data) { EXPECT_EQ(vector1.data(), &vector1[0]); }

// Проверка метода empty
TEST_F(VectorTest, Empty) {
  EXPECT_FALSE(vector1.empty());
  vector1.clear();
  EXPECT_TRUE(vector1.empty());
}

// Проверка метода size
TEST_F(VectorTest, Size) { EXPECT_EQ(vector1.size(), 5); }

// Проверка метода max_size
TEST_F(VectorTest, MaxSize) { EXPECT_GT(vector1.max_size(), 0); }

// Проверка метода reserve
TEST_F(VectorTest, Reserve) {
  vector1.reserve(10);
  EXPECT_GE(vector1.capacity(), 10);
}

// Проверка метода shrink_to_fit
TEST_F(VectorTest, ShrinkToFit) {
  vector1.reserve(10);
  vector1.shrink_to_fit();
  EXPECT_EQ(vector1.capacity(), vector1.size());
}

// Проверка конструктора с размером и значением
TEST_F(VectorTest, ConstructorWithSizeAndValue) {
  s21::vector<int> v(3, 42);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 42);
  EXPECT_EQ(v[1], 42);
  EXPECT_EQ(v[2], 42);

  s21::vector<int> v_empty(0, 42);
  EXPECT_TRUE(v_empty.empty());
}

// Проверка конструктора перемещения
TEST_F(VectorTest, MoveConstructor) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

// Проверка cbegin() и cend()
TEST_F(VectorTest, ConstIterators) {
  const s21::vector<int> v = {1, 2, 3};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(it, v.cend());
}

// Проверка инвалидации итераторов
TEST_F(VectorTest, IteratorInvalidation) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.begin();
  v.push_back(4);
  EXPECT_NE(it, v.begin());
}

// Проверка noexcept
TEST_F(VectorTest, Noexcept) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;
  EXPECT_TRUE(noexcept(v2 = std::move(v1)));
  EXPECT_TRUE(noexcept(v1.swap(v2)));
}

// Проверка emplace
TEST_F(VectorTest, Emplace) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.emplace(v.begin() + 1, 42);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(*it, 42);
  EXPECT_EQ(v[1], 42);
}

// Проверка assign
TEST_F(VectorTest, Assign) {
  s21::vector<int> v = {1, 2, 3};
  std::vector<int> src = {4, 5, 6};
  v.assign(src.begin(), src.end());
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 4);
  EXPECT_EQ(v[1], 5);
  EXPECT_EQ(v[2], 6);
}

// Проверка работы с исключениями
TEST_F(VectorTest, ExceptionSafety) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_THROW(v.at(5), std::out_of_range);
  v.clear();
  EXPECT_THROW(v.pop_back(), std::out_of_range);
}

// Проверка преобразования итераторов
TEST_F(VectorTest, IteratorConversion) {
  s21::vector<int> v = {1, 2, 3};
  s21::vector<int>::VectorIterator it = v.begin();
  s21::vector<int>::VectorConstIterator cit = it;

  EXPECT_EQ(*it, *cit);
  ++it;
  ++cit;
  EXPECT_EQ(*it, *cit);
}

// Проверка метода insert_many
TEST_F(VectorTest, InsertMany) {
  vector1.insert_many(vector1.begin() + 2, 10, 20, 30);
  EXPECT_EQ(vector1[2], 10);
  EXPECT_EQ(vector1[3], 20);
  EXPECT_EQ(vector1[4], 30);
  EXPECT_EQ(vector1.size(), 8);
}

// Проверка метода insert_many_back
TEST_F(VectorTest, InsertManyBack) {
  vector1.insert_many_back(10, 20, 30);
  EXPECT_EQ(vector1[5], 10);
  EXPECT_EQ(vector1[6], 20);
  EXPECT_EQ(vector1[7], 30);
  EXPECT_EQ(vector1.size(), 8);
}
