#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

class MimicNode : public rclcpp::Node
{
public:
  MimicNode() : rclcpp::Node("turtle_mimic")
  {
    twist_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("output/cmd_vel", 1);
//    pose_sub_ = this->create_subscription<turtlesim::msg::Pose>(
//      "input/pose", 1, std::bind(&MimicNode::poseCallback, this, std::placeholders::_1));
    twist_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "input/cmd_vel", 1, std::bind(&MimicNode::twistCallback, this, std::placeholders::_1));
  }

private:
  void poseCallback(const turtlesim::msg::Pose::SharedPtr pose)
  {
    geometry_msgs::msg::Twist twist;
    twist.angular.z = pose->angular_velocity;
    twist.linear.x = pose->linear_velocity;
    twist_pub_->publish(twist);
  }

  void twistCallback(const geometry_msgs::msg::Twist::SharedPtr twist)
  {
    geometry_msgs::msg::Twist twist_out;
    twist_out.linear.x = (-1 * twist->linear.x);
    twist_out.linear.y = (-1 * twist->linear.y);
    twist_out.linear.z = (-1 * twist->linear.z);
    twist_out.angular.x = (-1 * twist->angular.x);
    twist_out.angular.y = (-1 * twist->angular.y);
    twist_out.angular.z = (-1 * twist->angular.z);
    twist_pub_->publish(twist_out);
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twist_pub_;
//  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twist_sub_;
};

int main(int argc, char** argv)
{
  puts("mimic_main");
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MimicNode>());
}

