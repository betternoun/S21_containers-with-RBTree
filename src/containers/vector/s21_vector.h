/**
 * @file s21_vector.h
 * @brief Заголовочный файл для класса vector - реализации динамического массива
 */

#ifndef S21_VECTOR_H
#define S21_VECTOR_H

namespace s21 {

/**
 * @brief Шаблонный класс vector, реализующий динамический массив
 * @details Реализация контейнера vector, аналогичного std::vector из STL
 * @tparam T Тип элементов, хранящихся в векторе
 */
template <typename T>
class vector {
 public:
  /**
   * @brief Предварительное объявление класса итератора
   */
  class VectorIterator;

  /**
   * @brief Предварительное объявление класса константного итератора
   */
  class VectorConstIterator;

  /**
   * @brief Определение типа значения, хранящегося в векторе
   */
  using value_type = T;

  /**
   * @brief Определение типа ссылки на значение
   */
  using reference = value_type&;

  /**
   * @brief Определение типа константной ссылки на значение
   */
  using const_reference = const value_type&;

  /**
   * @brief Определение типа итератора
   */
  using iterator = VectorIterator;

  /**
   * @brief Определение типа константного итератора
   */
  using const_iterator = VectorConstIterator;

  /**
   * @brief Определение типа для размера и индексов
   */
  using size_type = size_t;

  /**
   * @brief Определение типа указателя на значение
   */
  using pointer = T*;

  /**
   * @brief Определение типа константного указателя на значение
   */
  using const_pointer = const pointer;

 private:
  /**
   * @brief Текущее количество элементов в векторе
   */
  size_type size_;

  /**
   * @brief Текущая емкость вектора (размер выделенной памяти)
   */
  size_type capacity_;

  /**
   * @brief Указатель на динамически выделенный массив элементов
   */
  value_type* data_;

 public:
  /**
   * @brief Конструктор по умолчанию
   * @details Создает пустой вектор с минимальной емкостью
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  explicit vector();

  /**
   * @brief Конструктор с указанием размера
   * @details Создает вектор заданного размера, заполненный значениями по
   * умолчанию
   * @param[in] n Начальный размер вектора
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  explicit vector(const size_type n);

  /**
   * @brief Конструктор из списка инициализации
   * @details Создает вектор и инициализирует его элементами из списка
   * @param[in] items Список инициализации
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  vector(std::initializer_list<value_type> const& items);

  /**
   * @brief Конструктор копирования
   * @details Создает копию существующего вектора
   * @param[in] v Копируемый вектор
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  vector(const vector& v);

  /**
   * @brief Конструктор перемещения
   * @details Перемещает ресурсы из другого вектора
   * @param[in] v Перемещаемый вектор
   * @note Не выбрасывает исключений (noexcept)
   */
  vector(vector&& v) noexcept;

  /**
   * @brief Конструктор с размером и значением
   * @details Создает вектор заданного размера, заполненный указанным значением
   * @param[in] n Размер вектора
   * @param[in] value Значение для инициализации элементов
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  vector(size_type n, const_reference value);

  /**
   * @brief Деструктор
   * @details Освобождает выделенную память
   */
  ~vector();

  /**
   * @brief Оператор перемещающего присваивания
   * @details Перемещает ресурсы из другого вектора
   * @param[in] v Перемещаемый вектор
   * @return Ссылка на текущий вектор
   * @note Не выбрасывает исключений (noexcept)
   */
  vector& operator=(vector&& v) noexcept;

  /**
   * @brief Оператор копирующего присваивания
   * @details Копирует содержимое другого вектора
   * @param[in] v Копируемый вектор
   * @return Ссылка на текущий вектор
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  vector& operator=(const vector& v);

  /**
   * @brief Доступ к элементу с проверкой границ
   * @details Возвращает ссылку на элемент по индексу с проверкой выхода за
   * границы
   * @param[in] pos Индекс элемента
   * @return Ссылка на элемент
   * @throw std::out_of_range если индекс выходит за границы вектора
   */
  reference at(size_type pos);

