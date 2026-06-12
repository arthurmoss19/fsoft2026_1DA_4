cmake_minimum_required(VERSION 3.21)
project(ProjectTester)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR ../Project/headers)
set(PROJECT_SOURCES_DIR ../Project/sources)

include_directories(${PROJECT_HEADERS_DIR})
include_directories(${PROJECT_SOURCES_DIR})
include_directories(${PROJECT_HEADERS_DIR}/model)
include_directories(${PROJECT_SOURCES_DIR}/model)
include_directories(${PROJECT_HEADERS_DIR}/exceptions)
include_directories(${PROJECT_SOURCES_DIR}/exceptions)

set(GOOGLE_TEST_LIB ${PROJECT_SOURCE_DIR}/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE ${GOOGLE_TEST_LIB}/googletest/include)

add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})

set(SOURCE_FILES
        main.cpp
        ${PROJECT_HEADERS_DIR}/model/Player.h
        ${PROJECT_SOURCES_DIR}/model/Player.cpp
        ${PROJECT_HEADERS_DIR}/model/Ship.h
        ${PROJECT_SOURCES_DIR}/model/Ship.cpp
        ${PROJECT_HEADERS_DIR}/model/Board.h
        ${PROJECT_SOURCES_DIR}/model/Board.cpp
        ${PROJECT_HEADERS_DIR}/model/Game.h
        ${PROJECT_SOURCES_DIR}/model/Game.cpp
        ${PROJECT_HEADERS_DIR}/model/PlayerContainer.h
        ${PROJECT_SOURCES_DIR}/model/PlayerContainer.cpp
        ${PROJECT_HEADERS_DIR}/exceptions/DuplicatedDataException.h
        ${PROJECT_SOURCES_DIR}/exceptions/DuplicatedDataException.cpp
        ${PROJECT_HEADERS_DIR}/exceptions/InvalidDataException.h
        ${PROJECT_SOURCES_DIR}/exceptions/InvalidDataException.cpp
        ${PROJECT_HEADERS_DIR}/exceptions/NoDataException.h
        ${PROJECT_SOURCES_DIR}/exceptions/NoDataException.cpp

)

add_executable(ProjectTester ${SOURCE_FILES})
target_link_libraries(ProjectTester gtest gtest_main)