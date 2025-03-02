/**
 * @file tree_utility.tpp
 * @brief Реализация утилитных функций для класса RBTree
 */

namespace s21 {

/**
 * @brief Получить значение по ключу
 * @param key Ключ для поиска
 * @return Константная ссылка на пару ключ-значение
 * @throw std::out_of_range Если ключ не найден
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::const_reference RBTree<Key, Value>::get(
    const Key& key) const {
  RBTreeNode* node = findNode(key);
  if (!node) throw std::out_of_range("Key not found");
  return node->pair;
}

/**
 * @brief Проверка на пустоту дерева
 * @return true если дерево пустое, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::empty() const noexcept {
  return tree_size == 0;
}

/**
 * @brief Получить количество элементов в дереве
 * @return Количество элементов
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::size()
    const noexcept {
  return tree_size;
}

/**
 * @brief Очистить дерево
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::clear() {
  deleteSubtree(root);
  root = nullptr;
  tree_size = 0;
}

/**
 * @brief Удалить поддерево
 * @param node Корень удаляемого поддерева
 * @details Рекурсивно удаляет все узлы в поддереве
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::deleteSubtree(RBTreeNode* node) {
  if (node) {
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
  }
}

/**
 * @brief Копировать узлы из одного дерева в другое
 * @param dest Узел назначения
 * @param src Исходный узел
 * @details Рекурсивно копирует все узлы из исходного дерева в дерево назначения
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::copyNodes(RBTreeNode* dest, RBTreeNode* src) {
  if (src == nullptr) return;

  if (src->left != nullptr) {
    dest->left =
        new RBTreeNode(src->left->key, src->left->value, src->left->color);
    dest->left->parent = dest;
    copyNodes(dest->left, src->left);
  }

  if (src->right != nullptr) {
    dest->right =
        new RBTreeNode(src->right->key, src->right->value, src->right->color);
    dest->right->parent = dest;
    copyNodes(dest->right, src->right);
  }
}

/**
 * @brief Обменять содержимое двух деревьев
 * @param other Дерево для обмена
 * @details Обменивает корни и размеры деревьев
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::swap(RBTree& other) noexcept {
  std::swap(root, other.root);
  std::swap(tree_size, other.tree_size);
}

/**
 * @brief Объединить два дерева
 * @param other Дерево для объединения
 * @details Переносит все элементы из другого дерева в текущее
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::merge(RBTree& other) {
  if (this != &other) {
    auto it = other.begin();
    while (it != other.end()) {
      auto current_pair = *it;
      insert(current_pair.first, current_pair.second);
      ++it;
    }
    other.clear();
  }
}

/**
 * @brief Проверка наличия ключа в дереве
 * @param key Ключ для поиска
 * @return true если ключ найден, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::contains(const Key& key) const {
  return findNode(key) != nullptr;
}

/**
 * @brief Найти элемент по ключу
 * @param key Ключ для поиска
 * @return Итератор на найденный элемент или end()
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::find(const Key& key) {
  RBTreeNode* node = findNode(key);
  return node ? Iterator(node) : end();
}

/**
 * @brief Найти элемент по ключу (константный)
 * @param key Ключ для поиска
 * @return Константный итератор на найденный элемент или cend()
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::ConstIterator RBTree<Key, Value>::find(
    const Key& key) const {
  return ConstIterator(findNode(key));
}

/**
 * @brief Максимальный размер дерева
 * @return Максимальное количество элементов
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::max_size()
    const noexcept {
  return std::numeric_limits<size_type>::max() /
         (std::is_same_v<Key, Value> ? sizeof(Key)
                                     : sizeof(std::pair<const Key, Value>));
}

}  // namespace s21
