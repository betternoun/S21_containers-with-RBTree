/**
 * @file s21_map_capacity.tpp
 * @brief Реализация методов для работы с емкостью для класса map
 */

namespace s21 {

/**
 * @brief Проверяет, пуст ли контейнер
 * @return true, если контейнер пуст, иначе false
 */
template <typename Key, typename T>
bool map<Key, T>::empty() const noexcept {
  return RBTree<Key, T>::empty();
}

/**
 * @brief Возвращает количество элементов в контейнере
 * @return Количество элементов
 */
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() const noexcept {
  return RBTree<Key, T>::size();
}

/**
 * @brief Возвращает максимальное количество элементов, которое может содержать
 * контейнер
 * @return Максимальное количество элементов
 */
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() const noexcept {
  return RBTree<Key, T>::max_size();
}

}  // namespace s21
