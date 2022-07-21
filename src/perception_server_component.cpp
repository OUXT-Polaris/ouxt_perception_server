// Copyright (c) 2020 OUXT Polaris
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

// Headers in this package
#include "perception_server/perception_server_component.hpp"
#include <memory>
#include <rclcpp_components/register_node_macro.hpp>

namespace perception_server
{
PerceptionComponent::PerceptionComponent(const rclcpp::NodeOptions & options)
: Node("image_rectify_node", options)
{
  declare_parameter("interpolation", 1);
  get_parameter("interpolation", interpolation_);
}
}

RCLCPP_COMPONENTS_REGISTER_NODE(perception_server::PerceptionComponent)
