/**
 * @file s21_list_modifiers.tpp
 * @brief Реализация методов модификации для класса list
 */

namespace s21 {

/**
 * @brief Добавляет элемент в конец списка
 * @param value Значение для добавления
 */
template <typename T>
void list<T>::push_back(const_reference value) {
  ListNode* new_node = new ListNode(value, tail, nullptr);
  if (tail) {
    tail->next = new_node;
  } else {
    head = new_node;
  }
  tail = new_node;
  ++size_;
}

/**
 * @brief Добавляет элемент в конец списка (с перемещением)
 * @param value Перемещаемое значение
 */
template <typename T>
void list<T>::push_back(value_type&& value) {
  ListNode* new_node = new ListNode(std::move(value), tail, nullptr);
  if (tail) {
    tail->next = new_node;
  } else {
    head = new_node;
  }
  tail = new_node;
  ++size_;
}

/**
 * @brief Удаляет последний элемент
 * @throw std::out_of_range если список пуст
 */
template <typename T>
void list<T>::pop_back() {
  if (tail) {
    ListNode* to_delete = tail;
    tail = tail->prev;
    if (tail) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }
    delete to_delete;
    --size_;
  } else {
    throw std::out_of_range("List is empty");
  }
}

/**
 * @brief Добавляет элемент в начало списка
 * @param value Значение для добавления
 */
template <typename T>
void list<T>::push_front(const_reference value) {
  ListNode* new_node = new ListNode(value, nullptr, head);
  if (head) {
    head->prev = new_node;
  }
  head = new_node;
  ++size_;
}

/**
 * @brief Удаляет первый элемент
 * @throw std::out_of_range если список пуст
 */
template <typename T>
void list<T>::pop_front() {
  if (head) {
    ListNode* to_delete = head;
    head = head->next;
    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete to_delete;
    --size_;
  } else {
    throw std::out_of_range("List is empty");
  }
}

/**
 * @brief Вставляет элемент перед указанной позицией
 * @param pos Итератор на позицию вставки
 * @param value Вставляемое значение
 * @return Итератор на вставленный элемент
 * @throw std::invalid_argument если итератор невалиден
 */
template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (!pos.is_valid(*this)) {
    throw std::invalid_argument(
        "Invalid iterator: does not belong to this list");
  }
  if (pos.node == head) {
    push_front(value);
    return begin();
  } else {
    ListNode* current = pos.node;
    ListNode* new_node = new ListNode(value, current->prev, current);
    current->prev->next = new_node;
    current->prev = new_node;
    ++size_;
    return iterator(new_node);
  }
}

/**
 * @brief Удаляет элемент в указанной позиции
 * @param pos Итератор на удаляемый элемент
 * @throw std::invalid_argument если итератор невалиден
 */
template <typename T>
void list<T>::erase(iterator pos) {
  if (!pos.is_valid(*this)) {
    throw std::invalid_argument(
        "Invalid iterator: does not belong to this list");
  }
  if (pos.node == head) {
    pop_front();
  } else if (pos.node == tail) {
    pop_back();
  } else if (pos.node != nullptr) {
    ListNode* current = pos.node;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --size_;
  }
}

/**
 * @brief Очищает список
 */
template <typename T>
void list<T>::clear() {
  while (head) {
    ListNode* to_delete = head;
    head = head->next;
    delete to_delete;
  }
  tail = nullptr;
  size_ = 0;
}

/**
 * @brief Обменивает содержимое с другим списком
 * @param other Список для обмена
 */
template <typename T>
void list<T>::swap(list& other) noexcept {
  std::swap(head, other.head);
  std::swap(tail, other.tail);
  std::swap(size_, other.size_);
}

}  // namespace s21
