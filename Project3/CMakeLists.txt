# CMakeList.txt: проект CMake для Project3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Project3 "Project3.cpp" "Project3.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Project3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

# подключить header-файлы
include_directories("inc")

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" Project3.cpp inc/func.hpp src/func.cpp)

# Копирование файла
file(COPY "input.txt" DESTINATION "/")
