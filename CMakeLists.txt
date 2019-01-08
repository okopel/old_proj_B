cmake_minimum_required(VERSION 3.13)
project(projB)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(projB main.cpp searchAlg/Astar.cpp searchAlg/Astar.h searchAlg/Bfs.cpp searchAlg/Bfs.h searchAlg/Dfs.cpp searchAlg/Dfs.h searchAlg/HillClimbing.cpp searchAlg/HillClimbing.h Searchable.cpp Searchable.h Searcher.cpp Searcher.h State.cpp State.h Equal.cpp Equal.h Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.h FileCacheManager.h MySerialServer.cpp MySerialServer.h StringReverser.cpp StringReverser.h Parser.h StringReverserParser.cpp StringReverserParser.h)