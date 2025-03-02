/**
 * @file s21_array_capacity.tpp
 * @brief Реализация методов для работы с емкостью для класса array
 */

namespace s21 {

/**
 * @brief Проверка, пуст ли контейнер
 *
 * Проверяет, является ли размер массива нулевым.
 *
 * @return true если N == 0, иначе false
 */
template <typename T, size_t N>
bool array<T, N>::empty() const {
  return N == 0;
}

/**
 * @brief Получение размера контейнера
 *
 * Возвращает количество элементов в массиве (N).
 *
 * @return Количество элементов (N)
 */
template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() const {
  return N;
}

/**
 * @brief Получение максимального размера контейнера
 *
 * Возвращает максимальное количество элементов, которое может содержать массив.
 * Для array это всегда равно N, так как размер фиксирован при компиляции.
 *
 * @return Максимальное количество элементов (N)
 */
template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const {
  return N;
}

}  // namespace s21
