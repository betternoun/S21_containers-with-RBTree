/**
 * @file s21_list_algorithms.tpp
 * @brief Реализация алгоритмов для класса list
 */

namespace s21 {

/**
 * @brief Разворачивает список
 *
 * Меняет порядок элементов на противоположный
 */
template <typename T>
void list<T>::reverse() {
  ListNode* current = head;
  ListNode* temp = nullptr;
  while (current) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if (temp) {
    head = temp->prev;
  }
}

/**
 * @brief Удаляет последовательные дубликаты
 */
template <typename T>
void list<T>::unique() {
  if (head == nullptr) return;
  ListNode* current = head;
  while (current->next) {
    if (current->data == current->next->data) {
      ListNode* to_delete = current->next;
      current->next = current->next->next;
      if (current->next) {
        current->next->prev = current;
      } else {
        tail = current;
      }
      delete to_delete;
      --size_;
    } else {
      current = current->next;
    }
  }
}

/**
 * @brief Сортирует список
 */
template <typename T>
void list<T>::sort() {
  if (size_ < 2) return;
  head = mergeSort(head);
  tail = head;
  while (tail->next) {
    tail = tail->next;
  }
}

/**
 * @brief Объединяет два отсортированных списка
 * @param other Список для объединения
 */
template <typename T>
void list<T>::merge(list& other) {
  if (this != &other) {
    if (!other.empty()) {
      sort();
      other.sort();

      ListNode dummy = ListNode(T(), nullptr, nullptr);
      ListNode* current = &dummy;

      ListNode* l1 = head;
      ListNode* l2 = other.head;

      while (l1 && l2) {
        if (l1->data <= l2->data) {
          current->next = l1;
          l1->prev = current;
          l1 = l1->next;
        } else {
          current->next = l2;
          l2->prev = current;
          l2 = l2->next;
        }
        current = current->next;
      }

      current->next = l1 ? l1 : l2;
      if (current->next) {
        current->next->prev = current;
        tail = (l1 ? tail : other.tail);
      }

      head = dummy.next;
      head->prev = nullptr;

      size_ += other.size_;
      other.head = nullptr;
      other.tail = nullptr;
      other.size_ = 0;
    }
  }
}

/**
 * @brief Перемещает все элементы другого списка перед указанной позицией
 * @param pos Позиция вставки
 * @param other Список, элементы которого будут перемещены
 */
template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (this != &other && !other.empty()) {
    ListNode* insert_pos = const_cast<ListNode*>(pos.node);
    if (insert_pos) {
      if (insert_pos->prev) {
        insert_pos->prev->next = other.head;
        other.head->prev = insert_pos->prev;
      } else {
        head = other.head;
      }
      insert_pos->prev = other.tail;
      other.tail->next = insert_pos;
    } else {
      if (tail) {
        tail->next = other.head;
        other.head->prev = tail;
      } else {
        head = other.head;
      }
      tail = other.tail;
    }
    size_ += other.size_;
    other.head = nullptr;
    other.tail = nullptr;
    other.size_ = 0;
  }
}

/**
 * @brief Вспомогательный метод для сортировки слиянием
 * @param node Начальный узел для сортировки
 * @return Указатель на отсортированный список
 */
template <typename T>
typename list<T>::ListNode* list<T>::mergeSort(ListNode* node) {
  if (!node || !node->next) return node;

  ListNode* middle = getMiddle(node);
  ListNode* nextOfMiddle = middle->next;

  middle->next = nullptr;

  ListNode* left = mergeSort(node);
  ListNode* right = mergeSort(nextOfMiddle);

  return merge(left, right);
}

/**
 * @brief Находит середину списка
 * @param node Начальный узел
 * @return Указатель на средний узел
 */
template <typename T>
typename list<T>::ListNode* list<T>::getMiddle(ListNode* node) {
  if (!node) return node;

  ListNode* slow = node;
  ListNode* fast = node->next;

  while (fast) {
    fast = fast->next;
    if (fast) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  return slow;
}

/**
 * @brief Объединяет два отсортированных списка
 * @param left Первый список
 * @param right Второй список
 * @return Указатель на объединенный список
 */
template <typename T>
typename list<T>::ListNode* list<T>::merge(ListNode* left, ListNode* right) {
  if (!left) return right;
  if (!right) return left;

  if (left->data <= right->data) {
    left->next = merge(left->next, right);
    left->next->prev = left;
    left->prev = nullptr;
    return left;
  } else {
    right->next = merge(left, right->next);
    right->next->prev = right;
    right->prev = nullptr;
    return right;
  }
}

}  // namespace s21
