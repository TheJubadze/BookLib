cmake_minimum_required(VERSION 3.5)

project(booklib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "~/Qt/5.15.1/gcc_64/")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(booklib
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    repository.cpp
    repository.h
    unitofwork.cpp
    unitofwork.h
    contentitem.h
    book.cpp
    book.h
    reader.cpp
    reader.h
    addbookdialog.cpp
    addbookdialog.h
    addbookdialog.ui
    addreaderdialog.cpp
    addreaderdialog.h
    addreaderdialog.ui
    removebookconfirmationdialog.cpp
    removebookconfirmationdialog.h
    removebookconfirmationdialog.ui
    removereaderconfirmationdialog.cpp
    removereaderconfirmationdialog.h
    removereaderconfirmationdialog.ui
    showbooksdialog.cpp
    showbooksdialog.h
    showbooksdialog.ui
)

target_link_libraries(booklib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
