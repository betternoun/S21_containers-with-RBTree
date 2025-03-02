#include <gtest/gtest.h>

#include "../../s21_containers.h"

class StackTest : public ::testing::Test {
 protected:
  s21::stack<int> stack1;
  s21::stack<int> stack2;

  void SetUp() override {
    stack1 = s21::stack<int>({1, 2, 3});
    stack2 = s21::stack<int>({4, 5});
  }
};

// Проверка конструктора по умолчанию
TEST_F(StackTest, DefaultConstructor) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

// Проверка конструктора с инициализатором
TEST_F(StackTest, InitializerListConstructor) {
  s21::stack<int> stack = {1, 2, 3};
  EXPECT_FALSE(stack.empty());
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.top(), 3);
}

// Проверка копирующего конструктора
TEST_F(StackTest, CopyConstructor) {
  s21::stack<int> copy(stack1);
  EXPECT_EQ(copy.size(), stack1.size());
  EXPECT_EQ(copy.top(), stack1.top());
}

// Проверка move конструктора
TEST_F(StackTest, MoveConstructor) {
  s21::stack<int> moved(std::move(stack1));
  EXPECT_EQ(moved.size(), 3);
  EXPECT_TRUE(stack1.empty());
}

// Проверка move оператора присваивания
TEST_F(StackTest, MoveAssignmentOperator) {
  s21::stack<int> moved;
  moved = std::move(stack1);
  EXPECT_EQ(moved.size(), 3);
  EXPECT_TRUE(stack1.empty());
}

// Проверка копирующего оператора присваивания
TEST_F(StackTest, CopyAssignmentOperator) {
  s21::stack<int> copy;
  copy = stack1;
  EXPECT_EQ(copy.size(), stack1.size());
  EXPECT_EQ(copy.top(), stack1.top());
  EXPECT_FALSE(stack1.empty());
}

// Проверка методов push и pop
TEST_F(StackTest, PushAndPop) {
  stack1.push(4);
  EXPECT_EQ(stack1.size(), 4);
  EXPECT_EQ(stack1.top(), 4);
  stack1.pop();
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 3);
}

// Проверка метода swap
TEST_F(StackTest, Swap) {
  stack1.swap(stack2);
  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack1.top(), 5);
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
}

// Проверка метода top
TEST_F(StackTest, Top) { EXPECT_EQ(stack1.top(), 3); }

// Проверка метода empty
TEST_F(StackTest, Empty) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
}

// Проверка метода size
TEST_F(StackTest, Size) { EXPECT_EQ(stack1.size(), 3); }

// Проверка константных методов
TEST_F(StackTest, ConstMethods) {
  const s21::stack<int> constStack = {1, 2, 3};
  EXPECT_EQ(constStack.top(), 3);
  EXPECT_EQ(constStack.size(), 3);
}

// Проверка метода insert_many_back
TEST_F(StackTest, InsertManyBack) {
  stack1.insert_many_back(4, 5);
  EXPECT_EQ(stack1.size(), 5);
  EXPECT_EQ(stack1.top(), 5);
}

// Проверка работы с пользовательским типом
TEST_F(StackTest, CustomType) {
  struct TestStruct {
    int a;
    double b;
  };

  s21::stack<TestStruct> customStack;
  customStack.push({1, 2.0});
  customStack.push({3, 4.0});

  EXPECT_EQ(customStack.size(), 2);
  EXPECT_EQ(customStack.top().a, 3);
}

// Проверка работы с большим количеством элементов
TEST_F(StackTest, LargeStack) {
  s21::stack<int> largeStack;
  const int count = 1000000;

  for (int i = 0; i < count; ++i) {
    largeStack.push(i);
  }

  EXPECT_EQ(largeStack.size(), count);
  EXPECT_EQ(largeStack.top(), count - 1);
}

// Проверка работы с разными типами контейнеров
TEST_F(StackTest, DifferentContainer) {
  s21::stack<int, s21::vector<int>> customContainerStack;
  customContainerStack.push(1);
  customContainerStack.push(2);

  EXPECT_EQ(customContainerStack.size(), 2);
  EXPECT_EQ(customContainerStack.top(), 2);
}

// Проверка работы с константным стеком
TEST_F(StackTest, ConstStack) {
  const s21::stack<int> constStack = {1, 2, 3};
  EXPECT_EQ(constStack.size(), 3);
  EXPECT_EQ(constStack.top(), 3);
}

// Проверка работы с noexcept методами
TEST_F(StackTest, NoexceptMethods) {
  s21::stack<int> stack;
  EXPECT_TRUE(noexcept(stack.swap(stack1)));
  EXPECT_TRUE(noexcept(stack = std::move(stack1)));
  EXPECT_TRUE(noexcept(stack.empty()));
  EXPECT_TRUE(noexcept(stack.size()));
}

