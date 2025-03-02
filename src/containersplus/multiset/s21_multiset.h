/**
 * @file s21_multiset.h
 * @brief Заголовочный файл для класса multiset - реализации мультимножества
 */

#ifndef S21_MULTISET_H
#define S21_MULTISET_H

namespace s21 {

/**
 * @brief Контейнер multiset, реализующий мультимножество
 *
 * Мультимножество - это ассоциативный контейнер, который содержит
 * отсортированный набор объектов типа Key, при этом допускаются дубликаты
 * элементов. Внутренняя реализация основана на красно-черном дереве через
 * контейнер map.
 *
 * @tparam T тип данных элементов в мультимножестве
 */
template <typename T>
class multiset {
 public:
  class Iterator;
  class ConstIterator;

  /** @brief Тип ключа элемента */
  using key_type = T;
  /** @brief Тип значения элемента */
  using value_type = T;
  /** @brief Тип ссылки на значение */
  using reference = value_type &;
  /** @brief Тип константной ссылки на значение */
  using const_reference = const value_type &;
  /** @brief Тип итератора */
  using iterator = Iterator;
  /** @brief Тип константного итератора */
  using const_iterator = ConstIterator;
  /** @brief Тип для представления размера контейнера */
  using size_type = size_t;
  /** @brief Тип дерева, используемого для хранения элементов */
  using TreeType = s21::map<T, size_type>;
  /** @brief Тип узла красно-черного дерева */
  using RBTreeNode = typename TreeType::RBTreeNode;

  /**
   * @brief Конструктор по умолчанию
   *
   * Создает пустой контейнер multiset
   */
  multiset();

  /**
   * @brief Конструктор со списком инициализации
   *
   * @param items список элементов для инициализации
   */
  multiset(std::initializer_list<value_type> const &items);

  /**
   * @brief Конструктор копирования
   *
   * @param ms другой объект multiset для копирования
   */
  multiset(const multiset &ms);

  /**
   * @brief Конструктор перемещения
   *
   * @param ms другой объект multiset для перемещения
   */
  multiset(multiset &&ms) noexcept;

  /**
   * @brief Деструктор
   *
   * Освобождает все ресурсы, занятые контейнером
   */
  ~multiset() { clear(); }

  /**
   * @brief Оператор присваивания копированием
   *
   * @param other другой объект multiset для копирования
   * @return multiset& ссылка на текущий объект
   */
  multiset &operator=(const multiset &other);

  /**
   * @brief Оператор присваивания перемещением
   *
   * @param ms другой объект multiset для перемещения
   * @return multiset& ссылка на текущий объект
   */
  multiset &operator=(multiset &&ms) noexcept;

  /**
   * @brief Возвращает итератор на начало контейнера
   *
   * @return iterator итератор, указывающий на первый элемент
   */
  iterator begin();

  /**
   * @brief Возвращает итератор на конец контейнера
   *
   * @return iterator итератор, указывающий на позицию после последнего элемента
   */
  iterator end();

  /**
   * @brief Возвращает константный итератор на начало контейнера
   *
   * @return const_iterator константный итератор, указывающий на первый элемент
   */
  const_iterator cbegin() const;

  /**
   * @brief Возвращает константный итератор на конец контейнера
   *
   * @return const_iterator константный итератор, указывающий на позицию после
   * последнего элемента
   */
  const_iterator cend() const;

  /**
   * @brief Возвращает константный итератор на начало контейнера
   *
   * @return const_iterator константный итератор, указывающий на первый элемент
   */
  const_iterator begin() const;

  /**
   * @brief Возвращает константный итератор на конец контейнера
   *
   * @return const_iterator константный итератор, указывающий на позицию после
   * последнего элемента
   */
  const_iterator end() const;

  /**
   * @brief Проверяет, пуст ли контейнер
   *
   * @return true если контейнер пуст
   * @return false если контейнер содержит элементы
   */
  [[nodiscard]] bool empty() const;

  /**
   * @brief Возвращает количество элементов в контейнере
   *
   * @return size_type количество элементов
   */
  [[nodiscard]] size_type size() const;

  /**
   * @brief Возвращает максимально возможное количество элементов
   *
   * @return size_type максимальный размер контейнера
   */
  [[nodiscard]] size_type max_size() const;

