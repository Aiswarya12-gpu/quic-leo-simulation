# QUIC over LEO Satellite Networks (OMNeT++ Simulation Framework)

This repository presents a **simulation framework for evaluating the QUIC transport protocol in Low Earth Orbit (LEO) satellite networks** using OMNeT++, INET, and FloRaSat.

The work is developed as part of a **Master’s thesis** focused on analyzing transport-layer performance under **dynamic satellite conditions**, including mobility, handovers, and variable propagation delays.

---

#  Project Highlights

✔ QUIC over dynamic LEO satellite networks
✔ Integration of INET + FloRaSat
✔ Handover-aware transport layer
✔ LEO-aware congestion control (research extension)
✔ Multi-hop satellite routing
✔ Validation using real-world Starlink delay data

---

# Motivation

Traditional transport protocols struggle in LEO environments due to:

* High satellite mobility (~27,000 km/h)
* Frequent handovers (every 5–10 minutes)
* Variable propagation delays (20–150 ms)
* Bursty packet loss

QUIC offers modern features such as:

* 0-RTT connection establishment
* Multiplexed streams
* Improved loss recovery

However, QUIC is designed for terrestrial networks.

👉 This project adapts QUIC for **satellite-based communication systems**.

---

#  System Architecture

The system follows a layered architecture:

```text id="arch01"
Application (Client/Server)
        ↓
QUIC Transport Layer (Modified)
        ↓
UDP Layer (LEO-aware delay)
        ↓
IP Layer
        ↓
RadioMedium + Inter-Satellite Links (FloRaSat)
```

---

# 📁 Repository Structure

```text id="repo01"
quic-leo-simulation/
│
├── src/                      # Core implementation
│   ├── quic/                # QUIC transport layer
│   ├── transport/           # UDP modifications
│   ├── leo/                 # Handover handling logic
│
├── simulations/             # Network setup
│   ├── omnetpp.ini
│   └── ned/
│       ├── SatelliteNetwork.ned
│       ├── GroundStation.ned
│       ├── SatelliteRouter.ned
│
├── florasat_fixes/          # Compatibility fixes
│
├── results/                 # Simulation output
│   ├── latency/
│   ├── throughput/
│
├── docs/                    # Diagrams
│   └── diagrams/
│
└── notes/                   # Setup guide
```

---

#  Key Contributions

## 1. QUIC Integration with LEO Networks

* Extended INET QUIC for satellite communication
* Enabled end-to-end QUIC over multi-hop satellite paths

---

## 2. UDP Layer Modification

* Modified `UdpSocket.cc`
* Introduced realistic propagation delay

```text id="udp01"
send() → sendDelayed()
```

* Delay range: **20–150 ms**

---

## 3. Handover-Aware QUIC

* Implemented handover detection
* Reset RTT during satellite switch
* Prevent connection instability

---

## 4. LEO-Aware Congestion Control (Research Contribution)

Standard congestion control misinterprets satellite delay as congestion.

### Solution:

* Ignore packet loss during handover
* Maintain stable congestion window
* Improve throughput stability

---

## 5. FloRaSat Compatibility Fixes

Resolved integration issues:

* Fixed SNIR include paths
* Replaced deprecated interfaces
* Simplified analog model

---

# 🛰️ Simulation Setup

## Topology

* 10 satellites (ring topology)
* 20 ground stations
* Multi-hop inter-satellite routing

## Communication Flow

```text id="flow01"
groundStation[0] → satellites → groundStation[19]
```

---

## Simulation Parameters

| Parameter         | Value      |
| ----------------- | ---------- |
| Packet Size       | 1024 bytes |
| Interval          | 10–100 ms  |
| RTT               | 20–150 ms  |
| Packet Loss       | 0–5%       |
| Handover Interval | 300–600 s  |

---

#  Results Summary

## Latency

* Normal RTT: 25–100 ms
* Handover spikes: up to 250 ms

## Throughput

* Stable under low loss
* Drops during handover (~10–15%)
* Recovers after stabilization

---

# External Dataset and Validation

## Dataset Used

* **Title:** A Detailed Characterization of Starlink One-way Delay
* **Published at:** ACM LEONET 2025
* **Dataset:** https://zenodo.org/records/16275284

---

## 📦 Dataset Content

* One-way delay (OWD) measurements
* Real Starlink network behavior
* Time-based latency variation

---

## Usage in This Project

The dataset is used for:

### ✔ Parameter Selection

* Delay range (20–150 ms)
* Variability modeling

### ✔ Validation

* Compare simulation latency trends
* Verify delay spikes and recovery

### ✔ Model Design

* Justifies dynamic delay modeling
* Supports handover-aware logic

---

## Supporting Tool

* WetLinks Repository: https://github.com/sys-uos/WetLinks

Used for:

* Understanding real satellite network behavior
* Benchmarking simulation performance

---

##  Summary

```text id="summary01"
Simulation (OMNeT++ + INET + FloRaSat)
        +
Real-world dataset (Starlink delay)
```

Enables realistic and validated LEO network analysis

---

#  How to Run

## Requirements

* OMNeT++ 6.x
* INET 4.5
* Ubuntu 22.04

---

## Steps

1. Import project into OMNeT++
2. Build project
3. Run:

```text id="run01"
simulations/omnetpp.ini
```

→ Run As → OMNeT++ Simulation

---

# 📁 Output

Results are stored in:

```text id="out01"
results/
```

* `.vec` → time-series data
* `.sca` → summary metrics

---

#  Limitations

* Simplified QUIC implementation (no TLS)
* No real-world deployment validation
* Congestion control not fully optimized
* FloRaSat originally designed for IoT

---

# Future Work

* Implement advanced congestion control (BBR, RL-based)
* Improve handover prediction
* Real satellite trace integration
* 5G/6G NTN integration

---

# Use Cases

* Transport protocol research
* Satellite network simulation
* Congestion control experiments
* Academic studies

---

#  Academic Context

This repository is part of the Master’s thesis:

**“Evaluation of Transport Layer Protocol QUIC over LEO Constellations”**

---

# Disclaimer

This project is intended for **research and educational purposes only**.

It is **not a production-ready QUIC implementation**.

---

#  Acknowledgements

* OMNeT++ Community
* INET Framework
* FloRaSat Project
* Starlink delay dataset contributors

---

#  Final Note

This repository demonstrates how modern transport protocols can be adapted for **next-generation satellite internet systems**, supporting future **global broadband and 6G networks**.
