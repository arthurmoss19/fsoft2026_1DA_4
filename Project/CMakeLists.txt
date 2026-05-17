cmake_minimum_required(VERSION 4.1)
project(Project)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR
        ${PROJECT_SOURCE_DIR}/headers)
set(PROJECT_SOURCES_DIR
        ${PROJECT_SOURCE_DIR}/sources)

set(PROJECT_HEADERS_CONTROLLERS_DIR
        ${PROJECT_HEADERS_DIR}/controllers)
set(PROJECT_SOURCES_CONTROLLERS_DIR
        ${PROJECT_SOURCES_DIR}/controllers)

set(PROJECT_HEADERS_VIEWS_DIR
        ${PROJECT_HEADERS_DIR}/views)
set(PROJECT_SOURCES_VIEWS_DIR
        ${PROJECT_SOURCES_DIR}/views)
set(VIEWS_SOURCE_FILES
        ${PROJECT_HEADERS_VIEWS_DIR}/View.h
        ${PROJECT_SOURCES_VIEWS_DIR}/View.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/Utils.h
        ${PROJECT_SOURCES_VIEWS_DIR}/Utils.cpp)

include_directories(
        ${PROJECT_HEADERS_CONTROLLERS_DIR}
        ${PROJECT_SOURCES_CONTROLLERS_DIR}
        ${PROJECT_HEADERS_VIEWS_DIR}
        ${PROJECT_SOURCES_VIEWS_DIR}
        headers/model
        headers/exceptions
)
set(CONTROLLERS_SOURCE_FILES
        ${PROJECT_HEADERS_CONTROLLERS_DIR}/Controller.h
        ${PROJECT_SOURCES_CONTROLLERS_DIR}/Controller.cpp)

add_executable(Project
        main.cpp
        ${VIEWS_SOURCE_FILES}
        ${CONTROLLERS_SOURCE_FILES}
        headers/model/Player.h            sources/model/Player.cpp
        headers/model/Ship.h              sources/model/Ship.cpp
        headers/model/Board.h             sources/model/Board.cpp
        headers/model/Game.h              sources/model/Game.cpp
        headers/model/PlayerContainer.h   sources/model/PlayerContainer.cpp
        headers/exceptions/NoDataException.h
        headers/exceptions/DuplicatedDataException.h
        headers/exceptions/InvalidDataException.h
        sources/exceptions/NoDataException.cpp
        sources/exceptions/DuplicatedDataException.cpp
        sources/exceptions/InvalidDataException.cpp
)