# 🌡️ Temperature Controlled Fan System using ESP32 and DHT22 (Wokwi Simulation)

### 🔗 Wokwi Simulation  
👉 [View and Run the Simulation on Wokwi](https://wokwi.com/projects/446983695060341761)

---

## 📘 Project Overview
This project demonstrates an **automatic temperature-controlled fan system** simulated entirely on the **Wokwi online platform**. The system uses an **ESP32 microcontroller** and a **DHT22 sensor** to monitor ambient temperature and humidity. Based on real-time temperature readings, the fan (simulated using a servo motor) adjusts its speed automatically through PWM signals. A **16×2 I²C LCD** displays the current temperature, humidity, and fan speed percentage.

---

## ⚙️ Components Used
- ESP32 Dev Kit V1  
- DHT22 Temperature and Humidity Sensor  
- Servo Motor (Fan Simulation)  
- 16×2 I²C LCD Display  
- Jumper Wires (Virtual Connections in Wokwi)

---

## 🧠 Working Principle
1. The **DHT22** sensor reads the surrounding temperature.  
2. The **ESP32** processes the data and maps the temperature value to a PWM signal.  
3. The PWM signal controls the **servo motor angle**, representing the fan speed.  
4. The **LCD** displays real-time temperature, humidity, and fan status.  
5. The system automatically increases fan speed as temperature rises.

---

## 🧩 Temperature-Speed Mapping
| Temperature (°C) | Fan Angle (°) | Fan Status |
|------------------|---------------|-------------|
| ≤ 25°C | 0° | OFF |
| 30°C | 60° | Low |
| 40°C | 120° | Medium |
| ≥ 50°C | 180° | High |

---

## 🛠️ How to Run
1. Open the Wokwi simulation link above.  
2. Click the **▶ Start Simulation** button.  
3. Adjust the DHT22 temperature slider to see the fan respond dynamically.  
4. Observe LCD updates for temperature, humidity, and fan speed.  

---

## 🎯 Objectives
- To design an automated fan speed control system using ESP32.  
- To demonstrate PWM-based control logic through simulation.  
- To monitor environmental parameters via LCD.  
- To validate functionality using Wokwi before real hardware implementation.

---

## 📈 Results
- The fan speed increased linearly with temperature.  
- The system responded instantly to sensor changes.  
- The LCD displayed accurate temperature and humidity readings.  
- The simulation matched expected theoretical performance.

---

## 🚀 Future Enhancements
- Add IoT connectivity for cloud monitoring.  
- Replace servo with an actual DC fan driver circuit.  
- Integrate mobile or web-based control.  

---

## 🧾 Author
**Madava Venkat J**  
B.E. Electronics and Communication Engineering  
Karunya Institute of Technology and Sciences  

---

## 🪪 License
This project is open-source and available for educational and research purposes.  
Feel free to fork, modify, and experiment with the design.

---
