/**
 * @file s21_stack_modifiers.tpp
 * @brief Реализация методов модификации для класса stack
 */

namespace s21 {

/**
 * @brief Добавляет элемент в стек
 * @param value Значение для добавления
 */
template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
  container_.push_back(value);
}

/**
 * @brief Удаляет верхний элемент из стека
 * @throw std::out_of_range Если стек пуст
 */
template <class T, class Container>
void stack<T, Container>::pop() {
  if (container_.empty()) {
    throw std::out_of_range("Stack is empty");
  }
  container_.pop_back();
}

/**
 * @brief Обменивает содержимое двух стеков
 * @param s Другой стек для обмена
 */
template <class T, class Container>
void stack<T, Container>::swap(stack &s) noexcept {
  container_.swap(s.container_);
}

}  // namespace s21
