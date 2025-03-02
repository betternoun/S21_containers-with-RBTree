#include <gtest/gtest.h>

#include "../../s21_containers.h"

class ListTest : public ::testing::Test {
 protected:
  s21::list<int> list1;
  s21::list<int> list2;

  void SetUp() override {
    list1 = s21::list<int>({1, 2, 3, 4, 5});
    list2 = s21::list<int>({6, 7, 8, 9, 10});
  }
};

// Класс для тестирования исключений
class ExceptionTrigger {
 public:
  ExceptionTrigger() = default;
  explicit ExceptionTrigger(int) {}
  ExceptionTrigger(const ExceptionTrigger& other) {
    if (other.throw_on_copy) throw std::runtime_error("Copy failed");
  }
  bool throw_on_copy = false;
};

// Класс для тестирования исключений
class ListExceptionTest : public ::testing::Test {
 protected:
  void SetUp() override {
    item1.throw_on_copy = false;
    item2.throw_on_copy = false;
    item3.throw_on_copy = false;
  }

  ExceptionTrigger item1, item2, item3;
};

// Тест для проверки исключения при конструкторе initializer_list
TEST_F(ListExceptionTest, InitializerListConstructorException) {
  try {
    std::initializer_list<ExceptionTrigger> init = {
        ExceptionTrigger(), ExceptionTrigger(), ExceptionTrigger()};

    auto it = init.begin();
    (const_cast<ExceptionTrigger&>(*(it + 2))).throw_on_copy = true;

    EXPECT_THROW((s21::list<ExceptionTrigger>(init)), std::runtime_error);

  } catch (...) {
    FAIL() << "Unexpected exception thrown";
  }
}

// Проверка состояния списка после исключения
TEST_F(ListExceptionTest, ListRemainsValidAfterException) {
  s21::list<ExceptionTrigger> list;
  try {
    ExceptionTrigger item;
    item.throw_on_copy = true;
    list.push_back(item);

  } catch (const std::runtime_error&) {
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.begin(), list.end());
  }
}

// Проверка конструктора по умолчанию
TEST_F(ListTest, DefaultConstructor) {
  s21::list<int> list;
  EXPECT_TRUE(list.empty());
  EXPECT_EQ(list.size(), 0);
}

// Проверка конструктора с размером
TEST_F(ListTest, SizeConstructor) {
  s21::list<int> list(5);
  EXPECT_EQ(list.size(), 5);
  for (auto it = list.begin(); it != list.end(); ++it) {
    EXPECT_EQ(*it, 0);
  }
}

