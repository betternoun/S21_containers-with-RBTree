#include <gtest/gtest.h>

#include "../../s21_containersplus.h"

class MultisetTest : public ::testing::Test {
 protected:
  s21::multiset<int> empty_multiset;
  s21::multiset<int> multiset;
  s21::multiset<int> multiset_with_duplicates;
  s21::multiset<int> large_multiset;
  s21::multiset<int> sorted_test;

  void SetUp() override {
    multiset = {1, 2, 3, 4, 5};
    multiset_with_duplicates = {1, 1, 2, 2, 3};
    for (int i = 0; i < 1000; ++i) {
      large_multiset.insert(i % 100);
    }
    sorted_test = {1, 1, 2, 2, 2, 3, 4, 5, 5};
  }
};

// Проверка конструктора по умолчанию
TEST_F(MultisetTest, DefaultConstructor) {
  EXPECT_TRUE(empty_multiset.empty());
  EXPECT_EQ(empty_multiset.size(), 0);
}

// Проверка конструктора с инициализатором
TEST_F(MultisetTest, InitializerListConstructor) {
  EXPECT_EQ(multiset.size(), 5);
  EXPECT_TRUE(multiset.contains(1));
  EXPECT_TRUE(multiset.contains(5));
}

// Проверка копирующего конструктора
TEST_F(MultisetTest, CopyConstructor) {
  s21::multiset<int> copy(multiset);
  EXPECT_EQ(copy.size(), multiset.size());
  EXPECT_TRUE(copy.contains(1));
  EXPECT_TRUE(copy.contains(5));
}

// Проверка move конструктора
TEST_F(MultisetTest, MoveConstructor) {
  s21::multiset<int> moved(std::move(multiset));
  EXPECT_EQ(moved.size(), 5);
  EXPECT_TRUE(moved.contains(1));
  EXPECT_TRUE(moved.contains(5));
  EXPECT_TRUE(multiset.empty());
}

// Проверка оператора перемещающего присваивания
TEST_F(MultisetTest, MoveAssignment) {
  s21::multiset<int> moved;
  moved = std::move(multiset);
  EXPECT_EQ(moved.size(), 5);
  EXPECT_TRUE(moved.contains(1));
  EXPECT_TRUE(moved.contains(5));
  EXPECT_TRUE(multiset.empty());
}

// Проверка работы итераторов
TEST_F(MultisetTest, Iterators) {
  int sum = 0;
  for (auto it = multiset.begin(); it != multiset.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 15);
}

// Проверка работы const итераторов
TEST_F(MultisetTest, ConstIterators) {
  const s21::multiset<int> const_multiset = multiset;
  int sum = 0;
  for (auto it = const_multiset.begin(); it != const_multiset.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 15);
}

// Проверка вставки элементов
TEST_F(MultisetTest, Insert) {
  empty_multiset.insert(1);
  EXPECT_EQ(empty_multiset.size(), 1);
  EXPECT_TRUE(empty_multiset.contains(1));
}

// Проверка удаления элементов
TEST_F(MultisetTest, Erase) {
  multiset.erase(multiset.find(1));
  EXPECT_EQ(multiset.size(), 4);
  EXPECT_FALSE(multiset.contains(1));
}

// Проверка очистки контейнера
TEST_F(MultisetTest, Clear) {
  multiset.clear();
  EXPECT_TRUE(multiset.empty());
  EXPECT_EQ(multiset.size(), 0);
}

// Проверка обмена содержимым между контейнерами
TEST_F(MultisetTest, Swap) {
  s21::multiset<int> other = {6, 7, 8};
  multiset.swap(other);

  EXPECT_EQ(multiset.size(), 3);
  EXPECT_TRUE(multiset.contains(6));

  EXPECT_EQ(other.size(), 5);
  EXPECT_TRUE(other.contains(1));
}

// Проверка слияния двух контейнеров
TEST_F(MultisetTest, Merge) {
  s21::multiset<int> other = {6, 7, 8};
  multiset.merge(other);

  EXPECT_EQ(multiset.size(), 8);
  EXPECT_TRUE(multiset.contains(6));
  EXPECT_TRUE(other.empty());
}

// Проверка подсчета элементов с заданным ключом
TEST_F(MultisetTest, Count) {
  EXPECT_EQ(multiset_with_duplicates.count(1), 2);
  EXPECT_EQ(multiset_with_duplicates.count(2), 2);
  EXPECT_EQ(multiset_with_duplicates.count(3), 1);
}

// Проверка поиска элемента
TEST_F(MultisetTest, Find) {
  auto it = multiset.find(3);
  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 3);
}

// Проверка наличия элемента в контейнере
TEST_F(MultisetTest, Contains) {
  EXPECT_TRUE(multiset.contains(1));
  EXPECT_FALSE(multiset.contains(6));
}

// Проверка получения диапазона элементов с заданным ключом
TEST_F(MultisetTest, EqualRange) {
  auto range = multiset_with_duplicates.equal_range(1);
  size_t count = 0;
  for (auto it = range.first; it != range.second; ++it) {
    EXPECT_EQ(*it, 1);
    ++count;
  }
  EXPECT_EQ(count, 2);
}

