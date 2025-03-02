cmake_minimum_required(VERSION 3.30)
project(s21_containers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем пути для исходников
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/../s21_containers.h"
    "${CMAKE_SOURCE_DIR}/../s21_containersplus.h"
    "${CMAKE_SOURCE_DIR}/../containers/*/*.h"
    "${CMAKE_SOURCE_DIR}/../containersplus/*/*.h"
)

# Создаём статическую библиотеку
add_library(s21_containers STATIC ${SOURCES})

# Указываем язык для целевой библиотеки
set_target_properties(s21_containers PROPERTIES LINKER_LANGUAGE CXX)

# Добавляем флаги компиляции
target_compile_options(s21_containers PRIVATE
    -g          # Включение отладочной информации
    -O0         # Отключение оптимизаций
    -Wall       # Включение всех предупреждений
    -Wextra     # Включение дополнительных предупреждений
    -Wpedantic  # Включение строгих стандартов C++
    --coverage  # Включение покрытия кода
    -pedantic  # Включение строгих стандартов C++
)

# Настройка Google Test
enable_testing()
find_package(GTest REQUIRED)

# Указываем пути для тестов
file(GLOB TEST_SOURCES
    "${CMAKE_SOURCE_DIR}/*/*.cpp"
)

# Добавляем тесты, можно указать конкретные файлы вместо переменной
add_executable(run_tests ${TEST_SOURCES})

# Линкуем библиотеку и GTest
target_link_libraries(run_tests PRIVATE s21_containers GTest::GTest GTest::Main pthread)

# Указываем директорию с заголовочными файлами
target_include_directories(run_tests PRIVATE "${CMAKE_SOURCE_DIR}/../")

# Определяем тесты
add_test(NAME MatrixTests COMMAND run_tests)

# Добавляем команду для сборки библиотеки перед тестами
add_dependencies(run_tests s21_containers)

# Поддержка покрытия кода
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

find_program(LCOV lcov)
find_program(GENHTML genhtml)

add_custom_target(coverage
    COMMAND ${LCOV} --capture --directory . --output-file coverage.info --exclude "*tests/*" --exclude "*c++/*" --exclude "*gtest/*"
    COMMAND ${GENHTML} coverage.info --output-directory ../../report/coverage
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    VERBATIM
)
