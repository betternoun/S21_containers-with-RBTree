/**
 * @file s21_array_iterators.tpp
 * @brief Реализация методов для работы с итераторами для класса array
 */

namespace s21 {

/**
 * @brief Получение итератора на начало контейнера
 *
 * Возвращает итератор, указывающий на первый элемент массива.
 *
 * @return Итератор на первый элемент
 */
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return elements_;
}

/**
 * @brief Получение итератора на конец контейнера
 *
 * Возвращает итератор, указывающий на позицию после последнего элемента
 * массива.
 *
 * @return Итератор на элемент за последним
 */
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return elements_ + N;
}

/**
 * @brief Получение константного итератора на начало контейнера
 *
 * Возвращает константный итератор, указывающий на первый элемент массива.
 *
 * @return Константный итератор на первый элемент
 */
template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::begin() const {
  return elements_;
}

/**
 * @brief Получение константного итератора на конец контейнера
 *
 * Возвращает константный итератор, указывающий на позицию после последнего
 * элемента массива.
 *
 * @return Константный итератор на элемент за последним
 */
template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::end() const {
  return elements_ + N;
}

}  // namespace s21
