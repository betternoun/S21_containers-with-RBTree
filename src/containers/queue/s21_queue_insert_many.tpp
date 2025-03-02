/**
 * @file s21_queue_insert_many.tpp
 * @brief Реализация метода insert_many для класса queue
 */

namespace s21 {

/**
 * @brief Добавляет несколько элементов в конец очереди
 * @tparam Args Типы аргументов
 * @param args Аргументы для добавления
 */
template <class T, class Container>
template <typename... Args>
void queue<T, Container>::insert_many_back(Args&&... args) {
  (push(std::forward<Args>(args)), ...);
}

}  // namespace s21
