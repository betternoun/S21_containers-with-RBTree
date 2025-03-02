/**
 * @file s21_vector_operations.tpp
 * @brief Реализация операций для класса vector
 */

namespace s21 {

/**
 * @brief Доступ к элементу вектора с проверкой границ
 * @details Возвращает ссылку на элемент по указанному индексу с проверкой
 * выхода за границы
 * @param[in] pos Индекс элемента
 * @return Ссылка на элемент
 * @throw std::out_of_range Если индекс выходит за границы вектора
 */
template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Vector Error: Index out of range");
  }
  return data_[pos];
}

/**
 * @brief Оператор доступа к элементу вектора
 * @details Возвращает ссылку на элемент по указанному индексу без проверки
 * границ
 * @param[in] pos Индекс элемента
 * @return Ссылка на элемент
 */
template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return data_[pos];
}

/**
 * @brief Доступ к первому элементу вектора
 * @details Возвращает ссылку на первый элемент вектора
 * @return Константная ссылка на первый элемент
 * @throw std::out_of_range Если вектор пуст
 */
template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  if (size_ > 0) return data_[0];
  throw std::out_of_range("Vector Error: Index out of range");
}

/**
 * @brief Доступ к последнему элементу вектора
 * @details Возвращает ссылку на последний элемент вектора
 * @return Константная ссылка на последний элемент
 * @throw std::out_of_range Если вектор пуст
 */
template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  if (size_ > 0) return data_[size_ - 1];
  throw std::out_of_range("Vector Error: Index out of range");
}

/**
 * @brief Получение указателя на данные вектора
 * @details Возвращает прямой указатель на массив данных
 * @return Указатель на данные
 */
template <typename T>
typename vector<T>::pointer vector<T>::data() const {
  return data_;
}

/**
 * @brief Проверка на пустоту
 * @details Проверяет, является ли вектор пустым
 * @return true если вектор пуст, false в противном случае
 */
template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

/**
 * @brief Получение размера вектора
 * @details Возвращает текущее количество элементов в векторе
 * @return Количество элементов
 */
template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

/**
 * @brief Получение максимального размера вектора
 * @details Возвращает максимально возможное количество элементов
 * @return Максимальный размер
 */
template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return capacity_;
}

/**
 * @brief Резервирование памяти
 * @details Резервирует память для указанного количества элементов
 * @param[in] size Требуемая емкость
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
void vector<T>::reserve(const size_type size) {
  if (size > capacity_) {
    value_type *new_data = new value_type[size];
    s21::move(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
  }
}

/**
 * @brief Получение емкости вектора
 * @details Возвращает текущую емкость вектора
 * @return Емкость вектора
 */
template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

/**
 * @brief Уменьшение емкости
 * @details Уменьшает емкость вектора до его размера
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    value_type *new_data = new value_type[size_];
    s21::move(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

/**
 * @brief Очистка вектора
 * @details Удаляет все элементы из вектора
 */
template <typename T>
void vector<T>::clear() {
  for (int i = 0; i < size_; ++i) this->data_[i] = T();
  size_ = 0;
}

/**
 * @brief Вставка элемента
 * @details Вставляет элемент в указанную позицию
 * @param[in] pos Итератор на позицию вставки
 * @param[in] value Вставляемое значение
 * @return Итератор на вставленный элемент
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  int index = pos - this->begin();
  if (index >= capacity_)
    this->reserve(index + 1);
  else if (size_ + 1 >= capacity_)
    this->reserve(capacity_ + 1);

  for (int i = size_; i > index; --i) {
    data_[i] = data_[i - 1];
  }

  data_[index] = value;

  size_ = s21::max(size_ + 1, static_cast<size_type>(index) + 1);

  return iterator(data_ + index);
}

/**
 * @brief Удаление элемента
 * @details Удаляет элемент в указанной позиции
 * @param[in] pos Итератор на удаляемый элемент
 * @throw std::out_of_range Если позиция находится за пределами вектора
 */
template <typename T>
void vector<T>::erase(iterator pos) {
  int index = pos - this->begin();

  if (index >= size_)
    throw std::out_of_range("Vector Error: Index out of range");

  int i = index;
  while (i < size_ - 1) {
    data_[i] = data_[i + 1];
    i++;
  }

  size_--;
}

/**
 * @brief Добавление элемента в конец
 * @details Добавляет элемент в конец вектора
 * @param[in] value Добавляемое значение
 * @throw std::bad_alloc В случае ошибки выделения памяти
 */
template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ * 2);
  }

  data_[size_] = value;
  size_++;
}

/**
 * @brief Удаление последнего элемента
 * @details Удаляет последний элемент вектора
 * @throw std::out_of_range Если вектор пуст
 */
template <typename T>
void vector<T>::pop_back() {
  if (size_ == 0) throw std::out_of_range("Vector Error: Index out of range");
  data_[size_ - 1] = T();
  size_--;
}

/**
 * @brief Обмен содержимым
 * @details Обменивает содержимое с другим вектором
 * @param[in,out] other Другой вектор для обмена
 */
template <typename T>
void vector<T>::swap(vector &other) noexcept {
  s21::swap(size_, other.size_);
  s21::swap(data_, other.data_);
  s21::swap(capacity_, other.capacity_);
}

/**
 * @brief Оператор сравнения на равенство
 * @details Проверяет, равны ли два вектора
 * @param[in] other Другой вектор для сравнения
 * @return true если векторы равны, false в противном случае
 */
template <typename T>
bool vector<T>::operator==(const vector &other) const {
  return size_ == other.size_ &&
         std::equal(begin(), end(), other.begin(), other.end());
}

/**
 * @brief Оператор сравнения на неравенство
 * @details Проверяет, не равны ли два вектора
 * @param[in] other Другой вектор для сравнения
 * @return true если векторы не равны, false в противном случае
 */
template <typename T>
bool vector<T>::operator!=(const vector &other) const {
  return !(*this == other);
}

}  // namespace s21
