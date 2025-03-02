/**
 * @file s21_map_lookup.tpp
 * @brief Реализация методов поиска для класса map
 */

namespace s21 {

/**
 * @brief Находит элемент по ключу
 * @param key Ключ для поиска
 * @return Итератор на найденный элемент или end(), если элемент не найден
 */
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) {
  auto node = RBTree<Key, T>::find(key);
  return node != RBTree<Key, T>::end() ? iterator(node) : this->end();
}

/**
 * @brief Находит элемент по ключу (константная версия)
 * @param key Ключ для поиска
 * @return Константный итератор на найденный элемент или end(), если элемент не
 * найден
 */
template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::find(const Key &key) const {
  auto node = RBTree<Key, T>::find(key);
  return node != RBTree<Key, T>::end() ? const_iterator(node) : this->end();
}

/**
 * @brief Проверяет наличие элемента с заданным ключом
 * @param key Ключ для проверки
 * @return true, если элемент найден, иначе false
 */
template <typename Key, typename T>
bool map<Key, T>::contains(const Key &key) const {
  return RBTree<Key, T>::contains(key);
}

}  // namespace s21
