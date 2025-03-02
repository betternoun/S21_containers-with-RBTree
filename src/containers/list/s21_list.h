/**
 * @file s21_list.h
 * @brief Заголовочный файл для класса list - реализации двусвязного списка
 */

#ifndef S21_LIST_H
#define S21_LIST_H

namespace s21 {

/**
 * @brief Шаблонный класс двусвязного списка
 * @tparam T Тип данных, хранимых в списке
 */
template <typename T>
class list {
 public:
  /**
   * @brief Внутренний класс узла списка
   *
   * Представляет собой элемент двусвязного списка, содержащий данные и
   * указатели на предыдущий и следующий узлы.
   */
  class ListNode {
   public:
    T data;          ///< Данные узла
    ListNode* next;  ///< Указатель на следующий узел
    ListNode* prev;  ///< Указатель на предыдущий узел

    ListNode(const T& data, ListNode* prev = nullptr, ListNode* next = nullptr);
    ListNode(T&& data, ListNode* prev = nullptr, ListNode* next = nullptr);
  };

  /**
   * @brief Класс итератора списка
   *
   * Предоставляет возможность обхода элементов списка в обоих направлениях.
   */
  class ListIterator {
   public:
    using pointer = ListNode*;
    using reference = T&;

    /**
     * @brief Конструктор итератора
     * @param node Узел, на который указывает итератор
     */
    explicit ListIterator(pointer node);

    reference operator*();
    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    bool operator==(const ListIterator& other) const noexcept;
    bool operator!=(const ListIterator& other) const noexcept;

    /**
     * @brief Проверяет, принадлежит ли итератор текущему списку
     * @param list Список, для которого проверяется принадлежность
     * @return true, если итератор принадлежит списку, иначе false
     */
    bool is_valid(const list& list) const;

   private:
    pointer node;
    // Позволяет классу list доступ к приватным членам
    friend class list;
  };

  /**
   * @brief Класс константного итератора списка
   *
   * Предоставляет возможность обхода элементов списка в обоих направлениях
   * без возможности изменения элементов.
   */
  class ListConstIterator {
   public:
    using pointer = const ListNode*;
    using reference = const T&;

    explicit ListConstIterator(pointer node);
    ListConstIterator(const ListIterator& other);

    reference operator*() const;
    ListConstIterator& operator++();
    ListConstIterator operator++(int);
    ListConstIterator& operator--();
    bool operator==(const ListConstIterator& other) const noexcept;
    bool operator!=(const ListConstIterator& other) const noexcept;
    bool is_valid(const list& list) const;

   private:
    pointer node;
    // Дружественный доступ для класса list
    friend class list;
  };

  // Определения типов
  using value_type = T;                      ///< Тип хранимых значений
  using reference = T&;                      ///< Ссылка на значение
  using const_reference = const T&;          ///< Константная ссылка на значение
  using iterator = ListIterator;             ///< Тип итератора
  using const_iterator = ListConstIterator;  ///< Тип константного итератора
  using size_type = size_t;                  ///< Тип для размера списка

  /**
   * @brief Конструктор по умолчанию
   *
   * Создает пустой список.
   */
  list();

  /**
   * @brief Конструктор копирования
   * @param other Копируемый список
   *
   * Создает новый список как копию существующего.
   */
  list(const list& other);

  /**
   * @brief Конструктор перемещения
   * @param other Перемещаемый список
   *
   * Создает новый список, перемещая содержимое другого списка.
   */
  list(list&& other) noexcept;

  /**
   * @brief Конструктор из списка инициализации
   * @param init Список инициализации
   *
   * Создает список с элементами из списка инициализации.
   */
  list(std::initializer_list<T> init);

  /**
   * @brief Конструктор с заданным количеством элементов
   * @param count Количество элементов
   * @param value Значение для инициализации элементов (по умолчанию T())
   *
   * Создает список с указанным количеством элементов, инициализированных
   * заданным значением.
   */
  list(size_type count, const T& value = T());

  /**
   * @brief Деструктор
   *
   * Освобождает память, занятую списком.
   */
  ~list();

  /**
   * @brief Оператор присваивания копированием
   * @param other Копируемый список
   * @return Ссылка на текущий список
   */
  list& operator=(const list& other);

  /**
   * @brief Оператор присваивания перемещением
   * @param other Перемещаемый список
   * @return Ссылка на текущий список
   */
  list& operator=(list&& other) noexcept;

  /**
   * @brief Возвращает итератор на начало списка
   * @return Итератор на первый элемент
   */
  iterator begin();

  /**
   * @brief Возвращает итератор на конец списка
   * @return Итератор, указывающий на позицию после последнего элемента
   */
  iterator end();

  /**
   * @brief Возвращает константный итератор на начало списка
   * @return Константный итератор на первый элемент
   */
  const_iterator begin() const;

  /**
   * @brief Возвращает константный итератор на конец списка
   * @return Константный итератор, указывающий на позицию после последнего
   * элемента
   */
  const_iterator end() const;

  /**
   * @brief Возвращает константный итератор на начало списка
   * @return Константный итератор на первый элемент
   */
  const_iterator cbegin() const;

