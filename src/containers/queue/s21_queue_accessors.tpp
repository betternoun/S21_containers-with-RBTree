/**
 * @file s21_queue_accessors.tpp
 * @brief Реализация методов доступа к элементам для класса queue
 */

namespace s21 {

/**
 * @brief Возвращает ссылку на первый элемент очереди
 * @return Ссылка на первый элемент
 * @throw std::out_of_range Если очередь пуста
 */
template <class T, class Container>
typename queue<T, Container>::reference queue<T, Container>::front() {
  if (container_.empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return container_.front();
}

/**
 * @brief Возвращает константную ссылку на первый элемент очереди
 * @return Константная ссылка на первый элемент
 * @throw std::out_of_range Если очередь пуста
 */
template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::front()
    const {
  if (container_.empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return container_.front();
}

/**
 * @brief Возвращает ссылку на последний элемент очереди
 * @return Ссылка на последний элемент
 * @throw std::out_of_range Если очередь пуста
 */
template <class T, class Container>
typename queue<T, Container>::reference queue<T, Container>::back() {
  if (container_.empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return container_.back();
}

/**
 * @brief Возвращает константную ссылку на последний элемент очереди
 * @return Константная ссылка на последний элемент
 * @throw std::out_of_range Если очередь пуста
 */
template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::back()
    const {
  if (container_.empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return container_.back();
}

/**
 * @brief Проверяет, пуста ли очередь
 * @return true, если очередь пуста, иначе false
 */
template <class T, class Container>
bool queue<T, Container>::empty() const noexcept {
  return container_.empty();
}

/**
 * @brief Возвращает количество элементов в очереди
 * @return Количество элементов
 */
template <class T, class Container>
typename queue<T, Container>::size_type queue<T, Container>::size()
    const noexcept {
  return container_.size();
}

}  // namespace s21
