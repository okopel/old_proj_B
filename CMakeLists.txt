cmake_minimum_required(VERSION 3.13)
project(projB)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(projB main.cpp searchAlg/Astar.cpp searchAlg/Astar.h searchAlg/Bestfs.h searchAlg/Dfs.h interface/Searchable.h interface/Searcher.h interface/State.h Equal.cpp Equal.h interface/Server.h interface/ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h interface/Solver.h interface/CacheManager.h cashManagers/FileCacheManager.h MySerialServer.cpp MySerialServer.h solvers/StringReverser.cpp solvers/StringReverser.h parser/Parser.h parser/StringReverserParser.cpp parser/StringReverserParser.h searchable/Matrix.h MyClientHandler.h searchAlg/BFS.h)