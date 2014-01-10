

using namespace lcsr_controllers;

EffortControllerWrapper::EffortControllerWrapper(std::string const& name) :
  RTT::TaskContext(name),
  hardware_interface::RobotHW()
{
    for(unsigned int j=0; j < n_dof_; j++) {
      joint_position_[j] = 1.0;
      joint_velocity_[j] = 0.0;
      joint_effort_[j] = 0.1;
      joint_effort_command_[j] = 0.0;

      js_interface_.registerJoint(joint_name_[j], &joint_position_[j], &joint_velocity_[j], &joint_effort_[j]);
      ej_interface_.registerJoint(js_interface_.getJointStateHandle(joint_name_[j]), &joint_effort_command_[j]);
    }

    // Register the interfaces
    registerInterface(&state_interface_);
    registerInterface(&effort_interface_);


    this->addOperation("loadController",EffortControllerWrapper::loadController)
}

EffortControllerWrapper::loadController(const std::string &controller_name) 
{

}
