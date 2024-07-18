// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {
    joystick = new frc::XboxController(1);
    driveBase = new OPRDrive();
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
    driveBase->Stop();
}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
    driveBase->ArcadeDrive(joystick->GetLeftY(), joystick->GetLeftX());
}

void Robot::DisabledInit() {
    driveBase->Stop();
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {
    driveBase->Stop();
}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif
