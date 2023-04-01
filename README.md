QT 6.2 QML CMake API

# Deploy on mac

```
mkdir deploy
cd deploy
/Volumes/FAST/Qt/6.5.0/macos/bin/qt-cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=. ../qt-qml-cmake-api
cmake --build .
cmake --install .
```
