/**
 * @file s21_list_constructors.tpp
 * @brief Реализация конструкторов для класса list
 */

namespace s21 {

/**
 * @brief Конструктор по умолчанию
 *
 * Создает пустой список.
 */
template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), size_(0) {}

/**
 * @brief Конструктор копирования
 * @param other Копируемый список
 *
 * Создает новый список как копию существующего.
 */
template <typename T>
list<T>::list(const list& other) : list() {
  for (const auto& value : other) {
    push_back(value);
  }
}

/**
 * @brief Конструктор перемещения
 * @param other Перемещаемый список
 *
 * Создает новый список, перемещая содержимое другого списка.
 */
template <typename T>
list<T>::list(list&& other) noexcept
    : head(other.head), tail(other.tail), size_(other.size_) {
  other.head = nullptr;
  other.tail = nullptr;
  other.size_ = 0;
}

/**
 * @brief Конструктор из списка инициализации
 * @param init Список инициализации
 *
 * Создает список с элементами из списка инициализации.
 */
template <typename T>
list<T>::list(std::initializer_list<T> init) : list() {
  try {
    for (const auto& value : init) {
      push_back(value);
    }
  } catch (...) {
    clear();
    throw;
  }
}

/**
 * @brief Конструктор с заданным количеством элементов
 * @param count Количество элементов
 * @param value Значение для инициализации элементов (по умолчанию T())
 *
 * Создает список с указанным количеством элементов, инициализированных
 * заданным значением.
 */
template <typename T>
list<T>::list(size_type count, const T& value) : list() {
  for (size_type i = 0; i < count; ++i) {
    push_back(value);
  }
}

/**
 * @brief Деструктор
 *
 * Освобождает память, занятую списком.
 */
template <typename T>
list<T>::~list() {
  clear();
}

}  // namespace s21
