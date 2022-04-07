cmake_minimum_required(VERSION 3.10)

set(ATSPI_NAME "DetailManager")

project(${ATSPI_NAME})

set(CMAKE_CXX_STANDARD 20)

set(ATSPI_BUILD_TYPE)
string(TOLOWER ${CMAKE_BUILD_TYPE} ATSPI_BUILD_TYPE)

set(ATSPI_DEBUG OFF)
set(ATSPI_TEST OFF)

if (ATSPI_BUILD_TYPE STREQUAL debug)
  set(ATSPI_DEBUG ON)
  set(ATSPI_TEST ON)
endif ()

set(BOOST_ROOT "3rdparty/boost/")
find_package(Boost REQUIRED)
include_directories(3rdparty/boost/include/boost-1_78)

if (ATSPI_TEST)
  enable_testing()
endif ()

set_property(
  DIRECTORY PROPERTY
  VS_STARTUP_PROJECT
  ${ATSPI_NAME}
)

include_directories(src)

if (WIN32)
  set(ATSPI_PAL_SOURCE_FILE
    src/Pal_Windows.cpp
    src/Types_Windows.hpp
  )
endif ()

set(ATSPI_SOURCE_FILE
  src/BveAtsPlugin.c
  src/EntryPoint.cpp
  ${ATSPI_PAL_SOURCE_FILE}
)

if (ATSPI_TEST)
  add_executable(pal_test
    src/Pal_Windows.cpp
    src/Pal_Windows_Test.cpp
  )

  add_test(NAME pal
    COMMAND $<TARGET_FILE:pal_test>
  )
  set_property(TEST pal
    APPEND PROPERTY
    LABELS src/Pal_Windows_Test.cpp
  )
else ()

  add_library(
    ${ATSPI_NAME}
    SHARED
    ${ATSPI_SOURCE_FILE}
  )
endif ()
