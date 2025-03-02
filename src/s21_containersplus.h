#ifndef S21_CONTAINERSPLUS_H
#define S21_CONTAINERSPLUS_H

/**
 * @file s21_containersplus.h
 * @brief Заголовочный файл с расширенными контейнерами библиотеки
 *
 * Содержит дополнительные контейнеры, расширяющие базовую функциональность
 */

/**
 * @defgroup BaseContainer Базовый контейнер
 * @brief Основной заголовок базовых контейнеров
 */
#include "./s21_containers.h"  ///< Основная библиотека контейнеров

/**
 * @defgroup PlusContainers Дополнительные контейнеры
 * @brief Заголовки реализованных расширенных контейнеров
 * @{
 */
// clang-format off
#include "./containersplus/array/s21_array.h"    ///< Статический массив фиксированного размера (array)
#include "./containersplus/multiset/s21_multiset.h" ///< Множество с дубликатами (multiset)
// clang-format on
/** @} */

#endif  // S21_CONTAINERSPLUS_H
