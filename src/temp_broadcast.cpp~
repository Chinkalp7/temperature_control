#include "ros/ros.h"
#include <std_msgs/Int16.h>
#include <stdlib.h>
#include <time.h>


void pid_callback(const std_msgs::Int16::ConstPtr& pid_temp)
{		
	if (pid_temp->data > 10)
	{
		ROS_INFO("Decrease temperature ");	//If temp is higher than Desired temp than decrease temp	
	}
	else if (pid_temp->data < 10)
	{
		ROS_INFO("Increase temperature ");	//If temp is lower than Desired temp than increase temp	
	}

}

int main(int argc, char **argv)
{	
	int te=0;
	std_msgs::Int16 temp_var;
	ros::init(argc, argv, "temp_broadcast");
	ros::NodeHandle nt;

	ros::Subscriber pid_receive = nt.subscribe("pid_out", 100, pid_callback);  //Subscriber for subscribing pid output
	ros::Publisher temp_publisher = nt.advertise<std_msgs::Int16>("temp",100); //publisher for publishing fake temp reading
	ros::Rate loop_rate(1);
	
	while(ros::ok())
	{
		srand (time(NULL));
		te = rand()%20+1;			// Generating random numbers between 1 to 20  (fake temp reading)
		temp_var.data = te;
		temp_publisher.publish(temp_var);	// Publishing random numbers
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}

 
