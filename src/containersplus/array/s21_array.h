/**
 * @file s21_array.h
 * @brief Заголовочный файл для класса array - контейнера фиксированного размера
 */

#ifndef S21_ARRAY_H
#define S21_ARRAY_H

namespace s21 {

/**
 * @brief Класс array - реализация контейнера фиксированного размера
 *
 * Класс array представляет собой последовательный контейнер фиксированного
 * размера, который хранит элементы заданного типа T в количестве N. Размер
 * контейнера задается при компиляции и не может быть изменен во время
 * выполнения.
 *
 * @tparam T Тип элементов, хранящихся в контейнере
 * @tparam N Количество элементов в контейнере (фиксированный размер)
 */
template <typename T, size_t N>
class array {
 public:
  /** @brief Тип значения, хранящегося в контейнере */
  using value_type = T;
  /** @brief Тип ссылки на значение */
  using reference = T &;
  /** @brief Тип константной ссылки на значение */
  using const_reference = const T &;
  /** @brief Тип итератора (указатель на T) */
  using iterator = T *;
  /** @brief Тип константного итератора (указатель на константный T) */
  using const_iterator = const T *;
  /** @brief Тип для представления размера контейнера */
  using size_type = size_t;

 private:
  /** @brief Массив элементов фиксированного размера N */
  T elements_[N];

 public:
  /**
   * @brief Конструктор по умолчанию
   *
   * Создает массив с неинициализированными элементами
   */
  array() = default;

  /**
   * @brief Конструктор со списком инициализации
   *
   * @param items Список инициализации элементов
   * @throw std::out_of_range если размер списка превышает N
   */
  array(std::initializer_list<value_type> const &items);

  /**
   * @brief Конструктор копирования
   *
   * @param other Другой массив для копирования
   */
  array(const array &other);

  /**
   * @brief Конструктор перемещения
   *
   * @param other Другой массив для перемещения
   */
  array(array &&other) noexcept;

  /**
   * @brief Оператор присваивания перемещением
   *
   * @param other Другой массив для перемещения
   * @return Ссылка на текущий объект
   */
  array &operator=(array &&other) noexcept;

  /**
   * @brief Деструктор по умолчанию
   */
  ~array() = default;

  /**
   * @brief Доступ к элементу с проверкой границ
   *
   * @param pos Индекс элемента
   * @return Ссылка на элемент
   * @throw std::out_of_range если pos >= N
   */
  reference at(size_type pos);

  /**
   * @brief Оператор доступа к элементу (константный)
   *
   * @param pos Индекс элемента
   * @return Константная ссылка на элемент
   */
  const_reference operator[](size_type pos) const;

  /**
   * @brief Доступ к первому элементу
   *
   * @return Константная ссылка на первый элемент
   */
  const_reference front() const;

  /**
   * @brief Доступ к последнему элементу
   *
   * @return Константная ссылка на последний элемент
   */
  const_reference back() const;

  /**
   * @brief Получение указателя на внутренний массив
   *
   * @return Итератор (указатель) на начало массива
   */
  iterator data();

  /**
   * @brief Получение итератора на начало контейнера
   *
   * @return Итератор на первый элемент
   */
  iterator begin();

  /**
   * @brief Получение итератора на конец контейнера
   *
   * @return Итератор на элемент за последним
   */
  iterator end();

  /**
   * @brief Получение константного итератора на начало контейнера
   *
   * @return Константный итератор на первый элемент
   */
  const_iterator begin() const;

  /**
   * @brief Получение константного итератора на конец контейнера
   *
   * @return Константный итератор на элемент за последним
   */
  const_iterator end() const;

  /**
   * @brief Проверка, пуст ли контейнер
   *
   * @return true если N == 0, иначе false
   */
  bool empty() const;

  /**
   * @brief Получение размера контейнера
   *
   * @return Количество элементов (N)
   */
  size_type size() const;

  /**
   * @brief Получение максимального размера контейнера
   *
   * @return Максимальное количество элементов (N)
   */
  size_type max_size() const;

  /**
   * @brief Обмен содержимым с другим массивом
   *
   * @param other Другой массив для обмена
   */
  void swap(array &other) noexcept;

  /**
   * @brief Заполнение массива заданным значением
   *
   * @param value Значение для заполнения
   */
  void fill(const_reference value);

  /**
   * @brief Константная версия метода at
   *
   * @param pos Индекс элемента
   * @return Константная ссылка на элемент
   * @throw std::out_of_range если pos >= N
   */
  const_reference at(size_type pos) const;

  /**
   * @brief Константная версия метода data
   *
   * @return Константный итератор на начало массива
   */
  const_iterator data() const;
};

}  // namespace s21

// clang-format off
#include "s21_array_constructors.tpp"
#include "s21_array_access.tpp"
#include "s21_array_iterators.tpp"
#include "s21_array_capacity.tpp"
#include "s21_array_modifiers.tpp"
// clang-format on

#endif  // S21_ARRAY_H
