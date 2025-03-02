#include <gtest/gtest.h>

#include "../../s21_containers.h"

class QueueTest : public ::testing::Test {
 protected:
  s21::queue<int> queue1;
  s21::queue<int> queue2;

  void SetUp() override {
    queue1 = s21::queue<int>({1, 2, 3});
    queue2 = s21::queue<int>({4, 5});
  }
};

// Проверка конструктора по умолчанию
TEST_F(QueueTest, DefaultConstructor) {
  s21::queue<int> queue;
  EXPECT_TRUE(queue.empty());
  EXPECT_EQ(queue.size(), 0);
}

// Проверка конструктора с инициализатором
TEST_F(QueueTest, InitializerListConstructor) {
  s21::queue<int> queue = {1, 2, 3};
  EXPECT_FALSE(queue.empty());
  EXPECT_EQ(queue.size(), 3);
}

// Проверка копирующего конструктора
TEST_F(QueueTest, CopyConstructor) {
  s21::queue<int> copy(queue1);
  EXPECT_EQ(copy.size(), queue1.size());
  EXPECT_EQ(copy.front(), queue1.front());
  EXPECT_EQ(copy.back(), queue1.back());
}

// Проверка move конструктора
TEST_F(QueueTest, MoveConstructor) {
  s21::queue<int> moved(std::move(queue1));
  EXPECT_EQ(moved.size(), 3);
  EXPECT_TRUE(queue1.empty());
}

// Проверка move оператора присваивания
TEST_F(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> moved;
  moved = std::move(queue1);
  EXPECT_EQ(moved.size(), 3);
  EXPECT_TRUE(queue1.empty());
}

// Проверка методов push и pop
TEST_F(QueueTest, PushAndPop) {
  queue1.push(4);
  EXPECT_EQ(queue1.size(), 4);
  queue1.pop();
  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 2);
}

// Проверка метода swap
TEST_F(QueueTest, Swap) {
  queue1.swap(queue2);
  EXPECT_EQ(queue1.size(), 2);
  EXPECT_EQ(queue1.front(), 4);
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
}

// Проверка метода front
TEST_F(QueueTest, Front) { EXPECT_EQ(queue1.front(), 1); }

// Проверка метода back
TEST_F(QueueTest, Back) { EXPECT_EQ(queue1.back(), 3); }

// Проверка метода empty
TEST_F(QueueTest, Empty) {
  s21::queue<int> queue;
  EXPECT_TRUE(queue.empty());
}

// Проверка метода size
TEST_F(QueueTest, Size) { EXPECT_EQ(queue1.size(), 3); }

// Проверка константных методов
TEST_F(QueueTest, ConstMethods) {
  const s21::queue<int> constQueue = {1, 2, 3};
  EXPECT_EQ(constQueue.front(), 1);
  EXPECT_EQ(constQueue.back(), 3);
  EXPECT_EQ(constQueue.size(), 3);
}

// Проверка метода insert_many_back
TEST_F(QueueTest, InsertManyBack) {
  queue1.insert_many_back(4, 5);
  EXPECT_EQ(queue1.size(), 5);
  EXPECT_EQ(queue1.back(), 5);
}

// Проверка оператора присваивания с копированием
TEST_F(QueueTest, CopyAssignmentOperator) {
  s21::queue<int> copy;
  copy = queue1;
  EXPECT_EQ(copy.size(), queue1.size());
  EXPECT_EQ(copy.front(), queue1.front());
  EXPECT_EQ(copy.back(), queue1.back());
}

// Проверка метода swap с пустой очередью
TEST_F(QueueTest, SwapWithEmpty) {
  s21::queue<int> emptyQueue;
  queue1.swap(emptyQueue);
  EXPECT_TRUE(queue1.empty());
  EXPECT_EQ(emptyQueue.size(), 3);
}

// Проверка метода pop на пустой очереди
TEST_F(QueueTest, PopEmptyQueue) {
  s21::queue<int> emptyQueue;
  EXPECT_THROW(emptyQueue.pop(), std::out_of_range);
}

