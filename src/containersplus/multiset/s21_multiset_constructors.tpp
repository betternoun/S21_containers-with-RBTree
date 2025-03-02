/**
 * @file s21_multiset_constructors.tpp
 * @brief Реализация конструкторов и операторов присваивания для класса multiset
 */

namespace s21 {

/**
 * @brief Конструктор по умолчанию
 *
 * Создает пустой контейнер multiset с нулевым количеством элементов
 *
 * @tparam T тип данных элементов в мультимножестве
 */
template <typename T>
multiset<T>::multiset() : map_(), copies_(0) {}

/**
 * @brief Конструктор копирования
 *
 * Создает копию существующего контейнера multiset
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param ms другой объект multiset для копирования
 */
template <typename T>
multiset<T>::multiset(const multiset &ms)
    : map_(ms.map_), copies_(ms.copies_) {}

/**
 * @brief Конструктор перемещения
 *
 * Перемещает ресурсы из другого контейнера multiset
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param ms другой объект multiset для перемещения
 */
template <typename T>
multiset<T>::multiset(multiset &&ms) noexcept
    : map_(std::move(ms.map_)), copies_(ms.copies_) {
  ms.copies_ = 0;  // Обнуляем количество элементов в исходном контейнере
}

/**
 * @brief Конструктор со списком инициализации
 *
 * Создает контейнер multiset и заполняет его элементами из списка
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param items список элементов для инициализации
 */
template <typename T>
multiset<T>::multiset(std::initializer_list<value_type> const &items)
    : multiset() {
  for (const auto &item : items) {
    insert(item);  // Вставляем каждый элемент из списка
  }
}

/**
 * @brief Оператор присваивания копированием
 *
 * Копирует содержимое другого контейнера multiset
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param other другой объект multiset для копирования
 * @return multiset& ссылка на текущий объект
 */
template <typename T>
multiset<T> &multiset<T>::operator=(const multiset &other) {
  if (this != &other) {  // Проверка на самоприсваивание
    map_ = other.map_;
    copies_ = other.copies_;
  }
  return *this;
}

/**
 * @brief Оператор присваивания перемещением
 *
 * Перемещает ресурсы из другого контейнера multiset
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param ms другой объект multiset для перемещения
 * @return multiset& ссылка на текущий объект
 */
template <typename T>
multiset<T> &multiset<T>::operator=(multiset &&ms) noexcept {
  if (this != &ms) {  // Проверка на самоприсваивание
    map_ = std::move(ms.map_);
    copies_ = ms.copies_;
    ms.copies_ = 0;  // Обнуляем количество элементов в исходном контейнере
  }
  return *this;
}

}  // namespace s21
