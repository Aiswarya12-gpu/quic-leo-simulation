# QUIC over LEO Satellite Networks (Simulation Framework)

This repository presents a simulation-based study of QUIC transport behavior in Low Earth Orbit (LEO) satellite networks.

This work is part of a Master's thesis focused on evaluating transport protocols under dynamic satellite conditions.

---

## Overview

The system integrates:

- OMNeT++ simulation environment  
- INET framework (extended)  
- FloRaSat satellite topology  
- QUIC-like transport implementation  

The objective is to study protocol behavior under:

- Variable latency  
- Packet loss  
- Frequent satellite handovers  

---

## Repository Contents

- inet_quic/  
  Contains selected modifications to support QUIC-like behavior.

- simulation/  
  Network topology and experiment configuration.

- notes/  
  Implementation explanation and design decisions.

---

## Key Contribution

- Extension of INET with QUIC-like transport behavior  
- Basic handover-aware packet handling  
- Multi-hop satellite communication simulation  
- Foundation for adaptive congestion control (RL-ready)

---

## Simulation Setup

- 10 satellites (ring topology)  
- 20 ground stations  
- QUIC client → gs[0]  
- QUIC server → gs[19]  

---

## How to Use

1. Install OMNeT++ and INET framework  
2. Integrate the provided QUIC-related files  
3. Load the simulation configuration  
4. Run using `omnetpp.ini`

---

## Note

This repository provides a simplified representation of the implementation.

It does not include the full INET framework or a complete QUIC standard implementation.

---

## Extension

Reinforcement learning-based congestion control is implemented separately as part of the overall thesis work.
