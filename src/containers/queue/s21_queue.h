/**
 * @file s21_queue.h
 * @brief Заголовочный файл для класса queue - реализации очереди
 */

#ifndef S21_QUEUE_H
#define S21_QUEUE_H

namespace s21 {

/**
 * @brief Шаблонный класс очереди
 * @tparam T Тип данных, хранимых в очереди
 * @tparam Container Тип контейнера, используемого для реализации очереди (по
 * умолчанию s21::list<T>)
 */
template <class T, class Container = s21::list<T>>
class queue {
 public:
  using value_type = T;              ///< Тип элементов, хранимых в очереди
  using reference = T&;              ///< Тип ссылки на элемент
  using const_reference = const T&;  ///< Тип константной ссылки на элемент
  using size_type = size_t;          ///< Тип для размера очереди

 public:
  /**
   * @brief Конструктор по умолчанию
   */
  queue();

  /**
   * @brief Конструктор с инициализацией через список
   * @param items Список инициализации
   */
  queue(std::initializer_list<value_type> const& items);

  /**
   * @brief Конструктор копирования
   * @param q Очередь для копирования
   */
  queue(const queue& q);

  /**
   * @brief Конструктор перемещения
   * @param q Очередь для перемещения
   */
  queue(queue&& q) noexcept;

  /**
   * @brief Деструктор
   */
  ~queue();

  /**
   * @brief Оператор присваивания с перемещением
   * @param q Очередь для перемещения
   * @return Ссылка на текущий объект
   */
  queue& operator=(queue&& q) noexcept;

  /**
   * @brief Оператор присваивания с копированием
   * @param q Очередь для копирования
   * @return Ссылка на текущий объект
   */
  queue& operator=(const queue& q);

  /**
   * @brief Возвращает ссылку на первый элемент очереди
   * @return Ссылка на первый элемент
   * @throw std::out_of_range Если очередь пуста
   */
  reference front();

  /**
   * @brief Возвращает константную ссылку на первый элемент очереди
   * @return Константная ссылка на первый элемент
   * @throw std::out_of_range Если очередь пуста
   */
  const_reference front() const;

  /**
   * @brief Возвращает ссылку на последний элемент очереди
   * @return Ссылка на последний элемент
   * @throw std::out_of_range Если очередь пуста
   */
  reference back();

  /**
   * @brief Возвращает константную ссылку на последний элемент очереди
   * @return Константная ссылка на последний элемент
   * @throw std::out_of_range Если очередь пуста
   */
  const_reference back() const;

  /**
   * @brief Проверяет, пуста ли очередь
   * @return true, если очередь пуста, иначе false
   */
  [[nodiscard]] bool empty() const noexcept;

  /**
   * @brief Возвращает количество элементов в очереди
   * @return Количество элементов
   */
  [[nodiscard]] size_type size() const noexcept;

  /**
   * @brief Добавляет элемент в конец очереди
   * @param value Значение для добавления
   */
  void push(const_reference value);

  /**
   * @brief Добавляет элемент в конец очереди (с перемещением)
   * @param value Значение для добавления
   */
  void push(value_type&& value);

  /**
   * @brief Удаляет первый элемент очереди
   */
  void pop();

  /**
   * @brief Обменивает содержимое двух очередей
   * @param q Очередь для обмена
   */
  void swap(queue& q) noexcept;

  /**
   * @brief Добавляет несколько элементов в конец очереди
   * @tparam Args Типы аргументов
   * @param args Аргументы для добавления
   */
  template <typename... Args>
  void insert_many_back(Args&&... args);

 private:
  Container container_;  ///< Внутренний контейнер для хранения элементов
};

}  // namespace s21

// clang-format off
#include "./s21_queue_constructors.tpp"
#include "./s21_queue_accessors.tpp"
#include "./s21_queue_modifiers.tpp"
#include "./s21_queue_insert_many.tpp"
// clang-format on

#endif  // S21_QUEUE_H
