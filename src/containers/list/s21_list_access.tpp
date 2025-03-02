/**
 * @file s21_list_access.tpp
 * @brief Реализация методов доступа к элементам для класса list
 */

namespace s21 {

/**
 * @brief Возвращает ссылку на первый элемент списка
 * @return Ссылка на данные первого узла
 * @throw std::out_of_range если список пуст
 */
template <typename T>
typename list<T>::reference list<T>::front() {
  if (!head) throw std::out_of_range("List is empty");
  return head->data;
}

/**
 * @brief Возвращает константную ссылку на первый элемент списка
 * @return Константная ссылка на данные первого узла
 * @throw std::out_of_range если список пуст
 */
template <typename T>
typename list<T>::const_reference list<T>::front() const {
  if (!head) throw std::out_of_range("List is empty");
  return head->data;
}

/**
 * @brief Возвращает ссылку на последний элемент списка
 * @return Ссылка на данные последнего узла
 * @throw std::out_of_range если список пуст
 */
template <typename T>
typename list<T>::reference list<T>::back() {
  if (!tail) throw std::out_of_range("List is empty");
  return tail->data;
}

/**
 * @brief Возвращает константную ссылку на последний элемент списка
 * @return Константная ссылка на данные последнего узла
 * @throw std::out_of_range если список пуст
 */
template <typename T>
typename list<T>::const_reference list<T>::back() const {
  if (!tail) throw std::out_of_range("List is empty");
  return tail->data;
}

}  // namespace s21
