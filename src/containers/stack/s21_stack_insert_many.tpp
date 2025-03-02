/**
 * @file s21_stack_insert_many.tpp
 * @brief Реализация метода insert_many для класса stack
 */

namespace s21 {

/**
 * @brief Вставляет несколько элементов в стек
 * @tparam Args Типы аргументов
 * @param args Аргументы для вставки
 */
template <class T, class Container>
template <typename... Args>
void stack<T, Container>::insert_many_back(Args&&... args) {
  static_assert((std::is_convertible_v<Args, T> && ...),
                "All arguments must be convertible to stack's value_type");

  auto reverse_order = [](auto&&... args) {
    return std::make_tuple(std::forward<Args>(args)...);
  };

  std::apply(
      [this](auto&&... item) {
        (container_.push_back(std::forward<decltype(item)>(item)), ...);
      },
      reverse_order(args...));
}

/**
 * @brief Доступ к контейнеру стека
 * @param s Стек
 * @return Ссылка на контейнер
 */
template <class T, class Container>
Container& stack_insert_many_access::get_container(stack<T, Container>& s) {
  return s.container_;
}

}  // namespace s21
