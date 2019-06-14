cmake_minimum_required(VERSION 3.14)

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})

project(npbmwngdus)

find_package(SFML  REQUIRED graphics window system)

set(CMAKE_CXX_STANDARD 11)

add_executable(npbmwngdus main.cpp EnvironmentView.cpp EnvironmentView.h GameWindow.cpp GameWindow.h CharacterLogic.cpp CharacterLogic.h GameManager.cpp GameManager.h)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(npbmwngdus ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(npbmwngdus sfml-system sfml-window sfml-graphics sfml-audio)
endif()