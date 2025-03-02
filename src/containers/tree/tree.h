/**
 * @file tree.h
 * @brief Заголовочный файл для класса RBTree - реализации красно-черного дерева
 */

#ifndef TREE_H
#define TREE_H

namespace s21 {

/**
 * @brief Перечисление для цвета узла в красно-черном дереве
 */
enum Color { RED, BLACK };

/**
 * @brief Класс реализующий красно-черное дерево
 * @details Красно-черное дерево - это сбалансированное бинарное дерево поиска,
 * где каждый узел имеет цвет (красный или черный) и удовлетворяет определенным
 * свойствам:
 * 1. Корень всегда черный
 * 2. Все листья (NULL) считаются черными
 * 3. У красного узла оба потомка черные
 * 4. Все пути от корня до листьев содержат одинаковое количество черных узлов
 *
 * @tparam Key Тип ключа в дереве
 * @tparam Value Тип значения, хранимого в дереве
 */
template <typename Key, typename Value>
class RBTree {
 public:
  using value_type = std::pair<const Key, Value>;  ///< Тип пары ключ-значение
  using reference = value_type&;  ///< Ссылка на пару ключ-значение
  using const_reference =
      const value_type&;     ///< Константная ссылка на пару ключ-значение
  using size_type = size_t;  ///< Тип для размера дерева

  /**
   * @brief Структура узла красно-черного дерева
   * @details Каждый узел содержит ключ, значение, цвет и указатели на родителя
   * и потомков
   */
  struct RBTreeNode {
    Key key;             ///< Ключ узла
    Value value;         ///< Значение узла
    value_type pair;     ///< Пара ключ-значение
    Color color;         ///< Цвет узла (RED или BLACK)
    RBTreeNode* left;    ///< Указатель на левого потомка
    RBTreeNode* right;   ///< Указатель на правого потомка
    RBTreeNode* parent;  ///< Указатель на родительский узел

    /**
     * @brief Конструктор узла
     * @param k Ключ узла
     * @param v Значение узла
     * @param c Цвет узла (по умолчанию RED)
     */
    RBTreeNode(Key k, Value v, Color c = Color::RED);
  };

  RBTreeNode* root;  ///< Корневой узел дерева

  // === Конструкторы и деструктор ===

  /**
   * @brief Конструктор по умолчанию
   * @details Создает пустое дерево
   */
  RBTree();

  /**
   * @brief Конструктор с инициализатором списка
   * @param items Список пар ключ-значение для инициализации дерева
   */
  RBTree(std::initializer_list<value_type> const& items);

  /**
   * @brief Конструктор копирования
   * @param t Дерево для копирования
   */
  RBTree(const RBTree& t);

  /**
   * @brief Конструктор перемещения
   * @param t Дерево для перемещения
   */
  RBTree(RBTree&& t) noexcept;

  /**
   * @brief Виртуальный деструктор
   * @details Освобождает всю память, занятую деревом
   */
  virtual ~RBTree();

  // === Операторы присваивания ===

  /**
   * @brief Оператор присваивания перемещением
   * @param t Дерево для перемещения
   * @return Ссылка на текущее дерево
   */
  RBTree& operator=(RBTree&& t) noexcept;

  /**
   * @brief Оператор присваивания копированием
   * @param other Дерево для копирования
   * @return Ссылка на текущее дерево
   */
  RBTree& operator=(const RBTree& other);

  // === Итераторы ===

  /**
   * @brief Класс итератора для обхода дерева
   * @details Позволяет обходить дерево в порядке возрастания ключей
   */
  class Iterator {
   public:
    using value_type = std::pair<const Key, Value>;
    using pointer = value_type*;
    using reference = value_type&;

    Iterator();
    Iterator(RBTreeNode* node, RBTreeNode* past = nullptr);

    RBTreeNode* iter_node_;  ///< Текущий узел
    RBTreeNode* past_node_;  ///< Предыдущий узел

    Iterator& operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator& other) const;
    bool operator==(const Iterator& other) const;
    reference operator*() const;
    pointer operator->() const;
  };

