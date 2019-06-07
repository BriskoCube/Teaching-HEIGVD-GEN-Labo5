cmake_minimum_required(VERSION 3.12)
project(GEN_LABO5)

set(CMAKE_CXX_STANDARD 14)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )


add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src" "{CMAKE_BINARY_DIR}/googletest-build")

#add_executable(GEN_LABO5 src/main/main.cpp "src/main/Customer.cpp" "src/main/Movie.cpp" "src/main/Rental.h")
add_executable(GEN_LABO5_TEST src/main/main.cpp "src/main/Customer.cpp" "src/main/movies/Movie.cpp" "src/main/Rental.h" src/main/movies/MovieImpl.h src/main/RentalImpl.h src/main/movies/ChildrenMovie.h)

add_executable(TESTS src/test/CustomerTests.cpp "src/main/Customer.cpp" "src/main/movies/Movie.cpp" "src/main/Rental.h" src/test/RentalMock.h src/test/MovieMock.h)

target_link_libraries(TESTS gtest gmock gmock_main)