/**
 * @file s21_vector_utilities.tpp
 * @brief Реализация утилитных функций для класса vector
 */

namespace s21 {

/**
 * @brief Копирует элементы из одного диапазона в другой
 * @details Последовательно копирует элементы из исходного диапазона в целевой
 * @tparam Input Тип входного итератора
 * @tparam Output Тип выходного итератора
 * @param[in] begin Итератор на начало исходного диапазона
 * @param[in] end Итератор на конец исходного диапазона
 * @param[out] dest Итератор на начало целевого диапазона
 * @throw Может выбросить исключения при копировании элементов
 */
template <typename Input, typename Output>
void copy(Input begin, Input end, Output dest) {
  while (begin != end) {
    *dest = *begin;
    ++begin;
    ++dest;
  }
}

/**
 * @brief Перемещает элементы из одного диапазона в другой
 * @details Последовательно перемещает элементы из исходного диапазона в целевой
 * @tparam Input Тип входного итератора
 * @tparam Output Тип выходного итератора
 * @param[in] begin Итератор на начало исходного диапазона
 * @param[in] end Итератор на конец исходного диапазона
 * @param[out] dest Итератор на начало целевого диапазона
 * @throw Может выбросить исключения при перемещении элементов
 */
template <typename Input, typename Output>
void move(Input begin, Input end, Output dest) {
  while (begin != end) {
    *dest = std::move(*begin);
    ++begin;
    ++dest;
  }
}

/**
 * @brief Заполняет диапазон заданным значением
 * @details Присваивает указанное значение всем элементам в диапазоне
 * @tparam ForwardIt Тип итератора
 * @tparam T Тип значения
 * @param[out] begin Итератор на начало диапазона
 * @param[out] end Итератор на конец диапазона
 * @param[in] value Значение для заполнения
 * @throw Может выбросить исключения при присваивании значений
 */
template <typename ForwardIt, typename T>
void fill(ForwardIt begin, ForwardIt end, const T &value) {
  for (; begin != end; ++begin) {
    *begin = value;
  }
}

/**
 * @brief Разворачивает элементы в диапазоне
 * @details Меняет порядок элементов на противоположный
 * @tparam BidirIt Тип двунаправленного итератора
 * @param[in,out] begin Итератор на начало диапазона
 * @param[in,out] end Итератор на конец диапазона
 * @throw Может выбросить исключения при обмене элементов
 */
template <typename BidirIt>
void reverse(BidirIt begin, BidirIt end) {
  while ((begin != end) && (begin != --end)) {
    std::swap(*begin++, *end);
  }
}

/**
 * @brief Возвращает максимальное из двух значений
 * @details Сравнивает два значения и возвращает большее
 * @tparam T Тип сравниваемых значений
 * @param[in] a Первое значение
 * @param[in] b Второе значение
 * @return Константная ссылка на большее значение
 */
template <typename T>
const T &max(const T &a, const T &b) {
  return (a < b) ? b : a;
}

/**
 * @brief Обменивает значения двух переменных
 * @details Выполняет обмен значений с использованием перемещения
 * @tparam T Тип обмениваемых значений
 * @param[in,out] a Первая переменная
 * @param[in,out] b Вторая переменная
 * @throw Может выбросить исключения при перемещении значений
 */
template <typename T>
void swap(T &a, T &b) {
  T temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
}

}  // namespace s21
