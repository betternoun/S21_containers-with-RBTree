/**
 * @file s21_vector_constructors.tpp
 * @brief Реализация конструкторов для класса vector
 */

namespace s21 {

/**
 * @brief Конструктор из списка инициализации
 * @details Создает вектор и инициализирует его элементами из списка
 * инициализации
 * @param[in] items Список инициализации с элементами для вектора
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
vector<T>::vector(std::initializer_list<T> const &items)
    : size_(items.size()),
      capacity_(items.size()),
      data_(new value_type[items.size()]) {
  s21::copy(items.begin(), items.end(), data_);
}

/**
 * @brief Конструктор с указанием размера
 * @details Создает вектор заданного размера с элементами по умолчанию
 * @param[in] n Начальный размер вектора
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
vector<T>::vector(const size_type n)
    : size_(n),
      capacity_(n == 0 ? 1 : n),
      data_(new value_type[n == 0 ? 1 : n]) {
  s21::fill(data_, data_ + size_, T());
}

/**
 * @brief Конструктор с указанием размера и значения
 * @details Создает вектор заданного размера и заполняет его указанным значением
 * @param[in] n Размер вектора
 * @param[in] value Значение для инициализации элементов
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
vector<T>::vector(const size_type n, const_reference value)
    : size_(n),
      capacity_(n == 0 ? 1 : n),
      data_(new value_type[n == 0 ? 1 : n]) {
  for (size_type i = 0; i < size_; ++i) {
    data_[i] = value;
  }
}

/**
 * @brief Конструктор копирования
 * @details Создает копию существующего вектора
 * @param[in] v Вектор для копирования
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
vector<T>::vector(const vector &v)
    : size_(v.size_),
      capacity_(v.capacity_),
      data_(new value_type[v.capacity_]) {
  s21::copy(v.data_, v.data_ + v.size_, data_);
}

/**
 * @brief Конструктор перемещения
 * @details Перемещает ресурсы из другого вектора
 * @param[in] v Вектор для перемещения
 * @note Не выбрасывает исключений (noexcept)
 */
template <typename T>
vector<T>::vector(vector &&v) noexcept
    : size_(v.size_), capacity_(v.capacity_), data_(v.data_) {
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

/**
 * @brief Конструктор по умолчанию
 * @details Создает пустой вектор с минимальной емкостью
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
vector<T>::vector() : size_(0), capacity_(1), data_(new value_type[1]) {}

/**
 * @brief Деструктор
 * @details Освобождает выделенную память
 */
template <typename T>
vector<T>::~vector() {
  delete[] data_;
}

/**
 * @brief Оператор перемещающего присваивания
 * @details Перемещает ресурсы из другого вектора
 * @param[in] v Вектор для перемещения
 * @return Ссылка на текущий вектор
 * @note Не выбрасывает исключений (noexcept)
 */
template <typename T>
vector<T> &vector<T>::operator=(vector &&v) noexcept {
  if (this != &v) {
    delete[] data_;
    data_ = v.data_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.size_ = 0;
    v.capacity_ = 0;
    v.data_ = nullptr;
  }
  return *this;
}

/**
 * @brief Оператор копирующего присваивания
 * @details Копирует содержимое другого вектора
 * @param[in] v Вектор для копирования
 * @return Ссылка на текущий вектор
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
vector<T> &vector<T>::operator=(const vector &v) {
  if (this != &v) {
    delete[] data_;
    data_ = new value_type[v.capacity_];
    size_ = v.size_;
    capacity_ = v.capacity_;
    s21::copy(v.data_, v.data_ + v.size_, data_);
  }
  return *this;
}

}  // namespace s21
