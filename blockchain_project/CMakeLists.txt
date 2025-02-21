cmake_minimum_required(VERSION 3.10)
project(BlockchainCpp)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/blockchain.cpp
    src/p2p.cpp
    src/wallet.cpp
    src/vm.cpp
    src/cli.cpp
    src/storage.cpp
    src/api.cpp 
    src/main.cpp
)

# Executable
add_executable(blockchain_cpp ${SOURCES})

# Link libraries
target_link_libraries(blockchain_cpp pthread ssl crypto boost_system sqlite3)