  /**
   * @brief Удаляет все элементы из контейнера
   */
  void clear();

  /**
   * @brief Вставляет элемент в контейнер
   *
   * @param value значение для вставки
   * @return iterator итератор, указывающий на вставленный элемент
   */
  iterator insert(const value_type &value);

  /**
   * @brief Вспомогательный метод для вставки элемента
   *
   * @param value значение для вставки
   * @return iterator итератор, указывающий на вставленный элемент
   */
  iterator insert_(value_type value);

  /**
   * @brief Удаляет элемент из контейнера по итератору
   *
   * @param pos итератор, указывающий на удаляемый элемент
   */
  void erase(iterator pos);

  /**
   * @brief Обменивает содержимое с другим контейнером
   *
   * @param ms другой контейнер multiset
   */
  void swap(multiset &ms) noexcept;

  /**
   * @brief Объединяет текущий контейнер с другим
   *
   * @param ms другой контейнер multiset, который будет опустошен после операции
   */
  void merge(multiset &ms);

  /**
   * @brief Возвращает количество элементов с заданным ключом
   *
   * @param value искомое значение
   * @return size_type количество элементов
   */
  size_type count(const key_type &value) const;

  /**
   * @brief Находит элемент с заданным ключом
   *
   * @param key искомый ключ
   * @return iterator итератор на найденный элемент или end() если не найден
   */
  iterator find(const key_type &key);

  /**
   * @brief Проверяет наличие элемента с заданным ключом
   *
   * @param value искомое значение
   * @return true если элемент найден
   * @return false если элемент не найден
   */
  bool contains(const key_type &value) const;

  /**
   * @brief Возвращает диапазон элементов с заданным ключом
   *
   * @param key искомый ключ
   * @return std::pair<iterator, iterator> пара итераторов, ограничивающих
   * диапазон
   */
  std::pair<iterator, iterator> equal_range(const key_type &key);

  /**
   * @brief Возвращает итератор на первый элемент, не меньший заданного ключа
   *
   * @param key искомый ключ
   * @return iterator итератор на найденный элемент или end() если не найден
   */
  iterator lower_bound(const key_type &key);

  /**
   * @brief Возвращает итератор на первый элемент, больший заданного ключа
   *
   * @param key искомый ключ
   * @return iterator итератор на найденный элемент или end() если не найден
   */
  iterator upper_bound(const key_type &key);

  /**
   * @brief Вставляет несколько элементов в контейнер
   *
   * @tparam Args типы аргументов
   * @param args аргументы для вставки
   * @return vector<std::pair<iterator, bool>> вектор пар (итератор, успех
   * вставки)
   */
  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  /**
   * @brief Возвращает диапазон константных итераторов с заданным ключом
   *
   * @param key искомый ключ
   * @return std::pair<const_iterator, const_iterator> пара константных
   * итераторов
   */
  std::pair<const_iterator, const_iterator> equal_range(
      const key_type &key) const;

  /**
   * @brief Класс итератора для контейнера multiset
   *
   * Обеспечивает двунаправленный доступ к элементам контейнера
   */
  class Iterator {
   public:
    /** @brief Категория итератора */
    using iterator_category = std::bidirectional_iterator_tag;
    /** @brief Тип значения */
    using value_type = T;
    /** @brief Тип разности между итераторами */
    using difference_type = std::ptrdiff_t;
    /** @brief Тип указателя на итератор базового дерева */
    using pointer = typename TreeType::Iterator;
    /** @brief Тип ссылки на значение */
    using reference = T &;

    /** @brief Конструктор по умолчанию */
    Iterator() = default;

    /**
     * @brief Конструктор из итератора базового дерева
     *
     * @param it итератор базового дерева
     */
    explicit Iterator(typename TreeType::Iterator it);

    /**
     * @brief Конструктор из итератора базового дерева с указанием индекса
     *
     * @param it итератор базового дерева
     * @param index индекс элемента в узле
     */
    Iterator(typename TreeType::Iterator it, size_type index);

    /**
     * @brief Оператор разыменования
     *
     * @return value_type значение текущего элемента
     */
    value_type operator*();

    /**
     * @brief Оператор префиксного инкремента
     *
     * @return Iterator& ссылка на текущий итератор
     */
    Iterator &operator++();

