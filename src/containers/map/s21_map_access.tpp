/**
 * @file s21_map_access.tpp
 * @brief Реализация методов доступа к элементам для класса map
 */

namespace s21 {

/**
 * @brief Возвращает ссылку на значение по ключу с проверкой
 * @param key Ключ элемента
 * @return Ссылка на значение
 * @throw std::out_of_range Если ключ не найден
 */
template <typename Key, typename T>
typename s21::map<Key, T>::mapped_type& s21::map<Key, T>::at(const Key& key) {
  typename RBTree<Key, T>::RBTreeNode* node = findNode(key);
  if (!node) throw std::out_of_range("Key not found");
  return node->value;
}

/**
 * @brief Доступ к элементу по ключу, добавляет элемент, если ключ не найден
 * @param key Ключ элемента
 * @return Ссылка на значение
 */
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  auto it = find(key);
  if (it == end()) {
    auto [inserted_it, success] = insert({key, T()});
    return inserted_it.iter_node_->value;
  }
  return it.iter_node_->value;
}

}  // namespace s21
