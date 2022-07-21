cmake_minimum_required(VERSION 3.8)
project(perception_server)

# Error output
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(perception_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${rclcpp_components_INCLUDE_DIRS}
  ${perception_msgs_INCLUDE_DIRS}
)


# Component
add_library(perception_server_component SHARED
  src/perception_server_component.cpp
  )
target_compile_definitions(perception_server_component
  PRIVATE "PERCEPTION_SERVER_COMPONENT_BUILDING_DLL")
ament_target_dependencies(perception_server_component
  rclcpp
  rclcpp_components
  perception_msgs
  )
rclcpp_components_register_nodes(perception_server_component
 "perception_server::PerceptionComponent")



# Node
add_executable(perception_server_node
  src/perception_server_node.cpp
)
target_link_libraries(perception_server_node
 perception_server_component)
ament_target_dependencies(perception_server_node
  rclcpp
  rclcpp_components
  )

#install
install(TARGETS
  perception_server_node
  DESTINATION lib/perception_server
)
install(TARGETS perception_server_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)

ament_package()
