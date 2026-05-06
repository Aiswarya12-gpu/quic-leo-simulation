void QuicCongestionControl::updatePacingRate()
{
    double rtt = getRTT();
    double throughput = getThroughput();
    double loss = getLoss();

    double action = rlAgent.predict(rtt, throughput, loss);

    double baseRate = getPacingRate();

    double updatedRate = baseRate * (1.0 + action);

    pacingRate = updatedRate;

    EV_INFO << "[RL-PACING]"
            << " RTT=" << rtt
            << " Throughput=" << throughput
            << " Loss=" << loss
            << " BaseRate=" << baseRate
            << " Action=" << action
            << " FinalRate=" << pacingRate
            << endl;
}
