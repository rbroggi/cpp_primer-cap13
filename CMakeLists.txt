cmake_minimum_required(VERSION 3.12)
project(cap13)

set(CMAKE_CXX_STANDARD 14)

add_executable(cap13 copy.cpp CopyData.cpp NonCopyData.cpp User.cpp BugClass.cpp CopyRefData.cpp CopyRefData.h ValueLikeData.cpp ValueLikeData.h PointerLikeData.cpp PointerLikeData.h)

target_include_directories(cap13
        PRIVATE /Users/rodrigobroggi/Documents/Workspace/cpp/boost/boost_1_67_0
        )
