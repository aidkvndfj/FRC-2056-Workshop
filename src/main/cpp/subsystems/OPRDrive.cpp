#include "Subsystems/OPRDrive.h"

OPRDrive::OPRDrive() {
    LeftMaster = new ctre::phoenix6::hardware::TalonFX(0, "rio");
    LeftFollower = new ctre::phoenix6::hardware::TalonFX(1, "rio");
    RightMaster = new ctre::phoenix6::hardware::TalonFX(2, "rio");
    RightFollower = new ctre::phoenix6::hardware::TalonFX(3, "rio");

    // All motors configs
    ctre::phoenix6::configs::TalonFXConfiguration LeftMasterConfigs{};
    ctre::phoenix6::configs::TalonFXConfiguration LeftFollowerConfigs{};
    ctre::phoenix6::configs::TalonFXConfiguration RightMasterConfigs{};
    ctre::phoenix6::configs::TalonFXConfiguration RightFollowerConfigs{};

    LeftMasterConfigs.MotorOutput.Inverted = ctre::phoenix6::signals::InvertedValue::Clockwise_Positive;
    LeftMasterConfigs.MotorOutput.NeutralMode = ctre::phoenix6::signals::NeutralModeValue::Brake;
    LeftMaster->GetConfigurator().Apply(LeftMasterConfigs);
    LeftFollower->SetControl(ctre::phoenix6::controls::Follower{LeftMaster->GetDeviceID(), false});

    RightMasterConfigs.MotorOutput.Inverted = ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive;
    RightMasterConfigs.MotorOutput.NeutralMode = ctre::phoenix6::signals::NeutralModeValue::Brake;
    RightMaster->GetConfigurator().Apply(RightMasterConfigs);
    RightFollower->SetControl(ctre::phoenix6::controls::Follower{RightMaster->GetDeviceID(), false});
}

OPRDrive::~OPRDrive() {}