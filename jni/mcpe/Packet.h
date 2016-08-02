#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Abilities.h"
#include "AdventureSettings.h"

#define PACKET_DISCONNECT_ID 5
#define PACKET_TEXT_ID 7
#define PACKET_ADVENTURESETTINGS_ID 49

namespace RakNet {
	class BitStream;
};
class NetEventCallback;

struct Packet {
	//void** vtable;	// 0-4
	int a;				// 4-8
	int b;				// 8-12
	bool c; 			// 12-13 and/or 12-16
	
	virtual ~Packet();
	virtual int getId() const = 0;
	virtual void write(RakNet::BitStream*) const = 0;
	virtual void read(RakNet::BitStream*) = 0;
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const = 0;
};

class MinecraftPackets {
public:
	static std::unique_ptr<Packet> createPacket(int);
};

struct DisconnectPacket : public Packet {
public:
	std::string message;	// 16-20
	
	virtual ~DisconnectPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream*) const;
	virtual void read(RakNet::BitStream*);
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const;
};

enum TextPacketType {
	RAW,
	CHAT,
	LOCALIZABLE,
	POPUP,
	TIP,
	SYSTEM
};

struct TextPacket : public Packet {
	TextPacketType type;				// 13-16
	std::string source; 				// 16-20
	std::string message;				// 20-24
	std::vector<std::string> params;	// 24-28
	
	virtual ~TextPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream*) const;
	virtual void read(RakNet::BitStream*);
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const;
	
	TextPacket(TextPacketType, const std::string&, const std::string&, std::vector<std::string> const&);
	
	static TextPacket* createRaw(const std::string&);
	static TextPacket* createSystemMessage(const std::string&);
	static TextPacket* createTranslated(const std::string&, std::vector<std::string> const&);
};

struct AdventureSettingsPacket : public Packet {
	int flags;	// I don't know lol
	
	virtual ~AdventureSettingsPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream*) const;
	virtual void read(RakNet::BitStream*);
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const;
	
	void fillIn(AdventureSettings&, Abilities&) const;
};