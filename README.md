# Starlinked Embedded Systems Simulator

**Starlinked** is a C++ simulation of a satellite control system designed to model key satellite operations, including orientation, battery management, and telemetry logging. This project simulates a real-time system where various satellite components are managed and logged over simulated time ticks.

## Features

- **Satellite Orientation**: Simulates pitch, yaw, and roll of a satellite.
- **Battery Management**: Simulates battery usage over time, displaying remaining power.
- **Telemetry Logging**: Logs satellite telemetry (e.g., orientation, battery levels) to a file for future analysis.
- **Real-Time Simulation**: Simulates 10 ticks of satellite operations, updating system parameters and logging telemetry data at each step.

## Technologies

- **C++**: Primary programming language for the simulation.
- **File I/O**: Logs telemetry data to a file for analysis.
- **Real-Time Operations**: Utilizes `std::this_thread::sleep_for` to simulate real-time operation.

## Installation

1. Clone the repository:

   ```
   git clone https://github.com/d-angelotorres/starlinked.git
   cd starlinked
   ```

2. Compile the C++ code:

   ```
   g++ -Iinclude -o starlinked src/*.cpp
   ```

3. Run the simulation:
   ```
   ./starlinked
   ```

## Usage

When the program is run, the satellite's control systems will boot up, and the status of the satellite will be printed at each simulation tick, including:

- **Pitch, Yaw, Roll**: The satellite’s orientation in degrees.
- **Battery**: The current battery level (percentage).

Telemetry data will also be logged to a file named `satellite_log.txt` for later analysis.

## Example Output

```
🛰️  Starlinked Embedded Systems Simulator
Booting satellite control systems...
✅ Systems online.

🛰️ Satellite Status Report
Pitch: 0°, Yaw: 0.05°, Roll: 0°
Battery: 99.9%

🛰️ Satellite Status Report
Pitch: 0°, Yaw: 0.1°, Roll: 0°
Battery: 99.8%

...
```

## Future Enhancements

- **Additional Sensors**: Add support for solar panel deployment, temperature sensors, and more.
- **Fault Simulation**: Introduce errors and malfunctions (e.g., battery failure, orientation misalignment).
- **Advanced Telemetry**: Log more detailed telemetry data such as environmental factors (temperature, pressure) or communication status.
- **Extended Control Systems**: Simulate complex maneuvers and decision-making algorithms for satellite control.

## License

This project is licensed under the [MIT License](LICENSE).