  /**
   * @brief Возвращает константный итератор на конец списка
   * @return Константный итератор, указывающий на позицию после последнего
   * элемента
   */
  const_iterator cend() const;

  /**
   * @brief Возвращает ссылку на первый элемент
   * @return Ссылка на первый элемент
   * @throw std::out_of_range если список пуст
   */
  reference front();

  /**
   * @brief Возвращает константную ссылку на первый элемент
   * @return Константная ссылка на первый элемент
   * @throw std::out_of_range если список пуст
   */
  const_reference front() const;

  /**
   * @brief Возвращает ссылку на последний элемент
   * @return Ссылка на последний элемент
   * @throw std::out_of_range если список пуст
   */
  reference back();

  /**
   * @brief Возвращает константную ссылку на последний элемент
   * @return Константная ссылка на последний элемент
   * @throw std::out_of_range если список пуст
   */
  const_reference back() const;

  /**
   * @brief Добавляет элемент в конец списка
   * @param value Добавляемое значение
   */
  void push_back(const_reference value);

  /**
   * @brief Добавляет элемент в конец списка (с перемещением)
   * @param value Перемещаемое значение
   */
  void push_back(value_type&& value);

  /**
   * @brief Удаляет последний элемент
   * @throw std::out_of_range если список пуст
   */
  void pop_back();

  /**
   * @brief Добавляет элемент в начало списка
   * @param value Добавляемое значение
   */
  void push_front(const_reference value);

  /**
   * @brief Удаляет первый элемент
   * @throw std::out_of_range если список пуст
   */
  void pop_front();

  /**
   * @brief Вставляет элемент перед указанной позицией
   * @param pos Итератор на позицию вставки
   * @param value Вставляемое значение
   * @return Итератор на вставленный элемент
   * @throw std::invalid_argument если итератор невалиден
   */
  iterator insert(iterator pos, const_reference value);

  /**
   * @brief Удаляет элемент в указанной позиции
   * @param pos Итератор на удаляемый элемент
   * @throw std::invalid_argument если итератор невалиден
   */
  void erase(iterator pos);

  /**
   * @brief Очищает список
   */
  void clear();

  /**
   * @brief Обменивает содержимое с другим списком
   * @param other Список для обмена
   */
  void swap(list& other) noexcept;

  /**
   * @brief Разворачивает список
   */
  void reverse();

  /**
   * @brief Удаляет последовательные дубликаты
   */
  void unique();

  /**
   * @brief Сортирует список
   */
  void sort();

  /**
   * @brief Проверяет, пуст ли список
   * @return true если список пуст, иначе false
   */
  [[nodiscard]] bool empty() const noexcept;

  /**
   * @brief Возвращает размер списка
   * @return Количество элементов в списке
   */
  [[nodiscard]] size_type size() const noexcept;

  /**
   * @brief Объединяет два отсортированных списка
   * @param other Список для объединения
   */
  void merge(list& other);

  /**
   * @brief Возвращает максимально возможный размер списка
   * @return Максимальное количество элементов
   */
  [[nodiscard]] size_type max_size() const noexcept;

  /**
   * @brief Перемещает все элементы другого списка перед указанной позицией
   * @param pos Позиция вставки
   * @param other Список, элементы которого будут перемещены
   */
  void splice(const_iterator pos, list& other);

  /**
   * @brief Вставляет элементы перед указанной позицией
   * @param pos Позиция вставки
   * @param args Аргументы для вставки
   * @return Итератор на первый вставленный элемент
   */
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);

  /**
   * @brief Вставляет элементы в конец списка
   * @param args Аргументы для вставки
   */
  template <typename... Args>
  void insert_many_back(Args&&... args);

  /**
   * @brief Вставляет элементы в начало списка
   * @param args Аргументы для вставки
   */
  template <typename... Args>
  void insert_many_front(Args&&... args);

 private:
  ListNode* head;   ///< Указатель на первый элемент
  ListNode* tail;   ///< Указатель на последний элемент
  size_type size_;  ///< Размер списка

  /**
   * @brief Вспомогательный метод для сортировки слиянием
   * @param node Начальный узел для сортировки
   * @return Указатель на отсортированный список
   */
  ListNode* mergeSort(ListNode* node);

  /**
   * @brief Находит середину списка
   * @param node Начальный узел
   * @return Указатель на средний узел
   */
  ListNode* getMiddle(ListNode* node);

  /**
   * @brief Объединяет два отсортированных списка
   * @param left Первый список
   * @param right Второй список
   * @return Указатель на объединенный список
   */
  ListNode* merge(ListNode* left, ListNode* right);
};

}  // namespace s21

// clang-format off
#include "./s21_list_node.tpp"
#include "./s21_list_constructors.tpp"
#include "./s21_list_operators.tpp"
#include "./s21_list_iterators.tpp"
#include "./s21_list_access.tpp"
#include "./s21_list_modifiers.tpp"
#include "./s21_list_algorithms.tpp"
#include "./s21_list_capacity.tpp"
#include "./s21_list_insert_many.tpp"
// clang-format on

#endif  // S21_LIST_H
