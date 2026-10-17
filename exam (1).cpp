#include <rclcpp/rclcpp.hpp>
#include "cus_msg/msg/custom_msg.hpp"
#include <functional>
#include <geometry_msgs/msg/twist.hpp>

class Exam : public rclcpp::Node {
  rclcpp::Subscription<cus_msg::msg::CustomMsg>::SharedPtr subscription_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
public:
  Exam()
  : Node("exam")
  {
    subscription_=this->create_subscription<cus_msg::msg::CustomMsg>("exam_topic",10,
      std::bind(&Exam::topic_callback,this,std::placeholders::_1));
    publisher_=this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel",10);
  }

private:
  void topic_callback(const cus_msg::msg::CustomMsg::SharedPtr message) const
  {
    //RCLCPP_INFO(this->get_logger(), "Received: v=%d , rad = %f",message->v,message->rad);

    auto twist_msg = geometry_msgs::msg::Twist();

    twist_msg.linear.x = message->v;
    twist_msg.angular.z = message->rad;
    publisher_->publish(twist_msg);
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Exam>());
  rclcpp::shutdown();
  return 0;
}
