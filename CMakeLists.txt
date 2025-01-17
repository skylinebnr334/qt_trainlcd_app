cmake_minimum_required(VERSION 3.16)

project(qt_trainlcd_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Quick Gui Qml QuickWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick Gui Qml QuickWidgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        led_subwindow.h
        led_subwindow.cpp
        led_subwindow.ui
        led_subwindow_quickwidget.h
        led_subwindow_quickwidget.cpp

)
include_directories("${CMAKE_SOURCE_DIR}")

QT6_ADD_RESOURCES(RESOURCES main.qrc)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt_trainlcd_app
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET qt_trainlcd_app APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qt_trainlcd_app SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qt_trainlcd_app
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(qt_trainlcd_app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Qml Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::QuickWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.qt_trainlcd_app)
endif()
set_target_properties(qt_trainlcd_app PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS qt_trainlcd_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qt_trainlcd_app)
endif()