// Проверка метода front на пустой очереди
TEST_F(QueueTest, FrontEmptyQueue) {
  s21::queue<int> emptyQueue;
  EXPECT_THROW(emptyQueue.front(), std::out_of_range);
}

// Проверка метода back на пустой очереди
TEST_F(QueueTest, BackEmptyQueue) {
  s21::queue<int> emptyQueue;
  EXPECT_THROW(emptyQueue.back(), std::out_of_range);
}

// Проверка метода insert_many_back с пустой очередью
TEST_F(QueueTest, InsertManyBackEmpty) {
  s21::queue<int> emptyQueue;
  emptyQueue.insert_many_back(1, 2, 3);
  EXPECT_EQ(emptyQueue.size(), 3);
  EXPECT_EQ(emptyQueue.front(), 1);
  EXPECT_EQ(emptyQueue.back(), 3);
}

// Проверка работы с пользовательским типом
TEST_F(QueueTest, CustomType) {
  struct TestStruct {
    int a;
    double b;
  };

  s21::queue<TestStruct> customQueue;
  customQueue.push({1, 2.0});
  customQueue.push({3, 4.0});

  EXPECT_EQ(customQueue.size(), 2);
  EXPECT_EQ(customQueue.front().a, 1);
  EXPECT_EQ(customQueue.back().b, 4.0);
}

// Проверка работы с большим количеством элементов
TEST_F(QueueTest, LargeQueue) {
  s21::queue<int> largeQueue;
  const int count = 1000000;

  for (int i = 0; i < count; ++i) {
    largeQueue.push(i);
  }

  EXPECT_EQ(largeQueue.size(), count);
  EXPECT_EQ(largeQueue.front(), 0);
  EXPECT_EQ(largeQueue.back(), count - 1);
}

// Проверка работы с разными типами контейнеров
TEST_F(QueueTest, DifferentContainer) {
  s21::queue<int, s21::list<int>> customContainerQueue;
  customContainerQueue.push(1);
  customContainerQueue.push(2);

  EXPECT_EQ(customContainerQueue.size(), 2);
  EXPECT_EQ(customContainerQueue.front(), 1);
  EXPECT_EQ(customContainerQueue.back(), 2);
}

// Проверка работы с константной очередью
TEST_F(QueueTest, ConstQueue) {
  const s21::queue<int> constQueue = {1, 2, 3};
  EXPECT_EQ(constQueue.size(), 3);
  EXPECT_EQ(constQueue.front(), 1);
  EXPECT_EQ(constQueue.back(), 3);
}

// Проверка работы с перемещением элементов
TEST_F(QueueTest, MoveElements) {
  s21::queue<std::unique_ptr<int>> uniquePtrQueue;
  uniquePtrQueue.push(std::make_unique<int>(42));
  uniquePtrQueue.push(std::make_unique<int>(24));

  EXPECT_EQ(*uniquePtrQueue.front(), 42);
  EXPECT_EQ(*uniquePtrQueue.back(), 24);

  uniquePtrQueue.pop();
  EXPECT_EQ(*uniquePtrQueue.front(), 24);
}

// Проверка работы с noexcept методами
TEST_F(QueueTest, NoexceptMethods) {
  s21::queue<int> queue;
  EXPECT_TRUE(noexcept(queue.swap(queue1)));
  EXPECT_TRUE(noexcept(queue = std::move(queue1)));
  EXPECT_TRUE(noexcept(queue.empty()));
  EXPECT_TRUE(noexcept(queue.size()));
}

// Проверка работы с пустой очередью после перемещения
TEST_F(QueueTest, EmptyAfterMove) {
  s21::queue<int> moved(std::move(queue1));
  EXPECT_TRUE(queue1.empty());
  EXPECT_EQ(moved.size(), 3);
}

// Проверка работы с пустой очередью после swap
TEST_F(QueueTest, EmptyAfterSwap) {
  s21::queue<int> emptyQueue;
  queue1.swap(emptyQueue);
  EXPECT_TRUE(queue1.empty());
  EXPECT_EQ(emptyQueue.size(), 3);
}
