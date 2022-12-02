cmake_minimum_required(VERSION 3.24)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector main.cpp Vector.cpp Vector.h Point.cpp Point.h Segment.cpp Segment.h SegmentWithPlane.cpp SegmentWithPlane.h Plane.cpp Plane.h TriangleWithPlane.cpp TriangleWithPlane.h)
