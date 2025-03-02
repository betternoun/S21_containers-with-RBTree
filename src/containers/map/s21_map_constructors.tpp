/**
 * @file s21_map_constructors.tpp
 * @brief Реализация конструкторов для класса map
 */

namespace s21 {

/**
 * @brief Конструктор с инициализацией через список
 * @param items Список элементов для инициализации
 */
template <typename Key, typename T>
map<Key, T>::map(const std::initializer_list<value_type> &items)
    : s21::RBTree<Key, T>() {
  for (const auto &item : items) {
    insert(item);
  }
}

/**
 * @brief Оператор присваивания перемещением
 * @param other Другой объект map для перемещения
 * @return Ссылка на текущий объект
 */
template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(map &&other) noexcept {
  if (this != &other) {
    s21::RBTree<Key, T>::operator=(std::move(other));
  }
  return *this;
}

/**
 * @brief Оператор присваивания копированием
 * @param other Другой объект map для копирования
 * @return Ссылка на текущий объект
 */
template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(const map &other) {
  if (this != &other) {
    s21::RBTree<Key, T>::operator=(other);
  }
  return *this;
}

}  // namespace s21
