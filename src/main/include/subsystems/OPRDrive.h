#pragma once
#include <ctre/phoenix6/TalonFX.hpp>

class OPRDrive {
   public:
    OPRDrive();
    ~OPRDrive();

    /**
     * @brief Controls the motors of the Drive Base for arcade drive
     * @param throttle front back backward speed
     * @param turn turn speed left and right
     */
    void ArcadeDrive(double throttle, double turn);

    /**
     * @brief Stops all the motors (0 percent out)
     */
    void Stop();

   private:
    // Drive Motors and their followers
    ctre::phoenix6::hardware::TalonFX* LeftMaster;
    ctre::phoenix6::hardware::TalonFX* LeftFollower;
    ctre::phoenix6::hardware::TalonFX* RightMaster;
    ctre::phoenix6::hardware::TalonFX* RightFollower;

    // All motors configs
    ctre::phoenix6::configs::TalonFXConfiguration LeftMasterConfigs{};
    ctre::phoenix6::configs::TalonFXConfiguration LeftFollowerConfigs{};
    ctre::phoenix6::configs::TalonFXConfiguration RightMasterConfigs{};
    ctre::phoenix6::configs::TalonFXConfiguration RightFollowerConfigs{};

    // Control mode for percent out
    ctre::phoenix6::controls::VoltageOut PercentOut{0_V, true, false};
};