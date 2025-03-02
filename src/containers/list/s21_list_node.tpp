/**
 * @file s21_list_node.tpp
 * @brief Реализация узлов списка
 */

namespace s21 {

/**
 * @brief Конструктор узла списка с копированием данных
 * @param data Данные для копирования
 * @param prev Указатель на предыдущий узел
 * @param next Указатель на следующий узел
 */
template <typename T>
list<T>::ListNode::ListNode(const T& data, ListNode* prev, ListNode* next)
    : data(data), prev(prev), next(next) {}

/**
 * @brief Конструктор узла списка с перемещением данных
 * @param data Данные для перемещения
 * @param prev Указатель на предыдущий узел
 * @param next Указатель на следующий узел
 */
template <typename T>
list<T>::ListNode::ListNode(T&& data, ListNode* prev, ListNode* next)
    : data(std::move(data)), prev(prev), next(next) {}

}  // namespace s21
