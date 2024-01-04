# Create a library for common functionality
add_library(common_lib global_message.cpp)

# Include directories for common_lib
target_include_directories(common_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# Create the executable for the server, linking against the library
add_executable(server 
    server/server_main.cpp
    server/auth.cpp
    server/message.cpp
    server/auth.cpp
    server/user.cpp
    server/server.cpp)

# Link the executable with the server library
target_link_libraries(server PRIVATE common_lib)
target_include_directories(server PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/server
)

