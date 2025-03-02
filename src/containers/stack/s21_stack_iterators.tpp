/**
 * @file s21_stack_iterators.tpp
 * @brief Реализация итераторов для класса stack
 */

namespace s21 {

/**
 * @brief Возвращает итератор на начало стека
 * @return Итератор на первый элемент
 */
template <class T, class Container>
typename stack<T, Container>::iterator stack<T, Container>::begin() {
  return container_.begin();
}

/**
 * @brief Возвращает итератор на конец стека
 * @return Итератор на элемент после последнего
 */
template <class T, class Container>
typename stack<T, Container>::iterator stack<T, Container>::end() {
  return container_.end();
}

/**
 * @brief Возвращает константный итератор на начало стека
 * @return Константный итератор на первый элемент
 */
template <class T, class Container>
typename stack<T, Container>::const_iterator stack<T, Container>::begin()
    const {
  return container_.begin();
}

/**
 * @brief Возвращает константный итератор на конец стека
 * @return Константный итератор на элемент после последнего
 */
template <class T, class Container>
typename stack<T, Container>::const_iterator stack<T, Container>::end() const {
  return container_.end();
}

}  // namespace s21
