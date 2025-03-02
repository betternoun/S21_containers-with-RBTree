/**
 * @file s21_set_accessors.tpp
 * @brief Реализация методов доступа к элементам для класса set
 */

namespace s21 {

/**
 * @brief Возвращает итератор на начало множества.
 *
 * @tparam Key Тип ключа.
 * @return Итератор на начало.
 */
template <typename Key>
typename set<Key>::iterator set<Key>::begin() {
  return Base::set_begin();
}

/**
 * @brief Возвращает итератор на конец множества.
 *
 * @tparam Key Тип ключа.
 * @return Итератор на конец.
 */
template <typename Key>
typename set<Key>::iterator set<Key>::end() {
  return Base::set_end();
}

/**
 * @brief Возвращает константный итератор на начало множества.
 *
 * @tparam Key Тип ключа.
 * @return Константный итератор на начало.
 */
template <typename Key>
typename set<Key>::const_iterator set<Key>::cbegin() const {
  return Base::set_cbegin();
}

/**
 * @brief Возвращает константный итератор на конец множества.
 *
 * @tparam Key Тип ключа.
 * @return Константный итератор на конец.
 */
template <typename Key>
typename set<Key>::const_iterator set<Key>::cend() const {
  return Base::set_cend();
}

/**
 * @brief Объединяет текущее множество с другим.
 *
 * @tparam Key Тип ключа.
 * @param other Другое множество для объединения.
 */
template <typename Key>
void set<Key>::merge(set<Key> &other) {
  Base::merge(other);
}

/**
 * @brief Обменивает содержимое текущего множества с другим.
 *
 * @tparam Key Тип ключа.
 * @param other Другое множество для обмена.
 */
template <typename Key>
void set<Key>::swap(set<Key> &other) noexcept {
  Base::swap(other);
}

/**
 * @brief Ищет элемент в множестве.
 *
 * @tparam Key Тип ключа.
 * @param key Ключ для поиска.
 * @return Итератор на найденный элемент или на конец, если элемент не найден.
 */
template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key &key) {
  return Base::set_find(key);
}

/**
 * @brief Проверяет, содержится ли элемент в множестве.
 *
 * @tparam Key Тип ключа.
 * @param key Ключ для проверки.
 * @return true, если элемент содержится в множестве, иначе false.
 */
template <typename Key>
bool set<Key>::contains(const Key &key) const {
  return Base::contains(key);
}

/**
 * @brief Возвращает максимальный возможный размер множества.
 *
 * @tparam Key Тип ключа.
 * @return Максимальный размер.
 */
template <typename Key>
typename set<Key>::size_type set<Key>::max_size() const {
  return Base::max_size();
}

/**
 * @brief Проверяет, пусто ли множество.
 *
 * @tparam Key Тип ключа.
 * @return true, если множество пусто, иначе false.
 */
template <typename Key>
bool set<Key>::empty() const {
  return Base::empty();
}

/**
 * @brief Возвращает количество элементов в множестве.
 *
 * @tparam Key Тип ключа.
 * @return Количество элементов.
 */
template <typename Key>
typename set<Key>::size_type set<Key>::size() const {
  return Base::size();
}

/**
 * @brief Очищает множество.
 *
 * @tparam Key Тип ключа.
 */
template <typename Key>
void set<Key>::clear() {
  Base::clear();
}

}  // namespace s21
