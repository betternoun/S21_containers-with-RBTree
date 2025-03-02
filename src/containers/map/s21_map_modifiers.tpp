/**
 * @file s21_map_modifiers.tpp
 * @brief Реализация методов модификации для класса map
 */

namespace s21 {

/**
 * @brief Вставляет элемент
 * @param value Пара ключ-значение для вставки
 * @return Пара итератор и флаг успешности вставки
 */
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type &value) {
  bool success = !this->contains(value.first);
  if (success) {
    s21::RBTree<Key, T>::insert(value.first, value.second);
  }
  return {find(value.first), success};
}

/**
 * @brief Вставляет элемент
 * @param key Ключ для вставки
 * @param obj Значение для вставки
 * @return Пара итератор и флаг успешности вставки
 */
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  bool success = !this->contains(key);
  if (success) {
    s21::RBTree<Key, T>::insert(key, obj);
  }
  return {find(key), success};
}

/**
 * @brief Вставляет элемент или обновляет существующий
 * @param key Ключ для вставки/обновления
 * @param obj Значение для вставки/обновления
 * @return Пара итератор и флаг успешности вставки
 */
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  auto it = find(key);
  if (it != this->end()) {
    erase(it);
    auto pr = insert(key, obj);
    pr.second = false;
    return pr;
  }
  return insert(key, obj);
}

/**
 * @brief Объединяет два контейнера
 * @param other Другой контейнер для объединения
 */
template <typename Key, typename T>
void map<Key, T>::merge(map &other) {
  if (this != &other) {
    auto it = other.begin();
    while (it != other.end()) {
      if (!this->contains((*it).first)) {
        this->insert(*it);
        auto current = it;
        ++it;
        other.erase(current);
      } else {
        ++it;
      }
    }
  }
}

/**
 * @brief Удаляет элемент по итератору
 * @param pos Итератор на удаляемый элемент
 */
template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  if (pos.iter_node_ == nullptr) {
    throw std::invalid_argument("Invalid iterator: null pointer");
  }
  RBTree<Key, T>::remove(pos.iter_node_->key);
}

/**
 * @brief Обменивает содержимое двух контейнеров
 * @param other Другой контейнер для обмена
 */
template <typename Key, typename T>
void map<Key, T>::swap(map &other) noexcept {
  s21::RBTree<Key, T>::swap(other);
}

/**
 * @brief Очищает контейнер
 */
template <typename Key, typename T>
void map<Key, T>::clear() noexcept {
  RBTree<Key, T>::clear();
}

/**
 * @brief Возвращает константный итератор на начало контейнера
 * @return Константный итератор на первый элемент
 */
template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::begin() const {
  return const_iterator(RBTree<Key, T>::cbegin());
}

/**
 * @brief Возвращает константный итератор на конец контейнера
 * @return Константный итератор на элемент после последнего
 */
template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::end() const {
  return const_iterator(typename RBTree<Key, T>::ConstIterator(nullptr));
}

}  // namespace s21
