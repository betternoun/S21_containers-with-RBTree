#ifndef S21_CONTAINERS_H
#define S21_CONTAINERS_H

/**
 * @file s21_containers.h
 * @brief Основной заголовочный файл библиотеки контейнеров
 *
 * Содержит все необходимые включения для работы с реализованными контейнерами
 */

/**
 * @defgroup STL_headers Стандартные заголовки
 * @brief Заголовочные файлы стандартной библиотеки C++
 * @{
 */
#include <limits>  ///< Для работы с numeric_limits (max_size())
#include <stdexcept>  ///< Для стандартных исключений (out_of_range, invalid_argument)
#include <utility>  ///< Для работы с std::pair (используется в map)
/** @} */

/**
 * @defgroup CustomContainers Пользовательские контейнеры
 * @brief Заголовки реализованных контейнеров
 * @{
 */
// clang-format off
#include "./containers/tree/tree.h"      ///< Реализация красно-черного дерева (база для map/set)
#include "./containers/list/s21_list.h"  ///< Двусвязный список (list)
#include "./containers/vector/s21_vector.h" ///< Динамический массив (vector)
#include "./containers/queue/s21_queue.h" ///< Очередь (queue)
#include "./containers/stack/s21_stack.h" ///< Стек (stack)
#include "./containers/map/s21_map.h"     ///< Ассоциативный массив (map)
#include "./containers/set/s21_set.h"     ///< Множество (set)
// clang-format on
/** @} */

#endif  // S21_CONTAINERS_H