  /**
   * @brief Оператор доступа к элементу
   * @details Возвращает ссылку на элемент по индексу без проверки границ
   * @param[in] pos Индекс элемента
   * @return Ссылка на элемент
   */
  reference operator[](size_type pos);

  /**
   * @brief Доступ к первому элементу
   * @details Возвращает ссылку на первый элемент вектора
   * @return Константная ссылка на первый элемент
   * @throw std::out_of_range если вектор пуст
   */
  const_reference front();

  /**
   * @brief Доступ к последнему элементу
   * @details Возвращает ссылку на последний элемент вектора
   * @return Константная ссылка на последний элемент
   * @throw std::out_of_range если вектор пуст
   */
  const_reference back() const;

  /**
   * @brief Прямой доступ к данным
   * @details Возвращает указатель на внутренний массив
   * @return Указатель на данные
   */
  pointer data() const;

  /**
   * @brief Проверка на пустоту
   * @details Проверяет, содержит ли вектор элементы
   * @return true если вектор пуст, false иначе
   */
  [[nodiscard]] bool empty() const;

  /**
   * @brief Получение размера
   * @details Возвращает текущее количество элементов
   * @return Количество элементов в векторе
   */
  [[nodiscard]] size_type size() const;

  /**
   * @brief Получение максимального размера
   * @details Возвращает максимально возможное количество элементов
   * @return Максимальный размер вектора
   */
  [[nodiscard]] size_type max_size() const;

  /**
   * @brief Резервирование памяти
   * @details Выделяет память под указанное количество элементов
   * @param[in] size Требуемая емкость
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  void reserve(size_type size);

  /**
   * @brief Получение емкости
   * @details Возвращает текущий размер выделенной памяти
   * @return Емкость вектора
   */
  [[nodiscard]] size_type capacity() const;

  /**
   * @brief Уменьшение емкости
   * @details Уменьшает емкость вектора до его размера
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  void shrink_to_fit();

  /**
   * @brief Получение итератора на начало
   * @details Возвращает итератор на первый элемент
   * @return Итератор на начало вектора
   */
  iterator begin();

  /**
   * @brief Получение константного итератора на начало
   * @details Возвращает константный итератор на первый элемент
   * @return Константный итератор на начало вектора
   */
  const_iterator begin() const;

  /**
   * @brief Получение итератора на конец
   * @details Возвращает итератор на позицию после последнего элемента
   * @return Итератор на конец вектора
   */
  iterator end();

  /**
   * @brief Получение константного итератора на конец
   * @details Возвращает константный итератор на позицию после последнего
   * элемента
   * @return Константный итератор на конец вектора
   */
  const_iterator end() const;

  /**
   * @brief Получение константного итератора на начало
   * @details Возвращает константный итератор на первый элемент
   * @return Константный итератор на начало вектора
   */
  const_iterator cbegin() const;

  /**
   * @brief Получение константного итератора на конец
   * @details Возвращает константный итератор на позицию после последнего
   * элемента
   * @return Константный итератор на конец вектора
   */
  const_iterator cend() const;

  /**
   * @brief Очистка вектора
   * @details Удаляет все элементы из вектора
   */
  void clear();

  /**
   * @brief Вставка элемента
   * @details Вставляет элемент в указанную позицию
   * @param[in] pos Итератор на позицию вставки
   * @param[in] value Вставляемое значение
   * @return Итератор на вставленный элемент
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  iterator insert(iterator pos, const_reference value);

  /**
   * @brief Удаление элемента
   * @details Удаляет элемент в указанной позиции
   * @param[in] pos Итератор на удаляемый элемент
   * @throw std::out_of_range если позиция невалидна
   */
  void erase(iterator pos);

  /**
   * @brief Добавление элемента в конец
   * @details Добавляет элемент в конец вектора
   * @param[in] value Добавляемое значение
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  void push_back(const_reference value);

  /**
   * @brief Удаление последнего элемента
   * @details Удаляет последний элемент вектора
   * @throw std::out_of_range если вектор пуст
   */
  void pop_back();

