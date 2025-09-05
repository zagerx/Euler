# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(DTS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../modules/lib/motorlib/drivers/drivers@Eulre.0.1.overlay)

get_filename_component(MODULES_BASE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../modules/lib" ABSOLUTE)

# 添加Zephyr外部模块
list(APPEND ZEPHYR_EXTRA_MODULES
    "${MODULES_BASE_PATH}/motorlib"
    "${MODULES_BASE_PATH}/CommonLibrary"
    "${MODULES_BASE_PATH}/ProtocolV4"    
)


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(euler)

# 添加源文件到 app target
target_sources(app PRIVATE
    src/main.c
)