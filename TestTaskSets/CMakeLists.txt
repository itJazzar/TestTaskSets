# CMakeList.txt: проект CMake для TestTaskSets; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TestTaskSets "main.cpp" "document.h" "document.cpp" "kit.h" "kit.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestTaskSets PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