  /**
   * @brief Класс константного итератора
   * @details Позволяет обходить дерево без возможности изменения элементов
   */
  class ConstIterator : public Iterator {
   public:
    ConstIterator();
    explicit ConstIterator(RBTreeNode* node);
    bool operator==(const ConstIterator& other) const;
    const std::pair<Key, Value> operator*() const;
  };

  // === Методы для работы с итераторами ===

  /**
   * @brief Получить итератор на начало дерева
   * @return Итератор, указывающий на узел с минимальным ключом
   */
  Iterator begin();

  /**
   * @brief Получить итератор на конец дерева
   * @return Итератор, указывающий на позицию после последнего элемента
   */
  Iterator end();

  /**
   * @brief Получить константный итератор на начало дерева
   * @return Константный итератор, указывающий на узел с минимальным ключом
   */
  ConstIterator begin() const;

  /**
   * @brief Получить константный итератор на конец дерева
   * @return Константный итератор, указывающий на позицию после последнего
   * элемента
   */
  ConstIterator end() const;

  /**
   * @brief Получить константный итератор на начало дерева
   * @return Константный итератор, указывающий на узел с минимальным ключом
   */
  ConstIterator cbegin() const;

  /**
   * @brief Получить константный итератор на конец дерева
   * @return Константный итератор, указывающий на позицию после последнего
   * элемента
   */
  ConstIterator cend() const;

  // === Методы модификации дерева ===

  /**
   * @brief Вставить элемент в дерево
   * @param key Ключ для вставки
   * @param value Значение для вставки
   * @details Если элемент с таким ключом уже существует, вставка не
   * производится
   */
  void insert(const Key& key, const Value& value);

  /**
   * @brief Удалить элемент из дерева
   * @param key Ключ элемента для удаления
   * @details Если элемент с таким ключом не найден, операция игнорируется
   */
  void remove(const Key& key);

  /**
   * @brief Очистить дерево
   * @details Удаляет все элементы из дерева и освобождает память
   */
  void clear();

  /**
   * @brief Обменять содержимое с другим деревом
   * @param other Дерево для обмена
   * @details Обменивает корни и размеры деревьев
   */
  void swap(RBTree& other) noexcept;

  /**
   * @brief Объединить с другим деревом
   * @param other Дерево для объединения
   * @details Переносит все элементы из другого дерева в текущее
   */
  void merge(RBTree& other);

  // === Методы доступа к элементам ===

  const_reference get(const Key& key) const;
  bool contains(const Key& key) const;
  Iterator find(const Key& key);
  ConstIterator find(const Key& key) const;

  // === Информационные методы ===

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // === Специальные итераторы для множества ===

  /**
   * @brief Итератор для работы с деревом как с множеством
   * @details Предоставляет доступ только к ключам дерева
   */
  class SetIterator {
   public:
    using pointer = RBTreeNode*;
    using reference = Key&;

    explicit SetIterator(pointer node = nullptr);
    SetIterator(const SetIterator& other);

    reference operator*() const;
    SetIterator& operator++();
    bool operator==(const SetIterator& other) const;
    bool operator!=(const SetIterator& other) const;

   private:
    pointer node_;
    friend class RBTree;
  };

  /**
   * @brief Константный итератор для работы с деревом как с множеством
   */
  class SetConstIterator {
   public:
    using pointer = const RBTreeNode*;
    using reference = const Key&;

    explicit SetConstIterator(pointer node = nullptr);
    SetConstIterator(const SetIterator& other);

    reference operator*() const;
    SetConstIterator& operator++();
    bool operator==(const SetConstIterator& other) const;
    bool operator!=(const SetConstIterator& other) const;

   private:
    pointer node_;
    friend class RBTree;
  };

  // === Методы для работы с множеством ===

  /**
   * @brief Получить итератор множества на начало дерева
   * @return Итератор множества, указывающий на узел с минимальным ключом
   */
  SetIterator set_begin();

  /**
   * @brief Получить итератор множества на конец дерева
   * @return Итератор множества, указывающий на позицию после последнего
   * элемента
   */
  SetIterator set_end();

