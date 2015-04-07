#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "AdsDef.h"
#include "Frame.h"
#include "RingBuffer.h"

struct Router {
	static const size_t NUM_PORTS_MAX = 128;
	static const uint16_t PORT_BASE = 30000;
	static_assert(PORT_BASE + NUM_PORTS_MAX <= UINT16_MAX, "Port limit is out of range");

	virtual void Dispatch(AmsAddr amsAddr, uint16_t port, size_t expectedSize) = 0;
	Frame& GetFrame() { return frame; };
	RingBuffer& GetRing(uint16_t port) { return ringBuffer[port - PORT_BASE]; }
private:
	Frame frame{ 10240 };
	RingBuffer ringBuffer[NUM_PORTS_MAX];
};
#endif /* #ifndef _ROUTER_H_ */