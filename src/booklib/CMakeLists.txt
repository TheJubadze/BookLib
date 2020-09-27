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
    entities/contentitem.h
    entities/book.cpp
    entities/book.h
    entities/reader.cpp
    entities/reader.h
    dialogs/addbookdialog.cpp
    dialogs/addbookdialog.h
    dialogs/addbookdialog.ui
    dialogs/addreaderdialog.cpp
    dialogs/addreaderdialog.h
    dialogs/addreaderdialog.ui
    dialogs/removebookconfirmationdialog.cpp
    dialogs/removebookconfirmationdialog.h
    dialogs/removebookconfirmationdialog.ui
    dialogs/removereaderconfirmationdialog.cpp
    dialogs/removereaderconfirmationdialog.h
    dialogs/removereaderconfirmationdialog.ui
    dialogs/showbooksdialog.cpp
    dialogs/showbooksdialog.h
    dialogs/showbooksdialog.ui
)

target_link_libraries(booklib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
