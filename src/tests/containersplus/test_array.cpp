#include <gtest/gtest.h>

#include "../../s21_containersplus.h"

class ArrayTest : public ::testing::Test {
 protected:
  s21::array<int, 5> arr;
  s21::array<int, 3> small_arr;
  s21::array<int, 0> empty_arr;

  void SetUp() override {
    arr = {1, 2, 3, 4, 5};
    small_arr = {1, 2, 3};
  }
};

// Проверка конструктора по умолчанию
TEST_F(ArrayTest, DefaultConstructor) {
  s21::array<int, 5> default_arr;
  EXPECT_EQ(default_arr.size(), 5);
  EXPECT_FALSE(default_arr.empty());
}

// Проверка конструктора с инициализатором
TEST_F(ArrayTest, InitializerListConstructor) {
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[4], 5);
}

// Проверка исключения при слишком большом инициализаторе
TEST_F(ArrayTest, InitializerListTooLarge) {
  EXPECT_THROW((s21::array<int, 3>{1, 2, 3, 4}), std::out_of_range);
}

// Проверка копирующего конструктора
TEST_F(ArrayTest, CopyConstructor) {
  s21::array<int, 5> copy(arr);
  EXPECT_EQ(copy[0], arr[0]);
  EXPECT_EQ(copy[1], arr[1]);
  EXPECT_EQ(copy[2], arr[2]);
}

// Проверка метода at с проверкой границ
TEST_F(ArrayTest, At) {
  EXPECT_EQ(arr.at(0), 1);
  EXPECT_EQ(arr.at(4), 5);
  EXPECT_THROW(arr.at(5), std::out_of_range);
}

// Проверка методов front и back
TEST_F(ArrayTest, FrontBack) {
  EXPECT_EQ(arr.front(), 1);
  EXPECT_EQ(arr.back(), 5);
}

// Проверка работы итераторов
TEST_F(ArrayTest, Iterators) {
  int sum = 0;
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 15);
}

// Проверка метода fill
TEST_F(ArrayTest, Fill) {
  arr.fill(42);
  EXPECT_EQ(arr[0], 42);
  EXPECT_EQ(arr[1], 42);
  EXPECT_EQ(arr[2], 42);
}

// Проверка метода swap
TEST_F(ArrayTest, Swap) {
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  arr.swap(arr2);
  EXPECT_EQ(arr[0], 6);
  EXPECT_EQ(arr2[0], 1);
}

// Проверка работы с пустым массивом
TEST_F(ArrayTest, EmptyArrayOperations) {
  EXPECT_TRUE(empty_arr.empty());
  EXPECT_EQ(empty_arr.size(), 0);
}

// Проверка move конструктора
TEST_F(ArrayTest, MoveConstructor) {
  s21::array<int, 5> moved(std::move(arr));
  EXPECT_EQ(moved[0], 1);
  EXPECT_EQ(moved[4], 5);
}

// Проверка const итераторов
TEST_F(ArrayTest, ConstIterators) {
  const s21::array<int, 5> const_arr = arr;
  int sum = 0;
  for (auto it = const_arr.begin(); it != const_arr.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 15);
}

// Проверка оператора []
TEST_F(ArrayTest, OperatorBrackets) {
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[4], 5);
}

// Проверка метода empty
TEST_F(ArrayTest, Empty) {
  EXPECT_TRUE(empty_arr.empty());
  EXPECT_FALSE(arr.empty());
}

// Проверка методов size и max_size
TEST_F(ArrayTest, Size) {
  EXPECT_EQ(arr.size(), 5);
  EXPECT_EQ(arr.max_size(), 5);
}

// Проверка работы с нетривиальным типом данных
TEST_F(ArrayTest, NonTrivialType) {
  s21::array<std::string, 3> str_arr = {"Hello", "World", "!"};
  EXPECT_EQ(str_arr[0], "Hello");
  EXPECT_EQ(str_arr[1], "World");
  EXPECT_EQ(str_arr[2], "!");
}

// Проверка fill и swap на пустом массиве
TEST_F(ArrayTest, FillAndSwapEmptyArray) {
  s21::array<int, 0> arr1, arr2;
  arr1.swap(arr2);
  arr1.fill(0);
  EXPECT_TRUE(arr1.empty());
}

// Проверка выхода за границы массива
TEST_F(ArrayTest, AccessOutOfBounds) {
  EXPECT_THROW(small_arr.at(5), std::out_of_range);
}

// Проверка swap с самим собой
TEST_F(ArrayTest, SwapSelf) {
  arr.swap(arr);
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
}

// Проверка swap с массивами разного размера
TEST_F(ArrayTest, SwapDifferentSizes) {
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  arr.swap(arr2);
  EXPECT_EQ(arr[0], 6);
  EXPECT_EQ(arr2[0], 1);
}

// Проверка работы с пустым массивом
TEST_F(ArrayTest, EmptyArrayOperationsExtended) {
  EXPECT_TRUE(empty_arr.empty());
  EXPECT_EQ(empty_arr.size(), 0);
  EXPECT_EQ(empty_arr.max_size(), 0);

  // Проверка итераторов на пустом массиве
  EXPECT_EQ(empty_arr.begin(), empty_arr.end());

  // Проверка swap с пустым массивом
  s21::array<int, 0> another_empty;
  empty_arr.swap(another_empty);
  EXPECT_TRUE(empty_arr.empty());
}

// Проверка fill на массиве с одним элементом
TEST_F(ArrayTest, SingleElementArray) {
  s21::array<int, 1> single = {42};
  EXPECT_EQ(single.size(), 1);
  EXPECT_EQ(single[0], 42);

  single.fill(99);
  EXPECT_EQ(single[0], 99);
}

// Проверка методов front и back на массиве с одним элементом
TEST_F(ArrayTest, FrontBackSingleElement) {
  s21::array<int, 1> single = {42};
  EXPECT_EQ(single.front(), 42);
  EXPECT_EQ(single.back(), 42);
}

// Проверка итераторов на массиве с одним элементом
TEST_F(ArrayTest, IteratorsSingleElement) {
  s21::array<int, 1> single = {42};
  auto it = single.begin();
  EXPECT_EQ(*it, 42);
  ++it;
  EXPECT_EQ(it, single.end());
}

// Проверка метода data
TEST_F(ArrayTest, DataMethod) {
  int* ptr = arr.data();
  EXPECT_EQ(*ptr, 1);
  *ptr = 99;
  EXPECT_EQ(arr[0], 99);
}

// Проверка const версии методов
TEST_F(ArrayTest, ConstMethods) {
  const s21::array<int, 5> const_arr = arr;

  EXPECT_EQ(const_arr[0], 1);
  EXPECT_EQ(const_arr.at(0), 1);
  EXPECT_EQ(const_arr.front(), 1);
  EXPECT_EQ(const_arr.back(), 5);
  EXPECT_EQ(const_arr.data()[0], 1);

  int sum = 0;
  for (auto it = const_arr.begin(); it != const_arr.end(); ++it) {
    sum += *it;
  }
  EXPECT_EQ(sum, 15);
}

// Проверка move assignment operator
TEST_F(ArrayTest, MoveAssignment) {
  s21::array<int, 5> moved;
  moved = std::move(arr);
  EXPECT_EQ(moved[0], 1);
  EXPECT_EQ(moved[4], 5);
}
