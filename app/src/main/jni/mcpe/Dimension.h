#pragma once

#include "Packet.h"

struct Player;

class Dimension {
public:
	void sendBroadcast(const Packet&, Player*);
};