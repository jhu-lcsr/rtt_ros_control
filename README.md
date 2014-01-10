rtt_ros_control
===============

This package contains RTT components which can be used to wrap ros-control-based controllers.

## Design Candidate A

In order to re-use as much of the ros_control architecture as possible, the RTT
components provided by this package each correspond to a type of joint command
interface (i.e. Effort, Velocity, Postion, etc) and include a plugin loader
which can load ros-control-based controllers dynamically at runtime via RTT
operations.

For example, the EffortControllerWrapper contains an EffortJointInterface and a
JointStateInterface. This requires replicating a lot of the content of the
ros_control controller_manager, but does not include all of the interaction
with the ROS parameter server and node handles.

## Design Candidate B

An alternative approach could leave all of this in, and simply instantiate a
controller manager inside of an orocos component. This would be the simplest
implementation, but care would need to be taken to prevent the non-real-time
parts of the controller_manager from interfering with the real-time process.
