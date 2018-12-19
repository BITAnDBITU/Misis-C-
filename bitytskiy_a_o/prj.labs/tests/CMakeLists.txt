
add_executable(test_complex complex_main.cpp)
target_link_libraries(test_complex complex)
set_property(TARGET test_complex PROPERTY CXX_STANDARD 14)

add_executable(test_dynamicalarray dynamicalarray_main.cpp)
target_link_libraries(test_dynamicalarray dynamicalarray)
set_property(TARGET test_dynamicalarray PROPERTY CXX_STANDARD 14)

add_executable(test_matrix matrix_main.cpp)
target_link_libraries(test_matrix matrix)
set_property(TARGET test_matrix PROPERTY CXX_STANDARD 14)

add_executable(test_queue queuemain.cpp)
target_link_libraries(test_queue queue)
set_property(TARGET test_queue PROPERTY CXX_STANDARD 14)

add_executable(test_rational rational_main.cpp)
target_link_libraries(test_rational rational)
set_property(TARGET test_rational PROPERTY CXX_STANDARD 14)

add_executable(test_stack stackmain.cpp)
target_link_libraries(test_stack stackOnList)
set_property(TARGET test_stack PROPERTY CXX_STANDARD 14)

add_executable(test_priorityqueue priorityqueue_main.cpp)
target_link_libraries(test_priorityqueue priorityqueue)
set_property(TARGET test_priorityqueue PROPERTY CXX_STANDARD 14)