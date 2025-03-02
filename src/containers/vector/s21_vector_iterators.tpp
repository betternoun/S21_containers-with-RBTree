/**
 * @file s21_vector_iterators.tpp
 * @brief Реализация итераторов для класса vector
 */

namespace s21 {

/**
 * @brief Оператор разыменования для итератора
 * @details Возвращает ссылку на элемент, на который указывает итератор
 * @return Ссылка на текущий элемент
 * @throw std::out_of_range Если итератор указывает на невалидную позицию
 */
template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() {
  return *ptr_;
}

/**
 * @brief Префиксный инкремент для итератора
 * @details Перемещает итератор на следующий элемент
 * @return Ссылка на текущий итератор после инкремента
 * @throw std::out_of_range Если следующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator++() {
  ++ptr_;
  return *this;
}

/**
 * @brief Префиксный декремент для итератора
 * @details Перемещает итератор на предыдущий элемент
 * @return Ссылка на текущий итератор после декремента
 * @throw std::out_of_range Если предыдущая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator--() {
  --ptr_;
  return *this;
}

/**
 * @brief Постфиксный инкремент для итератора
 * @details Создает копию текущего итератора, затем перемещает его на следующий
 * элемент
 * @param[in] int Фиктивный параметр для различения постфиксной версии
 * @return Копия итератора до инкремента
 * @throw std::out_of_range Если следующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(int) {
  VectorIterator tmp = *this;
  ++ptr_;
  return tmp;
}

/**
 * @brief Постфиксный декремент для итератора
 * @details Создает копию текущего итератора, затем перемещает его на предыдущий
 * элемент
 * @param[in] int Фиктивный параметр для различения постфиксной версии
 * @return Копия итератора до декремента
 * @throw std::out_of_range Если предыдущая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(int) {
  VectorIterator tmp = *this;
  --ptr_;
  return tmp;
}

/**
 * @brief Оператор сложения для итератора
 * @details Перемещает итератор вперед на n позиций
 * @param[in] n Количество позиций для перемещения
 * @return Новый итератор, указывающий на позицию через n элементов
 * @throw std::out_of_range Если результирующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(int n) {
  return iterator(ptr_ + n);
}

/**
 * @brief Оператор вычитания для итератора
 * @details Перемещает итератор назад на n позиций
 * @param[in] n Количество позиций для перемещения
 * @return Новый итератор, указывающий на позицию за n элементов до текущей
 * @throw std::out_of_range Если результирующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(int n) {
  return iterator(ptr_ - n);
}

/**
 * @brief Оператор сравнения на равенство двух итераторов
 * @details Проверяет, указывают ли итераторы на один и тот же элемент
 * @param[in] other Другой итератор для сравнения
 * @return true если итераторы равны, false в противном случае
 */
template <typename T>
bool vector<T>::VectorIterator::operator==(const VectorIterator& other) const {
  return ptr_ == other.ptr_;
}

/**
 * @brief Оператор сравнения на неравенство двух итераторов
 * @details Проверяет, указывают ли итераторы на разные элементы
 * @param[in] other Другой итератор для сравнения
 * @return true если итераторы не равны, false в противном случае
 */
template <typename T>
bool vector<T>::VectorIterator::operator!=(const VectorIterator& other) const {
  return ptr_ != other.ptr_;
}

/**
 * @brief Оператор разности двух итераторов
 * @details Вычисляет количество элементов между двумя итераторами
 * @param[in] other Другой итератор для вычисления разности
 * @return Количество элементов между текущим и другим итератором
 */
template <typename T>
int vector<T>::VectorIterator::operator-(const VectorIterator& other) {
  return ptr_ - other.ptr_;
}

/**
 * @brief Оператор сравнения "меньше" для итераторов
 * @details Проверяет, указывает ли текущий итератор на элемент, расположенный
 * раньше в векторе
 * @param[in] other Другой итератор для сравнения
 * @return true если текущий итератор указывает на элемент раньше в векторе,
 * false в противном случае
 */
template <typename T>
bool vector<T>::VectorIterator::operator<(const VectorIterator& other) const {
  return ptr_ < other.ptr_;
}

/**
 * @brief Возвращает итератор на начало вектора
 * @details Возвращает итератор, указывающий на первый элемент вектора
 * @return Итератор на первый элемент
 */
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}

/**
 * @brief Возвращает константный итератор на начало вектора
 * @details Возвращает константный итератор, указывающий на первый элемент
 * вектора
 * @return Константный итератор на первый элемент
 */
template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
  return const_iterator(data_);
}

/**
 * @brief Возвращает итератор на конец вектора
 * @details Возвращает итератор, указывающий на позицию после последнего
 * элемента
 * @return Итератор на позицию после последнего элемента
 */
template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

/**
 * @brief Возвращает константный итератор на конец вектора
 * @details Возвращает константный итератор, указывающий на позицию после
 * последнего элемента
 * @return Константный итератор на позицию после последнего элемента
 */
template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
  return const_iterator(data_ + size_);
}

/**
 * @brief Возвращает константный итератор на начало вектора
 * @details Возвращает константный итератор, указывающий на первый элемент
 * вектора
 * @return Константный итератор на первый элемент
 */
template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return VectorConstIterator(data_);
}

/**
 * @brief Возвращает константный итератор на конец вектора
 * @details Возвращает константный итератор, указывающий на позицию после
 * последнего элемента
 * @return Константный итератор на позицию после последнего элемента
 */
template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return VectorConstIterator(data_ + size_);
}

/**
 * @brief Конструктор итератора с указателем
 * @details Создает итератор, указывающий на заданный элемент
 * @param[in] ptr Указатель на элемент вектора
 */
template <typename T>
vector<T>::VectorIterator::VectorIterator(const pointer ptr) : ptr_(ptr) {}

}  // namespace s21
