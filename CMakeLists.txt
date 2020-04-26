cmake_minimum_required(VERSION 3.14)
project(ntlib)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.72)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(ntlib main.cpp includes/crypto.h includes/factorizer.h includes/primes.h includes/polynomial.h includes/string_modifiers.h includes/math.h includes/rational.h)
    target_link_libraries(ntlib ${Boost_LIBRARIES})
endif()

