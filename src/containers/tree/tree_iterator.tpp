/**
 * @file tree_iterator.tpp
 * @brief Реализация итераторов для класса RBTree
 */

namespace s21 {

/**
 * @brief Конструктор итератора по умолчанию
 * @details Создает итератор, указывающий на nullptr
 */
template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator()
    : iter_node_(nullptr), past_node_(nullptr) {}

/**
 * @brief Конструктор итератора
 * @param node Текущий узел
 * @param past Узел после последнего
 */
template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator(RBTreeNode *node, RBTreeNode *past)
    : iter_node_(node), past_node_(past) {}

/**
 * @brief Конструктор константного итератора по умолчанию
 * @details Создает константный итератор, вызывая конструктор базового класса
 * Iterator
 */
template <typename Key, typename Value>
RBTree<Key, Value>::ConstIterator::ConstIterator() : Iterator() {}

/**
 * @brief Конструктор константного итератора
 * @param node Текущий узел
 * @details Создает константный итератор для указанного узла
 */
template <typename Key, typename Value>
RBTree<Key, Value>::ConstIterator::ConstIterator(RBTreeNode *node)
    : Iterator(node) {}

/**
 * @brief Оператор инкремента префиксный
 * @return Ссылка на итератор
 * @details Перемещает итератор к следующему узлу в порядке возрастания ключей
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator &
RBTree<Key, Value>::Iterator::operator++() {
  if (iter_node_ == nullptr) return *this;

  if (iter_node_->right != nullptr) {
    iter_node_ = iter_node_->right;
    while (iter_node_->left != nullptr) {
      iter_node_ = iter_node_->left;
    }
  } else {
    RBTreeNode *parent = iter_node_->parent;
    while (parent != nullptr && iter_node_ == parent->right) {
      iter_node_ = parent;
      parent = parent->parent;
    }
    iter_node_ = parent;
  }
  return *this;
}

/**
 * @brief Оператор неравенства
 * @param other Другой итератор для сравнения
 * @return true если итераторы указывают на разные узлы, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator!=(const Iterator &other) const {
  return iter_node_ != other.iter_node_;
}

/**
 * @brief Оператор равенства
 * @param other Другой итератор для сравнения
 * @return true если итераторы указывают на один и тот же узел, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator==(const Iterator &other) const {
  return iter_node_ == other.iter_node_;
}

/**
 * @brief Оператор разыменования
 * @return Ссылка на пару ключ-значение текущего узла
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator::reference
RBTree<Key, Value>::Iterator::operator*() const {
  return iter_node_->pair;
}

/**
 * @brief Оператор инкремента постфиксный
 * @return Копия итератора до инкремента
 * @details Создает копию текущего итератора, затем перемещает текущий итератор
 * вперед
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::Iterator::operator++(
    int) {
  Iterator temp = *this;
  ++(*this);
  return temp;
}

/**
 * @brief Получить итератор на начало дерева
 * @return Итератор, указывающий на узел с минимальным ключом
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::begin() {
  return Iterator(GetMin(root), nullptr);
}

/**
 * @brief Получить итератор на конец дерева
 * @return Итератор, указывающий на позицию после последнего элемента (nullptr)
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator RBTree<Key, Value>::end() {
  return Iterator(nullptr, nullptr);
}

/**
 * @brief Получить константный итератор на начало дерева
 * @return Константный итератор, указывающий на узел с минимальным ключом
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::ConstIterator RBTree<Key, Value>::begin() const {
  return ConstIterator(GetMin(root));
}

/**
 * @brief Получить константный итератор на конец дерева
 * @return Константный итератор, указывающий на позицию после последнего
 * элемента (nullptr)
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::ConstIterator RBTree<Key, Value>::end() const {
  return ConstIterator(nullptr);
}

/**
 * @brief Оператор разыменования для константного итератора
 * @return Константная пара ключ-значение текущего узла
 */
template <typename Key, typename Value>
const std::pair<Key, Value> RBTree<Key, Value>::ConstIterator::operator*()
    const {
  return this->iter_node_->pair;
}

/**
 * @brief Оператор доступа к членам
 * @return Указатель на пару ключ-значение текущего узла
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::Iterator::pointer
RBTree<Key, Value>::Iterator::operator->() const {
  return &iter_node_->pair;
}

/**
 * @brief Оператор равенства для константного итератора
 * @param other Другой константный итератор для сравнения
 * @return true если итераторы указывают на один и тот же узел, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::ConstIterator::operator==(
    const ConstIterator &other) const {
  return this->iter_node_ == other.iter_node_;
}

// === Реализация методов SetIterator ===

/**
 * @brief Конструктор итератора множества
 * @param node Указатель на узел
 */
template <typename Key, typename Value>
RBTree<Key, Value>::SetIterator::SetIterator(pointer node) : node_(node) {}

/**
 * @brief Конструктор копирования итератора множества
 * @param other Другой итератор для копирования
 */
template <typename Key, typename Value>
RBTree<Key, Value>::SetIterator::SetIterator(const SetIterator &other)
    : node_(other.node_) {}

/**
 * @brief Оператор разыменования для итератора множества
 * @return Ссылка на ключ текущего узла
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetIterator::reference
RBTree<Key, Value>::SetIterator::operator*() const {
  return node_->key;
}

/**
 * @brief Оператор инкремента префиксный для итератора множества
 * @return Ссылка на итератор
 * @details Перемещает итератор к следующему узлу в порядке возрастания ключей
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetIterator &
RBTree<Key, Value>::SetIterator::operator++() {
  if (node_->right) {
    node_ = node_->right;
    while (node_->left) node_ = node_->left;
  } else {
    pointer parent = node_->parent;
    while (parent && node_ == parent->right) {
      node_ = parent;
      parent = parent->parent;
    }
    node_ = parent;
  }
  return *this;
}

/**
 * @brief Оператор равенства для итератора множества
 * @param other Другой итератор для сравнения
 * @return true если итераторы указывают на один и тот же узел, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::SetIterator::operator==(
    const SetIterator &other) const {
  return node_ == other.node_;
}

/**
 * @brief Оператор неравенства для итератора множества
 * @param other Другой итератор для сравнения
 * @return true если итераторы указывают на разные узлы, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::SetIterator::operator!=(
    const SetIterator &other) const {
  return !(*this == other);
}

// === Реализация методов SetConstIterator ===

/**
 * @brief Конструктор константного итератора множества
 * @param node Указатель на узел
 */
template <typename Key, typename Value>
RBTree<Key, Value>::SetConstIterator::SetConstIterator(pointer node)
    : node_(node) {}

/**
 * @brief Конструктор преобразования из обычного итератора множества
 * @param other Обычный итератор множества
 */
template <typename Key, typename Value>
RBTree<Key, Value>::SetConstIterator::SetConstIterator(const SetIterator &other)
    : node_(other.node_) {}

/**
 * @brief Оператор разыменования для константного итератора множества
 * @return Константная ссылка на ключ текущего узла
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetConstIterator::reference
RBTree<Key, Value>::SetConstIterator::operator*() const {
  return node_->key;
}

/**
 * @brief Оператор инкремента префиксный для константного итератора множества
 * @return Ссылка на итератор
 * @details Перемещает итератор к следующему узлу в порядке возрастания ключей
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetConstIterator &
RBTree<Key, Value>::SetConstIterator::operator++() {
  if (node_->right) {
    node_ = node_->right;
    while (node_->left) node_ = node_->left;
  } else {
    pointer parent = node_->parent;
    while (parent && node_ == parent->right) {
      node_ = parent;
      parent = parent->parent;
    }
    node_ = parent;
  }
  return *this;
}

/**
 * @brief Оператор равенства для константного итератора множества
 * @param other Другой константный итератор для сравнения
 * @return true если итераторы указывают на один и тот же узел, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::SetConstIterator::operator==(
    const SetConstIterator &other) const {
  return node_ == other.node_;
}

/**
 * @brief Оператор неравенства для константного итератора множества
 * @param other Другой константный итератор для сравнения
 * @return true если итераторы указывают на разные узлы, иначе false
 */
template <typename Key, typename Value>
bool RBTree<Key, Value>::SetConstIterator::operator!=(
    const SetConstIterator &other) const {
  return !(*this == other);
}

// === Реализация методов для работы с SetIterator ===

/**
 * @brief Получить итератор множества на начало дерева
 * @return Итератор множества, указывающий на узел с минимальным ключом
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetIterator RBTree<Key, Value>::set_begin() {
  return SetIterator(GetMin(root));
}

/**
 * @brief Получить итератор множества на конец дерева
 * @return Итератор множества, указывающий на позицию после последнего элемента
 * (nullptr)
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetIterator RBTree<Key, Value>::set_end() {
  return SetIterator(nullptr);
}

/**
 * @brief Получить константный итератор множества на начало дерева
 * @return Константный итератор множества, указывающий на узел с минимальным
 * ключом
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetConstIterator RBTree<Key, Value>::set_cbegin()
    const {
  return SetConstIterator(GetMin(root));
}

/**
 * @brief Получить константный итератор множества на конец дерева
 * @return Константный итератор множества, указывающий на позицию после
 * последнего элемента (nullptr)
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetConstIterator RBTree<Key, Value>::set_cend()
    const {
  return SetConstIterator(nullptr);
}

/**
 * @brief Найти элемент в дереве с использованием итератора множества
 * @param key Ключ для поиска
 * @return Итератор множества, указывающий на найденный элемент или set_end()
 * если элемент не найден
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::SetIterator RBTree<Key, Value>::set_find(
    const Key &key) {
  return SetIterator(findNode(key));
}

}  // namespace s21
