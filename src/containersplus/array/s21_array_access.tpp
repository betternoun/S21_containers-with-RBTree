/**
 * @file s21_array_access.tpp
 * @brief Реализация методов доступа к элементам для класса array
 */

namespace s21 {

/**
 * @brief Доступ к элементу с проверкой границ
 *
 * Возвращает ссылку на элемент по указанной позиции с проверкой выхода за
 * границы массива.
 *
 * @param pos Индекс элемента
 * @return Ссылка на элемент
 * @throw std::out_of_range если pos >= N
 */
template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Array Error: Index out of range");
  }
  return elements_[pos];
}

/**
 * @brief Оператор доступа к элементу (константный)
 *
 * Возвращает константную ссылку на элемент по указанной позиции без проверки
 * границ.
 *
 * @param pos Индекс элемента
 * @return Константная ссылка на элемент
 */
template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const {
  return elements_[pos];
}

/**
 * @brief Доступ к первому элементу
 *
 * Возвращает константную ссылку на первый элемент массива.
 *
 * @return Константная ссылка на первый элемент
 */
template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return elements_[0];
}

/**
 * @brief Доступ к последнему элементу
 *
 * Возвращает константную ссылку на последний элемент массива.
 *
 * @return Константная ссылка на последний элемент
 */
template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return elements_[N - 1];
}

/**
 * @brief Получение указателя на внутренний массив
 *
 * Возвращает указатель на начало внутреннего массива.
 *
 * @return Итератор (указатель) на начало массива
 */
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return elements_;
}

/**
 * @brief Константная версия метода at
 *
 * Возвращает константную ссылку на элемент по указанной позиции с проверкой
 * выхода за границы массива.
 *
 * @param pos Индекс элемента
 * @return Константная ссылка на элемент
 * @throw std::out_of_range если pos >= N
 */
template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("Array Error: Index out of range");
  }
  return elements_[pos];
}

/**
 * @brief Константная версия метода data
 *
 * Возвращает константный указатель на начало внутреннего массива.
 *
 * @return Константный итератор на начало массива
 */
template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::data() const {
  return elements_;
}

}  // namespace s21
