#pragma once

#include <string>
#include <vector>

struct Motive {
	std::string name;	// 0-12
	int width;			// 4-8
	int height;			// 8-12
	int uo;				// 12-16
	int vo;				// 16-20
	bool sPublic;		// 20-21
	
	Motive(std::string, int, int, int, int, bool);
	
	int getHeight() const;
	std::string getName() const;
	int getUo() const;
	int getVo() const;
	int getWidth() const;
	bool isPublic() const;
	
	static std::vector<const Motive*> getAllMotivesAsList();
	static const Motive getDefaultImage();
	static const Motive getMotiveByName(const std::string&);
	
	static const Motive mAlban;
	static const Motive mAztec;
	static const Motive mAztec2;
	static const Motive mBomb;
	static const Motive mBurningSkull;
	static const Motive mBust;
	static const Motive mCourbet;
	static const Motive mCreebet;
	static const Motive* mDefaultImage;
	static const Motive mDonkeyKong;
	static const Motive mEarth;
	static const Motive mFighters;
	static const Motive mFire;
	static const Motive mGraham;
	static const Motive mKebab;
	static const Motive mMatch;
	static const Motive mPigscene;
	static const Motive mPlant;
	static const Motive mPointer;
	static const Motive mPool;
	static const Motive mSea;
	static const Motive mSkeleton;
	static const Motive mSkullAndRoses;
	static const Motive mStage;
	static const Motive mSunset;
	static const Motive mVoid;
	static const Motive mWanderer;
	static const Motive mWasteland;
	static const Motive mWater;
	static const Motive mWind;
	static const Motive mWither;
};