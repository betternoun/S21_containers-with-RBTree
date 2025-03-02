/**
 * @file s21_list_capacity.tpp
 * @brief Реализация методов для работы с емкостью для класса list
 */

namespace s21 {

/**
 * @brief Проверяет, пуст ли список
 * @return true если список пуст, false в противном случае
 */
template <typename T>
[[nodiscard]] bool list<T>::empty() const noexcept {
  return size_ == 0;
}

/**
 * @brief Возвращает текущий размер списка
 * @return Количество элементов в списке
 */
template <typename T>
[[nodiscard]] typename list<T>::size_type list<T>::size() const noexcept {
  return size_;
}

/**
 * @brief Возвращает максимально возможный размер списка
 * @return Максимальное количество элементов, которое может содержать список
 */
template <typename T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max();
}

}  // namespace s21
