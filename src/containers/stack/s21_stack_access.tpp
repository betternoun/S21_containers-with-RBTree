/**
 * @file s21_stack_access.tpp
 * @brief Реализация методов доступа к элементам для класса stack
 */

namespace s21 {

/**
 * @brief Возвращает верхний элемент стека
 * @return Константная ссылка на верхний элемент
 * @throw std::out_of_range Если стек пуст
 */
template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
  if (container_.empty()) {
    throw std::out_of_range("Stack is empty");
  }
  return container_.back();
}

/**
 * @brief Проверяет, пуст ли стек
 * @return true, если стек пуст, иначе false
 */
template <class T, class Container>
bool stack<T, Container>::empty() const noexcept {
  return container_.empty();
}

/**
 * @brief Возвращает количество элементов в стеке
 * @return Количество элементов
 */
template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size()
    const noexcept {
  return container_.size();
}

}  // namespace s21
