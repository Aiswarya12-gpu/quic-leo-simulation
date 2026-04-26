# QUIC over LEO Satellite Networks (OMNeT++ Simulation Framework)

This repository presents a simulation-based framework for evaluating QUIC transport protocol behavior in Low Earth Orbit (LEO) satellite networks.

The work is developed as part of a Master's thesis focused on analyzing transport-layer performance under dynamic satellite conditions, including mobility, handovers, and variable propagation delays.

---

## Overview

This project integrates multiple network simulation components to enable end-to-end QUIC communication over LEO satellite topologies:

- OMNeT++ (discrete-event simulation engine)
- INET Framework (network protocol stack)
- FloRaSat (LEO satellite mobility and topology modeling)
- Extended QUIC transport model (custom integration)

Unlike standard INET-QUIC implementations designed for terrestrial networks, this framework extends QUIC to operate under LEO-specific conditions such as:

- Dynamic topology changes
- Mobility-induced delay variation
- Frequent satellite handovers
- Multi-hop satellite communication

---

## Key Contributions

This work focuses on enabling QUIC over LEO satellite networks through system-level integration and transport-layer adaptation:

- Extension of INET with a QUIC-based transport model for satellite environments
- Integration of QUIC with FloRaSat mobility and link dynamics
- Modification of UDP–RadioMedium interface to support realistic propagation delays
- Introduction of mobility-aware QUIC behavior through handover event handling
- Support for multi-hop satellite routing between ground stations
- Framework foundation for advanced congestion control (e.g., RL-based QUIC)

---

## System Architecture

The transport stack follows a layered architecture within OMNeT++:

Application (QuicClientApp / QuicServerApp)  
→ QUIC (QuicConnection, congestion control)  
→ UDP (modified UdpSocket)  
→ IP Layer  
→ RadioMedium / Inter-Satellite Links (FloRaSat)

### Key Architectural Enhancements

- QUIC operates over UDP using INET’s transport interface
- UDP layer is extended to incorporate satellite propagation delays from FloRaSat
- QUIC layer is enhanced with mobility awareness:
  - Handover events trigger RTT reset and congestion control updates
- Integration resolves incompatibilities between INET-QUIC and FloRaSat modules

---

## QUIC Integration Details

The default INET-QUIC implementation does not support LEO satellite environments. To enable compatibility, the following modifications were introduced:

- Added handover-aware logic in `QuicConnection` to handle dynamic path changes
- Extended UDP socket behavior to align with satellite link delays
- Updated INET–FloRaSat interfaces (e.g., RadioMedium, SNIR handling)
- Introduced custom modules for QUIC-based ground station communication
- Resolved version and dependency conflicts between INET and FloRaSat

These changes enable stable QUIC communication over dynamic satellite paths.

---

## Simulation Setup

- 10 satellites (Walker/ring topology)
- 20 ground stations
- Multi-hop inter-satellite communication
- QUIC client → `groundStation[0]`
- QUIC server → `groundStation[19]`

Simulation characteristics:

- Variable RTT (~60–80 ms)
- Packet loss (~0–5%)
- Periodic satellite handovers
- Dynamic routing paths

---

## Repository Structure

- `inet_quic/`  
  Contains modified INET components and QUIC-related extensions

- `simulation/`  
  Network topology, NED files, and configuration (.ini)

- `notes/`  
  Setup instructions and implementation documentation

---

## Requirements

- OMNeT++ 6.x  
- INET Framework 4.5  
- Ubuntu 22.04 (recommended)

---

## Setup and Execution

Detailed setup instructions are available in:

👉 `notes/run_instructions.md`

Includes:

- OMNeT++ installation
- INET setup and configuration
- Integration steps
- Running simulation scenarios

---

## Notes

- This repository includes only modified components (not full INET)
- QUIC is implemented as a research-oriented transport extension
- Some modules are simplified for simulation purposes
- Focus is on system-level evaluation, not full protocol compliance

---

## Extension: Reinforcement Learning (RL)

This framework serves as the base for RL-based congestion control:

- QUIC pacing rate can be externally controlled
- Integration supports real-time metric extraction (RTT, throughput, loss)
- RL agent can interact via external interface (e.g., PyBind11)

---

## Academic Context

This repository is part of a Master's thesis:

**“Evaluation of Transport Layer Protocol QUIC over LEO Constellations”**

The framework is designed for:

- Transport protocol evaluation
- Satellite network research
- Reproducible simulation studies

---

## Disclaimer

This implementation is intended for research and academic purposes.  
It does not represent a production-ready QUIC stack.

---
