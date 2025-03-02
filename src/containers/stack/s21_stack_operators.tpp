/**
 * @file s21_stack_operators.tpp
 * @brief Реализация операторов для класса stack
 */

namespace s21 {

/**
 * @brief Оператор присваивания копированием
 * @param s Другой стек для копирования
 * @return Ссылка на текущий стек
 */
template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=(const stack &s) {
  if (this != &s) {
    container_ = s.container_;
  }
  return *this;
}

/**
 * @brief Оператор присваивания перемещением
 * @param s Другой стек для перемещения
 * @return Ссылка на текущий стек
 */
template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=(stack &&s) noexcept {
  if (this != &s) {
    container_ = std::move(s.container_);
  }
  return *this;
}

}  // namespace s21