    /**
     * @brief Оператор префиксного декремента
     *
     * @return Iterator& ссылка на текущий итератор
     */
    Iterator &operator--();

    /**
     * @brief Оператор постфиксного инкремента
     *
     * @return Iterator копия итератора до инкремента
     */
    Iterator operator++(int);

    /**
     * @brief Оператор постфиксного декремента
     *
     * @return Iterator копия итератора до декремента
     */
    Iterator operator--(int);

    /**
     * @brief Оператор сравнения на равенство
     *
     * @param other другой итератор для сравнения
     * @return true если итераторы равны
     * @return false если итераторы не равны
     */
    bool operator==(const Iterator &other) const;

    /**
     * @brief Оператор сравнения на неравенство
     *
     * @param other другой итератор для сравнения
     * @return true если итераторы не равны
     * @return false если итераторы равны
     */
    bool operator!=(const Iterator &other) const;

    /** @brief Итератор базового дерева */
    typename TreeType::Iterator it_;
    /** @brief Индекс текущего элемента в узле */
    size_type index_ = 1;
  };

 private:
  /** @brief Базовое дерево для хранения элементов */
  TreeType map_;
  /** @brief Общее количество элементов в контейнере */
  size_type copies_ = 0;
};

/**
 * @brief Класс константного итератора для контейнера multiset
 *
 * Обеспечивает двунаправленный доступ к элементам контейнера без возможности их
 * изменения
 *
 * @tparam T тип данных элементов в мультимножестве
 */
template <typename T>
class multiset<T>::ConstIterator {
 public:
  /** @brief Тип для представления размера */
  using size_type = multiset<T>::size_type;
  /** @brief Категория итератора */
  using iterator_category = std::bidirectional_iterator_tag;
  /** @brief Тип значения */
  using value_type = multiset<T>::key_type;
  /** @brief Тип разности между итераторами */
  using difference_type = std::ptrdiff_t;
  /** @brief Тип указателя на константный итератор базового дерева */
  using pointer = typename map<T, size_type>::const_iterator;
  /** @brief Тип ссылки на значение */
  using reference = T &;

  /**
   * @brief Конструктор из константного итератора базового дерева
   *
   * @param it константный итератор базового дерева
   * @param index индекс элемента в узле
   */
  explicit ConstIterator(typename map<T, size_type>::const_iterator it,
                         size_type index = 1);

  /**
   * @brief Оператор разыменования
   *
   * @return const value_type& константная ссылка на текущий элемент
   */
  const value_type &operator*() const;

  /**
   * @brief Оператор префиксного инкремента
   *
   * @return ConstIterator& ссылка на текущий итератор
   */
  ConstIterator &operator++();

  /**
   * @brief Оператор префиксного декремента
   *
   * @return ConstIterator& ссылка на текущий итератор
   */
  ConstIterator &operator--();

  /**
   * @brief Оператор постфиксного инкремента
   *
   * @return ConstIterator копия итератора до инкремента
   */
  ConstIterator operator++(int);

  /**
   * @brief Оператор постфиксного декремента
   *
   * @return ConstIterator копия итератора до декремента
   */
  ConstIterator operator--(int);

  /**
   * @brief Оператор сравнения на равенство
   *
   * @param other другой константный итератор для сравнения
   * @return true если итераторы равны
   * @return false если итераторы не равны
   */
  bool operator==(const ConstIterator &other) const;

  /**
   * @brief Оператор сравнения на неравенство
   *
   * @param other другой константный итератор для сравнения
   * @return true если итераторы не равны
   * @return false если итераторы равны
   */
  bool operator!=(const ConstIterator &other) const;

  /** @brief Константный итератор базового дерева */
  typename map<T, multiset<T>::size_type>::const_iterator it_;
  /** @brief Индекс текущего элемента в узле */
  size_type index_;
};

}  // namespace s21

// clang-format off
#include "s21_multiset_constructors.tpp"
#include "s21_multiset_iterators.tpp"
#include "s21_multiset_modifiers.tpp"
#include "s21_multiset_insert_many.tpp"
#include "s21_multiset_access.tpp"
// clang-format on

#endif  // S21_MULTISET_H
