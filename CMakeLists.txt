cmake_minimum_required(VERSION 4.2)
project(YUMSH_classes)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(
        YUMSH_classes
        Trie.cpp
        Trie.h
        Trie_module.cpp

)