// Проверка конструктора с инициализатором
TEST_F(ListTest, InitializerListConstructor) {
  s21::list<int> list = {1, 2, 3};
  EXPECT_EQ(list.size(), 3);
  auto it = list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

// Проверка копирующего конструктора
TEST_F(ListTest, CopyConstructor) {
  s21::list<int> copy(list1);
  EXPECT_EQ(copy.size(), list1.size());
  auto it1 = list1.begin();
  auto it2 = copy.begin();
  while (it1 != list1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

// Проверка оператора присваивания
TEST_F(ListTest, AssignmentOperator) {
  s21::list<int> copy;
  copy = list1;
  EXPECT_EQ(copy.size(), list1.size());
  auto it1 = list1.begin();
  auto it2 = copy.begin();
  while (it1 != list1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

// Проверка метода push_back
TEST_F(ListTest, PushBack) {
  list1.push_back(6);
  EXPECT_EQ(list1.back(), 6);
  EXPECT_EQ(list1.size(), 6);
}

// Проверка метода push_front
TEST_F(ListTest, PushFront) {
  list1.push_front(0);
  EXPECT_EQ(list1.front(), 0);
  EXPECT_EQ(list1.size(), 6);
}

// Проверка метода pop_back
TEST_F(ListTest, PopBack) {
  list1.pop_back();
  EXPECT_EQ(list1.back(), 4);
  EXPECT_EQ(list1.size(), 4);
}

// Проверка метода pop_front
TEST_F(ListTest, PopFront) {
  list1.pop_front();
  EXPECT_EQ(list1.front(), 2);
  EXPECT_EQ(list1.size(), 4);
}

// Проверка метода clear
TEST_F(ListTest, Clear) {
  list1.clear();
  EXPECT_TRUE(list1.empty());
  EXPECT_EQ(list1.size(), 0);
}

// Проверка метода swap
TEST_F(ListTest, Swap) {
  list1.swap(list2);
  EXPECT_EQ(list1.front(), 6);
  EXPECT_EQ(list2.front(), 1);
}

// Проверка метода merge
TEST_F(ListTest, Merge) {
  s21::list<int> empty_list;
  list1.merge(list2);
  list1.merge(empty_list);
  empty_list.merge(list1);

  EXPECT_TRUE(list2.empty());
  EXPECT_TRUE(list1.empty());
  EXPECT_EQ(empty_list.size(), 10);
}

// Проверка метода reverse
TEST_F(ListTest, Reverse) {
  list1.reverse();
  auto it = list1.begin();
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 4);
}

// Проверка метода unique
TEST_F(ListTest, Unique) {
  s21::list<int> list = {1, 1, 2, 3, 3};
  list.unique();
  EXPECT_EQ(list.size(), 3);
  auto it = list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

// Проверка метода sort
TEST_F(ListTest, Sort) {
  s21::list<int> list = {5, 3, 4, 1, 2};
  list.sort();
  auto it = list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
}

// Тестируем pop_front на пустом списке. Ожидаем исключение std::out_of_range
TEST_F(ListTest, PopFront_EmptyList) {
  s21::list<int> our_list;
  EXPECT_THROW(our_list.pop_front(), std::out_of_range);
}

// Тестируем pop_front на списке с одним элементом
TEST_F(ListTest, SingleElementList) {
  s21::list<int> our_list = {42};
  EXPECT_EQ(our_list.front(), 42);
  EXPECT_EQ(our_list.back(), 42);
  EXPECT_EQ(our_list.size(), 1);
  our_list.pop_front();
  EXPECT_TRUE(our_list.empty());
}

// Тестируем, что итераторы остаются валидными после вставки элемента
TEST_F(ListTest, IteratorValidityAfterInsert) {
  s21::list<int> our_list = {1, 2, 3};
  auto it = our_list.begin();
  our_list.insert(it, 0);
  EXPECT_EQ(*it, 1);
}

// Проверка move конструктора
TEST_F(ListTest, MoveConstructor) {
  s21::list<int> moved(std::move(list1));
  EXPECT_EQ(moved.size(), 5);
  EXPECT_TRUE(list1.empty());
}

// Проверка move оператора присваивания
TEST_F(ListTest, MoveAssignmentOperator) {
  s21::list<int> moved;
  moved = std::move(list1);
  EXPECT_EQ(moved.size(), 5);
  EXPECT_TRUE(list1.empty());
}

// Проверка метода erase
TEST_F(ListTest, Erase) {
  auto it = list1.begin();
  ++it;
  list1.erase(it);
  EXPECT_EQ(list1.size(), 4);
  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(*list1.begin(), 1);
}

// Проверка метода splice
TEST_F(ListTest, Splice) {
  auto it = list1.begin();
  ++it;
  s21::list<int>::const_iterator const_it(it);
  list1.splice(const_it, list2);
  EXPECT_EQ(list1.size(), 10);
  EXPECT_TRUE(list2.empty());
}

// Проверка const итераторов
TEST_F(ListTest, ConstIterators) {
  const s21::list<int> const_list = {1, 2, 3};
  auto it = const_list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

// Проверка max_size
TEST_F(ListTest, MaxSize) { EXPECT_GT(list1.max_size(), 0); }

// Проверка вставки в разные позиции
TEST_F(ListTest, InsertPositions) {
  s21::list<int> l = {1, 3};
  auto it = l.begin();
  ++it;
  l.insert(it, 2);
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(*++l.begin(), 2);
}

// Проверка erase на граничных значениях
TEST_F(ListTest, EraseBoundaries) {
  s21::list<int> l = {1};
  l.erase(l.begin());
  EXPECT_TRUE(l.empty());
  l = {1, 2, 3};
  auto it = l.begin();
  ++it;
  ++it;
  l.erase(it);

  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(l.back(), 2);
}

// Проверка исключений для pop_back
TEST_F(ListTest, PopBackException) {
  s21::list<int> empty_list;
  EXPECT_THROW(empty_list.pop_back(), std::out_of_range);
}

// Проверить корректность обработки попытки удаления элемента из пустого списка
// после его очистки
TEST_F(ListTest, PopBackOnEmptyAfterClear) {
  s21::list<int> l = {1};
  l.clear();
  EXPECT_THROW(l.pop_back(), std::out_of_range);
}

// Проверка константных методов
TEST_F(ListTest, ConstMethods) {
  const s21::list<int> clist = {1, 2, 3};
  EXPECT_EQ(clist.front(), 1);
  EXPECT_EQ(clist.back(), 3);
}

// Проверка производительности для больших данных
TEST_F(ListTest, LargeData) {
  s21::list<int> l;
  const int count = 10000;
  for (int i = 0; i < count; ++i) {
    l.push_back(i);
  }
  EXPECT_EQ(l.size(), count);
}

// Проверка вставки с невалидным итератором
TEST_F(ListTest, InsertInvalidIterator) {
  s21::list<int> l1 = {1, 2, 3};
  s21::list<int> l2 = {4, 5};
  auto it = l2.begin();
  EXPECT_THROW(l1.insert(it, 10), std::invalid_argument);
}

// Проверка удаления с невалидным итератором
TEST_F(ListTest, EraseInvalidIterator) {
  s21::list<int> l1 = {1, 2, 3};
  s21::list<int> l2 = {4, 5};
  auto it = l2.begin();
  EXPECT_THROW(l1.erase(it), std::invalid_argument);
}

// Проверка удаления end итератора.
TEST_F(ListTest, EraseEndIterator) {
  s21::list<int> l = {1, 2, 3};
  auto it = l.end();
  EXPECT_THROW(l.erase(it), std::invalid_argument);
}

// Проверка вставки нескольких элементов в произвольную позицию
TEST_F(ListTest, InsertMany) {
  s21::list<int> l = {1, 2, 3};
  auto it = l.begin();
  ++it;
  l.insert(it, 0);
  EXPECT_EQ(l.size(), 4);
  EXPECT_EQ(*++l.begin(), 0);
}

// Тестирование добавления элементов в конец списка
TEST_F(ListTest, InsertManyBack) {
  s21::list<int> l = {1, 2};
  l.insert_many_back(3, 4);

  EXPECT_EQ(l.size(), 4);
  EXPECT_EQ(l.back(), 4);
  auto it = l.begin();
  ++it;
  ++it;
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it, 4);
}

// Проверка вставки элементов в начало списка
TEST_F(ListTest, InsertManyFront) {
  s21::list<int> l = {3, 4};
  l.insert_many_front(1, 2);

  EXPECT_EQ(l.size(), 4);
  auto it = l.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it, 4);
}

// Тестирование вставки в пустой список
TEST_F(ListTest, InsertManyIntoEmptyList) {
  s21::list<int> l;
  l.insert_many(l.cend(), 1);
  EXPECT_EQ(l.size(), 1);
  EXPECT_EQ(l.front(), 1);
  EXPECT_EQ(l.back(), 1);
}

// Тестирование вызова insert_many_front без аргументов
TEST_F(ListTest, InsertManyFrontWithoutArguments) {
  s21::list<int> l;
  l.insert_many_front();
  EXPECT_EQ(l.size(), 0);
}

// Тестирование комбинирования методов вставки
TEST_F(ListTest, InsertManyCombinationMethods) {
  s21::list<int> l;
  l.insert_many_back(2, 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(l.back(), 3);

  l.insert_many(l.cend(), 1);
  EXPECT_EQ(l.size(), 3);

  auto it = l.begin();
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it, 1);
}

// Проверка обработки невалидного итератора при вставке
TEST_F(ListTest, InsertManyInvalidIterator) {
  s21::list<int> l1 = {1, 2};
  s21::list<int> l2 = {3, 4};
  auto it = l2.cbegin();
  EXPECT_THROW(l1.insert_many(it, 5), std::invalid_argument);
}

// Тестирование декремента итератора
TEST_F(ListTest, IteratorDecrement) {
  s21::list<int> l = {1, 2, 3};
  auto it = l.begin();
  ++it;
  --it;
  EXPECT_EQ(*it, 1);

  ++it;
  ++it;
  --it;
  EXPECT_EQ(*it, 2);
}

// Тестирование декремента константного итератора
TEST_F(ListTest, ConstIteratorDecrement) {
  const s21::list<int> l = {1, 2, 3};
  auto it = l.begin();
  ++it;
  --it;
  EXPECT_EQ(*it, 1);
}

// Тестирование декремента из начальной позиции
TEST_F(ListTest, DecrementFromBegin) {
  s21::list<int> l = {1};
  auto it = l.begin();
  --it;
  EXPECT_FALSE(it.is_valid(l));
}

// Тестирование декремента end итератора
TEST_F(ListTest, DecrementEndIterator) {
  s21::list<int> l = {1, 2, 3};
  auto it = l.end();
  EXPECT_THROW(--it, std::out_of_range);
}

// Тестирование декремента итератора из конца списка
TEST_F(ListTest, IteratorDecrementFromEnd) {
  s21::list<int> l = {1, 2, 3};
  auto it = l.end();
  EXPECT_THROW(--it, std::out_of_range);
}

// Тестирование декремента константного итератора из конца списка
TEST_F(ListTest, ConstIteratorDecrementFromEnd) {
  const s21::list<int> l = {1, 2, 3};
  auto it = l.end();
  EXPECT_THROW(--it, std::out_of_range);
}

// Проверка move конструктора с пустым списком
TEST_F(ListTest, MoveConstructorWithEmptyList) {
  s21::list<int> empty_list;
  s21::list<int> moved(std::move(empty_list));
  EXPECT_TRUE(moved.empty());
  EXPECT_EQ(moved.size(), 0);
}

// Тест для проверки merge с пустым списком
TEST_F(ListTest, MergeWithEmptyList) {
  s21::list<int> empty_list;
  list1.merge(empty_list);
  EXPECT_EQ(list1.size(), 5);
  EXPECT_TRUE(empty_list.empty());
}

// Тест для перемещающего оператора присваивания с пустым списком
TEST_F(ListTest, MoveAssignmentWithEmptyList) {
  s21::list<int> empty_list;
  list1 = std::move(empty_list);
  EXPECT_TRUE(list1.empty());
  EXPECT_EQ(empty_list.size(), 0);
}

// Проверка unique с несколькими дубликатами подряд
TEST_F(ListTest, UniqueMultipleDuplicates) {
  s21::list<int> list = {1, 1, 1, 2, 2, 3, 3, 3};
  list.unique();
  EXPECT_EQ(list.size(), 3);
  auto it = list.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
}

// Тест для splice с пустым списком
TEST_F(ListTest, SpliceEmptyList) {
  s21::list<int> empty_list;
  list1.splice(list1.cbegin(), empty_list);
  EXPECT_EQ(list1.size(), 5);
  EXPECT_TRUE(empty_list.empty());
}

// Проверка слияния с пустым списком
TEST_F(ListTest, MergeWithEmptyCurrentList) {
  s21::list<int> empty_list;
  s21::list<int> non_empty{1, 2, 3};

  empty_list.merge(non_empty);

  EXPECT_TRUE(non_empty.empty());
  EXPECT_EQ(empty_list.size(), 3);
  EXPECT_EQ(empty_list.front(), 1);
  EXPECT_EQ(empty_list.back(), 3);
}

// Проверка порядка элементов после слияния
TEST_F(ListTest, MergeOrder) {
  s21::list<int> listA{1, 3, 5};
  s21::list<int> listB{2, 4, 6};

  listA.merge(listB);

  auto it = listA.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it, 6);
}

// Проверка слияния с пустым хвостом
TEST_F(ListTest, MergeTailAssignment) {
  s21::list<int> listA{5};
  s21::list<int> listB{3, 6};

  listA.sort();
  listB.sort();
  listA.merge(listB);

  EXPECT_EQ(listA.back(), 6);
  EXPECT_EQ(listA.size(), 3);

  s21::list<int> listC{2};
  s21::list<int> listD{1};
  listC.merge(listD);

  EXPECT_EQ(listC.back(), 2);
  EXPECT_TRUE(listD.empty());
}

// Проверка слияния с пустым хвостом
TEST_F(ListTest, MergeEmptyTailCase) {
  s21::list<int> list1{1, 3, 5};
  s21::list<int> list2{2, 4, 6};

  list1.merge(list2);

  EXPECT_EQ(list1.back(), 6);

  s21::list<int> list3{7};
  s21::list<int> list4{8};
  list3.merge(list4);

  EXPECT_EQ(list3.back(), 8);
  EXPECT_EQ(list3.front(), 7);
}

// Проверка слияния с пустым хвостом
TEST_F(ListTest, MergeTailAssignmentEdgeCase) {
  s21::list<int> listA{5};
  s21::list<int> listB{3};

  listA.merge(listB);
  EXPECT_EQ(listA.back(), 5);
  EXPECT_EQ(listA.size(), 2);

  s21::list<int> empty_list;
  listA.merge(empty_list);
  EXPECT_EQ(listA.back(), 5);

  s21::list<int> listC{2, 4, 6};
  s21::list<int> listD{1, 3, 5};
  listC.merge(listD);

  EXPECT_EQ(listC.back(), 6);
  EXPECT_EQ(listC.size(), 6);

  s21::list<int> listE{7};
  s21::list<int> listF{9};
  listE.merge(listF);
  listE.pop_back();
  listE.merge(listF);
  listF.push_back(8);
  listE.merge(listF);
  EXPECT_EQ(listE.back(), 8);
}

// Проверка слияния с пустым хвостом
TEST_F(ListTest, MergeTailExactMatchCase) {
  s21::list<int> list1{1, 3, 5};
  s21::list<int> list2{2, 4, 5};

  list1.merge(list2);

  EXPECT_EQ(list1.back(), 5);
  EXPECT_EQ(list1.size(), 6);

  auto it = list1.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it, 5);
}

// Проверка отката вставки при частичной вставке
TEST_F(ListExceptionTest, PartialInsertionRollback) {
  ExceptionTrigger items[] = {ExceptionTrigger(), ExceptionTrigger(),
                              ExceptionTrigger()};
  items[1].throw_on_copy = true;

  s21::list<ExceptionTrigger> lst;
  EXPECT_THROW((lst = {items[0], items[1], items[2]}), std::runtime_error);

  EXPECT_TRUE(lst.empty());
}

// Проверка безопасности вставки при частичной вставке
TEST_F(ListExceptionTest, PushBackExceptionSafety) {
  s21::list<ExceptionTrigger> lst;

  ExceptionTrigger item1, item2;
  item2.throw_on_copy = true;

  lst.push_back(item1);
  EXPECT_THROW(lst.push_back(item2), std::runtime_error);

  EXPECT_EQ(lst.size(), 1);
  EXPECT_FALSE(lst.front().throw_on_copy);
}

// Проверка самоприсваивания
TEST_F(ListTest, SelfAssignment) {
  list1 = list1;
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(list1.back(), 5);
}

// Проверка присваивания пустого списка
TEST_F(ListTest, AssignmentEmptyList) {
  s21::list<int> empty;
  list1 = empty;
  EXPECT_TRUE(list1.empty());
  EXPECT_EQ(list1.size(), 0);
}

// Проверка перемещающего оператора присваивания с непустым списком
TEST_F(ListTest, MoveAssignmentWithNonEmpty) {
  s21::list<int> temp{10, 20, 30};
  list1 = std::move(temp);
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), 10);
  EXPECT_EQ(list1.back(), 30);
  EXPECT_TRUE(temp.empty());
}

// Проверка перемещающего оператора присваивания с самоприсваиванием
TEST_F(ListTest, MoveSelfAssignment) {
  list1 = std::move(list1);
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list1.front(), 1);
}

// Проверка безопасности перемещающего оператора присваивания после исключения
TEST_F(ListExceptionTest, MoveAssignmentAfterException) {
  s21::list<ExceptionTrigger> lst1;
  lst1.push_back(ExceptionTrigger(1));

  s21::list<ExceptionTrigger> lst2;
  lst2.push_back(ExceptionTrigger(2));

  try {
    item1.throw_on_copy = true;
    lst1 = std::move(lst2);
  } catch (const std::runtime_error&) {
    EXPECT_EQ(lst1.size(), 1);
    EXPECT_EQ(lst2.size(), 1);
  }
}
