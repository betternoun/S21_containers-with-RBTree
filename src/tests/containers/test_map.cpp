#include <gtest/gtest.h>

#include "../../s21_containers.h"

class MapTest : public ::testing::Test {
 protected:
  s21::map<int, char> my_empty_map;
  s21::map<int, char> my_map;
  s21::map<int, int> my_map_int;

  void SetUp() override {
    my_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
    my_map_int = {{1, 2}, {3, 4}, {5, 6}};
  }
};

// Проверка конструктора по умолчанию
TEST_F(MapTest, DefaultConstructor) { EXPECT_TRUE(my_empty_map.empty()); }

// Проверка конструктора с инициализатором
TEST_F(MapTest, InitializerListConstructor) {
  EXPECT_EQ(my_map.size(), 4);
  auto it = my_map.begin();
  EXPECT_EQ((*it).first, 1);
  EXPECT_EQ((*it).second, 'x');
}

// Проверка копирующего конструктора
TEST_F(MapTest, CopyConstructor) {
  s21::map<int, int> copy(my_map_int);
  EXPECT_EQ(copy.size(), my_map_int.size());
  auto it_copy = copy.begin();
  auto it_orig = my_map_int.begin();
  for (; it_orig != my_map_int.end(); ++it_orig, ++it_copy) {
    EXPECT_EQ((*it_copy).first, (*it_orig).first);
    EXPECT_EQ((*it_copy).second, (*it_orig).second);
  }
}

// Проверка оператора присваивания
TEST_F(MapTest, AssignmentOperator) {
  s21::map<int, int> copy;
  copy = my_map_int;
  EXPECT_EQ(copy.size(), my_map_int.size());
  auto it_copy = copy.begin();
  auto it_orig = my_map_int.begin();
  for (; it_orig != my_map_int.end(); ++it_orig, ++it_copy) {
    EXPECT_EQ((*it_copy).first, (*it_orig).first);
    EXPECT_EQ((*it_copy).second, (*it_orig).second);
  }
}

// Проверка метода insert
TEST_F(MapTest, Insert) {
  auto result = my_empty_map.insert({5, 'a'});
  EXPECT_TRUE(result.second);
  EXPECT_EQ(my_empty_map.size(), 1);
  EXPECT_EQ((*my_empty_map.begin()).first, 5);
}

// Проверка метода erase
TEST_F(MapTest, Erase) {
  my_map.erase(my_map.begin());
  EXPECT_EQ(my_map.size(), 3);
  EXPECT_EQ((*my_map.begin()).first, 2);
}

// Проверка метода at
TEST_F(MapTest, At) {
  EXPECT_EQ(my_map.at(1), 'x');
  EXPECT_THROW(my_map.at(10), std::out_of_range);
}

// Проверка метода swap
TEST_F(MapTest, Swap) {
  s21::map<int, char> other_map = {{10, 'a'}, {20, 'b'}};
  my_map.swap(other_map);
  EXPECT_EQ(my_map.size(), 2);
  EXPECT_EQ(other_map.size(), 4);
}

// Проверка метода clear
TEST_F(MapTest, Clear) {
  my_map.clear();
  EXPECT_TRUE(my_map.empty());
}

// Проверка метода merge
TEST_F(MapTest, Merge) {
  s21::map<int, char> other_map = {{5, 'e'}, {6, 'f'}};
  my_map.merge(other_map);
  EXPECT_EQ(my_map.size(), 6);
  EXPECT_TRUE(other_map.empty());
}

// Проверка метода contains
TEST_F(MapTest, Contains) {
  EXPECT_TRUE(my_map.contains(1));
  EXPECT_FALSE(my_map.contains(10));
}

// Проверка метода operator[]
TEST_F(MapTest, OperatorSquareBrackets) {
  my_map[1] = 'z';
  EXPECT_EQ(my_map[1], 'z');
  my_map[10] = 'a';
  EXPECT_EQ(my_map[10], 'a');
  EXPECT_EQ(my_map.size(), 5);
}

// Проверка метода erase с некорректным итератором
TEST_F(MapTest, EraseInvalidIterator) {
  s21::map<int, char>::iterator invalid_it;
  EXPECT_THROW(my_map.erase(invalid_it), std::invalid_argument);
}

// Проверка метода insert_many
TEST_F(MapTest, InsertMany) {
  auto result = my_empty_map.insert_many(
      typename s21::map<int, char>::value_type(1, 'a'),
      typename s21::map<int, char>::value_type(2, 'b'),
      typename s21::map<int, char>::value_type(3, 'c'));

  EXPECT_EQ(result.size(), 3);
  for (const auto& res : result) {
    EXPECT_TRUE(res.second);
  }
  EXPECT_EQ(my_empty_map.size(), 3);

  int expected_keys[] = {1, 2, 3};
  char expected_values[] = {'a', 'b', 'c'};
  size_t i = 0;
  for (auto it = my_empty_map.begin(); it != my_empty_map.end(); ++it, ++i) {
    EXPECT_EQ((*it).first, expected_keys[i]);
    EXPECT_EQ((*it).second, expected_values[i]);
  }
}

