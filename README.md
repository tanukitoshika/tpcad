# Take Pictures of Color and Depth Image

## Usage
In terminal,  
`$ roslaunch realsense2_camera rs_rgbd.launch`  
In new terminal, move to the repository where you want to save pictures.
After that,  
``$ ROS_HOME=`pwd` roslaunch tpcdi tpcdi.launch``  
OR  
``$ ROS_HOME=`pwd` roslaunch tpcdi tpcdi.launch date:=$(date +"%Y-%m-%d-%I-%M")``  
After set the pose of your camera,  
`$ rosrun tpcdi tpcdi`  
