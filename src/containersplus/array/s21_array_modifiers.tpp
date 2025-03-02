/**
 * @file s21_array_modifiers.tpp
 * @brief Реализация методов-модификаторов для класса array
 */

namespace s21 {

/**
 * @brief Обмен содержимым с другим массивом
 *
 * Обменивает содержимое текущего массива с другим массивом того же типа и
 * размера. Использует перемещение для эффективного обмена элементами.
 *
 * @param other Другой массив для обмена
 */
template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept {
  for (size_type i = 0; i < N; ++i) {
    T temp = std::move(elements_[i]);
    elements_[i] = std::move(other.elements_[i]);
    other.elements_[i] = std::move(temp);
  }
}

/**
 * @brief Заполнение массива заданным значением
 *
 * Заполняет все элементы массива указанным значением.
 *
 * @param value Значение для заполнения
 */
template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; ++i) {
    elements_[i] = value;
  }
}

}  // namespace s21
