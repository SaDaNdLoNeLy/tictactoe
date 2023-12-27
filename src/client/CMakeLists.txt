cmake_minimum_required(VERSION 3.5)

project(client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(client
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        forgot_password.cpp forgot_password.h forgot_password.ui game_screen.cpp game_screen.h game_screen.ui list_online_player.qml login_form.cpp login_form.h login_form.ui main.cpp mainwindow.cpp mainwindow.h mainwindow.ui menu_login.cpp menu_login.h menu_login.ui move.h online_list.cpp online_list.h online_list.ui player.cpp player.h register_form.cpp register_form.h register_form.ui TcpClient.cpp TcpClient.h test.txt
        nlohmann/detail/conversions/from_json.hpp nlohmann/detail/conversions/to_chars.hpp nlohmann/detail/conversions/to_json.hpp nlohmann/detail/input/binary_reader.hpp nlohmann/detail/input/input_adapters.hpp nlohmann/detail/input/json_sax.hpp nlohmann/detail/input/lexer.hpp nlohmann/detail/input/parser.hpp nlohmann/detail/input/position_t.hpp nlohmann/detail/iterators/internal_iterator.hpp nlohmann/detail/iterators/iter_impl.hpp nlohmann/detail/iterators/iteration_proxy.hpp nlohmann/detail/iterators/iterator_traits.hpp nlohmann/detail/iterators/json_reverse_iterator.hpp nlohmann/detail/iterators/primitive_iterator.hpp nlohmann/detail/meta/call_std/begin.hpp nlohmann/detail/meta/call_std/end.hpp nlohmann/detail/meta/cpp_future.hpp nlohmann/detail/meta/detected.hpp nlohmann/detail/meta/identity_tag.hpp nlohmann/detail/meta/is_sax.hpp nlohmann/detail/meta/std_fs.hpp nlohmann/detail/meta/type_traits.hpp nlohmann/detail/meta/void_t.hpp nlohmann/detail/output/binary_writer.hpp nlohmann/detail/output/output_adapters.hpp nlohmann/detail/output/serializer.hpp nlohmann/detail/abi_macros.hpp nlohmann/detail/exceptions.hpp nlohmann/detail/hash.hpp nlohmann/detail/json_custom_base_class.hpp nlohmann/detail/json_pointer.hpp nlohmann/detail/json_ref.hpp nlohmann/detail/macro_scope.hpp nlohmann/detail/macro_unscope.hpp nlohmann/detail/string_concat.hpp nlohmann/detail/string_escape.hpp nlohmann/detail/value_t.hpp nlohmann/thirdparty/hedley/hedley.hpp nlohmann/thirdparty/hedley/hedley_undef.hpp nlohmann/adl_serializer.hpp nlohmann/byte_container_with_subtype.hpp nlohmann/json.hpp nlohmann/json_fwd.hpp nlohmann/ordered_map.hpp Resource/arrow-left-solid.svg Resource/background-login.qrc Resource/background.jpg Resource/background.qrc Resource/bg-01.jpg Resource/game_bg.jpg Resource/hide-password.svg Resource/pacifico-font.qrc Resource/Pacifico-Regular.ttf Resource/right-from-bracket-solid.svg Resource/show-password.svg Resource/user-regular.svg Resource/user-solid.svg Resource/user_icon.qrc

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET client APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(client SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(client
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(client PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.client)
endif()
set_target_properties(client PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS client
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(client)
endif()
