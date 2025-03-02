/**
 * @file s21_set.h
 * @brief Заголовочный файл для класса set - реализации множества
 */

#ifndef S21_SET_H
#define S21_SET_H

namespace s21 {

/**
 * @brief Класс множества, реализованный на основе красно-черного дерева.
 *
 * @tparam Key Тип ключа.
 */
template <typename Key>
class set : public s21::RBTree<Key, Key> {
 public:
  using Base = s21::RBTree<Key, Key>;
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename Base::SetIterator;
  using const_iterator = typename Base::SetConstIterator;
  using size_type = size_t;

  /**
   * @brief Конструктор по умолчанию.
   */
  set() : Base() {}

  /**
   * @brief Конструктор из списка инициализации.
   *
   * @param items Список инициализации.
   */
  set(std::initializer_list<value_type> const &items);

  /**
   * @brief Конструктор копирования.
   *
   * @param other Другое множество для копирования.
   */
  set(const set &other) : Base(other) {}

  /**
   * @brief Конструктор перемещения.
   *
   * @param other Другое множество для перемещения.
   */
  set(set &&other) noexcept : Base(std::move(other)) {}

  /**
   * @brief Оператор перемещающего присваивания.
   *
   * @param other Другое множество для перемещения.
   * @return Ссылка на текущее множество.
   */
  set &operator=(set &&other) noexcept;

  /**
   * @brief Оператор копирующего присваивания.
   *
   * @param other Другое множество для копирования.
   * @return Ссылка на текущее множество.
   */
  set &operator=(const set &other);

  /**
   * @brief Деструктор.
   */
  ~set() = default;

  /**
   * @brief Возвращает итератор на начало множества.
   *
   * @return Итератор на начало.
   */
  iterator begin();

  /**
   * @brief Возвращает итератор на конец множества.
   *
   * @return Итератор на конец.
   */
  iterator end();

  /**
   * @brief Возвращает константный итератор на начало множества.
   *
   * @return Константный итератор на начало.
   */
  const_iterator cbegin() const;

  /**
   * @brief Возвращает константный итератор на конец множества.
   *
   * @return Константный итератор на конец.
   */
  const_iterator cend() const;

  /**
   * @brief Объединяет текущее множество с другим.
   *
   * @param other Другое множество для объединения.
   */
  void merge(set &other);

  /**
   * @brief Обменивает содержимое текущего множества с другим.
   *
   * @param other Другое множество для обмена.
   */
  void swap(set &other) noexcept;

  /**
   * @brief Вставляет элемент в множество.
   *
   * @param value Значение для вставки.
   * @return Пара из итератора на вставленный элемент и флага успешности.
   */
  std::pair<iterator, bool> insert(const value_type &value);

  /**
   * @brief Вставляет несколько элементов в множество.
   *
   * @tparam Args Типы аргументов.
   * @param args Аргументы для вставки.
   * @return Вектор пар из итераторов на вставленные элементы и флагов
   * успешности.
   */
  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  /**
   * @brief Удаляет элемент из множества по итератору.
   *
   * @param pos Итератор на элемент для удаления.
   */
  void erase(iterator pos);

  /**
   * @brief Ищет элемент в множестве.
   *
   * @param key Ключ для поиска.
   * @return Итератор на найденный элемент или на конец, если элемент не найден.
   */
  iterator find(const Key &key);

  /**
   * @brief Проверяет, содержится ли элемент в множестве.
   *
   * @param key Ключ для проверки.
   * @return true, если элемент содержится в множестве, иначе false.
   */
  bool contains(const Key &key) const;

  /**
   * @brief Возвращает максимальный возможный размер множества.
   *
   * @return Максимальный размер.
   */
  size_type max_size() const;

  /**
   * @brief Проверяет, пусто ли множество.
   *
   * @return true, если множество пусто, иначе false.
   */
  bool empty() const;

  /**
   * @brief Возвращает количество элементов в множестве.
   *
   * @return Количество элементов.
   */
  size_type size() const;

  /**
   * @brief Очищает множество.
   */
  void clear();
};

}  // namespace s21

// clang-format off
#include "./s21_set_constructors.tpp"
#include "./s21_set_accessors.tpp"
#include "./s21_set_modifiers.tpp"
#include "./s21_set_insert_many.tpp"
// clang-format on

#endif  // S21_SET_H
