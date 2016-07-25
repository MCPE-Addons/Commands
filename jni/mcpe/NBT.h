#pragma once

#include <map>
#include <memory>
#include <string>

class PrintStream;
class IDataOutput;
class IDataInput;

// Size: 8
struct Tag {
	// void** vtable;	// 0-4
	std::string name;	// 4-8
	
	virtual ~Tag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const = 0;
	virtual void load(IDataInput&) const = 0;
	virtual std::string toString() const = 0;
	virtual char getId() const = 0;
	virtual bool equals(const Tag&) const;
	virtual void print(PrintStream&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* setName(const std::string&);
	virtual std::string getName() const;
	virtual Tag* copy() const = 0;
	
	enum class Type {
		End = 0,
		Byte,
		Short,
		Int,
		Long,
		Float,
		Double,
		ByteArray,
		String,
		List,
		Compound,
		IntArray
	};
	
	Tag(const std::string&);
};

struct ListTag;
struct TagMemoryChunk;

// Size: 32
struct CompoundTag : public Tag {
	std::map<std::string, std::unique_ptr<Tag>> data; // 8-?
	
	virtual ~CompoundTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* copy() const;
	
	bool contains(const std::string&) const;
	bool contains(const std::string&, Tag::Type) const;
	std::unique_ptr<Tag> get(const std::string&) const; // not sure about return type
	void getAllTags(std::vector<Tag*>&) const;
	bool getBoolean(const std::string&) const;
	char getByte(const std::string&) const;
	TagMemoryChunk getByteArray(const std::string&) const;
	CompoundTag getCompound(const std::string&) const; // probably a std::unique_ptr<CompoundTag>; #FuckMojang
	double getDouble(const std::string&) const;
	float getFloat(const std::string&) const;
	int getInt(const std::string&) const;
	long long getInt64(const std::string&) const;
	TagMemoryChunk getIntArray(const std::string&) const;
	ListTag getList(const std::string&) const; // probably a std::unique_ptr<ListTag>; #FuckMojang
	short getShort(const std::string&) const;
	std::string getString(const std::string&) const;
	bool isEmpty() const;
	CompoundTag&& operator=(CompoundTag&&);
	void put(const std::string&, std::unique_ptr<Tag>);
	void putBoolean(const std::string&, bool);
	void putByte(const std::string&, char);
	void putByteArray(const std::string&, TagMemoryChunk);
	void putCompound(const std::string&, std::unique_ptr<CompoundTag>);
	void putDouble(const std::string&, float);
	void putFloat(const std::string&, float);
	void putInt(const std::string&, int);
	void putInt64(const std::string&, long long);
	void putShort(const std::string&, short);
	void putString(const std::string&, const std::string&);
	int rawView() const;
	void remove(const std::string&);
	
	CompoundTag();
	CompoundTag(CompoundTag&&);
	CompoundTag(const std::string&);
};

// Size: 20
struct ListTag : public Tag {
	std::vector<std::unique_ptr<Tag>> list;	// 8-20
	
	virtual ~ListTag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* copy() const;
	
	void add(std::unique_ptr<Tag>);
	std::unique_ptr<Tag> get(int) const; // not sure about return type
	std::unique_ptr<CompoundTag> getCompound(unsigned int) const;
	float getFloat(int) const;
	int getInt(int) const;
	int size() const;
	
	ListTag();
	ListTag(const std::string&);
};

struct TagMemoryChunk {
	void* data;
	int len;
};

// Size: 12
struct ByteArrayTag : public Tag {
	TagMemoryChunk data; // who cares about size lol
	
	virtual ~ByteArrayTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	ByteArrayTag(const std::string&);
	ByteArrayTag(const std::string&, TagMemoryChunk);
};

// Size: 12
struct IntArrayTag : public Tag {
	TagMemoryChunk data; // 8-12
	
	virtual ~IntArrayTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	IntArrayTag(const std::string&);
	IntArrayTag(const std::string&, TagMemoryChunk);
};

// Size: 8
struct StringTag : public Tag {
	std::string data; // supposed to be 8-12
	
	virtual ~StringTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	StringTag(const std::string&);
	StringTag(const std::string&, const std::string&);
};

// Size: 16
struct DoubleTag : public Tag {
	double data; // 8-16
	
	virtual ~DoubleTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	DoubleTag(const std::string&);
	DoubleTag(const std::string&, double);
};

// Size: 12
struct FloatTag : public Tag {
	float data;	// 8-12
	
	virtual ~FloatTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	FloatTag(const std::string&);
	FloatTag(const std::string&, float);
};

// Size: 8
struct ShortTag : public Tag {
	short data;	// supposed to be 8-10
	
	virtual ~ShortTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	ShortTag(const std::string&);
	ShortTag(const std::string&, short);
};

// Size: 8
struct ByteTag : public Tag {
	unsigned char data; // supposed to be 8-9
	
	virtual ~ByteTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	ByteTag(const std::string&);
	ByteTag(const std::string&, unsigned char);
};

// Size: 8
struct IntTag : public Tag {
	int data; // supposed to be 4-8
	
	virtual ~IntTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	IntTag(const std::string&);
	IntTag(const std::string&, int);
};

// Size: 16
struct Int64Tag : public Tag {
	long long data;	// 8-16
	
	virtual ~Int64Tag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
	
	Int64Tag(const std::string&);
	Int64Tag(const std::string&, long long);
};

// Size: 8
struct EndTag : public Tag {
	virtual ~EndTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual Tag* copy() const;
};

class NbtIo {
public:
	static CompoundTag* read(IDataInput*);
};
