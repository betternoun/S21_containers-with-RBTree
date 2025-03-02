/**
 * @file s21_stack_constructors.tpp
 * @brief Реализация конструкторов для класса stack
 */

namespace s21 {

/**
 * @brief Конструктор по умолчанию
 */
template <class T, class Container>
stack<T, Container>::stack() : container_(){};

/**
 * @brief Конструктор с инициализацией через initializer_list
 * @param items Список элементов для инициализации стека
 */
template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items)
    : container_(items){};

/**
 * @brief Конструктор копирования
 * @param s Другой стек для копирования
 */
template <class T, class Container>
stack<T, Container>::stack(const stack &s) : container_(s.container_){};

/**
 * @brief Конструктор перемещения
 * @param s Другой стек для перемещения
 */
template <class T, class Container>
stack<T, Container>::stack(stack &&s) noexcept
    : container_(std::move(s.container_)){};

/**
 * @brief Деструктор
 */
template <class T, class Container>
stack<T, Container>::~stack() {}

}  // namespace s21
