cmake_minimum_required(VERSION 3.18)

project(hello VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 COMPONENTS Quick Gui REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(mylib)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()
if(WIN32 OR MSVC OR MSYS OR MINGW)
    set(WINDOWS TRUE)
endif()


if(MACOSX)
    # Application icon
    set(MACOSX_BUNDLE_ICON_FILE icon.icns)
    set(APP_ICON_MACOSX ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
    set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES
           MACOSX_PACKAGE_LOCATION "Resources")
endif()

qt_add_executable(myapp
        main.cpp
        ${APP_ICON_MACOSX}
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





# Install the executable into "${CMAKE_INSTALL_PREFIX}/bin".
install(TARGETS myapp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Generate the deployment script for the target MyApp.
qt_generate_deploy_qml_app_script(
    TARGET myapp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

# Call the deployment script on "cmake --install".
install(SCRIPT ${deploy_script})
