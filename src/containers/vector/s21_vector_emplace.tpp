/**
 * @file s21_vector_emplace.tpp
 * @brief Реализация метода emplace для класса vector
 */

namespace s21 {

/**
 * @brief Конструирует элемент на месте в указанной позиции
 * @details Создает новый элемент непосредственно в памяти вектора, используя
 * perfect forwarding
 * @tparam Args Типы аргументов для конструирования элемента
 * @param[in] pos Итератор на позицию вставки
 * @param[in] args Аргументы для конструирования элемента
 * @return Итератор на вставленный элемент
 * @throw std::bad_alloc В случае ошибки выделения памяти
 * @throw Любые исключения, которые может выбросить конструктор элемента
 */
template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::emplace(const_iterator pos,
                                                Args&&... args) {
  return insert(iterator(pos.get_ptr()),
                value_type(std::forward<Args>(args)...));
}

/**
 * @brief Присваивает новые элементы вектору из диапазона
 * @details Заменяет содержимое вектора элементами из указанного диапазона
 * @tparam InputIt Тип итератора входного диапазона
 * @param[in] first Итератор на начало диапазона
 * @param[in] last Итератор на конец диапазона
 * @throw std::bad_alloc В случае ошибки выделения памяти
 * @throw Любые исключения, которые могут выбросить конструкторы копирования
 * элементов
 */
template <typename T>
template <typename InputIt>
void vector<T>::assign(InputIt first, InputIt last) {
  clear();
  for (auto it = first; it != last; ++it) {
    push_back(*it);
  }
}

}  // namespace s21
