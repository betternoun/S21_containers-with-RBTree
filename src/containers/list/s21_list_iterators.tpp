/**
 * @file s21_list_iterators.tpp
 * @brief Реализация итераторов для класса list
 */

namespace s21 {

/**
 * @brief Конструктор итератора
 * @param node Указатель на узел списка
 */
template <typename T>
list<T>::ListIterator::ListIterator(pointer node) : node(node) {}

/**
 * @brief Оператор разыменования итератора
 * @return Ссылка на данные текущего узла
 */
template <typename T>
typename list<T>::ListIterator::reference list<T>::ListIterator::operator*() {
  return node->data;
}

/**
 * @brief Префиксный инкремент итератора
 * @return Ссылка на текущий итератор
 */
template <typename T>
typename list<T>::ListIterator& list<T>::ListIterator::operator++() {
  node = node->next;
  return *this;
}

/**
 * @brief Постфиксный инкремент итератора
 * @return Копия итератора до инкремента
 */
template <typename T>
typename list<T>::ListIterator list<T>::ListIterator::operator++(int) {
  ListIterator tmp = *this;
  node = node->next;
  return tmp;
}

/**
 * @brief Префиксный декремент итератора
 * @return Ссылка на текущий итератор
 * @throw std::out_of_range если итератор указывает на nullptr
 */
template <typename T>
typename list<T>::ListIterator& list<T>::ListIterator::operator--() {
  if (node) {
    node = node->prev;
  } else {
    throw std::out_of_range("Cannot decrement end iterator");
  }
  return *this;
}

/**
 * @brief Оператор сравнения на равенство
 * @param other Другой итератор
 * @return true если итераторы равны, иначе false
 */
template <typename T>
bool list<T>::ListIterator::operator==(
    const ListIterator& other) const noexcept {
  return node == other.node;
}

/**
 * @brief Оператор сравнения на неравенство
 * @param other Другой итератор
 * @return true если итераторы не равны, иначе false
 */
template <typename T>
bool list<T>::ListIterator::operator!=(
    const ListIterator& other) const noexcept {
  return node != other.node;
}

/**
 * @brief Проверяет, принадлежит ли итератор текущему списку
 * @param list Список, для которого проверяется принадлежность
 * @return true, если итератор принадлежит списку, иначе false
 */
template <typename T>
bool list<T>::ListIterator::is_valid(const list& list) const {
  ListNode* current = list.head;
  while (current) {
    if (current == node) {
      return true;
    }
    current = current->next;
  }
  return false;
}

/**
 * @brief Конструктор константного итератора
 * @param node Указатель на узел списка
 */
template <typename T>
list<T>::ListConstIterator::ListConstIterator(pointer node) : node(node) {}

/**
 * @brief Конструктор константного итератора из обычного итератора
 * @param other Обычный итератор
 */
template <typename T>
list<T>::ListConstIterator::ListConstIterator(const ListIterator& other)
    : node(other.node) {}

/**
 * @brief Оператор разыменования константного итератора
 * @return Константная ссылка на данные текущего узла
 */
template <typename T>
typename list<T>::ListConstIterator::reference
list<T>::ListConstIterator::operator*() const {
  return node->data;
}

/**
 * @brief Префиксный инкремент константного итератора
 * @return Ссылка на текущий константный итератор
 */
template <typename T>
typename list<T>::ListConstIterator& list<T>::ListConstIterator::operator++() {
  node = node->next;
  return *this;
}

/**
 * @brief Постфиксный инкремент константного итератора
 * @return Копия константного итератора до инкремента
 */
template <typename T>
typename list<T>::ListConstIterator list<T>::ListConstIterator::operator++(
    int) {
  ListConstIterator tmp = *this;
  node = node->next;
  return tmp;
}

/**
 * @brief Префиксный декремент константного итератора
 * @return Ссылка на текущий константный итератор
 * @throw std::out_of_range если итератор указывает на nullptr
 */
template <typename T>
typename list<T>::ListConstIterator& list<T>::ListConstIterator::operator--() {
  if (node) {
    node = node->prev;
  } else {
    throw std::out_of_range("Cannot decrement end iterator");
  }
  return *this;
}

/**
 * @brief Оператор сравнения на равенство для константных итераторов
 * @param other Другой константный итератор
 * @return true если итераторы равны, иначе false
 */
template <typename T>
bool list<T>::ListConstIterator::operator==(
    const ListConstIterator& other) const noexcept {
  return node == other.node;
}

/**
 * @brief Оператор сравнения на неравенство для константных итераторов
 * @param other Другой константный итератор
 * @return true если итераторы не равны, иначе false
 */
template <typename T>
bool list<T>::ListConstIterator::operator!=(
    const ListConstIterator& other) const noexcept {
  return node != other.node;
}

/**
 * @brief Проверяет, принадлежит ли константный итератор текущему списку
 * @param list Список, для которого проверяется принадлежность
 * @return true, если итератор принадлежит списку, иначе false
 */
template <typename T>
bool list<T>::ListConstIterator::is_valid(const list& list) const {
  const ListNode* current = list.head;
  while (current) {
    if (current == node) return true;
    current = current->next;
  }
  return false;
}

/**
 * @brief Возвращает итератор на начало списка
 * @return Итератор на первый элемент
 */
template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(head);
}

/**
 * @brief Возвращает итератор на конец списка
 * @return Итератор, указывающий на позицию после последнего элемента
 */
template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(nullptr);
}

/**
 * @brief Возвращает константный итератор на начало списка
 * @return Константный итератор на первый элемент
 */
template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return const_iterator(head);
}

/**
 * @brief Возвращает константный итератор на конец списка
 * @return Константный итератор, указывающий на позицию после последнего
 * элемента
 */
template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return const_iterator(nullptr);
}

/**
 * @brief Возвращает константный итератор на начало списка
 * @return Константный итератор на первый элемент
 */
template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(head);
}

/**
 * @brief Возвращает константный итератор на конец списка
 * @return Константный итератор, указывающий на позицию после последнего
 * элемента
 */
template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(nullptr);
}

}  // namespace s21
