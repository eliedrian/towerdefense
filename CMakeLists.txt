cmake_minimum_required(VERSION 3.14)
project(towerdefense)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB test_srcs CONFIGURE_DEPENDS "tests/*.cpp")

add_executable(
  towerdefense_tests
  ${test_srcs}
)

target_link_libraries(
  towerdefense_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(towerdefense_tests)
