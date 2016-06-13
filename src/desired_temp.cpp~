#include "ros/ros.h"
#include <std_msgs/Int16.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{	
	ros::init(argc, argv, "desired_temp");
	ros::NodeHandle nt;

	ros::Publisher temp_publisher = nt.advertise<std_msgs::Int16>("temp_goal",100);
	ros::Rate loop_rate(10);
	
	while(ros::ok())
	{
		std_msgs::Int16 temp_var;
		temp_var.data = 10;
		temp_publisher.publish(temp_var);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}

 
