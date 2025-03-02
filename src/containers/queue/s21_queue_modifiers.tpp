/**
 * @file s21_queue_modifiers.tpp
 * @brief Реализация методов модификации для класса queue
 */

namespace s21 {

/**
 * @brief Добавляет элемент в конец очереди
 * @param value Значение для добавления
 */
template <class T, class Container>
void queue<T, Container>::push(const_reference value) {
  container_.push_back(value);
}

/**
 * @brief Добавляет элемент в конец очереди (с перемещением)
 * @param value Значение для добавления
 */
template <class T, class Container>
void queue<T, Container>::push(value_type&& value) {
  container_.push_back(std::move(value));
}

/**
 * @brief Удаляет первый элемент очереди
 */
template <class T, class Container>
void queue<T, Container>::pop() {
  container_.pop_front();
}

/**
 * @brief Обменивает содержимое двух очередей
 * @param q Очередь для обмена
 */
template <class T, class Container>
void queue<T, Container>::swap(queue& q) noexcept {
  container_.swap(q.container_);
}

}  // namespace s21
