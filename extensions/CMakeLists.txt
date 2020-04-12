cmake_minimum_required(VERSION 3.2.0)
project (potato_webook)

file (GLOB SOURCES "Webhook.cpp")

add_subdirectory(cpr)

add_library(potato_webook SHARED ${SOURCES})
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(potato_webook ${CPR_LIBRARIES})

