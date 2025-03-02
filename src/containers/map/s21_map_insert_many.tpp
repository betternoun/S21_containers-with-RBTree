/**
 * @file s21_map_insert_many.tpp
 * @brief Реализация метода insert_many для класса map
 */

namespace s21 {

/**
 * @brief Вставляет несколько элементов
 * @tparam Args Типы аргументов
 * @param args Аргументы для вставки
 * @return Вектор пар итератор и флаг успешности вставки
 */
template <typename Key, typename T>
template <class... Args>
s21::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args &&...args) {
  static_assert((std::is_constructible_v<value_type, Args> && ...),
                "All arguments must be convertible to value_type");
  s21::vector<std::pair<iterator, bool>> vec;
  (vec.push_back(insert(std::forward<Args>(args))), ...);
  return vec;
}

}  // namespace s21
