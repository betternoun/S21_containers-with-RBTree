/**
 * @file tree_node.tpp
 * @brief Реализация узла красно-черного дерева
 */

namespace s21 {

/**
 * @brief Узел красно-черного дерева
 * @details Содержит ключ, значение, цвет и указатели на родительский и дочерние
 * узлы
 *
 * @param k Ключ узла
 * @param v Значение узла
 * @param c Цвет узла (по умолчанию RED)
 */
template <typename Key, typename Value>
RBTree<Key, Value>::RBTreeNode::RBTreeNode(Key k, Value v, Color c)
    : key(k),
      value(v),
      pair(k, v),
      color(c),
      parent(nullptr),
      left(nullptr),
      right(nullptr) {}

}  // namespace s21
