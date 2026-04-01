# How to Run the Simulation

## Environment Setup

The simulation was developed and tested with the following environment:

- OMNeT++ 6.2
- INET 4.5
- Linux environment (Ubuntu recommended)

---

## Step 1: Install OMNeT++

1. Download OMNeT++ 6.2 from the official website
2. Extract and install:


cd omnetpp-6.2
. setenv
./configure
make -j$(nproc)



---

## Step 2: Import INET Framework (Version 4.5)

1. Clone or download INET 4.5
2. Place it inside your OMNeT++ workspace
3. Build INET:


cd inet-4.5
make makefiles
make -j$(nproc)



---

## Step 3: Import This Project

1. Open OMNeT++ IDE
2. Go to:

   File → Import → Existing Projects into Workspace

3. Select this repository folder
4. Finish import

---

## Step 4: Configure Project Dependencies

1. Right-click your project
2. Go to:

   Properties → Project References

3. Enable:

   ✔ INET

---

## Step 5: Run the Simulation

1. Open:

   simulation/SatQuic.ned

2. Right-click → Run As → OMNeT++ Simulation

3. The simulation will use:

   simulation/omnetpp.ini

---

## Simulation Overview

- 10 satellites (ring topology)
- 20 ground stations
- Multi-hop routing via satellites
- QUIC client at gs[0]
- QUIC server at gs[19]

---

## Notes

- The QUIC implementation is based on an extended INET framework
- This repository focuses on simulation setup and system behavior
- The reinforcement learning module is provided in a separate repository

---

## Important Disclaimer

This is a simulation-based implementation designed to evaluate transport protocol behavior under LEO satellite conditions.

It does not represent a full production-level QUIC deployment.



---

## Step 3: Import This Project

1. Open OMNeT++ IDE
2. Go to:

   File → Import → Existing Projects into Workspace

3. Select this repository folder
4. Finish import

---

## Step 4: Configure Project Dependencies

1. Right-click your project
2. Go to:

   Properties → Project References

3. Enable:

   ✔ INET

---

## Step 5: Run the Simulation

1. Open:

   simulation/SatQuic.ned

2. Right-click → Run As → OMNeT++ Simulation

3. The simulation will use:

   simulation/omnetpp.ini

---

## Simulation Overview

- 10 satellites (ring topology)
- 20 ground stations
- Multi-hop routing via satellites
- QUIC client at gs[0]
- QUIC server at gs[19]

---

## Notes

- The QUIC implementation is based on an extended INET framework
- This repository focuses on simulation setup and system behavior
- The reinforcement learning module is provided in a separate repository

---

## Important Disclaimer

This is a simulation-based implementation designed to evaluate transport protocol behavior under LEO satellite conditions.

It does not represent a full production-level QUIC deployment.


