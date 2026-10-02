cmake_minimum_required(VERSION 3.16)

project(PtrBox VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

add_library(project_options INTERFACE)
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(project_options INTERFACE
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
    if(ENABLE_SANITIZERS)
        target_compile_options(project_options INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )
        target_link_options(project_options INTERFACE -fsanitize=address,undefined)
    endif()
elseif(ENABLE_SANITIZERS)
    message(FATAL_ERROR "ENABLE_SANITIZERS is supported only with GCC and Clang")
endif()

add_library(ptrbox_core src/app.c)
target_include_directories(ptrbox_core PUBLIC include)
target_link_libraries(ptrbox_core PRIVATE project_options)

add_executable(ptrbox src/main.c)
target_link_libraries(ptrbox PRIVATE ptrbox_core project_options)

include(CTest)
if(BUILD_TESTING)
    add_executable(test_app tests/test_app.c)
    target_link_libraries(test_app PRIVATE ptrbox_core project_options)
    add_test(NAME app_tests COMMAND test_app)
endif()