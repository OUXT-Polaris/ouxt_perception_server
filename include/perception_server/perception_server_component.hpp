// Copyright (c) 2022 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PERCEPTION_SERVER_PERCEPTION_COMPONENT_HPP_
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_HPP_

#if __cplusplus
extern "C" {
#endif

// The below macros are taken from https://gcc.gnu.org/wiki/Visibility and from
// demos/composition/include/composition/visibility_control.h at https://github.com/ros2/demos
#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_EXPORT __attribute__((dllexport))
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_IMPORT __attribute__((dllimport))
#else
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_EXPORT __declspec(dllexport)
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_IMPORT __declspec(dllimport)
#endif
#ifdef PERCEPTION_SERVER_PERCEPTION_COMPONENT_BUILDING_DLL
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC \
  PERCEPTION_SERVER_PERCEPTION_COMPONENT_EXPORT
#else
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC \
  PERCEPTION_SERVER_PERCEPTION_COMPONENT_IMPORT
#endif
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC_TYPE \
  PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_LOCAL
#else
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_EXPORT __attribute__((visibility("default")))
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_IMPORT
#if __GNUC__ >= 4
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC __attribute__((visibility("default")))
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_LOCAL __attribute__((visibility("hidden")))
#else
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_LOCAL
#endif
#define PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC_TYPE
#endif

#if __cplusplus
}  // extern "C"
#endif

// Headers in ROS2
#include <rclcpp/rclcpp.hpp>

// Headers in STL
#include <memory>

// Headers in OUXT
#include <perception_msgs/msg/tracking2_d.hpp>

namespace perception_server
{
class PerceptionComponent : public rclcpp::Node
{
public:
  PERCEPTION_SERVER_PERCEPTION_COMPONENT_PUBLIC
  explicit PerceptionComponent(const rclcpp::NodeOptions & options);

private:
  std::shared_ptr<rclcpp::Publisher<perception_msgs::msg::Tracking2D>> pub_;
};
}

#endif
