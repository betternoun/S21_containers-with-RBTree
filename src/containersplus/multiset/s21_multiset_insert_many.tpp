/**
 * @file s21_multiset_insert_many.tpp
 * @brief Реализация метода insert_many для класса multiset
 */

namespace s21 {

/**
 * @brief Вставляет несколько элементов в контейнер
 *
 * Метод использует вариативные шаблоны для вставки произвольного количества
 * элементов. Для каждого аргумента вызывается метод insert и результат
 * добавляется в вектор результатов.
 *
 * @tparam T тип данных элементов в мультимножестве
 * @tparam Args типы аргументов для вставки
 * @param args аргументы для вставки (произвольное количество)
 * @return vector<std::pair<typename multiset<T>::iterator, bool>> вектор пар
 * (итератор, успех вставки)
 */
template <typename T>
template <typename... Args>
vector<std::pair<typename multiset<T>::iterator, bool>>
multiset<T>::insert_many(Args &&...args) {
  vector<std::pair<iterator, bool>> results;
  (results.push_back(std::make_pair(insert(std::forward<Args>(args)), true)),
   ...);
  return results;
}

}  // namespace s21
