cmake_minimum_required(VERSION 3.0.2)
project(realsense_SR300_pkg)


find_package(catkin REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PCL 1.8 REQUIRED)
find_package(realsense2 REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  roscpp
  std_msgs
  image_transport
  cv_bridge
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES realsense_SR300_pkg
#  CATKIN_DEPENDS actionlib actionlib_msgs roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${/home/hyda/catkin_ws/src/realsense_SR300_pkg/include}
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${OPENCV_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)


link_directories(
  ${OpenCV_LIBRARY_DIRS}
  ${PCL_LIBRARY_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_definitions(${PCL_DEFINITIONS})


add_executable(CapRGB src/CapRGB.cpp)
add_dependencies(CapRGB realsense_SR300_pkg)
target_link_libraries(CapRGB
  ${catkin_LIBRARIES}
  ${PCL_LIBRARIES}
  ${DEPENDENCIES}
  ${realsense2_LIBRARY}
  ${PCL_COMMON_LIBRARIES}
  ${PCL_IO_LIBRARIES}
  ${SPECIAL_OS_LIBS}
  ${OpenCV_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${PCL_LIBRARIES}
  ${OpenCV_LIBS}
)
