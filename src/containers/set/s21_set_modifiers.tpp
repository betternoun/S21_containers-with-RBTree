/**
 * @file s21_set_modifiers.tpp
 * @brief Реализация методов модификации для класса set
 */

namespace s21 {

/**
 * @brief Вставляет элемент в множество.
 *
 * @tparam Key Тип ключа.
 * @param value Значение для вставки.
 * @return Пара из итератора на вставленный элемент и флага успешности.
 */
template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const Key &value) {
  bool success = !this->contains(value);
  if (success) {
    s21::RBTree<Key, Key>::insert(value, value);
  }
  return {find(value), success};
}

/**
 * @brief Удаляет элемент из множества по итератору.
 *
 * @tparam Key Тип ключа.
 * @param pos Итератор на элемент для удаления.
 * @throws std::invalid_argument Если итератор указывает на конец или является
 * недействительным.
 */
template <typename Key>
void set<Key>::erase(iterator pos) {
  if (pos == end()) {
    throw std::invalid_argument("Invalid iterator");
  }
  Base::remove(*pos);
}

}  // namespace s21
