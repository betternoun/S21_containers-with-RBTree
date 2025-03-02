/**
 * @file tree_constructors.tpp
 * @brief Реализация конструкторов для класса RBTree
 */

namespace s21 {

/**
 * @class RBTree
 * @brief Класс, представляющий красно-черное дерево.
 * @tparam Key Тип ключа.
 * @tparam Value Тип значения.
 */

/**
 * @brief Конструктор по умолчанию.
 * @details Инициализирует пустое дерево.
 */
template <typename Key, typename Value>
RBTree<Key, Value>::RBTree() : root(nullptr), tree_size(0) {}

/**
 * @brief Конструктор с инициализатором списка.
 * @param items Список пар ключ-значение для вставки.
 * @details Создает дерево и вставляет в него элементы из списка.
 */
template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(std::initializer_list<value_type> const& items)
    : RBTree() {
  for (const auto& item : items) {
    insert(item.first, item.second);
  }
}

/**
 * @brief Конструктор копирования.
 * @param t Дерево для копирования.
 * @details Создает копию переданного дерева.
 */
template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(const RBTree& t) : RBTree() {
  if (t.root != nullptr) {
    root = new RBTreeNode(t.root->key, t.root->value, t.root->color);
    copyNodes(root, t.root);
    tree_size = t.tree_size;
  }
}

/**
 * @brief Конструктор перемещения.
 * @param t Дерево для перемещения.
 * @details Перемещает данные из переданного дерева в новое дерево.
 */
template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(RBTree&& t) noexcept
    : root(t.root), tree_size(t.tree_size) {
  t.root = nullptr;
  t.tree_size = 0;
}

/**
 * @brief Деструктор.
 * @details Удаляет все узлы дерева и освобождает память.
 */
template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree() {
  if (root != nullptr) {
    RecursiveDelete(root);
    root = nullptr;
  }
}

/**
 * @brief Рекурсивное удаление узлов.
 * @param node Узел для удаления.
 * @details Удаляет все узлы, начиная с указанного.
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::RecursiveDelete(RBTreeNode* node) {
  if (node == nullptr) return;

  if (node->left) {
    RecursiveDelete(node->left);
    node->left = nullptr;
  }

  if (node->right) {
    RecursiveDelete(node->right);
    node->right = nullptr;
  }

  node->parent = nullptr;
  delete node;
  --tree_size;
}

/**
 * @brief Оператор присваивания перемещением.
 * @param t Дерево для перемещения.
 * @return Ссылка на текущее дерево.
 * @details Перемещает данные из переданного дерева в текущее дерево.
 */
template <typename Key, typename Value>
RBTree<Key, Value>& RBTree<Key, Value>::operator=(RBTree&& t) noexcept {
  if (this != &t) {
    clear();
    root = t.root;
    tree_size = t.tree_size;
    t.root = nullptr;
    t.tree_size = 0;
  }
  return *this;
}

/**
 * @brief Оператор присваивания копированием.
 * @param other Дерево для копирования.
 * @return Ссылка на текущее дерево.
 * @details Копирует данные из переданного дерева в текущее дерево.
 */
template <typename Key, typename Value>
RBTree<Key, Value>& RBTree<Key, Value>::operator=(const RBTree& other) {
  if (this != &other) {
    clear();
    if (other.root != nullptr) {
      root =
          new RBTreeNode(other.root->key, other.root->value, other.root->color);
      copyNodes(root, other.root);
      tree_size = other.tree_size;
    }
  }
  return *this;
}

/**
 * @brief Получить константный итератор на начало дерева.
 * @return Константный итератор.
 * @details Возвращает итератор на минимальный элемент дерева.
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::ConstIterator RBTree<Key, Value>::cbegin() const {
  return ConstIterator(GetMin(root));
}

/**
 * @brief Получить константный итератор на конец дерева.
 * @return Константный итератор.
 * @details Возвращает итератор на элемент, следующий за последним элементом
 * дерева.
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::ConstIterator RBTree<Key, Value>::cend() const {
  return ConstIterator(nullptr);
}

}  // namespace s21
