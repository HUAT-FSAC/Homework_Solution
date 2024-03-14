#include "ros/ros.h"
#include "hw_2/test.h"

void callback(const hw_2::test::ConstPtr& msg)
{
    if (msg -> flag)
    {
        std::cout << "x: " << msg -> x << std::endl;
        std::cout << "y: " << msg -> y << std::endl;
        std::cout << "z: " << msg -> z << std::endl;
    } else {
        // change name?
    }
    
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "h2");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/point_position", 10, callback);
    ros::spin();
    return 0;
}