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

## Repository Structure

- `inet_quic/`  
  Contains selected modifications to support QUIC-like behavior.

- `simulation/`  
  Network topology and experiment configuration.

- `notes/`  
  Additional documentation including implementation details and setup instructions.

---

## Key Contributions

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

## Requirements

- OMNeT++ 6.x  
- INET Framework 4.5  
- Ubuntu 22.04 (recommended)  

---

## Setup and Execution

Detailed environment setup and execution steps are provided in:

👉 `notes/run_instructions.md`

This includes:

- Installation of OMNeT++  
- INET framework setup  
- Project configuration  
- Running the simulation  

---

## Notes

This repository provides a simplified representation of the implementation.

- It does not include the full INET framework  
- QUIC is implemented as a simplified transport extension for research purposes  

---

## Extension

Reinforcement learning-based congestion control is implemented separately as part of the overall thesis work.

---

## Academic Use

This repository is part of an academic thesis project and is shared for research and reproducibility purposes.