// Проверка метода insert_many с пустым набором данных
TEST_F(MapTest, InsertManyEmpty) {
  auto result = my_empty_map.insert_many();
  EXPECT_EQ(result.size(), 0);
  EXPECT_TRUE(my_empty_map.empty());
}

// Проверка метода insert_many с повторяющимися ключами
TEST_F(MapTest, InsertManyDuplicateKeys) {
  auto result =
      my_map.insert_many(typename s21::map<int, char>::value_type(1, 'a'),
                         typename s21::map<int, char>::value_type(2, 'b'),
                         typename s21::map<int, char>::value_type(3, 'c'));

  EXPECT_EQ(result.size(), 3);
  EXPECT_FALSE(result[0].second);
  EXPECT_FALSE(result[1].second);
  EXPECT_FALSE(result[2].second);
  EXPECT_EQ(my_map.size(), 4);
}

// Проверка константных методов
TEST_F(MapTest, ConstMethods) {
  const s21::map<int, char> const_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};

  auto it = const_map.find(2);
  EXPECT_NE(it, const_map.end());
  EXPECT_EQ((*it).first, 2);
  EXPECT_EQ((*it).second, 'b');

  auto not_found = const_map.find(4);
  EXPECT_EQ(not_found, const_map.end());

  auto const_it = const_map.begin();
  EXPECT_EQ((*const_it).first, 1);
  EXPECT_EQ((*const_it).second, 'a');

  std::vector<int> keys;
  std::vector<char> values;
  for (auto it = const_map.begin(); it != const_map.end(); ++it) {
    keys.push_back((*it).first);
    values.push_back((*it).second);
  }

  EXPECT_EQ(keys.size(), 3);
  EXPECT_EQ(values.size(), 3);
  EXPECT_EQ(keys[0], 1);
  EXPECT_EQ(values[0], 'a');
  EXPECT_EQ(keys[1], 2);
  EXPECT_EQ(values[1], 'b');
  EXPECT_EQ(keys[2], 3);
  EXPECT_EQ(values[2], 'c');
}

// Проверка последовательности операций
TEST_F(MapTest, MainSequenceTest) {
  s21::map<int, std::string> myMap;

  // Проверка пустого словаря
  EXPECT_EQ(myMap.size(), 0);

  // Вставка элементов
  myMap.insert({1, "one"});
  myMap.insert({2, "two"});
  myMap.insert({3, "three"});
  EXPECT_EQ(myMap.size(), 3);

  // Проверка доступа к элементам
  EXPECT_EQ(myMap[2], "two");
  myMap[4] = "four";
  EXPECT_EQ(myMap.size(), 4);

  // Проверка удаления
  myMap.erase(myMap.find(2));
  EXPECT_EQ(myMap.size(), 3);
  EXPECT_FALSE(myMap.contains(2));

  // Проверка наличия ключей
  EXPECT_TRUE(myMap.contains(3));
  EXPECT_FALSE(myMap.contains(5));

  // Проверка merge
  s21::map<int, std::string> otherMap = {{5, "five"}, {6, "six"}, {7, "seven"}};
  myMap.merge(otherMap);
  EXPECT_EQ(myMap.size(), 6);
  EXPECT_TRUE(otherMap.empty());

  // Проверка итогового содержимого
  std::vector<int> expected_keys = {1, 3, 4, 5, 6, 7};
  std::vector<std::string> expected_values = {"one",  "three", "four",
                                              "five", "six",   "seven"};

  auto it = myMap.begin();
  for (size_t i = 0; i < expected_keys.size(); ++i, ++it) {
    EXPECT_EQ((*it).first, expected_keys[i]);
    EXPECT_EQ((*it).second, expected_values[i]);
  }
}

// Проверка сохранения порядка обхода
TEST_F(MapTest, OrderPreservationTest) {
  s21::map<int, std::string> myMap;

  myMap[3] = "three";
  myMap[1] = "one";
  myMap[4] = "four";
  myMap[2] = "two";

  std::vector<int> expected_order = {1, 2, 3, 4};
  int i = 0;
  for (const auto& pair : myMap) {
    EXPECT_EQ(pair.first, expected_order[i++]);
  }
}

// Проверка merge с дубликатами
TEST_F(MapTest, MergeWithDuplicatesTest) {
  s21::map<int, std::string> map1 = {{1, "one"}, {2, "two"}};
  s21::map<int, std::string> map2 = {{2, "два"}, {3, "three"}};

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 3);
  EXPECT_EQ(map1[2], "two");
  EXPECT_TRUE(map2.contains(2));
  EXPECT_EQ(map2.size(), 1);
}
