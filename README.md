# Blockchain in C++

A fully functional blockchain implementation in C++ with P2P networking, transactions, and Proof of Stake consensus.

## Features
- **P2P Networking**: Nodes communicate over TCP/IP.
- **Transactions**: Users can send and receive coins.
- **Proof of Stake**: Energy-efficient consensus mechanism.
- **Smart Contracts**: Basic scripting support.
- **CLI Interface**: Easy-to-use command-line interface.
- **Persistent Storage**: Blockchain saved to SQLite database.
- **REST API**: Expose blockchain functionality via HTTP endpoints.

## Installation

### Dependencies
To run this project, you need to install the following dependencies:

#### 1. **C++ Compiler**
   - **Windows**: Install [MinGW](http://www.mingw.org/) or use [WSL](https://docs.microsoft.com/en-us/windows/wsl/install).
   - **Linux (Ubuntu/Debian)**:
     ```bash
     sudo apt update
     sudo apt install build-essential
     ```
   - **macOS**:
     ```bash
     xcode-select --install
     ```

#### 2. **Boost Library**
   - **Windows**: Download and install Boost from [boost.org](https://www.boost.org/).
   - **Linux (Ubuntu/Debian)**:
     ```bash
     sudo apt install libboost-all-dev
     ```
   - **macOS**:
     ```bash
     brew install boost
     ```

#### 3. **OpenSSL**
   - **Windows**: Download and install OpenSSL from [OpenSSL Binaries](https://slproweb.com/products/Win32OpenSSL.html).
   - **Linux (Ubuntu/Debian)**:
     ```bash
     sudo apt install libssl-dev
     ```
   - **macOS**:
     ```bash
     brew install openssl
     ```

#### 4. **SQLite3**
   - **Windows**: Download and install SQLite3 from [sqlite.org](https://www.sqlite.org/download.html).
   - **Linux (Ubuntu/Debian)**:
     ```bash
     sudo apt install sqlite3 libsqlite3-dev
     ```
   - **macOS**:
     ```bash
     brew install sqlite3
     ```

#### 5. **CMake**
   - **Windows**: Download and install CMake from [cmake.org](https://cmake.org/download/).
   - **Linux (Ubuntu/Debian)**:
     ```bash
     sudo apt install cmake
     ```
   - **macOS**:
     ```bash
     brew install cmake
     ```

#### 6. **cpp-httplib (Optional)**
   - Clone the cpp-httplib repository:
     ```bash
     git clone https://github.com/yhirose/cpp-httplib.git
     ```
   - Copy the `httplib.h` file into your project’s `include/` directory:
     ```bash
     cp cpp-httplib/httplib.h include/
     ```

---

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/arshamakhtar/BLOCKCHAIN_PROJECT.git
   cd BLOCKCHAIN_PROJECT

   
---

## Contributing

We welcome contributions! Please read our [CONTRIBUTING.md](CONTRIBUTING.md) file for details on how to get started.
