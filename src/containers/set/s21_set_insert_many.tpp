/**
 * @file s21_set_insert_many.tpp
 * @brief Реализация метода insert_many для класса set
 */

namespace s21 {

/**
 * @brief Вставляет несколько элементов в множество.
 *
 * @tparam Key Тип ключа.
 * @tparam Args Типы аргументов.
 * @param args Аргументы для вставки.
 * @return Вектор пар из итераторов на вставленные элементы и флагов успешности.
 */
template <typename Key>
template <typename... Args>
s21::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args&&... args) {
  s21::vector<std::pair<iterator, bool>> results;
  (results.push_back(this->insert(std::forward<Args>(args))), ...);
  return results;
}

}  // namespace s21
