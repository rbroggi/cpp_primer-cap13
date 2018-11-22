cmake_minimum_required(VERSION 3.12)
project(cap13)

set(CMAKE_CXX_STANDARD 14)

add_executable(cap13 src/copy.cpp src/CopyData.cpp src/NonCopyData.cpp src/User.cpp src/BugClass.cpp src/CopyRefData.cpp include/CopyRefData.h src/ValueLikeData.cpp include/ValueLikeData.h src/PointerLikeData.cpp include/PointerLikeData.h)

target_include_directories(cap13
        PRIVATE ./include
        PRIVATE /Users/rodrigobroggi/Documents/Workspace/cpp/boost/boost_1_67_0
        )
