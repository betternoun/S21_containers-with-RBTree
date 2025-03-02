/**
 * @file tree_operations.tpp
 * @brief Реализация операций для класса RBTree
 */

namespace s21 {

/**
 * @brief Получить корень дерева
 * @return Указатель на корневой узел дерева
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::RBTreeNode* RBTree<Key, Value>::GetRoot() const {
  return root;
}

/**
 * @brief Выполнить левый поворот вокруг указанного узла
 * @param node Узел, вокруг которого выполняется поворот
 * @details Перестраивает связи между узлами для поддержания свойств
 * красно-черного дерева
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::leftRotate(RBTreeNode* node) {
  RBTreeNode* y = node->right;
  node->right = y->left;
  if (y->left != nullptr) {
    y->left->parent = node;
  }
  y->parent = node->parent;
  if (node->parent == nullptr) {
    root = y;
  } else if (node == node->parent->left) {
    node->parent->left = y;
  } else {
    node->parent->right = y;
  }
  y->left = node;
  node->parent = y;
}

/**
 * @brief Правый поворот вокруг узла
 * @param node Узел для поворота
 * @details Перестраивает связи между узлами для поддержания свойств
 * красно-черного дерева
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::rightRotate(RBTreeNode* node) {
  RBTreeNode* leftChild = node->left;
  node->left = leftChild->right;

  if (leftChild->right != nullptr) {
    leftChild->right->parent = node;
  }

  leftChild->parent = node->parent;

  if (node->parent == nullptr) {
    root = leftChild;
  } else if (node == node->parent->right) {
    node->parent->right = leftChild;
  } else {
    node->parent->left = leftChild;
  }

  leftChild->right = node;
  node->parent = leftChild;
}

/**
 * @brief Исправление свойств красно-черного дерева после вставки
 * @param node Узел, с которого начинается исправление
 * @details Восстанавливает свойства красно-черного дерева после вставки нового
 * узла
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::insertFixup(RBTreeNode* node) {
  while (node->parent != nullptr && node->parent->color == RED) {
    if (node->parent == node->parent->parent->left) {
      RBTreeNode* uncle = node->parent->parent->right;
      if (uncle != nullptr && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          node = node->parent;
          leftRotate(node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        rightRotate(node->parent->parent);
      }
    } else {
      RBTreeNode* uncle = node->parent->parent->left;
      if (uncle != nullptr && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        leftRotate(node->parent->parent);
      }
    }
  }
  root->color = BLACK;
}

/**
 * @brief Вставка элемента в дерево
 * @param key Ключ для вставки
 * @param value Значение для вставки
 * @details Вставляет новый узел и восстанавливает свойства красно-черного
 * дерева
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::insert(const Key& key, const Value& value) {
  if (contains(key)) return;
  RBTreeNode* newNode = new RBTreeNode(key, value, RED);
  RBTreeNode* parent = nullptr;
  RBTreeNode* current = root;

  while (current != nullptr) {
    parent = current;
    if (newNode->key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  newNode->parent = parent;
  if (parent == nullptr) {
    root = newNode;
  } else if (newNode->key < parent->key) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }

  insertFixup(newNode);
  tree_size++;
}

/**
 * @brief Удаление элемента из дерева
 * @param key Ключ элемента для удаления
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::remove(const Key& key) {
  RBTreeNode* node = findNode(key);
  if (!node) return;

  root = RecursiveDelete(root, key);
  if (root) {
    root->parent = nullptr;
    root->color = BLACK;
  }
}

/**
 * @brief Найти узел по ключу
 * @param key Ключ для поиска
 * @return Указатель на найденный узел или nullptr, если узел не найден
 * @details Выполняет бинарный поиск по дереву
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::RBTreeNode* RBTree<Key, Value>::findNode(
    const Key& key) const {
  RBTreeNode* current = root;
  while (current) {
    if (key < current->key) {
      current = current->left;
    } else if (key > current->key) {
      current = current->right;
    } else {
      return current;
    }
  }
  return nullptr;
}

/**
 * @brief Получить минимальный узел в поддереве
 * @param node Корень поддерева
 * @return Указатель на узел с минимальным ключом
 * @details Идет по левым потомкам до конца
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::RBTreeNode* RBTree<Key, Value>::GetMin(
    RBTreeNode* node) const {
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return node;
}

/**
 * @brief Рекурсивное удаление узла по ключу
 * @param node Текущий узел
 * @param key Ключ для удаления
 * @return Указатель на новый корень поддерева после удаления
 * @details Выполняет рекурсивный поиск и удаление узла, сохраняя свойства
 * дерева
 */
template <typename Key, typename Value>
typename RBTree<Key, Value>::RBTreeNode* RBTree<Key, Value>::RecursiveDelete(
    RBTreeNode* node, const Key& key) {
  if (node == nullptr) return nullptr;

  if (key < node->key) {
    node->left = RecursiveDelete(node->left, key);
    if (node->left) node->left->parent = node;
  } else if (key > node->key) {
    node->right = RecursiveDelete(node->right, key);
    if (node->right) node->right->parent = node;
  } else {
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      --tree_size;
      return nullptr;
    } else if (node->left == nullptr) {
      RBTreeNode* temp = node->right;
      if (temp) temp->parent = node->parent;
      delete node;
      --tree_size;
      return temp;
    } else if (node->right == nullptr) {
      RBTreeNode* temp = node->left;
      if (temp) temp->parent = node->parent;
      delete node;
      --tree_size;
      return temp;
    }

    RBTreeNode* successor = GetMin(node->right);
    node->key = successor->key;
    node->value = successor->value;
    node->right = RecursiveDelete(node->right, successor->key);
    if (node->right) node->right->parent = node;
  }

