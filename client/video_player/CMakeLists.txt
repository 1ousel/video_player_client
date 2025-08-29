cmake_minimum_required(VERSION 3.5)

project(video_player LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

INCLUDE_DIRECTORIES(
  ${PROJECT_SOUCE_DIR}
)

if(ANDROID)
  add_library(video_player SHARED
    main.cpp
    video_player.cpp
    video_player.h
    video_player.ui
  )
else()
  add_executable(video_player
    main.cpp
    video_player.cpp
    video_player.h
    video_player.ui
    imageRes.qrc
    startuppage.h startuppage.cpp
    pageswitchbutton.h pageswitchbutton.cpp
    util.h
    homepagewidget.h homepagewidget.cpp homepagewidget.ui
    searchlineedit.h searchlineedit.cpp
    videobox.h videobox.cpp videobox.ui
  )
endif()

target_link_libraries(video_player PRIVATE Qt6::Widgets)
target_link_libraries(video_player PRIVATE Qt6::Widgets)
target_link_libraries(video_player PRIVATE Qt6::Widgets)
target_link_libraries(video_player PRIVATE Qt6::Widgets)
