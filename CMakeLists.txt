# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TestTaskSets")

# Включите подпроекты.
add_subdirectory ("TestTaskSets")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    Document.cpp
    Kit.cpp
)

#add_executable(TestTaskSets ${SOURCES})

target_include_directories(TestTaskSets PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Для сборки под Windows
if (WIN32)
    # Дополнительные настройки для Windows
    target_compile_options(TestTaskSets PRIVATE /W4)  # Уровень предупреждений
    target_link_libraries(TestTaskSets PRIVATE)
elseif (UNIX)
    # Дополнительные настройки для Linux
    target_compile_options(TestTaskSets PRIVATE -Wall -Wextra)  # Уровень предупреждений
    target_link_libraries(TestTaskSets PRIVATE)
endif ()