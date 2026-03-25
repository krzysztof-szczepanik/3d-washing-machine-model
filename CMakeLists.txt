cmake_minimum_required(VERSION 3.10)
project(3DWashingMachineModel)

set(CMAKE_CXX_STANDARD 20)

# GLFW paths:
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/glfw/include")
set(GLFW_LIB_DIR "${CMAKE_SOURCE_DIR}/external/glfw/lib")

# Include directories:
include_directories(
    ${GLFW_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/external/stb
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/inc/config
    ${CMAKE_SOURCE_DIR}/inc/core
    ${CMAKE_SOURCE_DIR}/inc/model
    ${CMAKE_SOURCE_DIR}/inc/scene
    ${CMAKE_SOURCE_DIR}/inc/utils
)

# Library directories:
link_directories(${GLFW_LIB_DIR})

# Collect all source files:
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Add STB implementation file manually:
list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/external/stb/stb_image.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Link GLFW + Windows libs:
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        glfw3dll
        opengl32
        gdi32
)

# Copy DLL next to the .exe after build:
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLFW_LIB_DIR}/glfw3.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

if (MINGW)
    # These DLLs are required only when building with MinGW-w64.
    # Users on MSVC, Linux or macOS should remove or replace this section

    # Copy MinGW runtime DLLs next to the .exe after build:
    set(MINGW_DLL_DIR "${CMAKE_SOURCE_DIR}/external/mingw/bin")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MINGW_DLL_DIR}/libgcc_s_seh-1.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MINGW_DLL_DIR}/libstdc++-6.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MINGW_DLL_DIR}/libwinpthread-1.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# Copy textures directory next to the .exe after build:
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/textures"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/textures
)