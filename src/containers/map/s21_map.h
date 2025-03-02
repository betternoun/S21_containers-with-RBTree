/**
 * @file s21_map.h
 * @brief Заголовочный файл для класса map - реализации ассоциативного
 * контейнера
 */

#ifndef S21_MAP_H
#define S21_MAP_H

namespace s21 {

/**
 * @brief Класс map, реализующий ассоциативный контейнер с уникальными ключами
 * @tparam Key Тип ключа
 * @tparam T Тип значения
 */
template <typename Key, typename T>
class map : public s21::RBTree<Key, T> {
 public:
  class MapIterator;
  class ConstMapIterator;

  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator;
  using const_iterator = ConstMapIterator;
  using size_type = size_t;

  using RBTree<Key, T>::findNode;
  using RBTreeNode = typename RBTree<Key, T>::RBTreeNode;

  /**
   * @brief Конструктор по умолчанию
   */
  map() : s21::RBTree<Key, T>() {};

  /**
   * @brief Конструктор с инициализацией через список
   * @param items Список элементов для инициализации
   */
  map(std::initializer_list<value_type> const &items);

  /**
   * @brief Конструктор копирования
   * @param other Другой объект map для копирования
   */
  map(const map &other) : s21::RBTree<Key, T>(other) {};

  /**
   * @brief Конструктор перемещения
   * @param other Другой объект map для перемещения
   */
  map(map &&other) noexcept : s21::RBTree<Key, T>(std::move(other)) {};

  /**
   * @brief Оператор присваивания перемещением
   * @param other Другой объект map для перемещения
   * @return Ссылка на текущий объект
   */
  map &operator=(map &&other) noexcept;

  /**
   * @brief Оператор присваивания копированием
   * @param other Другой объект map для копирования
   * @return Ссылка на текущий объект
   */
  map &operator=(const map &other);

  ~map() = default;

  /**
   * @brief Возвращает итератор на начало контейнера
   * @return Итератор на первый элемент
   */
  iterator begin();

  /**
   * @brief Возвращает итератор на конец контейнера
   * @return Итератор на элемент после последнего
   */
  iterator end();

  /**
   * @brief Объединяет два контейнера
   * @param other Другой контейнер для объединения
   */
  void merge(map &other);

  /**
   * @brief Обменивает содержимое двух контейнеров
   * @param other Другой контейнер для обмена
   */
  void swap(map &other) noexcept;

  /**
   * @brief Класс итератора для map
   */
  class MapIterator : public s21::RBTree<Key, T>::Iterator {
   public:
    friend class map;
    using RBTree = s21::RBTree<Key, T>;
    using RBTreeNode = typename RBTree::RBTreeNode;
    MapIterator() : s21::RBTree<Key, T>::Iterator() {}
    MapIterator(typename s21::RBTree<Key, T>::Iterator it)
        : s21::RBTree<Key, T>::Iterator(it) {}
    MapIterator(RBTreeNode *node, RBTreeNode *past_node)
        : RBTree::Iterator(node, past_node) {}

    /**
     * @brief Оператор разыменования итератора
     * @return Пара ключ-значение
     */
    value_type operator*() const;

    /**
     * @brief Оператор доступа к члену через указатель
     * @return Указатель на пару ключ-значение
     */
    value_type *operator->() const;

    /**
     * @brief Префиксный инкремент итератора
     * @return Ссылка на текущий итератор
     */
    MapIterator &operator++();

    /**
     * @brief Постфиксный инкремент итератора
     * @return Копия итератора до инкремента
     */
    MapIterator operator++(int);

    /**
     * @brief Сравнение итераторов на неравенство
     * @param other Другой итератор
     * @return true, если итераторы не равны, иначе false
     */
    bool operator!=(const MapIterator &other) const;

    /**
     * @brief Сравнение итераторов на равенство
     * @param other Другой итератор
     * @return true, если итераторы равны, иначе false
     */
    bool operator==(const MapIterator &other) const;
  };

