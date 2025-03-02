/**
 * @file s21_vector_const_iterators.tpp
 * @brief Реализация константных итераторов для класса vector
 */

namespace s21 {

/**
 * @brief Оператор разыменования для константного итератора
 * @details Возвращает константную ссылку на элемент, на который указывает
 * итератор
 * @return Константная ссылка на текущий элемент
 * @throw std::out_of_range Если итератор указывает на невалидную позицию
 */
template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const {
  return *ptr_;
}

/**
 * @brief Префиксный инкремент для константного итератора
 * @details Перемещает итератор на следующий элемент
 * @return Ссылка на текущий итератор после инкремента
 * @throw std::out_of_range Если следующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator++() {
  ++ptr_;
  return *this;
}

/**
 * @brief Префиксный декремент для константного итератора
 * @details Перемещает итератор на предыдущий элемент
 * @return Ссылка на текущий итератор после декремента
 * @throw std::out_of_range Если предыдущая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator--() {
  --ptr_;
  return *this;
}

/**
 * @brief Постфиксный инкремент для константного итератора
 * @details Создает копию текущего итератора, затем перемещает его на следующий
 * элемент
 * @param[in] int Фиктивный параметр для различения постфиксной версии
 * @return Копия итератора до инкремента
 * @throw std::out_of_range Если следующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator++(int) {
  VectorConstIterator tmp = *this;
  ++ptr_;
  return tmp;
}

/**
 * @brief Постфиксный декремент для константного итератора
 * @details Создает копию текущего итератора, затем перемещает его на предыдущий
 * элемент
 * @param[in] int Фиктивный параметр для различения постфиксной версии
 * @return Копия итератора до декремента
 * @throw std::out_of_range Если предыдущая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator--(int) {
  VectorConstIterator tmp = *this;
  --ptr_;
  return tmp;
}

/**
 * @brief Оператор сложения для константного итератора
 * @details Перемещает итератор вперед на n позиций
 * @param[in] n Количество позиций для перемещения
 * @return Новый итератор, указывающий на позицию через n элементов
 * @throw std::out_of_range Если результирующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator+(int n) {
  return VectorConstIterator(ptr_ + n);
}

/**
 * @brief Оператор вычитания для константного итератора
 * @details Перемещает итератор назад на n позиций
 * @param[in] n Количество позиций для перемещения
 * @return Новый итератор, указывающий на позицию за n элементов до текущей
 * @throw std::out_of_range Если результирующая позиция находится за пределами
 * вектора
 */
template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator-(int n) {
  return VectorConstIterator(ptr_ - n);
}

/**
 * @brief Оператор разности двух константных итераторов
 * @details Вычисляет количество элементов между двумя итераторами
 * @param[in] other Другой итератор для сравнения
 * @return Количество элементов между текущим и другим итератором
 */
template <typename T>
typename vector<T>::size_type vector<T>::VectorConstIterator::operator-(
    const VectorConstIterator& other) {
  return ptr_ - other.ptr_;
}

/**
 * @brief Оператор сравнения на равенство двух константных итераторов
 * @details Проверяет, указывают ли итераторы на один и тот же элемент
 * @param[in] other Другой итератор для сравнения
 * @return true если итераторы равны, false в противном случае
 */
template <typename T>
bool vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator& other) const {
  return ptr_ == other.ptr_;
}

/**
 * @brief Оператор сравнения на неравенство двух константных итераторов
 * @details Проверяет, указывают ли итераторы на разные элементы
 * @param[in] other Другой итератор для сравнения
 * @return true если итераторы не равны, false в противном случае
 */
template <typename T>
bool vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator& other) const {
  return ptr_ != other.ptr_;
}

/**
 * @brief Конструктор преобразования из обычного итератора в константный
 * @details Создает константный итератор на основе обычного итератора
 * @param[in] other Обычный итератор для преобразования
 */
template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(const VectorIterator& other)
    : ptr_(other.ptr_) {}

/**
 * @brief Получение указателя на текущий элемент
 * @details Возвращает внутренний указатель итератора
 * @return Указатель на текущий элемент
 */
template <typename T>
typename vector<T>::pointer vector<T>::VectorConstIterator::get_ptr() const {
  return ptr_;
}

}  // namespace s21
