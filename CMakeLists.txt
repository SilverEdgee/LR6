cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Главный исполняемый файл
add_executable(main main.cpp onlyFunc.cpp)

# Подключение Google Test
find_package(GTest REQUIRED)

# Тесты
add_executable(tests googletest.cpp onlyFunc.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)

option(USE_ASAN "Enable AddressSanitizer" ON)
option(USE_TSAN "Enable ThreadSanitizer" OFF)

if (USE_ASAN)
    message(STATUS "AddressSanitizer enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
endif()

if (USE_TSAN)
    message(STATUS "ThreadSanitizer enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fno-omit-frame-pointer -g")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=thread")
endif()



# Включаем тесты
enable_testing()

