// src/Satellite.cpp
#include "Satellite.hpp"
#include <iostream>
#include <cstdlib> // For random number generation
#include <fstream> // For file output (ofstream)

Satellite::Satellite()
{
    pitch = 0;
    yaw = 0;
    roll = 0;
    battery = 100.0;
    solarPanel = 1.0;   // Default solar panel charge rate
    temperature = 20.0; // Room temperature in Celsius
    manualControl = false;
}

void Satellite::update()
{
    // Simulate battery drain
    battery -= 0.1;
    if (battery < 0)
        battery = 0;

    // Simulate solar panel charging (if not manually controlled)
    if (!manualControl)
    {
        simulateSolarPanelCharge();
    }

    // Simulate small automatic adjustments
    yaw += 0.05;
    if (yaw > 360)
        yaw -= 360;

    // Simulate temperature change (fluctuates slowly)
    simulateTemperatureChange();

    // Simulate solar flare or space debris randomly
    if (rand() % 100 < 5) // 5% chance of an event each tick
    {
        if (rand() % 2 == 0)
            simulateSolarFlare();
        else
            simulateSpaceDebrisImpact();
    }
}

void Satellite::rotate(double dp, double dy, double dr)
{
    pitch += dp;
    yaw += dy;
    roll += dr;
    manualControl = true; // Manual control is active when rotating
}

void Satellite::statusReport() const
{
    std::cout << "\n🛰️ Satellite Status Report\n";
    std::cout << "Pitch: " << pitch << "°, Yaw: " << yaw << "°, Roll: " << roll << "°\n";
    std::cout << "Battery: " << battery << "%\n";
    std::cout << "Temperature: " << temperature << "°C\n";
}

void Satellite::logTelemetry() const
{
    std::ofstream logFile("satellite_log.txt", std::ios::app);
    logFile << "Time: " << std::time(0) << ", "
            << "Battery: " << battery << "%, "
            << "Pitch: " << pitch << "°, "
            << "Yaw: " << yaw << "°, "
            << "Roll: " << roll << "°, "
            << "Temperature: " << temperature << "°C\n";
    logFile.close();
}

void Satellite::simulateSolarPanelCharge()
{
    battery += solarPanel;
    if (battery > 100)
        battery = 100; // Max battery is 100%
}

void Satellite::simulateTemperatureChange()
{
    // Temperature fluctuates between -50 and 50°C (simulating space environment)
    temperature += (rand() % 10 - 5); // Random fluctuation by ±5°C
}

void Satellite::simulateSolarFlare()
{
    std::cout << "\n⚡ Solar flare detected! Battery drained by 20%.\n";
    battery -= 20;
    if (battery < 0)
        battery = 0;
}

void Satellite::simulateSpaceDebrisImpact()
{
    std::cout << "\n☄️ Space debris impact! Minor system damage, battery drained by 10%.\n";
    battery -= 10;
    if (battery < 0)
        battery = 0;
}
