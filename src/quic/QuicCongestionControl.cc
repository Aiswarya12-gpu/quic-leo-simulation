#include "QuicCongestionControl.h"
#include <iostream>

void QuicCongestionControl::onPacketAcked()
{
    if (cwnd < ssthresh) {
        // Slow start
        cwnd += 1;
    } else {
        // Congestion avoidance
        cwnd += 1 / cwnd;
    }

    std::cout << "ACK received → CWND: " << cwnd << std::endl;
}

void QuicCongestionControl::onPacketLost()
{
    if (handoverActive) {
        // 🚀 KEY IDEA: IGNORE LOSS DURING HANDOVER
        std::cout << "Loss during handover → IGNORE\n";
        return;
    }

    ssthresh = cwnd / 2;
    cwnd = 1;

    std::cout << "Loss detected → CWND reduced to " << cwnd << std::endl;
}

void QuicCongestionControl::onHandover()
{
    handoverActive = true;

    std::cout << "Handover mode ON\n";
}
