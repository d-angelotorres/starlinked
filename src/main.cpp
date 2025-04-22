// src/main.cpp
#include <iostream>
#include <chrono>
#include <thread>
#include "Satellite.hpp"

int main()
{
    Satellite sat;

    std::cout << "🛰️  Starlinked Embedded Systems Simulator\n";
    std::cout << "Booting satellite control systems...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "✅ Systems online.\n";

    // Simulate 20 ticks of time
    for (int i = 0; i < 20; ++i)
    {
        sat.update();
        sat.statusReport();
        sat.logTelemetry(); // Log telemetry data to file

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "[✔] Satellite system simulator ran successfully!" << std::endl;
    return 0;
}
