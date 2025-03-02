/**
 * @file s21_queue_constructors.tpp
 * @brief Реализация конструкторов для класса queue
 */

namespace s21 {

/**
 * @brief Конструктор по умолчанию
 */
template <class T, class Container>
queue<T, Container>::queue() : container_(){};

/**
 * @brief Конструктор с инициализацией через список
 * @param items Список инициализации
 */
template <class T, class Container>
queue<T, Container>::queue(std::initializer_list<value_type> const& items)
    : container_(items){};

/**
 * @brief Конструктор копирования
 * @param q Очередь для копирования
 */
template <class T, class Container>
queue<T, Container>::queue(const queue& q) : container_(q.container_) {}

/**
 * @brief Конструктор перемещения
 * @param q Очередь для перемещения
 */
template <class T, class Container>
queue<T, Container>::queue(queue&& q) noexcept
    : container_(std::move(q.container_)) {}

/**
 * @brief Деструктор
 */
template <class T, class Container>
queue<T, Container>::~queue() {}

/**
 * @brief Оператор присваивания с перемещением
 * @param q Очередь для перемещения
 * @return Ссылка на текущий объект
 */
template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(queue&& q) noexcept {
  if (this != &q) {
    container_ = std::move(q.container_);
  }
  return *this;
}

/**
 * @brief Оператор присваивания с копированием
 * @param q Очередь для копирования
 * @return Ссылка на текущий объект
 */
template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(const queue& q) {
  if (this != &q) {
    container_ = q.container_;
  }
  return *this;
}

}  // namespace s21