  /**
   * @brief Обмен содержимым
   * @details Обменивает содержимое с другим вектором
   * @param[in,out] other Другой вектор для обмена
   * @note Не выбрасывает исключений (noexcept)
   */
  void swap(vector& other) noexcept;

  /**
   * @brief Вставка нескольких элементов
   * @details Вставляет произвольное количество элементов в указанную позицию
   * @tparam Args Типы аргументов для вставки
   * @param[in] pos Итератор на позицию вставки
   * @param[in] args Аргументы для вставки
   * @return Итератор на первый вставленный элемент
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);

  /**
   * @brief Добавление нескольких элементов в конец
   * @details Добавляет произвольное количество элементов в конец вектора
   * @tparam Args Типы аргументов для добавления
   * @param[in] args Аргументы для добавления
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  template <typename... Args>
  void insert_many_back(Args&&... args);

  /**
   * @brief Конструирование элемента на месте
   * @details Создает новый элемент непосредственно в памяти вектора
   * @tparam Args Типы аргументов для конструирования
   * @param[in] pos Итератор на позицию вставки
   * @param[in] args Аргументы для конструирования
   * @return Итератор на созданный элемент
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args);

  /**
   * @brief Присваивание элементов из диапазона
   * @details Заменяет содержимое вектора элементами из указанного диапазона
   * @tparam InputIt Тип входного итератора
   * @param[in] first Итератор на начало диапазона
   * @param[in] last Итератор на конец диапазона
   * @throw std::bad_alloc при ошибке выделения памяти
   */
  template <typename InputIt>
  void assign(InputIt first, InputIt last);

  /**
   * @brief Класс константного итератора
   * @details Предоставляет доступ только для чтения к элементам вектора
   */
  class VectorConstIterator {
   public:
    /**
     * @brief Категория итератора
     */
    using iterator_category = std::random_access_iterator_tag;

    /**
     * @brief Тип значения
     */
    using value_type = typename vector<T>::value_type;

    /**
     * @brief Тип разности
     */
    using difference_type = std::ptrdiff_t;

    /**
     * @brief Тип указателя
     */
    using pointer = vector<T>::pointer;

    /**
     * @brief Тип ссылки
     */
    using reference = vector<T>::reference;

    /**
     * @brief Конструктор с указателем
     * @param[in] ptr Указатель на элемент
     */
    explicit VectorConstIterator(const pointer ptr) : ptr_(ptr) {}

    /**
     * @brief Конструктор по умолчанию
     */
    VectorConstIterator() : ptr_(nullptr) {}

    /**
     * @brief Конструктор преобразования
     * @param[in] other Обычный итератор
     */
    VectorConstIterator(const VectorIterator& other);

    /**
     * @brief Оператор разыменования
     * @return Константная ссылка на элемент
     */
    const_reference operator*() const;

    /**
     * @brief Префиксный инкремент
     * @return Ссылка на итератор
     */
    VectorConstIterator operator++();

    /**
     * @brief Префиксный декремент
     * @return Ссылка на итератор
     */
    VectorConstIterator operator--();

    /**
     * @brief Постфиксный инкремент
     * @return Копия итератора до инкремента
     */
    VectorConstIterator operator++(int);

    /**
     * @brief Постфиксный декремент
     * @return Копия итератора до декремента
     */
    VectorConstIterator operator--(int);

    /**
     * @brief Оператор сложения
     * @param[in] n Количество позиций
     * @return Новый итератор
     */
    VectorConstIterator operator+(int n);

    /**
     * @brief Оператор вычитания
     * @param[in] n Количество позиций
     * @return Новый итератор
     */
    VectorConstIterator operator-(int n);

    /**
     * @brief Оператор разности
     * @param[in] other Другой итератор
     * @return Количество элементов между итераторами
     */
    size_type operator-(const VectorConstIterator& other);

