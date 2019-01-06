cmake_minimum_required(VERSION 3.13)
project(projB)

set(CMAKE_CXX_STANDARD 14)

add_executable(projB main.cpp Astar.cpp Astar.h Bfs.cpp Bfs.h Dfs.cpp Dfs.h HillClimbing.cpp HillClimbing.h Searchable.cpp Searchable.h Searcher.cpp Searcher.h Solution.h Solution.cpp State.cpp State.h Equal.cpp Equal.h Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h Problem.cpp Problem.h CacheManager.h FileCacheManager.h MySerialServer.cpp MySerialServer.h)