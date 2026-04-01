# Implementation Summary

This repository contains a simulation setup for evaluating QUIC transport protocol behavior over LEO satellite networks.

## Overview

The system is built using:

- OMNeT++ simulation framework
- INET network library (extended with QUIC support)
- Satellite topology representing LEO constellations

## Network Design

The simulation consists of:

- 10 satellites connected in a ring topology
- 20 ground stations connected to satellites
- Multi-hop communication between ground stations via satellites

## Communication Flow

- Ground station `gs[0]` acts as QUIC client
- Ground station `gs[19]` acts as QUIC server
- Data is transmitted across multiple satellite nodes

## QUIC Integration

QUIC is implemented as a transport layer over UDP and supports:

- Connection-based communication
- Packet transmission over multi-hop paths
- Compatibility with IP routing

## Purpose

The objective of this setup is to:

- Evaluate transport protocol behavior under dynamic satellite conditions
- Provide a base framework for further experimentation
- Support reinforcement learning-based congestion control (separate module)

## Note

This implementation focuses on simulation-based evaluation and is designed to reflect realistic network behavior using controlled parameters.
