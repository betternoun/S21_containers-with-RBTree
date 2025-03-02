/**
 * @file s21_multiset_access.tpp
 * @brief Реализация методов доступа к элементам для класса multiset
 */

namespace s21 {

/**
 * @brief Возвращает количество элементов с заданным ключом
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param value искомое значение
 * @return typename multiset<T>::size_type количество элементов с заданным
 * ключом
 */
template <typename T>
typename multiset<T>::size_type multiset<T>::count(
    const key_type &value) const {
  auto it = map_.find(value);
  return it != map_.end() ? it.iter_node_->value
                          : 0;  // Возвращаем количество дубликатов или 0
}

/**
 * @brief Находит элемент с заданным ключом
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param key искомый ключ
 * @return typename multiset<T>::iterator итератор на найденный элемент или
 * end() если не найден
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::find(const key_type &key) {
  auto it = map_.find(key);
  return it != map_.end()
             ? iterator(it, 1)
             : end();  // Возвращаем итератор на первый дубликат или end()
}

/**
 * @brief Проверяет наличие элемента с заданным ключом
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param value искомое значение
 * @return true если элемент найден
 * @return false если элемент не найден
 */
template <typename T>
bool multiset<T>::contains(const key_type &value) const {
  return map_.contains(value);  // Делегируем проверку базовому дереву
}

/**
 * @brief Возвращает диапазон элементов с заданным ключом
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param key искомый ключ
 * @return std::pair<typename multiset<T>::iterator, typename
 * multiset<T>::iterator> пара итераторов, ограничивающих диапазон
 */
template <typename T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const key_type &key) {
  auto lower = lower_bound(key);  // Нижняя граница
  auto upper = upper_bound(key);  // Верхняя граница
  return {lower, upper};
}

/**
 * @brief Возвращает итератор на первый элемент, не меньший заданного ключа
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param key искомый ключ
 * @return typename multiset<T>::iterator итератор на найденный элемент или
 * end() если не найден
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const key_type &key) {
  auto it = begin();
  while (it != end() && *it < key) {
    ++it;  // Ищем первый элемент, не меньший key
  }
  return it;
}

/**
 * @brief Возвращает итератор на первый элемент, больший заданного ключа
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param key искомый ключ
 * @return typename multiset<T>::iterator итератор на найденный элемент или
 * end() если не найден
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const key_type &key) {
  auto it = begin();
  while (it != end() && *it <= key) {
    ++it;  // Ищем первый элемент, больший key
  }
  return it;
}

/**
 * @brief Возвращает диапазон константных итераторов с заданным ключом
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param key искомый ключ
 * @return std::pair<typename multiset<T>::const_iterator, typename
 * multiset<T>::const_iterator> пара константных итераторов, ограничивающих
 * диапазон
 */
template <typename T>
std::pair<typename multiset<T>::const_iterator,
          typename multiset<T>::const_iterator>
multiset<T>::equal_range(const key_type &key) const {
  auto lower = const_iterator(map_.find(key), 1);  // Нижняя граница
  auto it = lower;
  while (it != end() && *it == key) ++it;  // Ищем верхнюю границу
  return {lower, it};
}

/**
 * @brief Проверяет, пуст ли контейнер
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return true если контейнер пуст
 * @return false если контейнер содержит элементы
 */
template <typename T>
bool multiset<T>::empty() const {
  return copies_ == 0;  // Проверяем счетчик элементов
}

/**
 * @brief Возвращает количество элементов в контейнере
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::size_type количество элементов
 */
template <typename T>
typename multiset<T>::size_type multiset<T>::size() const {
  return copies_;  // Возвращаем счетчик элементов
}

/**
 * @brief Возвращает максимально возможное количество элементов
 *
 * @tparam T тип данных элементов в мультимножестве
 * @return typename multiset<T>::size_type максимальный размер контейнера
 */
template <typename T>
typename multiset<T>::size_type multiset<T>::max_size() const {
  return map_.max_size();  // Делегируем базовому дереву
}

}  // namespace s21
