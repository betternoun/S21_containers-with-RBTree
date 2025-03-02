/**
 * @file s21_array_constructors.tpp
 * @brief Реализация конструкторов и операторов присваивания для класса array
 */

namespace s21 {

/**
 * @brief Конструктор со списком инициализации
 *
 * Инициализирует массив элементами из списка инициализации.
 * Если размер списка меньше N, оставшиеся элементы инициализируются значением
 * по умолчанию.
 *
 * @param items Список инициализации элементов
 * @throw std::out_of_range если размер списка превышает N
 */
template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  if (items.size() > N) {
    throw std::out_of_range(
        "Array Error: The initializer list exceeds the allowed size");
  }
  auto it = items.begin();
  for (size_type i = 0; i < items.size(); ++i) {
    elements_[i] = *it++;
  }

  for (size_type i = items.size(); i < N; ++i) {
    elements_[i] = T();
  }
}

/**
 * @brief Конструктор копирования
 *
 * Создает копию другого массива, копируя все его элементы.
 *
 * @param other Другой массив для копирования
 */
template <typename T, size_t N>
array<T, N>::array(const array &other) {
  for (size_type i = 0; i < N; ++i) {
    elements_[i] = other.elements_[i];
  }
}

/**
 * @brief Конструктор перемещения
 *
 * Перемещает элементы из другого массива в текущий.
 *
 * @param other Другой массив для перемещения
 */
template <typename T, size_t N>
array<T, N>::array(array &&other) noexcept {
  for (size_type i = 0; i < N; ++i) {
    elements_[i] = std::move(other.elements_[i]);
  }
}

/**
 * @brief Оператор присваивания перемещением
 *
 * Перемещает элементы из другого массива в текущий.
 *
 * @param other Другой массив для перемещения
 * @return Ссылка на текущий объект
 */
template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&other) noexcept {
  if (this != &other) {
    for (size_type i = 0; i < N; ++i) {
      elements_[i] = std::move(other.elements_[i]);
    }
  }
  return *this;
}

}  // namespace s21
