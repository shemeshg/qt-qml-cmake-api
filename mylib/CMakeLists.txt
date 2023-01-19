qt6_add_qml_module(mylib
        URI mylib
        VERSION 1.0
        SOURCES
            mytype.h mytype.cc
            qrc.qrc
        QML_FILES
            FramedImage.qml
            qrc.qrc
        RESOURCES
            img/cat.jpeg    )

# Specify here the include directories exported
# by this library

target_include_directories(mylib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
