set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
        ${Boost_INCLUDE_DIRS}
)

add_executable(PolynomialTest ${CMAKE_CURRENT_SOURCE_DIR}/test_polynomial.cpp)
target_link_libraries(PolynomialTest ${Boost_LIBRARIES})

add_executable(RationalTest ${CMAKE_CURRENT_SOURCE_DIR}/test_rational.cpp)
target_link_libraries(RationalTest ${Boost_LIBRARIES})

