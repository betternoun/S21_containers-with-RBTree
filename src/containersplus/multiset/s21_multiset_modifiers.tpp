/**
 * @file s21_multiset_modifiers.tpp
 * @brief Реализация методов модификации для класса multiset
 */

namespace s21 {

/**
 * @brief Удаляет элемент из контейнера по итератору
 *
 * Если в узле несколько дубликатов, уменьшает их количество.
 * Если это последний дубликат, удаляет узел полностью.
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param pos итератор, указывающий на удаляемый элемент
 */
template <typename T>
void multiset<T>::erase(iterator pos) {
  if (pos.it_.iter_node_ == nullptr) return;

  if (pos.it_.iter_node_->value > 1) {
    --pos.it_.iter_node_->value;  // Уменьшаем количество дубликатов
    --copies_;                    // Уменьшаем общее количество элементов
  } else {
    map_.remove(pos.it_.iter_node_->key);  // Удаляем узел полностью
    --copies_;  // Уменьшаем общее количество элементов
  }
}

/**
 * @brief Обменивает содержимое с другим контейнером
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param ms другой контейнер multiset
 */
template <typename T>
void multiset<T>::swap(multiset &ms) noexcept {
  map_.swap(ms.map_);              // Обмениваем базовые деревья
  std::swap(copies_, ms.copies_);  // Обмениваем счетчики элементов
}

/**
 * @brief Удаляет все элементы из контейнера
 *
 * @tparam T тип данных элементов в мультимножестве
 */
template <typename T>
void multiset<T>::clear() {
  if (!empty()) {
    map_.clear();  // Очищаем базовое дерево
    copies_ = 0;   // Сбрасываем счетчик элементов
  }
}

/**
 * @brief Вставляет элемент в контейнер
 *
 * Если элемент уже существует, увеличивает количество его дубликатов.
 * Иначе создает новый узел.
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param value значение для вставки
 * @return typename multiset<T>::iterator итератор, указывающий на вставленный
 * элемент
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::insert(const value_type &value) {
  auto it = map_.find(value);
  if (it != map_.end()) {
    ++it.iter_node_->value;  // Увеличиваем количество дубликатов
    ++copies_;               // Увеличиваем общее количество элементов
    return iterator(it, it.iter_node_->value);
  }
  auto result = map_.insert(value, 1);  // Создаем новый узел
  ++copies_;  // Увеличиваем общее количество элементов
  return iterator(result.first, 1);
}

/**
 * @brief Вспомогательный метод для вставки элемента
 *
 * Аналогичен методу insert, но принимает значение по значению
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param value значение для вставки
 * @return typename multiset<T>::iterator итератор, указывающий на вставленный
 * элемент
 */
template <typename T>
typename multiset<T>::iterator multiset<T>::insert_(value_type value) {
  auto it = map_.find(value);
  if (it != map_.end()) {
    ++it.iter_node_->value;  // Увеличиваем количество дубликатов
    ++copies_;               // Увеличиваем общее количество элементов
    return iterator(it, it.iter_node_->value);
  }
  auto result = map_.insert(value, 1);  // Создаем новый узел
  ++copies_;  // Увеличиваем общее количество элементов
  return iterator(result.first, 1);
}

/**
 * @brief Объединяет текущий контейнер с другим
 *
 * Перемещает все элементы из другого контейнера в текущий.
 * После операции другой контейнер становится пустым.
 *
 * @tparam T тип данных элементов в мультимножестве
 * @param ms другой контейнер multiset
 */
template <typename T>
void multiset<T>::merge(multiset &ms) {
  for (auto it = ms.begin(); it != ms.end();) {
    auto current = it++;
    insert(*current);  // Вставляем каждый элемент из другого контейнера
  }
  ms.clear();  // Очищаем другой контейнер
}

}  // namespace s21
