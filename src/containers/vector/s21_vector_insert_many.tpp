/**
 * @file s21_vector_insert_many.tpp
 * @brief Реализация метода insert_many для класса vector
 */

namespace s21 {

/**
 * @brief Вставляет несколько элементов в указанную позицию
 * @details Вставляет произвольное количество элементов в вектор, используя
 * perfect forwarding
 * @tparam Args Типы аргументов для вставки
 * @param[in] pos Итератор на позицию вставки
 * @param[in] args Аргументы для вставки (элементы для добавления)
 * @return Итератор на первый вставленный элемент
 * @throw std::bad_alloc В случае ошибки выделения памяти
 * @throw Любые исключения, которые могут выбросить конструкторы копирования
 * элементов
 */
template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args&&... args) {
  size_type index = pos - cbegin();
  size_type insert_count = sizeof...(Args);

  if (size_ + insert_count > capacity_) {
    reserve((size_ + insert_count) * 2);
  }

  for (size_type i = size_ + insert_count - 1; i >= index + insert_count; --i) {
    data_[i] = std::move(data_[i - insert_count]);
  }

  size_type i = index;
  ((data_[i++] = std::forward<Args>(args)), ...);

  size_ += insert_count;
  return iterator(data_ + index);
}

/**
 * @brief Добавляет несколько элементов в конец вектора
 * @details Добавляет произвольное количество элементов в конец вектора,
 * используя perfect forwarding
 * @tparam Args Типы аргументов для добавления
 * @param[in] args Аргументы для добавления (элементы для добавления)
 * @throw std::bad_alloc В случае ошибки выделения памяти
 * @throw Любые исключения, которые могут выбросить конструкторы копирования
 * элементов
 */
template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args&&... args) {
  size_type insert_count = sizeof...(Args);

  if (size_ + insert_count > capacity_) {
    reserve((size_ + insert_count) * 2);
  }

  ((data_[size_++] = std::forward<Args>(args)), ...);
}

}  // namespace s21
