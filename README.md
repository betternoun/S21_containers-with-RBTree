# Проект: s21_containers

Разработчики Школы 21:
- [Amycushu](https://edu.21-school.ru/profile/amycushu)
- [Lothostr](https://edu.21-school.ru/profile/lothostr)

## Сборка библиотеки

```zsh
make
```
> В папке src будет создана библиотека `lib_s21_containers`

## Компиляция проекта

```zsh
g++ -std=c++17 -o main main.cpp
./main
```
> Компиляция и запуск примера использования библиотеки

```zsh
make && g++ -std=c++17 -o main main.cpp && ./main
```
> Сборка, компиляция, запуск примера использования библиотеки

## Part 1. Пример реализация библиотеки s21_containers.h

### List

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание пустого списка
  s21::list<int> myList;
  std::cout << "=== Создание пустого списка ===" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl << std::endl;

  // Добавление элементов в конец списка
  std::cout << "=== Добавление элементов в конец списка ===" << std::endl;
  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);
  std::cout << "Добавлены элементы 10, 20, 30" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl << std::endl;

  // Добавление элемента в начало списка
  std::cout << "=== Добавление элемента в начало списка ===" << std::endl;
  myList.push_front(5);
  std::cout << "Добавлен элемент 5 в начало" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl << std::endl;

  // Вывод элементов списка
  std::cout << "=== Элементы списка ===" << std::endl;
  for (const auto& elem : myList) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Доступ к первому и последнему элементам
  std::cout << "=== Доступ к элементам ===" << std::endl;
  std::cout << "Первый элемент: " << myList.front() << std::endl;
  std::cout << "Последний элемент: " << myList.back() << std::endl << std::endl;

  // Удаление элементов
  std::cout << "=== Удаление элементов ===" << std::endl;
  myList.pop_front();
  std::cout << "Удален первый элемент" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl;

  myList.pop_back();
  std::cout << "Удален последний элемент" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl << std::endl;

  // Вставка элемента в середину списка
  std::cout << "=== Вставка элемента в середину списка ===" << std::endl;
  auto it = myList.begin();
  ++it;  // Переход ко второму элементу
  myList.insert(it, 15);
  std::cout << "Вставлен элемент 15" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl << std::endl;

  // Вывод элементов после вставки
  std::cout << "=== Элементы списка после вставки ===" << std::endl;
  for (const auto& elem : myList) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Удаление элемента по итератору
  std::cout << "=== Удаление элемента по итератору ===" << std::endl;
  it = myList.begin();
  ++it;
  myList.erase(it);
  std::cout << "Удален второй элемент" << std::endl;
  std::cout << "Размер: " << myList.size() << std::endl << std::endl;

  // Создание нового списка через initializer_list
  std::cout << "=== Создание нового списка через initializer_list ==="
            << std::endl;
  s21::list<int> anotherList = {100, 200, 300};
  std::cout << "Размер нового списка: " << anotherList.size() << std::endl
            << std::endl;

  // Объединение списков
  std::cout << "=== Объединение списков ===" << std::endl;
  myList.merge(anotherList);
  std::cout << "Списки объединены" << std::endl;
  std::cout << "Размер основного списка: " << myList.size() << std::endl
            << std::endl;

  // Вывод элементов после объединения
  std::cout << "=== Элементы основного списка после объединения ==="
            << std::endl;
  for (const auto& elem : myList) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание пустого списка ===
Размер: 0

=== Добавление элементов в конец списка ===
Добавлены элементы 10, 20, 30
Размер: 3

=== Добавление элемента в начало списка ===
Добавлен элемент 5 в начало
Размер: 4

=== Элементы списка ===
5 10 20 30 

=== Доступ к элементам ===
Первый элемент: 5
Последний элемент: 30

=== Удаление элементов ===
Удален первый элемент
Размер: 3
Удален последний элемент
Размер: 2

=== Вставка элемента в середину списка ===
Вставлен элемент 15
Размер: 3

=== Элементы списка после вставки ===
10 15 20 

=== Удаление элемента по итератору ===
Удален второй элемент
Размер: 2

=== Создание нового списка через initializer_list ===
Размер нового списка: 3

=== Объединение списков ===
Списки объединены
Размер основного списка: 5

=== Элементы основного списка после объединения ===
10 20 100 200 300

```

### Map

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание пустого словаря
  s21::map<int, std::string> myMap;
  std::cout << "=== Создание пустого словаря ===" << std::endl;
  std::cout << "Размер: " << myMap.size() << std::endl << std::endl;

  // Вставка элементов
  std::cout << "=== Вставка элементов ===" << std::endl;
  myMap.insert({1, "one"});
  myMap.insert({2, "two"});
  myMap.insert({3, "three"});
  std::cout << "Добавлены 3 элемента" << std::endl;
  std::cout << "Размер: " << myMap.size() << std::endl << std::endl;

  // Доступ к элементам
  std::cout << "=== Доступ к элементам ===" << std::endl;
  std::cout << "Элемент с ключом 2: " << myMap[2] << std::endl;
  myMap[4] = "four";  // Вставка через operator[]
  std::cout << "Добавлен элемент с ключом 4" << std::endl << std::endl;

  // Вывод элементов словаря
  std::cout << "=== Элементы словаря ===" << std::endl;
  for (const auto& [key, value] : myMap) {
    std::cout << key << ": " << value << std::endl;
  }
  std::cout << std::endl;

  // Удаление элемента
  std::cout << "=== Удаление элемента ===" << std::endl;
  myMap.erase(myMap.find(2));
  std::cout << "Удален элемент с ключом 2" << std::endl;
  std::cout << "Размер: " << myMap.size() << std::endl << std::endl;

  // Проверка наличия ключа
  std::cout << "=== Проверка наличия ключа ===" << std::endl;
  std::cout << "Ключ 3 существует: " << (myMap.contains(3) ? "да" : "нет")
            << std::endl;
  std::cout << "Ключ 5 существует: " << (myMap.contains(5) ? "да" : "нет")
            << std::endl
            << std::endl;

  // Создание второго словаря
  std::cout << "=== Создание второго словаря ===" << std::endl;
  s21::map<int, std::string> otherMap = {{5, "five"}, {6, "six"}, {7, "seven"}};
  std::cout << "Размер второго словаря: " << otherMap.size() << std::endl
            << std::endl;

  // Объединение словарей
  std::cout << "=== Объединение словарей ===" << std::endl;
  myMap.merge(otherMap);
  std::cout << "Размер основного словаря после объединения: " << myMap.size()
            << std::endl
            << std::endl;

  // Итоговые элементы
  std::cout << "=== Итоговые элементы словаря ===" << std::endl;
  for (const auto& [key, value] : myMap) {
    std::cout << key << ": " << value << std::endl;
  }

  return 0;
}

```

**Результат работы программы**

```log
=== Создание пустого словаря ===
Размер: 0

=== Вставка элементов ===
Добавлены 3 элемента
Размер: 3

=== Доступ к элементам ===
Элемент с ключом 2: two
Добавлен элемент с ключом 4

=== Элементы словаря ===
1: one
2: two
3: three
4: four

=== Удаление элемента ===
Удален элемент с ключом 2
Размер: 3

=== Проверка наличия ключа ===
Ключ 3 существует: да
Ключ 5 существует: нет

=== Создание второго словаря ===
Размер второго словаря: 3

=== Объединение словарей ===
Размер основного словаря после объединения: 6

=== Итоговые элементы словаря ===
1: one
3: three
4: four
5: five
6: six
7: seven

```

### Queue

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание очереди через initializer_list
  s21::queue<int> myQueue = {10, 20, 30};
  std::cout << "=== Создание очереди ===" << std::endl;
  std::cout << "Размер: " << myQueue.size() << std::endl;
  std::cout << "Первый элемент: " << myQueue.front() << std::endl;
  std::cout << "Последний элемент: " << myQueue.back() << std::endl
            << std::endl;

  // Добавление элементов
  std::cout << "=== Добавление элементов ===" << std::endl;
  myQueue.push(40);
  myQueue.push(50);
  std::cout << "Добавлены 40 и 50" << std::endl;
  std::cout << "Размер: " << myQueue.size() << std::endl;
  std::cout << "Последний элемент: " << myQueue.back() << std::endl
            << std::endl;

  // Удаление элементов
  std::cout << "=== Удаление элементов ===" << std::endl;
  std::cout << "Удален: " << myQueue.front() << std::endl;
  myQueue.pop();
  std::cout << "Новый первый элемент: " << myQueue.front() << std::endl;
  std::cout << "Размер: " << myQueue.size() << std::endl << std::endl;

  // Проверка на пустоту
  std::cout << "=== Проверка состояния очереди ===" << std::endl;
  std::cout << "Очередь пуста: " << (myQueue.empty() ? "да" : "нет")
            << std::endl
            << std::endl;

  // Создание второй очереди
  s21::queue<int> otherQueue = {100, 200};
  std::cout << "=== Создание второй очереди ===" << std::endl;
  std::cout << "Размер второй очереди: " << otherQueue.size() << std::endl
            << std::endl;

  // Обмен содержимого очередей
  std::cout << "=== Обмен содержимого очередей ===" << std::endl;
  myQueue.swap(otherQueue);
  std::cout << "Размер myQueue после обмена: " << myQueue.size() << std::endl;
  std::cout << "Первый элемент myQueue: " << myQueue.front() << std::endl
            << std::endl;

  // Добавление нескольких элементов
  std::cout << "=== Добавление нескольких элементов ===" << std::endl;
  myQueue.insert_many_back(300, 400, 500);
  std::cout << "Размер: " << myQueue.size() << std::endl;
  std::cout << "Последний элемент: " << myQueue.back() << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание очереди ===
Размер: 3
Первый элемент: 10
Последний элемент: 30

=== Добавление элементов ===
Добавлены 40 и 50
Размер: 5
Последний элемент: 50

=== Удаление элементов ===
Удален: 10
Новый первый элемент: 20
Размер: 4

=== Проверка состояния очереди ===
Очередь пуста: нет

=== Создание второй очереди ===
Размер второй очереди: 2

=== Обмен содержимого очередей ===
Размер myQueue после обмена: 2
Первый элемент myQueue: 100

=== Добавление нескольких элементов ===
Размер: 5
Последний элемент: 500

```

### Set

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание пустого множества
  s21::set<int> mySet;
  std::cout << "=== Создание пустого множества ===" << std::endl;
  std::cout << "Размер: " << mySet.size() << std::endl << std::endl;

  // Вставка элементов
  std::cout << "=== Вставка элементов ===" << std::endl;
  mySet.insert(10);
  mySet.insert(20);
  mySet.insert(30);
  std::cout << "Добавлены элементы 10, 20, 30" << std::endl;
  std::cout << "Размер: " << mySet.size() << std::endl << std::endl;

  // Попытка вставки дубликата
  std::cout << "=== Попытка вставки дубликата ===" << std::endl;
  auto [it, success] = mySet.insert(20);
  std::cout << "Вставка 20: " << (success ? "успешно" : "не удалось")
            << std::endl
            << std::endl;

  // Проверка наличия элементов
  std::cout << "=== Проверка наличия элементов ===" << std::endl;
  std::cout << "Содержит 15: " << (mySet.contains(15) ? "да" : "нет")
            << std::endl;
  std::cout << "Содержит 20: " << (mySet.contains(20) ? "да" : "нет")
            << std::endl
            << std::endl;

  // Вывод элементов множества
  std::cout << "=== Элементы множества ===" << std::endl;
  for (const auto& elem : mySet) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Удаление элемента
  std::cout << "=== Удаление элемента ===" << std::endl;
  mySet.erase(mySet.find(20));
  std::cout << "Удален элемент 20" << std::endl;
  std::cout << "Размер: " << mySet.size() << std::endl << std::endl;

  // Создание второго множества
  std::cout << "=== Создание второго множества ===" << std::endl;
  s21::set<int> otherSet = {40, 50, 60};
  std::cout << "Размер второго множества: " << otherSet.size() << std::endl
            << std::endl;

  // Объединение множеств
  std::cout << "=== Объединение множеств ===" << std::endl;
  mySet.merge(otherSet);
  std::cout << "Объединение выполнено" << std::endl;
  std::cout << "Размер основного множества: " << mySet.size() << std::endl;
  std::cout << "Размер второго множества: " << otherSet.size() << std::endl
            << std::endl;

  // Вставка нескольких элементов
  std::cout << "=== Вставка нескольких элементов ===" << std::endl;
  mySet.insert_many(70, 80, 90);
  std::cout << "Добавлены элементы 70, 80, 90" << std::endl;
  std::cout << "Размер: " << mySet.size() << std::endl << std::endl;

  // Итоговые элементы множества
  std::cout << "=== Итоговые элементы множества ===" << std::endl;
  for (const auto& elem : mySet) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание пустого множества ===
Размер: 0

=== Вставка элементов ===
Добавлены элементы 10, 20, 30
Размер: 3

=== Попытка вставки дубликата ===
Вставка 20: не удалось

=== Проверка наличия элементов ===
Содержит 15: нет
Содержит 20: да

=== Элементы множества ===
10 20 30 

=== Удаление элемента ===
Удален элемент 20
Размер: 2

=== Создание второго множества ===
Размер второго множества: 3

=== Объединение множеств ===
Объединение выполнено
Размер основного множества: 5
Размер второго множества: 0

=== Вставка нескольких элементов ===
Добавлены элементы 70, 80, 90
Размер: 8

=== Итоговые элементы множества ===
10 30 40 50 60 70 80 90 

```

### Stack

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание стека через initializer_list
  s21::stack<int> myStack = {1, 2, 3};
  std::cout << "=== Создание стека ===" << std::endl;
  std::cout << "Размер: " << myStack.size() << std::endl;
  std::cout << "Верхний элемент: " << myStack.top() << std::endl << std::endl;

  // Добавление элементов
  std::cout << "=== Добавление элементов ===" << std::endl;
  myStack.push(4);
  myStack.push(5);
  std::cout << "Добавлены 4 и 5" << std::endl;
  std::cout << "Размер: " << myStack.size() << std::endl;
  std::cout << "Верхний элемент: " << myStack.top() << std::endl << std::endl;

  // Удаление элементов
  std::cout << "=== Удаление элементов ===" << std::endl;
  std::cout << "Удален: " << myStack.top() << std::endl;
  myStack.pop();
  std::cout << "Новый верхний элемент: " << myStack.top() << std::endl;
  std::cout << "Размер: " << myStack.size() << std::endl << std::endl;

  // Проверка на пустоту
  std::cout << "=== Проверка состояния стека ===" << std::endl;
  std::cout << "Стек пуст: " << (myStack.empty() ? "да" : "нет") << std::endl
            << std::endl;

  // Создание второго стека
  s21::stack<int> otherStack = {10, 20};
  std::cout << "=== Создание второго стека ===" << std::endl;
  std::cout << "Размер второго стека: " << otherStack.size() << std::endl
            << std::endl;

  // Обмен содержимого стеков
  std::cout << "=== Обмен содержимого стеков ===" << std::endl;
  myStack.swap(otherStack);
  std::cout << "Размер myStack после обмена: " << myStack.size() << std::endl;
  std::cout << "Верхний элемент myStack: " << myStack.top() << std::endl
            << std::endl;

  // Добавление нескольких элементов
  std::cout << "=== Добавление нескольких элементов ===" << std::endl;
  myStack.insert_many_back(30, 40, 50);
  std::cout << "Размер: " << myStack.size() << std::endl;
  std::cout << "Верхний элемент: " << myStack.top() << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание стека ===
Размер: 3
Верхний элемент: 3

=== Добавление элементов ===
Добавлены 4 и 5
Размер: 5
Верхний элемент: 5

=== Удаление элементов ===
Удален: 5
Новый верхний элемент: 4
Размер: 4

=== Проверка состояния стека ===
Стек пуст: нет

=== Создание второго стека ===
Размер второго стека: 2

=== Обмен содержимого стеков ===
Размер myStack после обмена: 2
Верхний элемент myStack: 20

=== Добавление нескольких элементов ===
Размер: 5
Верхний элемент: 50

```

### Tree

**Пример использования**

```cpp
#include <iostream>
#include <string>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание пустого дерева
  s21::RBTree<int, std::string> tree;
  std::cout << "=== Создание пустого дерева ===" << std::endl;
  std::cout << "Размер: " << tree.size() << std::endl << std::endl;

  // Вставка элементов
  std::cout << "=== Вставка элементов ===" << std::endl;
  tree.insert(5, "Apple");
  tree.insert(3, "Banana");
  tree.insert(7, "Cherry");
  tree.insert(2, "Date");
  tree.insert(4, "Elderberry");
  std::cout << "Добавлено 5 элементов" << std::endl;
  std::cout << "Размер: " << tree.size() << std::endl << std::endl;

  // Поиск элементов
  std::cout << "=== Поиск элементов ===" << std::endl;
  std::cout << "Ключ 3: " << tree.find(3)->second << std::endl;
  std::cout << "Ключ 7: " << tree.get(7).second << std::endl << std::endl;

  // Обход дерева
  std::cout << "=== Обход дерева ===" << std::endl;
  for (const auto& pair : tree) {
    std::cout << "{" << pair.first << ": " << pair.second << "} ";
  }
  std::cout << std::endl << std::endl;

  // Удаление элемента
  std::cout << "=== Удаление элемента ===" << std::endl;
  tree.remove(5);
  std::cout << "Удален элемент с ключом 5" << std::endl;
  std::cout << "Размер: " << tree.size() << std::endl << std::endl;

  // Проверка наличия элементов
  std::cout << "=== Проверка наличия элементов ===" << std::endl;
  std::cout << "Содержит ключ 5: " << (tree.contains(5) ? "Да" : "Нет")
            << std::endl;
  std::cout << "Содержит ключ 4: " << (tree.contains(4) ? "Да" : "Нет")
            << std::endl
            << std::endl;

  // Создание дерева через initializer_list
  std::cout << "=== Создание дерева через initializer_list ===" << std::endl;
  s21::RBTree<int, std::string> new_tree = {
      {10, "Fig"}, {8, "Grape"}, {12, "Honeydew"}};
  std::cout << "Размер нового дерева: " << new_tree.size() << std::endl
            << std::endl;

  // Объединение деревьев
  std::cout << "=== Объединение деревьев ===" << std::endl;
  tree.merge(new_tree);
  std::cout << "Объединенный размер: " << tree.size() << std::endl << std::endl;

  // Вывод элементов после объединения
  std::cout << "=== Элементы после объединения ===" << std::endl;
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    std::cout << "{" << it->first << ": " << it->second << "} ";
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание пустого дерева ===
Размер: 0

=== Вставка элементов ===
Добавлено 5 элементов
Размер: 5

=== Поиск элементов ===
Ключ 3: Banana
Ключ 7: Cherry

=== Обход дерева ===
{2: Date} {3: Banana} {4: Elderberry} {5: Apple} {7: Cherry} 

=== Удаление элемента ===
Удален элемент с ключом 5
Размер: 4

=== Проверка наличия элементов ===
Содержит ключ 5: Нет
Содержит ключ 4: Да

=== Создание дерева через initializer_list ===
Размер нового дерева: 3

=== Объединение деревьев ===
Объединенный размер: 7

=== Элементы после объединения ===
{2: Date} {3: Banana} {4: Elderberry} {5: Apple} {8: Grape} {10: Fig} {12: Honeydew} 

```

### Vector

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание вектора через initializer_list
  s21::vector<int> myVector = {5, 10, 15};
  std::cout << "=== Создание вектора через initializer_list ===" << std::endl;
  std::cout << "Размер: " << myVector.size() << std::endl;
  std::cout << "Емкость: " << myVector.capacity() << std::endl << std::endl;

  // Добавление элементов
  std::cout << "=== Добавление элементов ===" << std::endl;
  myVector.push_back(20);
  myVector.push_back(25);
  std::cout << "После push_back: Размер: " << myVector.size()
            << ", Емкость: " << myVector.capacity() << std::endl
            << std::endl;

  // Доступ к элементам
  std::cout << "=== Доступ к элементам ===" << std::endl;
  std::cout << "Элемент [2]: " << myVector[2] << std::endl;
  std::cout << "Первый элемент: " << myVector.front() << std::endl;
  std::cout << "Последний элемент: " << myVector.back() << std::endl
            << std::endl;

  // Итерация по вектору
  std::cout << "=== Итерация по вектору ===" << std::endl;
  for (auto it = myVector.begin(); it != myVector.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl << std::endl;

  // Вставка элемента
  std::cout << "=== Вставка элемента ===" << std::endl;
  auto it = myVector.begin() + 3;
  myVector.insert(it, 99);
  std::cout << "После вставки: Размер: " << myVector.size()
            << ", Емкость: " << myVector.capacity() << std::endl;
  std::cout << "Содержимое: ";
  for (const auto& elem : myVector) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Удаление элемента
  std::cout << "=== Удаление элемента ===" << std::endl;
  myVector.pop_back();
  myVector.erase(myVector.begin() + 2);
  std::cout << "После удалений: Размер: " << myVector.size()
            << ", Емкость: " << myVector.capacity() << std::endl;
  std::cout << "Содержимое: ";
  for (const auto& elem : myVector) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Изменение емкости
  std::cout << "=== Изменение емкости ===" << std::endl;
  myVector.shrink_to_fit();
  std::cout << "После shrink_to_fit: Емкость: " << myVector.capacity()
            << std::endl;
  myVector.reserve(10);
  std::cout << "После reserve(10): Емкость: " << myVector.capacity()
            << std::endl
            << std::endl;

  // Вставка нескольких элементов
  std::cout << "=== Вставка нескольких элементов ===" << std::endl;
  myVector.insert_many(myVector.end(), 100, 200, 300);
  std::cout << "После insert_many: Размер: " << myVector.size()
            << ", Емкость: " << myVector.capacity() << std::endl;
  std::cout << "Содержимое: ";
  for (const auto& elem : myVector) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание вектора через initializer_list ===
Размер: 3
Емкость: 3

=== Добавление элементов ===
После push_back: Размер: 5, Емкость: 6

=== Доступ к элементам ===
Элемент [2]: 15
Первый элемент: 5
Последний элемент: 25

=== Итерация по вектору ===
5 10 15 20 25 

=== Вставка элемента ===
После вставки: Размер: 6, Емкость: 7
Содержимое: 5 10 15 99 20 25 

=== Удаление элемента ===
После удалений: Размер: 4, Емкость: 7
Содержимое: 5 10 99 20 

=== Изменение емкости ===
После shrink_to_fit: Емкость: 4
После reserve(10): Емкость: 10

=== Вставка нескольких элементов ===
После insert_many: Размер: 7, Емкость: 10
Содержимое: 5 10 99 20 100 200 300 

```

## Part 2. Дополнительно. Реализация библиотеки s21_containersplus.h

### Array

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containersplus.h"

int main() {
  // Создание массива через initializer_list
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::cout << "=== Создание массива ===" << std::endl;
  std::cout << "Размер: " << arr.size() << std::endl;
  std::cout << "Первый элемент: " << arr.front() << std::endl;
  std::cout << "Последний элемент: " << arr.back() << std::endl << std::endl;

  // Доступ к элементам
  std::cout << "=== Доступ к элементам ===" << std::endl;
  std::cout << "Элемент [2]: " << arr[2] << std::endl;
  std::cout << "Элемент at(3): " << arr.at(3) << std::endl;
  try {
    std::cout << "Попытка доступа к элементу 10: ";
    std::cout << arr.at(10) << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Итерация по массиву
  std::cout << "=== Итерация по массиву ===" << std::endl;
  std::cout << "Элементы: ";
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl << std::endl;

  // Заполнение массива
  std::cout << "=== Заполнение массива ===" << std::endl;
  arr.fill(42);
  std::cout << "После fill(42): ";
  for (const auto& elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Обмен с другим массивом
  std::cout << "=== Обмен с другим массивом ===" << std::endl;
  s21::array<int, 5> other = {10, 20, 30, 40, 50};
  arr.swap(other);
  std::cout << "arr после swap: ";
  for (const auto& elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << "other после swap: ";
  for (const auto& elem : other) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << std::endl;

  // Проверка на пустоту и размер
  std::cout << "=== Проверка состояния ===" << std::endl;
  std::cout << "Массив пуст: " << (arr.empty() ? "да" : "нет") << std::endl;
  std::cout << "Максимальный размер: " << arr.max_size() << std::endl
            << std::endl;

  // Работа с пустым массивом
  std::cout << "=== Пустой массив ===" << std::endl;
  s21::array<int, 0> empty_arr;
  std::cout << "Размер: " << empty_arr.size() << std::endl;
  std::cout << "Пустой: " << (empty_arr.empty() ? "да" : "нет") << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание массива ===
Размер: 5
Первый элемент: 1
Последний элемент: 5

=== Доступ к элементам ===
Элемент [2]: 3
Элемент at(3): 4
Попытка доступа к элементу 10: Array Error: Index out of range

=== Итерация по массиву ===
Элементы: 1 2 3 4 5 

=== Заполнение массива ===
После fill(42): 42 42 42 42 42 

=== Обмен с другим массивом ===
arr после swap: 10 20 30 40 50 
other после swap: 42 42 42 42 42 

=== Проверка состояния ===
Массив пуст: нет
Максимальный размер: 5

=== Пустой массив ===
Размер: 0
Пустой: да

```

### Multiset

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containersplus.h"

int main() {
  // Создание multiset через initializer_list с дубликатами
  s21::multiset<int> ms = {3, 1, 4, 1, 5, 9, 2, 6, 5};
  std::cout << "=== Создание multiset ===" << std::endl;
  std::cout << "Размер: " << ms.size() << std::endl;
  std::cout << "Содержит 5: " << (ms.contains(5) ? "да" : "нет") << std::endl;
  std::cout << std::endl;

  // Вставка новых элементов
  std::cout << "=== Вставка элементов ===" << std::endl;
  ms.insert(7);
  ms.insert(3);  // Дубликат
  std::cout << "Новый размер: " << ms.size() << std::endl << std::endl;

  // Итерация по multiset
  std::cout << "=== Элементы в отсортированном порядке ===" << std::endl;
  std::cout << "Элементы: ";
  for (auto it = ms.begin(); it != ms.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl << std::endl;

  // Поиск и подсчет элементов
  std::cout << "=== Поиск элементов ===" << std::endl;
  std::cout << "Количество 1: " << ms.count(1) << std::endl;
  std::cout << "Количество 3: " << ms.count(3) << std::endl;
  auto it = ms.find(5);
  std::cout << "Найден 5: " << (it != ms.end() ? "да" : "нет") << std::endl;
  std::cout << std::endl;

  // Удаление элементов
  std::cout << "=== Удаление элементов ===" << std::endl;
  ms.erase(ms.find(1));
  std::cout << "Количество 1 после удаления: " << ms.count(1) << std::endl;
  std::cout << "Новый размер: " << ms.size() << std::endl << std::endl;

  // Объединение multiset
  std::cout << "=== Объединение multiset ===" << std::endl;
  s21::multiset<int> other = {2, 7, 15};
  ms.merge(other);
  std::cout << "Размер после merge: " << ms.size() << std::endl;
  std::cout << "Пуст ли другой контейнер: " << (other.empty() ? "да" : "нет")
            << std::endl
            << std::endl;

  // Использование bound методов
  std::cout << "=== Границы для значения 5 ===" << std::endl;
  auto low = ms.lower_bound(5);
  auto high = ms.upper_bound(5);
  std::cout << "Элементы от lower_bound до upper_bound: ";
  for (; low != high; ++low) std::cout << *low << " ";
  std::cout << std::endl << std::endl;

  // Вставка нескольких элементов
  std::cout << "=== Вставка нескольких элементов ===" << std::endl;
  ms.insert_many(8, 0, 3, 15);
  std::cout << "Количество 3: " << ms.count(3) << std::endl;
  std::cout << "Количество 15: " << ms.count(15) << std::endl << std::endl;

  // Очистка контейнера
  std::cout << "=== Очистка контейнера ===" << std::endl;
  ms.clear();
  std::cout << "Пустой: " << (ms.empty() ? "да" : "нет") << std::endl;
  std::cout << "Размер: " << ms.size() << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Создание multiset ===
Размер: 9
Содержит 5: да

=== Вставка элементов ===
Новый размер: 11

=== Элементы в отсортированном порядке ===
Элементы: 1 1 2 3 3 4 5 5 6 7 9 

=== Поиск элементов ===
Количество 1: 2
Количество 3: 2
Найден 5: да

=== Удаление элементов ===
Количество 1 после удаления: 1
Новый размер: 10

=== Объединение multiset ===
Размер после merge: 13
Пуст ли другой контейнер: да

=== Границы для значения 5 ===
Элементы от lower_bound до upper_bound: 5 5 

=== Вставка нескольких элементов ===
Количество 3: 3
Количество 15: 2

=== Очистка контейнера ===
Пустой: да
Размер: 0

```

## Part 3. Дополнительно. Реализация методов insert_many

- List
- Vector
- Queue
- Stack
- Map
- Set
- Multiset

### List insert_many

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание списка через initializer_list
  s21::list<int> mylist = {10, 20, 30};
  std::cout << "=== Начальный список ===" << std::endl;
  std::cout << "Элементы: ";
  for (const auto& elem : mylist) std::cout << elem << " ";
  std::cout << std::endl << std::endl;

  // Вставка нескольких элементов в середину
  std::cout << "=== Вставка в середину ===" << std::endl;
  auto it = mylist.insert_many(++mylist.begin(), 15, 25);
  std::cout << "Вставленные элементы: ";
  for (; it != mylist.end(); ++it) std::cout << *it << " ";
  std::cout << "\nСписок после вставки: ";
  for (const auto& elem : mylist) std::cout << elem << " ";
  std::cout << std::endl << std::endl;

  // Вставка в начало
  std::cout << "=== Вставка в начало ===" << std::endl;
  mylist.insert_many_front(5, 0);
  std::cout << "Список после вставки в начало: ";
  for (const auto& elem : mylist) std::cout << elem << " ";
  std::cout << std::endl << std::endl;

  // Вставка в конец
  std::cout << "=== Вставка в конец ===" << std::endl;
  mylist.insert_many_back(35, 40);
  std::cout << "Список после вставки в конец: ";
  for (const auto& elem : mylist) std::cout << elem << " ";
  std::cout << std::endl << std::endl;

  // Итоговые данные
  std::cout << "=== Итоговый список ===" << std::endl;
  std::cout << "Размер: " << mylist.size() << std::endl;
  std::cout << "Элементы: ";
  for (const auto& elem : mylist) std::cout << elem << " ";

  return 0;
}

```

**Результат работы программы**

```log
=== Начальный список ===
Элементы: 10 20 30 

=== Вставка в середину ===
Вставленные элементы: 15 25 20 30 
Список после вставки: 10 15 25 20 30 

=== Вставка в начало ===
Список после вставки в начало: 5 0 10 15 25 20 30 

=== Вставка в конец ===
Список после вставки в конец: 5 0 10 15 25 20 30 35 40 

=== Итоговый список ===
Размер: 9
Элементы: 5 0 10 15 25 20 30 35 40 
```

### Vector insert_many

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание вектора и заполнение начальными значениями
  s21::vector<int> vec = {10, 20, 30};

  // Вставка нескольких элементов в середину вектора
  auto it = vec.insert_many(vec.cbegin() + 1, 15, 25);
  std::cout << "Вставлены элементы 15 и 25 на позицию 1" << std::endl;

  // Добавление элементов в конец
  vec.insert_many_back(40, 50, 60);

  // Вывод элементов вектора
  std::cout << "Содержимое вектора: ";
  for (const auto& num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
Вставлены элементы 15 и 25 на позицию 1
Содержимое вектора: 10 15 25 20 30 40 50 60 

```

### Queue insert_many

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание очереди с начальными значениями
  s21::queue<int> q = {10, 20, 30};
  std::cout << "=== Исходная очередь ===" << std::endl;
  std::cout << "Размер: " << q.size() << std::endl;
  std::cout << "Первый элемент: " << q.front() << std::endl << std::endl;

  // Добавление нескольких элементов в конец
  q.insert_many_back(40, 50, 60);
  std::cout << "Добавлены элементы 40, 50, 60" << std::endl;

  // Вывод всех элементов очереди
  std::cout << "Содержимое очереди: ";
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Исходная очередь ===
Размер: 3
Первый элемент: 10

Добавлены элементы 40, 50, 60
Содержимое очереди: 10 20 30 40 50 60 

```

### Stack insert_many

**Пример использования**

```cpp
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание стека с начальными значениями
  s21::stack<int> s = {10, 20, 30};
  std::cout << "=== Исходный стек ===" << std::endl;
  std::cout << "Размер: " << s.size() << std::endl;
  std::cout << "Верхний элемент: " << s.top() << std::endl << std::endl;

  // Добавление нескольких элементов в конец (на вершину стека)
  s.insert_many_back(40, 50, 60);
  std::cout << "Добавлены элементы 40, 50, 60" << std::endl;

  // Вывод всех элементов стека
  std::cout << "Содержимое стека (LIFO порядок): ";
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Исходный стек ===
=== Исходный стек ===
Размер: 3
Верхний элемент: 30

Добавлены элементы 40, 50, 60
Содержимое стека (LIFO порядок): 60 50 40 30 20 10 

```

### Map insert_many

**Пример использования**

```cpp
#include <algorithm>
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание пустой map
  s21::map<int, std::string> m;

  // Вставка нескольких элементов с помощью insert_many
  std::cout << "=== Вставка нескольких элементов ===" << std::endl;
  auto results =
      m.insert_many(std::make_pair(1, "one"), std::make_pair(2, "two"),
                    std::make_pair(3, "three"), std::make_pair(1, "uno"));

  // Вывод результатов вставки
  std::cout << "Попыток вставки: " << results.size() << std::endl;
  std::cout << "Результаты (ключ : успешно):" << std::endl;
  for (const auto& [it, success] : results) {
    std::cout << it->first << " : " << (success ? "да" : "нет") << std::endl;
  }

  // Вывод всех элементов map
  std::cout << "\nСодержимое map:" << std::endl;
  for (const auto& [key, value] : m) {
    std::cout << key << " => " << value << std::endl;
  }

  // Проверка размера контейнера
  std::cout << "\nТекущий размер map: " << m.size() << std::endl;

  // Проверка наличия ключей
  std::cout << "Содержит ключ 3: " << (m.contains(3) ? "да" : "нет")
            << std::endl;
  std::cout << "Содержит ключ 6: " << (m.contains(6) ? "да" : "нет")
            << std::endl;

  // Попытка доступа к несуществующему ключу
  try {
    std::cout << "Значение ключа 4: " << m.at(4) << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << "Ошибка доступа: " << e.what() << std::endl;
  }

  // Вставка дополнительных элементов
  std::cout << "\n=== Дополнительная вставка ===" << std::endl;
  auto more_results =
      m.insert_many(std::make_pair(4, "four"), std::make_pair(5, "five"),
                    std::make_pair(2, "два"));

  std::cout << "Успешных вставок: "
            << std::count_if(more_results.begin(), more_results.end(),
                             [](const auto& p) { return p.second; })
            << std::endl;

  // Финальный вывод
  std::cout << "\nФинальное содержимое map:" << std::endl;
  for (const auto& [key, value] : m) {
    std::cout << key << " => " << value << std::endl;
  }

  return 0;
}

```

**Результат работы программы**

```log
=== Вставка нескольких элементов ===
Попыток вставки: 4
Результаты (ключ : успешно):
1 : да
2 : да
3 : да
1 : нет

Содержимое map:
1 => one
2 => two
3 => three

Текущий размер map: 3
Содержит ключ 3: да
Содержит ключ 6: нет
Значение ключа 4: Ошибка доступа: Key not found

=== Дополнительная вставка ===
Успешных вставок: 2

Финальное содержимое map:
1 => one
2 => two
3 => three
4 => four
5 => five

```

### Set insert_many

**Пример использования**

```cpp
#include <algorithm>
#include <iostream>

#include "lib_s21_containers/s21_containers.h"

int main() {
  // Создание пустого set
  s21::set<int> s;

  // Вставка нескольких элементов с помощью insert_many
  std::cout << "=== Вставка нескольких элементов ===" << std::endl;
  auto results = s.insert_many(5, 3, 10, 5, 7, 3);

  // Вывод результатов вставки
  std::cout << "Попыток вставки: " << results.size() << std::endl;
  std::cout << "Результаты (значение : успешно):" << std::endl;
  for (const auto& [it, success] : results) {
    std::cout << *it << " : " << (success ? "да" : "нет") << std::endl;
  }

  // Вывод всех элементов set
  std::cout << "\nСодержимое set: ";
  for (const auto& elem : s) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // Проверка наличия элементов
  std::cout << "\nПроверка наличия:" << std::endl;
  std::cout << "Содержит 7: " << (s.contains(7) ? "да" : "нет") << std::endl;
  std::cout << "Содержит 2: " << (s.contains(2) ? "да" : "нет") << std::endl;

  // Вставка дополнительных элементов
  std::cout << "\n=== Дополнительная вставка ===" << std::endl;
  auto more_results = s.insert_many(5, 8, 3, 12);

  std::cout << "Успешных вставок: "
            << std::count_if(more_results.begin(), more_results.end(),
                             [](const auto& p) { return p.second; })
            << std::endl;

  // Финальный вывод
  std::cout << "\nФинальное содержимое set: ";
  for (const auto& elem : s) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Вставка нескольких элементов ===
Попыток вставки: 6
Результаты (значение : успешно):
5 : да
3 : да
10 : да
5 : нет
7 : да
3 : нет

Содержимое set: 3 5 7 10 

Проверка наличия:
Содержит 7: да
Содержит 2: нет

=== Дополнительная вставка ===
Успешных вставок: 2

Финальное содержимое set: 3 5 7 8 10 12 

```

### Multiset insert_many

**Пример использования**

```cpp
#include <algorithm>
#include <iostream>

#include "lib_s21_containers/s21_containersplus.h"

int main() {
  // Создание пустого multiset
  s21::multiset<int> ms;

  // Вставка нескольких элементов с помощью insert_many
  std::cout << "=== Вставка нескольких элементов ===" << std::endl;
  auto results = ms.insert_many(5, 3, 10, 5, 7, 3);

  // Вывод результатов вставки
  std::cout << "Вставлено элементов: " << results.size() << std::endl;
  std::cout << "Результаты вставки (значение : успешно):" << std::endl;
  for (const auto& pair : results) {
    auto it = pair.first;
    std::cout << *it << " : " << (pair.second ? "да" : "нет") << std::endl;
  }

  // Вывод всех элементов multiset
  std::cout << "\nЭлементы multiset: ";
  for (const auto& elem : ms) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // Проверка количества элементов для дубликатов
  std::cout << "\nКоличество вхождений:" << std::endl;
  std::cout << "3: " << ms.count(3) << std::endl;
  std::cout << "5: " << ms.count(5) << std::endl;
  std::cout << "7: " << ms.count(7) << std::endl;

  // Вставка с дубликатами и новыми значениями
  std::cout << "\n=== Вставка дополнительных элементов ===" << std::endl;
  auto more_results = ms.insert_many(5, 8, 3, 12);

  std::cout << "Вставлено дополнительно: " << more_results.size() << std::endl;
  std::cout << "Обновленные элементы: ";
  for (const auto& elem : ms) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // Финальное количество элементов
  std::cout << "\nФинальное количество элементов: " << ms.size() << std::endl;

  return 0;
}

```

**Результат работы программы**

```log
=== Вставка нескольких элементов ===
Вставлено элементов: 6
Результаты вставки (значение : успешно):
5 : да
3 : да
10 : да
5 : да
7 : да
3 : да

Элементы multiset: 3 3 5 5 7 10 

Количество вхождений:
3: 2
5: 2
7: 1

=== Вставка дополнительных элементов ===
Вставлено дополнительно: 4
Обновленные элементы: 3 3 3 5 5 5 7 8 10 12 

Финальное количество элементов: 10

```