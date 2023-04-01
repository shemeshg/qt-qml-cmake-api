cmake_minimum_required(VERSION 3.18)

project(hello VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(mylib)

qt_add_executable(myapp
        main.cpp
        )



target_link_libraries(myapp PRIVATE Qt6::Gui Qt6::Quick 
        mylib
    )



qt6_add_qml_module(myapp
        URI hello
        VERSION 1.0
        QML_FILES
            Main.qml
    )

set_target_properties(myapp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
