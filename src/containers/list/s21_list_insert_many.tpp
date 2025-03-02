/**
 * @file s21_list_insert_many.tpp
 * @brief Реализация метода insert_many для класса list
 */

namespace s21 {

/**
 * @brief Вставляет произвольное количество элементов перед указанной позицией
 * @param pos Итератор на позицию вставки
 * @param args Аргументы для создания элементов
 * @return Итератор на первый вставленный элемент
 * @throw std::invalid_argument если итератор невалиден
 */
template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  if (pos.node != nullptr && !pos.is_valid(*this)) {
    throw std::invalid_argument("Iterator does not belong to this list");
  }
  list<T> temp;
  (temp.push_back(std::forward<Args>(args)), ...);
  if (temp.empty()) return iterator(const_cast<ListNode*>(pos.node));
  auto first = temp.begin();
  splice(pos, temp);
  temp.head = nullptr;
  return iterator(first.node);
}

/**
 * @brief Вставляет элементы в конец списка
 * @param args Аргументы для вставки
 */
template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args&&... args) {
  list<T> temp;
  (temp.push_back(std::forward<Args>(args)), ...);
  splice(cend(), temp);
}

/**
 * @brief Вставляет элементы в начало списка
 * @param args Аргументы для вставки
 */
template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args&&... args) {
  list<T> temp;
  (temp.push_back(std::forward<Args>(args)), ...);
  splice(cbegin(), temp);
}

}  // namespace s21
