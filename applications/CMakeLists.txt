# ---------------------------------------------------------------------------
# Example application
#   This is the drawing app you can run to see your shapes rendered on screen.
# ---------------------------------------------------------------------------
add_executable(example
  example.cpp
)
add_executable(clock
  clock.cpp
)
target_include_directories(clock PRIVATE
		${CMAKE_SOURCE_DIR}/framework
)

target_link_libraries(clock
		framework_aufgabenblatt_2
)
target_include_directories(example PRIVATE
						   ${CMAKE_SOURCE_DIR}/framework
)

# target_link_libraries() connects our executable to the framework library.
# This means we can use all the classes defined in framework/ (Vec2, Circle, etc.)
target_link_libraries(example
  framework_aufgabenblatt_2
)

# ---------------------------------------------------------------------------
# Test executable
#   This program runs our unit tests using the doctest framework.
#   It also links against the framework so we can test our own classes.
# ---------------------------------------------------------------------------
add_executable(tests
  tests.cpp
)

target_link_libraries(tests
  framework_aufgabenblatt_2
)

target_include_directories(tests PRIVATE
						   ${CMAKE_SOURCE_DIR}/framework
						   ${CMAKE_SOURCE_DIR}/external/doctest
)

# Register the test executable with ctest (CMake's test runner)
add_test(NAME doctest COMMAND tests)
