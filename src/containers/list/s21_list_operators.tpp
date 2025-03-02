/**
 * @file s21_list_operators.tpp
 * @brief Реализация операторов для класса list
 */

namespace s21 {

/**
 * @brief Оператор присваивания копированием
 * @param other Копируемый список
 * @return Ссылка на текущий список
 */
template <typename T>
list<T>& list<T>::operator=(const list& other) {
  if (this != &other) {
    list temp(other);
    swap(temp);
  }
  return *this;
}

/**
 * @brief Оператор присваивания перемещением
 * @param other Перемещаемый список
 * @return Ссылка на текущий список
 */
template <typename T>
list<T>& list<T>::operator=(list&& other) noexcept {
  if (this != &other) {
    clear();
    head = other.head;
    tail = other.tail;
    size_ = other.size_;
    other.head = nullptr;
    other.tail = nullptr;
    other.size_ = 0;
  }
  return *this;
}

}  // namespace s21
