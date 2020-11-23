cmake_minimum_required(VERSION 3.17)
project(Signal_Driven)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Code/main.cpp
        Code/SignalReceiver/signal_receiver.cpp
        Code/SignalReceiver/Modules/Connection/connect.cpp
        Code/SignalReceiver/Modules/Disconnection/disconnect.cpp)

set(HEADER_FILES
        Code/SignalReceiver/signal_receiver.h
        Code/SignalReceiver/Modules/Connection/connect.cpp
        Code/SignalReceiver/Modules/Connection/connect_config.h
        Code/SignalReceiver/Modules/Disconnection/disconnect.h
        Code/SignalReceiver/Modules/Disconnection/disconnect_config.h)

add_executable(Signal_Driven ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(Signal_Driven PUBLIC Code)
target_include_directories(Signal_Driven PUBLIC Code/SignalReceiver)
target_include_directories(Signal_Driven PUBLIC Code/SignalReceiver/Modules)
target_include_directories(Signal_Driven PUBLIC Code/SignalReceiver/Modules/Connection)
target_include_directories(Signal_Driven PUBLIC Code/SignalReceiver/Modules/Disconnection)