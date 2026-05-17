cmake_minimum_required(VERSION 4.1)
project(Project)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR
        ${PROJECT_SOURCE_DIR}/headers)
set(PROJECT_SOURCES_DIR
        ${PROJECT_SOURCE_DIR}/sources)

################################################

set(PROJECT_HEADERS_CONTROLLERS_DIR
        ${PROJECT_HEADERS_DIR}/controllers)
set(PROJECT_SOURCES_CONTROLLERS_DIR
        ${PROJECT_SOURCES_DIR}/controllers)
include_directories(
        ${PROJECT_HEADERS_CONTROLLERS_DIR}
        ${PROJECT_SOURCES_CONTROLLERS_DIR})
set(CONTROLLERS_SOURCE_FILES
        ${PROJECT_HEADERS_CONTROLLERS_DIR}/Controller.h
        ${PROJECT_SOURCES_CONTROLLERS_DIR}/Controller.cpp)

################################################

set(PROJECT_HEADERS_EXCEPTIONS_DIR
        ${PROJECT_HEADERS_DIR}/exceptions)
set(PROJECT_SOURCES_EXCEPTIONS_DIR
        ${PROJECT_SOURCES_DIR}/exceptions)
include_directories(
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}
        ${PROJECT_SOURCES_EXCEPTIONS_DIR})
set(EXCEPTIONS_SOURCE_FILES
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/DuplicatedDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/DuplicatedDataException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/InvalidDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/InvalidDataException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/NoDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/NoDataException.cpp)

################################################

set(PROJECT_HEADERS_MODEL_DIR
        ${PROJECT_HEADERS_DIR}/model)
set(PROJECT_SOURCES_MODEL_DIR
        ${PROJECT_SOURCES_DIR}/model)
include_directories(
        ${PROJECT_HEADERS_MODEL_DIR}
        ${PROJECT_SOURCES_MODEL_DIR})
set(MODEL_SOURCE_FILES
        ${PROJECT_HEADERS_MODEL_DIR}/Board.h
        ${PROJECT_SOURCES_MODEL_DIR}/Board.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Game.h
        ${PROJECT_HEADERS_MODEL_DIR}/Game.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Player.h
        ${PROJECT_HEADERS_MODEL_DIR}/Player.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/PlayerContainer.h
        ${PROJECT_HEADERS_MODEL_DIR}/PlayerContainer.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Ship.h
        ${PROJECT_HEADERS_MODEL_DIR}/Ship.cpp)

################################################

set(PROJECT_HEADERS_DTO_DIR
        ${PROJECT_HEADERS_DIR}/dto)
include_directories(
        ${PROJECT_HEADERS_DTO_DIR})
set(DTO_SOURCE_FILES
        ${PROJECT_HEADERS_DTO_DIR}/BoardDTO.h
        ${PROJECT_HEADERS_DTO_DIR}/ShipDTO.h
        ${PROJECT_HEADERS_DTO_DIR}/GameDTO.h
        ${PROJECT_HEADERS_DTO_DIR}/PlayerDTO.h)

################################################

set(PROJECT_HEADERS_VIEWS_DIR
        ${PROJECT_HEADERS_DIR}/views)
set(PROJECT_SOURCES_VIEWS_DIR
        ${PROJECT_SOURCES_DIR}/views)
set(VIEWS_SOURCE_FILES
        ${PROJECT_HEADERS_VIEWS_DIR}/View.h
        ${PROJECT_SOURCES_VIEWS_DIR}/View.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/Utils.h
        ${PROJECT_SOURCES_VIEWS_DIR}/Utils.cpp)

################################################

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

################################################

set(PROJECT_HEADERS_MAPPERS_DIR
        ${PROJECT_HEADERS_DIR}/mappers)
set(PROJECT_SOURCES_MAPPERS_DIR
        ${PROJECT_SOURCES_DIR}/mappers)
include_directories(
        ${PROJECT_HEADERS_MAPPERS_DIR}
        ${PROJECT_SOURCES_MAPPERS_DIR})
set(MAPPERS_SOURCE_FILES${PROJECT_HEADERS_MAPPERS_DIR}/StudentMapper.h
        ${PROJECT_SOURCES_MAPPERS_DIR}/BoardMapper.cpp
        ${PROJECT_HEADERS_MAPPERS_DIR}/BoardMapper.h
        ${PROJECT_SOURCES_MAPPERS_DIR}/ShipMapper.cpp
        ${PROJECT_HEADERS_MAPPERS_DIR}/ShipMapper.h
        ${PROJECT_SOURCES_MAPPERS_DIR}/GameMapper.cpp
        ${PROJECT_HEADERS_MAPPERS_DIR}/GameMapper.h
        ${PROJECT_SOURCES_MAPPERS_DIR}/PlayerMapper.cpp
        ${PROJECT_SOURCES_MAPPERS_DIR}/PlayerMapper.h)

################################################

add_executable(
        Project
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