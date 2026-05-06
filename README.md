QUIC over LEO Satellite Networks with RL-Based Adaptive Pacing

This repository presents a simulation framework for evaluating QUIC transport performance in Low Earth Orbit (LEO) satellite networks, extended with a reinforcement learning (RL)-based adaptive pacing control mechanism.

The system is implemented using OMNeT++, INET, and FloRaSat, and is designed to study transport-layer behavior under dynamic satellite conditions, including mobility, handovers, and time-varying propagation delays.

🎯 Key Idea

Traditional congestion control mechanisms assume that:

Packet loss → congestion
RTT increase → queue buildup

👉 This assumption breaks in LEO networks, where:

RTT variation is caused by satellite movement
Packet loss is often due to handover events, not congestion
✅ Proposed Solution

This work introduces a learning-based pacing refinement layer on top of QUIC:

Final Pacing Rate = BBR Rate × (1 + RL Action)
BBR provides baseline bandwidth estimation
RL agent adjusts pacing rate dynamically
No modification to congestion window (cwnd)

👉 This creates a hybrid congestion control architecture

🧠 System Architecture
Application (Client/Server)
        ↓
QUIC Transport Layer (Modified)
        ↓
[BBR Congestion Control]
        ↓
[RL-Based Pacing Adjustment]
        ↓
UDP Layer
        ↓
IP Layer
        ↓
LEO Satellite Network (FloRaSat)
🔁 RL Control Loop

At runtime (every 100 ms):

Network State (RTT, Throughput, Loss)
            ↓
        RL Agent
            ↓
   Pacing Adjustment Action
            ↓
 Updated QUIC Pacing Rate
⚙️ Implementation Details
📍 Modified Files
1. QUIC Congestion Control
src/quic/QuicCongestionControl.cc

Added:

State extraction (RTT, throughput, loss)
RL-based pacing refinement
Integration with existing QUIC pacing
2. QUIC Connection Timer
src/quic/QuicConnection.cc
Periodic control loop (100 ms)
Triggers pacing updates
🔧 Core Logic
double baseRate = getPacingRate();   // From BBR
double action = rlAgent.predict(rtt, throughput, loss);

double updatedRate = baseRate * (1.0 + action);
pacingRate = updatedRate;
📌 Important Design Note

✔ RL does NOT replace BBR
✔ RL only refines pacing behavior
✔ Ensures stability and compatibility

🛰️ Simulation Setup
Topology
10 LEO satellites (550 km altitude)
20 ground stations
Multi-hop satellite routing
Network Characteristics
Parameter	Value
RTT	60–80 ms
Packet Loss	~0.3–0.4%
Link Capacity	300 Mbps
Handover Interval	~10–20 s
Mobility Model
SGP4 (TLE-based satellite movement)
Elevation-based handover
Dynamic routing updates
📊 Key Results

Compared to QUIC-BBR:

Metric	Improvement
RTT	↓ Reduced
Packet Loss	↓ Reduced
Recovery Time	↓ Faster
Stability	↑ Improved
🔍 Key Insight

👉 RL improves response to transient events, not raw throughput

Avoids overreaction during handovers
Maintains smoother transmission
Reduces performance variability
📈 Dataset-Based Calibration

Simulation is calibrated using real-world datasets:

Starlink Delay Dataset
https://zenodo.org/records/16275284
WetLinks Dataset
https://github.com/sys-uos/WetLinks

Used for:

RTT modeling
Packet loss characteristics
Realistic variability
▶️ How to Run
Requirements
OMNeT++ 6.x
INET 4.5
Ubuntu 22.04
Steps
1. Import project into OMNeT++
2. Build project
3. Run:
   simulations/omnetpp.ini
📁 Output
results/
.vec → time-series data
.sca → summary metrics
⚠️ Limitations
Simplified QUIC implementation (no TLS)
RL model is lightweight (no large-scale training)
Simulation-based evaluation (no real deployment)
🔮 Future Work
Multi-agent RL for satellite networks
Real-time model inference integration
Cross-layer optimization
6G NTN integration
📚 Academic Context

This work is part of a Master’s thesis:

“Evaluation of QUIC Transport Protocol over LEO Satellite Constellations with Adaptive Pacing Control”

⚡ Key Contribution (What makes this work novel)

✔ First integration of RL-based pacing control in QUIC for LEO networks
✔ Works on top of BBR, not replacing it
✔ Handles mobility-induced dynamics explicitly
✔ Improves stability and recovery, not just throughput

📜 License

For research and educational use only.

🙏 Acknowledgements
OMNeT++ Community
INET Framework
FloRaSat
Starlink dataset contributors
🔚 Final Note

This repository demonstrates how learning-based control can enhance transport protocols for next-generation satellite networks, enabling more reliable and adaptive communication in highly dynamic environments.
