cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CHAIR_PTOJECT_NAME "blockchair-api")

set(CHAIR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(CMAKE_SOURCE_DIR STREQUAL CHAIR_SOURCE_DIR)
    set(CHAIR_STANDALONE TRUE)
    message(STATUS "chair stand alone")
endif()

option(CHAIR_BUILD_STATIC_LIBRARY "Generate static library target" ${CHAIR_STANDALONE})

option(CHAIR_BUILD_DOCS "Build the chair documentation" OFF)
option(CHAIR_BUILD_TESTS "Build the chair tests and examples" ${CHAIR_STANDALONE})

# set project(VERSION) policy // deprecated
if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif()

project(${CHAIR_PTOJECT_NAME}
    DESCRIPTION "unofficial api library for the blockchair database"
    VERSION 0.0.1
    LANGUAGES C CXX
)

set(CHAIR_SOURCE_PATH "${CHAIR_SOURCE_DIR}/src")
set(CHAIR_INCLUDE_PATH "${CHAIR_SOURCE_DIR}/include")

file(GLOB_RECURSE CHAIR_SOURCE_FILES
    "${CHAIR_SOURCE_PATH}/*.cxx"
    "${CHAIR_SOURCE_PATH}/*.hxx*"
)
file(GLOB_RECURSE CHAIR_INCLUDE_FILES
    "${CHAIR_INCLUDE_PATH}/*.hxx*"
)

configure_file(
    "config/version.hxx.in"
    "${PROJECT_BINARY_DIR}/include/config/version.hxx"
)

# confiure utils
add_subdirectory("./ext/utils")

if(NOT UTIlS_INCLUDE_MODULES_PATH IN_LIST CMAKE_MODULE_PATH)
    list(APPEND CMAKE_MODULE_PATH ${UTIlS_INCLUDE_MODULES_PATH})
endif()

if(CHAIR_BUILD_STATIC_LIBRARY)
    message(STATUS "chair: build static library")
    set(CHAIR_STATIC_LIBRARY_NAME "chair")

    add_library(${CHAIR_STATIC_LIBRARY_NAME} STATIC
        ${CHAIR_SOURCE_FILES}
        ${CHAIR_INCLUDE_FILES}
        "${PROJECT_BINARY_DIR}/include/config/version.hxx"
    )

    target_include_directories(${CHAIR_STATIC_LIBRARY_NAME}
        PUBLIC ${CHAIR_INCLUDE_PATH}
        PRIVATE ${CHAIR_SOURCE_PATH} "${PROJECT_BINARY_DIR}/include"
    )

    target_link_libraries(${CHAIR_STATIC_LIBRARY_NAME} PUBLIC utils)

    install(TARGETS ${CHAIR_STATIC_LIBRARY_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
    )
endif()

if(CHAIR_BUILD_TESTS)
    add_subdirectory(tests)
endif()