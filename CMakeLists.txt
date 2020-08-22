cmake_minimum_required(VERSION 3.5)

MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE "${curdir}" "${curdir}/*")
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY "${curdir}/${child}")
            LIST(APPEND dirlist "${child}")
        ENDIF()
    ENDFOREACH()
    SET("${result}" "${dirlist}")
ENDMACRO()

set(INCLUDE_LIST)

# --------------------------------------------------------------------------------
# Add all include directories in ESP-IDF
# --------------------------------------------------------------------------------

file(TO_CMAKE_PATH "$ENV{IDF_PATH}" IDF_PATH)
message(STATUS "IDF PATH: ${IDF_PATH}")

SUBDIRLIST(idf_components "${IDF_PATH}/components")
FOREACH(component_dir ${idf_components})
    set(component_path "${IDF_PATH}/components/${component_dir}")
    list(APPEND INCLUDE_LIST "${component_path}")
    if(IS_DIRECTORY "${component_path}/include")
        list(APPEND INCLUDE_LIST "${component_path}/include")
    endif()
ENDFOREACH()

# --------------------------------------------------------------------------------
# Add libraries in "components" directory
# --------------------------------------------------------------------------------

message(STATUS "PSD: ${CMAKE_SOURCE_DIR}")
SUBDIRLIST(local_components "${CMAKE_SOURCE_DIR}/components")
message(STATUS "local components: ${local_components}")
foreach(component_dir ${local_components})
    set(component_path "${CMAKE_SOURCE_DIR}/components/${component_dir}")
    if(component_dir STREQUAL "arduino")
        list(APPEND INCLUDE_LIST "${component_path}/cores/esp32")
    else()
        list(APPEND INCLUDE_LIST "${component_path}")
    endif()
endforeach()

# --------------------------------------------------------------------------------
# Configure project and entry point
# --------------------------------------------------------------------------------

project(auto-home)
add_executable(${PROJECT_NAME} main/main.cpp)

list(LENGTH INCLUDE_LIST INCLUDE_LIST_LENGTH)
message(STATUS "Include directories (${INCLUDE_LIST_LENGTH}): ${INCLUDE_LIST}")
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_LIST})
