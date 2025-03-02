/**
 * @file s21_stack.h
 * @brief Заголовочный файл для класса stack - реализации стека
 */

#ifndef S21_STACK_H
#define S21_STACK_H

namespace s21 {

/**
 * @brief Шаблонный класс stack, реализующий структуру данных стек
 *
 * @tparam T Тип элементов стека
 * @tparam Container Тип контейнера для хранения элементов (по умолчанию
 * s21::vector<T>)
 *
 * Класс stack предоставляет интерфейс для работы с элементами в стиле стека
 * (LIFO). По умолчанию используется контейнер s21::vector для хранения
 * элементов.
 */
template <class T, class Container = s21::vector<T>>
class stack {
 public:
  using value_type = T;               ///< Тип элементов в стеке
  using reference = T &;              ///< Ссылка на элемент
  using const_reference = const T &;  ///< Константная ссылка на элемент
  using size_type = size_t;           ///< Тип для размера стека
  using iterator = typename Container::iterator;  ///< Итератор для контейнера
  using const_iterator =
      typename Container::const_iterator;  ///< Константный итератор для
                                           ///< контейнера

 public:
  /**
   * @brief Конструктор по умолчанию
   * Создает пустой стек.
   */
  stack();

  /**
   * @brief Конструктор с инициализацией через initializer_list
   * @param items Список элементов для инициализации стека
   */
  stack(std::initializer_list<value_type> const &items);

  /**
   * @brief Конструктор копирования
   * @param s Другой стек для копирования
   */
  stack(const stack &s);

  /**
   * @brief Конструктор перемещения
   * @param s Другой стек для перемещения
   */
  stack(stack &&s) noexcept;

  /**
   * @brief Деструктор
   * Освобождает ресурсы, занятые стеком.
   */
  ~stack();

  /**
   * @brief Оператор присваивания перемещением
   * @param s Другой стек для перемещения
   * @return Ссылка на текущий стек
   */
  stack &operator=(stack &&s) noexcept;

  /**
   * @brief Оператор присваивания копированием
   * @param s Другой стек для копирования
   * @return Ссылка на текущий стек
   */
  stack &operator=(const stack &s);

  /**
   * @brief Возвращает верхний элемент стека
   * @return Константная ссылка на верхний элемент
   * @throw std::out_of_range Если стек пуст
   */
  const_reference top() const;

  /**
   * @brief Проверяет, пуст ли стек
   * @return true, если стек пуст, иначе false
   */
  [[nodiscard]] bool empty() const noexcept;

  /**
   * @brief Возвращает количество элементов в стеке
   * @return Количество элементов
   */
  [[nodiscard]] size_type size() const noexcept;

  /**
   * @brief Добавляет элемент в стек
   * @param value Значение для добавления
   */
  void push(const_reference value);

  /**
   * @brief Удаляет верхний элемент из стека
   * @throw std::out_of_range Если стек пуст
   */
  void pop();

  /**
   * @brief Обменивает содержимое двух стеков
   * @param s Другой стек для обмена
   */
  void swap(stack &s) noexcept;

  /**
   * @brief Вставляет несколько элементов в стек
   * @tparam Args Типы аргументов
   * @param args Аргументы для вставки
   */
  template <typename... Args>
  void insert_many_back(Args &&...args);

  /**
   * @brief Возвращает итератор на начало стека
   * @return Итератор на первый элемент
   */
  iterator begin();

  /**
   * @brief Возвращает итератор на конец стека
   * @return Итератор на элемент после последнего
   */
  iterator end();

  /**
   * @brief Возвращает константный итератор на начало стека
   * @return Константный итератор на первый элемент
   */
  const_iterator begin() const;

  /**
   * @brief Возвращает константный итератор на конец стека
   * @return Константный итератор на элемент после последнего
   */
  const_iterator end() const;

 private:
  Container container_;  ///< Контейнер для хранения элементов стека
  friend struct stack_insert_many_access;
};

/**
 * @brief Структура для доступа к контейнеру стека
 */
struct stack_insert_many_access {
  /**
   * @brief Возвращает ссылку на контейнер стека
   * @tparam T Тип элементов стека
   * @tparam Container Тип контейнера
   * @param s Стек
   * @return Ссылка на контейнер
   */
  template <class T, class Container>
  static Container &get_container(stack<T, Container> &s);
};

}  // namespace s21

// clang-format off
#include "./s21_stack_constructors.tpp"
#include "./s21_stack_iterators.tpp"
#include "./s21_stack_operators.tpp"
#include "./s21_stack_access.tpp"
#include "./s21_stack_modifiers.tpp"
#include "./s21_stack_insert_many.tpp"
// clang-format on

#endif  // S21_STACK_H