  return node;
}

/**
 * @brief Исправление двойного черного узла
 * @param parent Родительский узел
 * @param isLeftChild Флаг, указывающий является ли узел левым потомком
 * @details Восстанавливает свойства красно-черного дерева после удаления узла
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::fixDoubleBlack(RBTreeNode* parent, bool isLeftChild) {
  RBTreeNode* sibling = isLeftChild ? parent->right : parent->left;
  if (!sibling) return;

  if (sibling->color == RED) {
    parent->color = RED;
    sibling->color = BLACK;
    isLeftChild ? leftRotate(parent) : rightRotate(parent);
    fixDoubleBlack(parent, isLeftChild);
  } else {
    bool hasRedChild = (sibling->left && sibling->left->color == RED) ||
                       (sibling->right && sibling->right->color == RED);

    if (hasRedChild) {
      handleRedSiblingChild(parent, isLeftChild, sibling);
    } else {
      sibling->color = RED;
      if (parent->color == BLACK && parent != root) {
        bool parentIsLeft = parent->parent->left == parent;
        fixDoubleBlack(parent->parent, parentIsLeft);
      }
      parent->color = BLACK;
    }
  }
}

/**
 * @brief Обработка красного потомка у брата узла
 * @param parent Родительский узел
 * @param isLeftChild Флаг, указывающий является ли узел левым потомком
 * @param sibling Братский узел
 * @details Выполняет необходимые повороты и перекрашивания для восстановления
 * свойств дерева
 */
template <typename Key, typename Value>
void RBTree<Key, Value>::handleRedSiblingChild(RBTreeNode* parent,
                                               bool isLeftChild,
                                               RBTreeNode* sibling) {
  if (isLeftChild) {
    if (sibling->right && sibling->right->color == RED) {
      sibling->right->color = BLACK;
      leftRotate(parent);
    } else {
      sibling->left->color = BLACK;
      rightRotate(sibling);
      leftRotate(parent);
    }
  } else {
    if (sibling->left && sibling->left->color == RED) {
      sibling->left->color = BLACK;
      rightRotate(parent);
    } else {
      sibling->right->color = BLACK;
      leftRotate(sibling);
      rightRotate(parent);
    }
  }
  sibling->color = parent->color;
  parent->color = BLACK;
}

}  // namespace s21
