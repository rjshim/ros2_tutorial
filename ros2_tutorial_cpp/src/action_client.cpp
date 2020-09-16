// Copyright 2019 Open Source Robotics Foundation, Inc.
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

/* Authors: Ryan Shim */

#include <memory>
#include <string>
#include <sstream>

#include "rclcpp/rclcpp.hpp"
// TODO(jacobperron): Remove this once it is included as part of 'rclcpp.hpp'
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "ros2_tutorial_cpp/action/fetch.hpp"
#include "ros2_tutorial_cpp/visibility_control.hpp"

namespace ros2_tutorial_cpp
{
class ActionClient : public rclcpp::Node
{
public:
  using Fetch = ros2_tutorial_cpp::action::Fetch;
//   using GoalHandleFetch = rclcpp_action::ClientGoalHandle<Fetch>;

//   ROS2_TUTORIAL_CPP_PUBLIC
  explicit ActionClient(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Node("action_client", node_options)
  {
    RCLCPP_INFO(this->get_logger(), "Initialized action client node");

//     this->client_ptr_ = rclcpp_action::create_client<Fetch>(
//       this->get_node_base_interface(),
//       this->get_node_graph_interface(),
//       this->get_node_logging_interface(),
//       this->get_node_waitables_interface(),
//       "fetch");

//     this->timer_ = this->create_wall_timer(
//       std::chrono::milliseconds(500),
//       std::bind(&ActionClient::send_goal, this));
  }

//   ROS2_TUTORIAL_CPP_PUBLIC
//   void send_goal()
//   {
//     using namespace std::placeholders;

//     this->timer_->cancel();

//     if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) {
//       RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
//       rclcpp::shutdown();
//       return;
//     }

//     auto goal_msg = Fetch::Goal();
//     goal_msg.order = 10;

//     RCLCPP_INFO(this->get_logger(), "Sending goal");

//     auto send_goal_options = rclcpp_action::Client<Fetch>::SendGoalOptions();
//     send_goal_options.goal_response_callback =
//       std::bind(&ActionClient::goal_response_callback, this, _1);
//     send_goal_options.feedback_callback =
//       std::bind(&ActionClient::feedback_callback, this, _1, _2);
//     send_goal_options.result_callback =
//       std::bind(&ActionClient::result_callback, this, _1);
//     this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
//   }

  ~ActionClient()
  {
    RCLCPP_INFO(this->get_logger(), "Terminated listener node");
  }

private:
  rclcpp_action::Client<Fetch>::SharedPtr client_ptr_;
  rclcpp::TimerBase::SharedPtr timer_;

  // ROS2_TUTORIAL_CPP_LOCAL
  // void goal_response_callback(std::shared_future<GoalHandleFetch::SharedPtr> future)
  // {
  //   auto goal_handle = future.get();
  //   if (!goal_handle) {
  //     RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
  //   } else {
  //     RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
  //   }
  // }

  // ROS2_TUTORIAL_CPP_LOCAL
  // void feedback_callback(
  //   GoalHandleFetch::SharedPtr,
  //   const std::shared_ptr<const Fetch::Feedback> feedback)
  // {
  //   std::stringstream ss;
  //   ss << "Next number in sequence received: ";
  //   for (auto number : feedback->partial_sequence) {
  //     ss << number << " ";
  //   }
  //   RCLCPP_INFO(this->get_logger(), ss.str().c_str());
  // }

  // ROS2_TUTORIAL_CPP_LOCAL
  // void result_callback(const GoalHandleFetch::WrappedResult & result)
  // {
  //   switch (result.code) {
  //     case rclcpp_action::ResultCode::SUCCEEDED:
  //       break;
  //     case rclcpp_action::ResultCode::ABORTED:
  //       RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
  //       return;
  //     case rclcpp_action::ResultCode::CANCELED:
  //       RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
  //       return;
  //     default:
  //       RCLCPP_ERROR(this->get_logger(), "Unknown result code");
  //       return;
  //   }
  //   std::stringstream ss;
  //   ss << "Result received: ";
  //   for (auto number : result.result->sequence) {
  //     ss << number << " ";
  //   }
  //   RCLCPP_INFO(this->get_logger(), ss.str().c_str());
  //   rclcpp::shutdown();
  // }
};  // class ActionClient
}  // namespace ros2_tutorial_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(ros2_tutorial_cpp::ActionClient)
