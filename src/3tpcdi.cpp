#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_srvs/Empty.h>
#include <std_srvs/Trigger.h>

bool print_b;
ros::Publisher brightness_pub;
int frames_passed = 0;
int saved_imgs = 0;

bool saved_img(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {
   res.success = 1;
   std::string str("Saved images: ");
   std::string num = std::to_string(saved_imgs);
   str.append(num);
   res.message = str;
   return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "save_node");

  ros::NodeHandle n;
  ros::ServiceClient client1 = n.serviceClient<std_srvs::Empty>("/image_saver1/image_saver/save");
  std_srvs::Empty srv1;
  ros::ServiceClient client2 = n.serviceClient<std_srvs::Empty>("/image_saver2/image_saver/save");
  std_srvs::Empty srv2;
  ros::ServiceClient client3 = n.serviceClient<std_srvs::Empty>("/image_saver3/image_saver/save");
  std_srvs::Empty srv3;
  client1.call(srv1);
  saved_imgs++;
  client2.call(srv2);
  saved_imgs++;
  client2.call(srv3);
  saved_imgs++;
  return 0;
}
