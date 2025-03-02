/**
 * @file s21_map_iterators.tpp
 * @brief Реализация итераторов для класса map
 */

namespace s21 {

/**
 * @brief Возвращает итератор на начало контейнера
 * @return Итератор на первый элемент
 */
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return iterator(typename s21::RBTree<Key, T>::Iterator(
      s21::RBTree<Key, T>::GetMin(s21::RBTree<Key, T>::GetRoot())));
}

/**
 * @brief Возвращает итератор на конец контейнера
 * @return Итератор на элемент после последнего
 */
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  return iterator(typename s21::RBTree<Key, T>::Iterator(nullptr));
}

/**
 * @brief Оператор разыменования итератора
 * @return Пара ключ-значение
 */
template <typename Key, typename T>
typename map<Key, T>::value_type map<Key, T>::MapIterator::operator*() const {
  return std::make_pair(const_cast<const Key &>(this->iter_node_->key),
                        this->iter_node_->value);
}

/**
 * @brief Префиксный инкремент итератора
 * @return Ссылка на текущий итератор
 */
template <typename Key, typename T>
typename map<Key, T>::MapIterator &map<Key, T>::MapIterator::operator++() {
  s21::RBTree<Key, T>::Iterator::operator++();
  return *this;
}

/**
 * @brief Постфиксный инкремент итератора
 * @return Копия итератора до инкремента
 */
template <typename Key, typename T>
typename map<Key, T>::MapIterator map<Key, T>::MapIterator::operator++(int) {
  MapIterator temp = *this;
  ++(*this);
  return temp;
}

/**
 * @brief Сравнение итераторов на неравенство
 * @param other Другой итератор
 * @return true, если итераторы не равны, иначе false
 */
template <typename Key, typename T>
bool map<Key, T>::MapIterator::operator!=(const MapIterator &other) const {
  return this->iter_node_ != other.iter_node_;
}

/**
 * @brief Сравнение итераторов на равенство
 * @param other Другой итератор
 * @return true, если итераторы равны, иначе false
 */
template <typename Key, typename T>
bool map<Key, T>::MapIterator::operator==(const MapIterator &other) const {
  return this->iter_node_ == other.iter_node_;
}

/**
 * @brief Оператор разыменования константного итератора
 * @return Пара ключ-значение
 */
template <typename Key, typename T>
typename s21::map<Key, T>::value_type
s21::map<Key, T>::ConstMapIterator::operator*() const {
  return {this->iter_node_->key, this->iter_node_->value};
}

/**
 * @brief Сравнение константных итераторов на равенство
 * @param other Другой итератор
 * @return true, если итераторы равны, иначе false
 */
template <typename Key, typename T>
bool map<Key, T>::ConstMapIterator::operator==(
    const ConstMapIterator &other) const {
  return this->iter_node_ == other.iter_node_;
}

/**
 * @brief Оператор доступа к члену через указатель
 * @return Указатель на пару ключ-значение
 */
template <typename Key, typename T>
typename map<Key, T>::value_type *map<Key, T>::MapIterator::operator->() const {
  return &(this->iter_node_->pair);
}

}  // namespace s21
