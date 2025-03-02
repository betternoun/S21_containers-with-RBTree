/**
 * @file s21_set_constructors.tpp
 * @brief Реализация конструкторов для класса set
 */

namespace s21 {

/**
 * @brief Конструктор множества из списка инициализации.
 *
 * @tparam Key Тип ключа.
 * @param items Список инициализации.
 */
template <typename Key>
set<Key>::set(const std::initializer_list<Key> &items) : Base() {
  for (const auto &item : items) {
    insert(item);
  }
}

/**
 * @brief Оператор перемещающего присваивания.
 *
 * @tparam Key Тип ключа.
 * @param other Другое множество для перемещения.
 * @return Ссылка на текущее множество.
 */
template <typename Key>
set<Key> &set<Key>::operator=(set<Key> &&other) noexcept {
  if (this != &other) {
    Base::operator=(std::move(other));
  }
  return *this;
}

/**
 * @brief Оператор копирующего присваивания.
 *
 * @tparam Key Тип ключа.
 * @param other Другое множество для копирования.
 * @return Ссылка на текущее множество.
 */
template <typename Key>
set<Key> &set<Key>::operator=(const set<Key> &other) {
  if (this != &other) {
    Base::operator=(other);
  }
  return *this;
}

}  // namespace s21