    /**
     * @brief Оператор равенства
     * @param[in] other Другой итератор
     * @return true если итераторы равны
     */
    bool operator==(const VectorConstIterator& other) const;

    /**
     * @brief Оператор неравенства
     * @param[in] other Другой итератор
     * @return true если итераторы не равны
     */
    bool operator!=(const VectorConstIterator& other) const;

    /**
     * @brief Получение указателя
     * @return Указатель на текущий элемент
     */
    pointer get_ptr() const;

   private:
    /**
     * @brief Указатель на текущий элемент
     */
    pointer ptr_;
  };

  /**
   * @brief Оператор равенства векторов
   * @param[in] other Другой вектор
   * @return true если векторы равны
   */
  bool operator==(const vector& other) const;

  /**
   * @brief Оператор неравенства векторов
   * @param[in] other Другой вектор
   * @return true если векторы не равны
   */
  bool operator!=(const vector& other) const;
};

/**
 * @brief Класс итератора
 * @details Предоставляет доступ для чтения и записи к элементам вектора
 */
template <typename T>
class vector<T>::VectorIterator {
 public:
  /**
   * @brief Категория итератора
   */
  using iterator_category = std::random_access_iterator_tag;

  /**
   * @brief Тип значения
   */
  using value_type = typename vector<T>::value_type;

  /**
   * @brief Тип разности
   */
  using difference_type = std::ptrdiff_t;

  /**
   * @brief Тип указателя
   */
  using pointer = vector<T>::pointer;

  /**
   * @brief Тип ссылки
   */
  using reference = vector<T>::reference;

  /**
   * @brief Конструктор по умолчанию
   */
  VectorIterator();

  /**
   * @brief Конструктор с указателем
   * @param[in] ptr Указатель на элемент
   */
  explicit VectorIterator(const pointer ptr);

  /**
   * @brief Оператор разыменования
   * @return Ссылка на элемент
   */
  reference operator*();

  /**
   * @brief Префиксный инкремент
   * @return Ссылка на итератор
   */
  VectorIterator& operator++();

  /**
   * @brief Префиксный декремент
   * @return Ссылка на итератор
   */
  VectorIterator& operator--();

  /**
   * @brief Постфиксный инкремент
   * @return Копия итератора до инкремента
   */
  VectorIterator operator++(int);

  /**
   * @brief Постфиксный декремент
   * @return Копия итератора до декремента
   */
  VectorIterator operator--(int);

  /**
   * @brief Оператор сложения
   * @param[in] n Количество позиций
   * @return Новый итератор
   */
  VectorIterator operator+(int n);

  /**
   * @brief Оператор вычитания
   * @param[in] n Количество позиций
   * @return Новый итератор
   */
  VectorIterator operator-(int n);

  /**
   * @brief Оператор "меньше"
   * @param[in] other Другой итератор
   * @return true если текущий итератор меньше
   */
  bool operator<(const VectorIterator& other) const;

  /**
   * @brief Оператор разности
   * @param[in] other Другой итератор
   * @return Количество элементов между итераторами
   */
  int operator-(const VectorIterator& other);

  /**
   * @brief Оператор равенства
   * @param[in] other Другой итератор
   * @return true если итераторы равны
   */
  bool operator==(const VectorIterator& other) const;

  /**
   * @brief Оператор неравенства
   * @param[in] other Другой итератор
   * @return true если итераторы не равны
   */
  bool operator!=(const VectorIterator& other) const;

  /**
   * @brief Объявление дружественного класса
   */
  friend class VectorConstIterator;

 private:
  /**
   * @brief Указатель на текущий элемент
   */
  pointer ptr_;
};

}  // namespace s21

// clang-format off
#include "./s21_vector_utilities.tpp"
#include "./s21_vector_iterators.tpp"
#include "./s21_vector_const_iterators.tpp"
#include "./s21_vector_constructors.tpp"
#include "./s21_vector_operations.tpp"
#include "./s21_vector_insert_many.tpp"
#include "./s21_vector_emplace.tpp"
// clang-format on

#endif  // S21_VECTOR_H
