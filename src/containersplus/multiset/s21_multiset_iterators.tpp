/**
 * @file s21_multiset_iterators.tpp
 * @brief Реализация итераторов и методов доступа к итераторам для класса
 * multiset
 */

namespace s21 {

/**
 * @brief Возвращает итератор на начало контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::iterator итератор, указывающий на первый
 * элемент
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::begin() {
  return iterator(map_.begin(), 1);
}

/**
 * @brief Возвращает итератор на конец контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::iterator итератор, указывающий на позицию после
 * последнего элемента
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::end() {
  return iterator(map_.end(), 1);
}

/**
 * @brief Возвращает константный итератор на начало контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::const_iterator константный итератор,
 * указывающий на первый элемент
 */
template <typename T>
typename multiset<T>::const_iterator multiset<T>::cbegin() const {
  return const_iterator(map_.cbegin(), 1);
}

/**
 * @brief Возвращает константный итератор на конец контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::const_iterator константный итератор,
 * указывающий на позицию после последнего элемента
 */
template <typename T>
typename multiset<T>::const_iterator multiset<T>::cend() const {
  return const_iterator(map_.cend(), 1);
}

/**
 * @brief Возвращает константный итератор на начало контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::const_iterator константный итератор,
 * указывающий на первый элемент
 */
template <typename T>
typename multiset<T>::const_iterator multiset<T>::begin() const {
  return const_iterator(map_.cbegin(), 1);
}

/**
 * @brief Возвращает константный итератор на конец контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::const_iterator константный итератор,
 * указывающий на позицию после последнего элемента
 */
template <typename T>
typename multiset<T>::const_iterator multiset<T>::end() const {
  return const_iterator(map_.cend(), 1);
}

/**
 * @brief Оператор префиксного инкремента для итератора
 *
 * Перемещает итератор к следующему элементу в контейнере.
 * Если текущий индекс меньше количества дубликатов в узле, увеличивает индекс.
 * Иначе переходит к следующему узлу и сбрасывает индекс.
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::Iterator& ссылка на текущий итератор
 */
template <typename T>
typename multiset<T>::Iterator &multiset<T>::Iterator::operator++() {
  if (it_.iter_node_ == nullptr) return *this;

  if (index_ < it_.iter_node_->value) {
    ++index_;  // Увеличиваем индекс, если есть еще дубликаты в текущем узле
  } else {
    ++it_;       // Переходим к следующему узлу
    index_ = 1;  // Сбрасываем индекс
  }
  return *this;
}

/**
 * @brief Оператор префиксного декремента для итератора
 *
 * Перемещает итератор к предыдущему элементу в контейнере.
 * Если текущий индекс больше 1, уменьшает индекс.
 * Иначе переходит к предыдущему узлу и устанавливает индекс на последний
 * дубликат.
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::Iterator& ссылка на текущий итератор
 */
template <typename T>
typename multiset<T>::Iterator &multiset<T>::Iterator::operator--() {
  if (it_.iter_node_ == nullptr) {
    if (it_.past_node_ != nullptr) {
      it_.iter_node_ = it_.past_node_;
      index_ =
          it_.iter_node_->value;  // Устанавливаем индекс на последний дубликат
    }
    return *this;
  }

  if (index_ > 1) {
    --index_;  // Уменьшаем индекс, если не первый дубликат
  } else {
    --it_;  // Переходим к предыдущему узлу
    if (it_.iter_node_ != nullptr) {
      index_ =
          it_.iter_node_->value;  // Устанавливаем индекс на последний дубликат
    }
  }
  return *this;
}

/**
 * @brief Оператор постфиксного инкремента для итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::Iterator копия итератора до инкремента
 */
template <typename T>
typename multiset<T>::Iterator multiset<T>::Iterator::operator++(int) {
  Iterator tmp = *this;
  ++(*this);
  return tmp;
}

/**
 * @brief Оператор постфиксного декремента для итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::Iterator копия итератора до декремента
 */
template <typename T>
typename multiset<T>::Iterator multiset<T>::Iterator::operator--(int) {
  Iterator tmp = *this;
  --(*this);
  return tmp;
}

/**
 * @brief Оператор сравнения на равенство для итератора
 *
 * Итераторы равны, если они указывают на один и тот же узел и имеют одинаковый
 * индекс
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param other другой итератор для сравнения
 * @return true если итераторы равны
 * @return false если итераторы не равны
 */
template <typename T>
bool multiset<T>::Iterator::operator==(const Iterator &other) const {
  return it_.iter_node_ == other.it_.iter_node_ && index_ == other.index_;
}

/**
 * @brief Оператор сравнения на неравенство для итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param other другой итератор для сравнения
 * @return true если итераторы не равны
 * @return false если итераторы равны
 */
template <typename T>
bool multiset<T>::Iterator::operator!=(const Iterator &other) const {
  return !(*this == other);
}

/**
 * @brief Оператор префиксного инкремента для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::ConstIterator& ссылка на текущий константный
 * итератор
 */
template <typename T>
typename multiset<T>::ConstIterator &multiset<T>::ConstIterator::operator++() {
  if (index_ < (*it_).second)
    index_++;  // Увеличиваем индекс, если есть еще дубликаты
  else {
    ++it_;       // Переходим к следующему узлу
    index_ = 1;  // Сбрасываем индекс
  }
  return *this;
}

/**
 * @brief Оператор префиксного декремента для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::ConstIterator& ссылка на текущий константный
 * итератор
 */
template <typename T>
typename multiset<T>::ConstIterator &multiset<T>::ConstIterator::operator--() {
  if (index_ > 1) {
    index_--;  // Уменьшаем индекс, если не первый дубликат
  } else {
    --it_;  // Переходим к предыдущему узлу
    if (it_ != typename TreeType::const_iterator()) {
      index_ = (*it_).second;  // Устанавливаем индекс на последний дубликат
    }
  }
  return *this;
}

/**
 * @brief Оператор постфиксного инкремента для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::ConstIterator копия итератора до инкремента
 */
template <typename T>
typename multiset<T>::ConstIterator multiset<T>::ConstIterator::operator++(
    int) {
  ConstIterator tmp = *this;
  ++(*this);
  return tmp;
}

/**
 * @brief Оператор постфиксного декремента для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::ConstIterator копия итератора до декремента
 */
template <typename T>
typename multiset<T>::ConstIterator multiset<T>::ConstIterator::operator--(
    int) {
  ConstIterator tmp = *this;
  --(*this);
  return tmp;
}

/**
 * @brief Оператор сравнения на равенство для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param other другой константный итератор для сравнения
 * @return true если итераторы равны
 * @return false если итераторы не равны
 */
template <typename T>
bool multiset<T>::ConstIterator::operator==(const ConstIterator &other) const {
  return it_.iter_node_ == other.it_.iter_node_ && index_ == other.index_;
}

/**
 * @brief Оператор сравнения на неравенство для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param other другой константный итератор для сравнения
 * @return true если итераторы не равны
 * @return false если итераторы равны
 */
template <typename T>
bool multiset<T>::ConstIterator::operator!=(const ConstIterator &other) const {
  return !(*this == other);
}

/**
 * @brief Конструктор итератора из итератора базового дерева
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param it итератор базового дерева
 */
template <typename T>
multiset<T>::Iterator::Iterator(typename TreeType::Iterator it)
    : it_(it), index_(1) {}

/**
 * @brief Конструктор итератора из итератора базового дерева с указанием индекса
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param it итератор базового дерева
 * @param index индекс элемента в узле
 */
template <typename T>
multiset<T>::Iterator::Iterator(typename TreeType::Iterator it, size_type index)
    : it_(it), index_(index) {}

/**
 * @brief Оператор разыменования для итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::Iterator::value_type значение текущего элемента
 */
template <typename T>
typename multiset<T>::Iterator::value_type multiset<T>::Iterator::operator*() {
  return it_.iter_node_->key;
}

/**
 * @brief Конструктор константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param it константный итератор базового дерева
 * @param index индекс элемента в узле
 */
template <typename T>
multiset<T>::ConstIterator::ConstIterator(
    typename map<T, size_type>::const_iterator it, size_type index)
    : it_(it), index_(index) {}

/**
 * @brief Оператор разыменования для константного итератора
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return const typename multiset<T>::ConstIterator::value_type& константная
 * ссылка на текущий элемент
 */
template <typename T>
const typename multiset<T>::ConstIterator::value_type &
multiset<T>::ConstIterator::operator*() const {
  return this->it_.iter_node_->key;
}

}  // namespace s21