// Проверка получения итератора на первый элемент, не меньший заданного ключа
TEST_F(MultisetTest, LowerBound) {
  auto it = multiset.lower_bound(3);
  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 3);
}

// Проверка получения итератора на первый элемент, больший заданного ключа
TEST_F(MultisetTest, UpperBound) {
  auto it = multiset.upper_bound(3);
  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 4);
}

// Тест сортировки элементов
TEST_F(MultisetTest, SortedOrder) {
  std::vector<int> result;
  for (auto it = sorted_test.begin(); it != sorted_test.end(); ++it) {
    result.push_back(*it);
  }
  std::vector<int> expected = {1, 1, 2, 2, 2, 3, 4, 5, 5};
  ASSERT_EQ(result, expected);
}

// Тест работы с большим количеством элементов
TEST_F(MultisetTest, LargeInsert) {
  EXPECT_EQ(large_multiset.size(), 1000);
  EXPECT_EQ(large_multiset.count(0), 10);
  EXPECT_EQ(large_multiset.count(99), 10);
}

// Тест метода max_size
TEST_F(MultisetTest, MaxSize) { EXPECT_GT(multiset.max_size(), 0); }

// Тест итераторов после удаления
TEST_F(MultisetTest, IteratorAfterErase) {
  auto it = sorted_test.begin();
  sorted_test.erase(it);
  it = sorted_test.begin();
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(sorted_test.size(), 8);
}

// Тест equal_range
TEST_F(MultisetTest, EqualRangeTest) {
  auto range = sorted_test.equal_range(2);
  size_t count = 0;
  for (auto it = range.first; it != range.second; ++it) {
    EXPECT_EQ(*it, 2);
    ++count;
  }
  EXPECT_EQ(count, 3);
}

// Тест граничных значений для bound методов
TEST_F(MultisetTest, BoundEdgeCases) {
  auto lb = sorted_test.lower_bound(0);
  EXPECT_EQ(*lb, 1);

  auto ub = sorted_test.upper_bound(6);
  EXPECT_EQ(ub, sorted_test.end());

  lb = sorted_test.lower_bound(3);
  EXPECT_EQ(*lb, 3);
  ub = sorted_test.upper_bound(3);
  EXPECT_EQ(*ub, 4);
}

// Тест копирующего присваивания
TEST_F(MultisetTest, CopyAssignment) {
  s21::multiset<int> copy;
  copy = sorted_test;

  EXPECT_EQ(copy.size(), sorted_test.size());
  EXPECT_EQ(copy.count(2), 3);
  EXPECT_EQ(sorted_test.count(2), 3);

  copy.erase(copy.find(2));

  EXPECT_EQ(copy.count(2), 2);
  EXPECT_EQ(sorted_test.count(2), 3);
}

// Тест производительности вставки
TEST_F(MultisetTest, PerformanceTest) {
  s21::multiset<int> perf_test;
  for (int i = 0; i < 10000; ++i) {
    perf_test.insert(i % 100);
  }
  EXPECT_EQ(perf_test.count(99), 100);
}

// Тест вставки нескольких элементов: пустой контейнер
TEST_F(MultisetTest, InsertMany) {
  s21::multiset<int> ms;
  auto results = ms.insert_many(5, 2, 3, 5, 1, 4, 5);

  EXPECT_EQ(ms.size(), 7);
  EXPECT_EQ(ms.count(5), 3);

  std::vector<int> expected = {1, 2, 3, 4, 5, 5, 5};
  std::vector<int> actual;
  for (auto&& item : ms) actual.push_back(item);
  EXPECT_EQ(actual, expected);

  // Проверка возвращаемых значений
  ASSERT_EQ(results.size(), 7);
  EXPECT_EQ(*results[0].first, 5);
  EXPECT_EQ(*results[3].first, 5);
  EXPECT_TRUE(results[5].second);
}

// Новый тест для вставки в непустой контейнер
TEST_F(MultisetTest, InsertManyToExisting) {
  s21::multiset<int> ms = {2, 4, 6};
  auto results = ms.insert_many(1, 3, 5, 7, 2, 4);

  EXPECT_EQ(ms.size(), 9);
  EXPECT_EQ(ms.count(2), 2);
  EXPECT_EQ(ms.count(4), 2);

  std::vector<int> expected = {1, 2, 2, 3, 4, 4, 5, 6, 7};
  std::vector<int> actual;
  for (auto&& item : ms) actual.push_back(item);
  EXPECT_EQ(actual, expected);
}

// Модифицированный тест возвращаемых значений
TEST_F(MultisetTest, InsertManyReturnValues) {
  s21::multiset<int> ms;
  auto results = ms.insert_many(2, 1, 2, 3, 2);

  ASSERT_EQ(results.size(), 5);
  EXPECT_EQ(*results[0].first, 2);
  EXPECT_EQ(*results[2].first, 2);
  EXPECT_EQ(*results[4].first, 2);

  for (const auto& res : results) {
    EXPECT_TRUE(res.second);
  }
}
