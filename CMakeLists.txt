cmake_minimum_required(VERSION 3.10)

set(SUPPORT_JPG OFF)

project(template)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib/sdl)
add_subdirectory(lib/sdl_image)
add_subdirectory(lib/ge)

target_include_directories(${PROJECT_NAME}
    PUBLIC lib/sdl/include
    PUBLIC lib/sdl_image
    PUBLIC lib/ge
)

target_link_directories(${PROJECT_NAME}
    PUBLIC lib/sdl
    PUBLIC lib/sdl_image
    PUBLIC lib/ge
)

#file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32 AND NOT MSVC)
    target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image ge)
else()
    target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image ge)
endif()
