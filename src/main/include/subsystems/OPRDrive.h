#pragma once

class OPRDrive {
   public:
    OPRDrive();
    ~OPRDrive();

    void SetOpenLoop(double throttle, double turn);
    void Stop();

   private:
};