// include/Satellite.hpp
#ifndef SATELLITE_HPP
#define SATELLITE_HPP

#include <string>
#include <ctime> // For simulating time-based events

class Satellite
{
private:
    double pitch, yaw, roll; // Orientation in degrees
    double battery;          // % battery level
    double solarPanel;       // Solar panel charging rate
    double temperature;      // Temperature in Celsius
    bool manualControl;      // Manual control flag for rotating satellite

public:
    Satellite(); // Constructor

    void update();                                // Simulate time passing
    void rotate(double dp, double dy, double dr); // Manual control
    void statusReport() const;                    // Print status
    void logTelemetry() const;                    // Log telemetry data

    // Future ideas: add solar panel, temp sensors, deployables, etc.
    void simulateSolarPanelCharge();  // Simulate battery charging via solar panel
    void simulateTemperatureChange(); // Simulate temperature variations
    void simulateSolarFlare();        // Simulate solar flare events
    void simulateSpaceDebrisImpact(); // Simulate space debris risk
};

#endif
