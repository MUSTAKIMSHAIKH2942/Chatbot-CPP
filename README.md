
# ChatApp in C++ (2-Way Chat with Factory Pattern)

This is a simple two-way terminal chat application built in C++ using sockets and threads. It supports:

- Nickname support via Factory Design Pattern
- Multi-threaded client handling on the server
- Linux/macOS compatible

## Features

- Custom nickname entry
- Factory pattern for user management
- Multi-client support (basic echo-style)
- Clean code structure and Makefile

## How to Run

### Build:
```bash
make
```

### Run Server:
```bash
./chatapp
# Choose 1 for server
```

### Run Client:
```bash
./chatapp
# Choose 2, enter IP and nickname
```

## Inspired By

- https://github.com/angrave/SystemProgramming
- https://beej.us/guide/bgnet/html/

## Author

Mustakim Shaikh