  /**
   * @brief Получить константный итератор множества на начало дерева
   * @return Константный итератор множества, указывающий на узел с минимальным
   * ключом
   */
  SetConstIterator set_cbegin() const;

  /**
   * @brief Получить константный итератор множества на конец дерева
   * @return Константный итератор множества, указывающий на позицию после
   * последнего элемента
   */
  SetConstIterator set_cend() const;

  /**
   * @brief Найти элемент в дереве с использованием итератора множества
   * @param key Ключ для поиска
   * @return Итератор множества, указывающий на найденный элемент или set_end()
   * если элемент не найден
   */
  SetIterator set_find(const Key& key);

 protected:
  size_type tree_size;  ///< Количество узлов в дереве

  // === Вспомогательные методы ===

  /**
   * @brief Выполнить левый поворот вокруг узла
   * @param node Узел, вокруг которого выполняется поворот
   */
  void leftRotate(RBTreeNode* node);

  /**
   * @brief Выполнить правый поворот вокруг узла
   * @param node Узел, вокруг которого выполняется поворот
   */
  void rightRotate(RBTreeNode* node);

  /**
   * @brief Исправить нарушения свойств красно-черного дерева после вставки
   * @param node Узел, с которого начинается исправление
   */
  void insertFixup(RBTreeNode* node);

  /**
   * @brief Копировать узлы из одного дерева в другое
   * @param dest Узел назначения
   * @param src Исходный узел
   */
  void copyNodes(RBTreeNode* dest, RBTreeNode* src);

  /**
   * @brief Удалить поддерево
   * @param node Корень удаляемого поддерева
   */
  void deleteSubtree(RBTreeNode* node);

  /**
   * @brief Исправить случай двойного черного узла при удалении
   * @param parent Родительский узел
   * @param isLeftChild Флаг, указывающий является ли узел левым потомком
   */
  void fixDoubleBlack(RBTreeNode* parent, bool isLeftChild);

  /**
   * @brief Обработать случай красного потомка у брата узла
   * @param parent Родительский узел
   * @param isLeftChild Флаг, указывающий является ли узел левым потомком
   * @param sibling Братский узел
   */
  void handleRedSiblingChild(RBTreeNode* parent, bool isLeftChild,
                             RBTreeNode* sibling);

  /**
   * @brief Найти узел по ключу
   * @param key Ключ для поиска
   * @return Указатель на найденный узел или nullptr
   */
  RBTreeNode* findNode(const Key& key) const;

  /**
   * @brief Получить корень дерева
   * @return Указатель на корневой узел
   */
  RBTreeNode* GetRoot() const;

  /**
   * @brief Получить узел с минимальным ключом в поддереве
   * @param node Корень поддерева
   * @return Указатель на узел с минимальным ключом
   */
  RBTreeNode* GetMin(RBTreeNode* node) const;

  /**
   * @brief Получить узел с максимальным ключом в поддереве
   * @param node Корень поддерева
   * @return Указатель на узел с максимальным ключом
   */
  RBTreeNode* GetMax(RBTreeNode* node) const;

  /**
   * @brief Рекурсивно вставить узел в дерево
   * @param node Текущий узел
   * @param key Ключ для вставки
   * @param value Значение для вставки
   * @return true если вставка успешна, false если узел с таким ключом уже
   * существует
   */
  bool RecursiveInsert(RBTreeNode* node, const Key& key, const Value& value);

  /**
   * @brief Рекурсивно удалить узел
   * @param node Узел для удаления
   */
  void RecursiveDelete(RBTreeNode* node);

  /**
   * @brief Рекурсивно удалить узел по ключу
   * @param node Текущий узел
   * @param key Ключ для удаления
   * @return Указатель на новый корень поддерева
   */
  RBTreeNode* RecursiveDelete(RBTreeNode* node, const Key& key);

  friend class RBTreeTest;  ///< Для доступа к защищенным членам в тестах
};

}  // namespace s21

// clang-format off
#include "tree_node.tpp"
#include "tree_iterator.tpp"
#include "tree_operations.tpp"
#include "tree_constructors.tpp"
#include "tree_utility.tpp"
// clang-format on

#endif  // TREE_H