// Проверка работы с итераторами
TEST_F(StackTest, Iterators) {
  s21::stack<int> stack = {1, 2, 3};

  // Проверка неконстантных итераторов
  auto it = stack.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(it, stack.end());

  // Проверка константных итераторов
  const s21::stack<int> constStack = {1, 2, 3};
  auto cit = constStack.begin();
  EXPECT_EQ(*cit, 1);
  ++cit;
  EXPECT_EQ(*cit, 2);
  ++cit;
  EXPECT_EQ(*cit, 3);
  ++cit;
  EXPECT_EQ(cit, constStack.end());
}

// Проверка работы с итераторами на пустом стеке
TEST_F(StackTest, IteratorsEmptyStack) {
  s21::stack<int> stack;

  // Проверка неконстантных итераторов
  EXPECT_EQ(stack.begin(), stack.end());

  // Проверка константных итераторов
  const s21::stack<int> constStack;
  EXPECT_EQ(constStack.begin(), constStack.end());
}

// Проверка работы с итераторами после модификации стека
TEST_F(StackTest, IteratorsAfterModification) {
  s21::stack<int> stack = {1, 2, 3};

  // Проверка итераторов до модификации
  auto it = stack.begin();
  EXPECT_EQ(*it, 1);

  // Модификация стека
  stack.push(4);
  stack.pop();

  // Проверка итераторов после модификации
  it = stack.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(it, stack.end());
}

// Проверка, что деструктор корректно освобождает память
TEST_F(StackTest, Destructor) {
  s21::stack<int>* stack = new s21::stack<int>({1, 2, 3});
  delete stack;
}

// Проверка исключений
TEST_F(StackTest, PopOnEmptyStack) {
  s21::stack<int> stack;
  EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST_F(StackTest, TopOnEmptyStack) {
  s21::stack<int> stack;
  EXPECT_THROW(stack.top(), std::out_of_range);
}

// Проверка типов
TEST_F(StackTest, TypeTraits) {
  using StackType = s21::stack<int>;
  static_assert(std::is_same_v<StackType::value_type, int>);
  static_assert(std::is_same_v<StackType::reference, int&>);
  static_assert(std::is_same_v<StackType::const_reference, const int&>);
  static_assert(std::is_same_v<StackType::size_type, size_t>);
}

// Тест на вставку нескольких элементов в стек и проверку размера и порядка
// элементов
TEST_F(StackTest, InsertManyBackDetailed) {
  stack1.insert_many_back(4, 5);

  EXPECT_EQ(stack1.size(), 5);

  s21::vector<int> expected_elements = {5, 4, 3, 2, 1};
  s21::vector<int> actual_elements;

  while (!stack1.empty()) {
    actual_elements.push_back(stack1.top());
    stack1.pop();
  }

  EXPECT_EQ(actual_elements, expected_elements);
}

// Тест на вставку без аргументов и проверку размера стека
TEST_F(StackTest, InsertManyBackEmptyArgs) {
  stack1.insert_many_back();
  EXPECT_EQ(stack1.size(), 3);
}

// Тест на вставку с int
TEST_F(StackTest, InsertManyBackDifferentTypes) {
  stack1.insert_many_back(4, 5.0f, static_cast<short>(6));
  EXPECT_EQ(stack1.size(), 6);

  s21::vector<int> expected = {6, 5, 4, 3, 2, 1};
  s21::vector<int> actual;
  while (!stack1.empty()) {
    actual.push_back(stack1.top());
    stack1.pop();
  }
  EXPECT_EQ(actual, expected);
}

// Проверка покрытия кода stack
TEST_F(StackTest, CoverageFix) {
  s21::stack<int> s;
  s.push(42);
  EXPECT_EQ(s.top(), 42);
  s.pop();
  EXPECT_TRUE(s.empty());
}

// Проверка копирующего конструктора с пустым стеком
TEST_F(StackTest, CopyConstructorWithEmptyStack) {
  s21::stack<int> empty_stack;
  s21::stack<int> copied_stack(empty_stack);
  EXPECT_TRUE(copied_stack.empty());
}

// Проверка move конструктора с пустым стеком
TEST_F(StackTest, MoveConstructorWithEmptyStack) {
  s21::stack<int> empty_stack;
  s21::stack<int> moved_stack(std::move(empty_stack));
  EXPECT_TRUE(moved_stack.empty());
  EXPECT_TRUE(empty_stack.empty());
}

// Проверка swap с пустым стеком
TEST_F(StackTest, SwapWithEmptyStack) {
  s21::stack<int> stack1;
  stack1.push(1);
  s21::stack<int> stack2;
  stack1.swap(stack2);
  EXPECT_TRUE(stack1.empty());
  EXPECT_FALSE(stack2.empty());
  EXPECT_EQ(stack2.top(), 1);
}
