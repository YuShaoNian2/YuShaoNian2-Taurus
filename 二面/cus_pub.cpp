#include <rclcpp/rclcpp.hpp>
#include "cus_msg/msg/custom_msg.hpp"
#include <chrono>
#include <functional>
using namespace std::chrono_literals;
class ExamMsgPublisher : public rclcpp::Node {
public:
  ExamMsgPublisher()
  : Node("exam_msg_publisher")
  {
    publisher_=this->create_publisher<cus_msg::msg::CustomMsg>("exam_topic",10);
    timer_=this->create_wall_timer(std::chrono::seconds(1)
,std::bind(&ExamMsgPublisher::publish_message,this));
  }

private:
  void publish_message()
  {
    auto message = cus_msg::msg::CustomMsg();
    message.v = 1;
    message.rad = 1;
    RCLCPP_INFO(this->get_logger(), "Publishing: v=%d,rad = %f",
                    message.v, message.rad);
    publisher_->publish(message);
                  }
rclcpp::Publisher<cus_msg::msg::CustomMsg>::SharedPtr publisher_;
rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ExamMsgPublisher>());
  rclcpp::shutdown();
  return 0;
}
