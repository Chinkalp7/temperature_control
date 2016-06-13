#include "ros/ros.h"
#include <std_msgs/Int16.h>
#include <stdlib.h>
#include <time.h>


float error=0, dterror=0, _pid=0, previous_error=0, kp=1.2, kd=0;
int target=10;
std_msgs::Int16 pid_info;

void pid_callback(const std_msgs::Int16::ConstPtr& tempr)
{		
	error=target-tempr->data;			// difference between desired temp and current temp
	dterror = (error - previous_error);
	_pid = kp*error + kd*dterror;			// Output based on previous error and current error
	ROS_INFO("error: [%d] dterror: [%d] pid: [%d]", (int)error, (int)dterror, (int)_pid);
	previous_error=error;
}

void goal_callback(const std_msgs::Int16::ConstPtr& tr)
{
	target=tr->data;				// Desired temperature
}

int main(int argc, char **argv)
{	
	
	ros::init(argc, argv, "pid_control");
	ros::NodeHandle np;

	ros::Publisher pid_publisher = np.advertise<std_msgs::Int16>("pid_out",100); 
	ros::Subscriber pid_data = np.subscribe("temp", 10, pid_callback);	     // Subscribing to temp data
	ros::Subscriber goal_data = np.subscribe("temp_goal", 1, goal_callback);     // Subscribing to desired temp value
	ros::Rate loop_rate(1);

	while(ros::ok())
	{
		pid_info.data=_pid;
		pid_publisher.publish(pid_info);	// Publishing PID output
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}

 
