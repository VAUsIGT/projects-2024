# CMakeList.txt: проект CMake для Project3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME example) #задание значения переменной
project("${PROJECT_NAME}") #устанавливаем имя проекта
set(CMAKE_CXX_STANDARD 17) #устанавливаем 17 стандарт языка (набор поддерживаемых библиотек\команд)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (Project3 "Project3.cpp" "Project3.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Project3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

# подключить header-файлы
include_directories("inc")

# Сказать программе, что должен быть исполняемый файл и что в него входит
add_executable("${PROJECT_NAME}" Project3.cpp inc/func.hpp src/func.cpp)

# Копирование файла
file(COPY "input.txt" DESTINATION "/")