  /**
   * @brief Класс константного итератора для map
   */
  class ConstMapIterator : public MapIterator {
   public:
    friend class map;
    using RBTree = s21::RBTree<Key, T>;
    using RBTreeNode = typename RBTree::RBTreeNode;
    ConstMapIterator() : MapIterator() {}
    ConstMapIterator(typename RBTree::ConstIterator it)
        : MapIterator(it.iter_node_, it.past_node_) {}

    /**
     * @brief Оператор разыменования константного итератора
     * @return Пара ключ-значение
     */
    value_type operator*() const;

    /**
     * @brief Сравнение константных итераторов на равенство
     * @param other Другой итератор
     * @return true, если итераторы равны, иначе false
     */
    bool operator==(const ConstMapIterator &other) const;
  };

  /**
   * @brief Доступ к элементу по ключу с проверкой
   * @param key Ключ элемента
   * @return Ссылка на значение
   * @throw std::out_of_range Если ключ не найден
   */
  T &at(const Key &key);

  /**
   * @brief Доступ к элементу по ключу
   * @param key Ключ элемента
   * @return Ссылка на значение
   */
  T &operator[](const Key &key);

  /**
   * @brief Вставляет элемент
   * @param value Пара ключ-значение для вставки
   * @return Пара итератор и флаг успешности вставки
   */
  std::pair<iterator, bool> insert(const value_type &value);

  /**
   * @brief Вставляет элемент
   * @param key Ключ для вставки
   * @param obj Значение для вставки
   * @return Пара итератор и флаг успешности вставки
   */
  std::pair<iterator, bool> insert(const Key &key, const T &obj);

  /**
   * @brief Вставляет элемент или обновляет существующий
   * @param key Ключ для вставки/обновления
   * @param obj Значение для вставки/обновления
   * @return Пара итератор и флаг успешности вставки
   */
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

  /**
   * @brief Вставляет несколько элементов
   * @tparam Args Типы аргументов
   * @param args Аргументы для вставки
   * @return Вектор пар итератор и флаг успешности вставки
   */
  template <class... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  /**
   * @brief Удаляет элемент по итератору
   * @param pos Итератор на удаляемый элемент
   */
  void erase(iterator pos);

  /**
   * @brief Находит элемент по ключу
   * @param key Ключ для поиска
   * @return Итератор на найденный элемент
   */
  iterator find(const Key &key);

  /**
   * @brief Находит элемент по ключу (константная версия)
   * @param key Ключ для поиска
   * @return Константный итератор на найденный элемент
   */
  const_iterator find(const Key &key) const;

  /**
   * @brief Возвращает константный итератор на начало контейнера
   * @return Константный итератор на первый элемент
   */
  const_iterator begin() const;

  /**
   * @brief Возвращает константный итератор на конец контейнера
   * @return Константный итератор на элемент после последнего
   */
  const_iterator end() const;

  /**
   * @brief Проверяет, пуст ли контейнер
   * @return true, если контейнер пуст, иначе false
   */
  bool empty() const noexcept;

  /**
   * @brief Возвращает количество элементов в контейнере
   * @return Количество элементов
   */
  size_type size() const noexcept;

  /**
   * @brief Возвращает максимальное количество элементов, которое может
   * содержать контейнер
   * @return Максимальное количество элементов
   */
  size_type max_size() const noexcept;

  /**
   * @brief Очищает контейнер
   */
  void clear() noexcept;

  /**
   * @brief Проверяет наличие элемента с заданным ключом
   * @param key Ключ для проверки
   * @return true, если элемент найден, иначе false
   */
  bool contains(const Key &key) const;
};

}  // namespace s21

// clang-format off
#include "./s21_map_constructors.tpp"
#include "./s21_map_iterators.tpp"
#include "./s21_map_modifiers.tpp"
#include "./s21_map_access.tpp"
#include "./s21_map_capacity.tpp"
#include "./s21_map_lookup.tpp"
#include "./s21_map_insert_many.tpp"
// clang-format on

#endif  // S21_MAP_H
