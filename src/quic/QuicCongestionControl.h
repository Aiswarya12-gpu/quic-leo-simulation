#ifndef __QUIC_CONGESTION_CONTROL_H
#define __QUIC_CONGESTION_CONTROL_H

class QuicCongestionControl
{
  protected:
    int cwnd = 10;
    int ssthresh = 20;

    bool handoverActive = false;

  public:
    void onPacketAcked();
    void onPacketLost();
    void onHandover();

    int getCwnd() const { return cwnd; }
};

#endif
