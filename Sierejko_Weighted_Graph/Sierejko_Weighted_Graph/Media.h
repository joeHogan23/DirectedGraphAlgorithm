#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

__interface IMediaInterface
{
	void setMediaName(string);
	string getMediaName();

	void setFormat(string);
	string getFormat();

	virtual void printProperties();
};

struct ScreenSize 
{
	int width;
	int height;
};

//--------------------------------------------------------------------------------------//
//									Resolution Interface								//
//--------------------------------------------------------------------------------------//

class Resolution {
private:
	ScreenSize size;
	float aspectRatio;

public:
	//Default Constructor
	Resolution() : size({720,480}), aspectRatio(720/480) {};

	//Overload Constructor
	Resolution(int w, int h) {
		size = { w,h };
		aspectRatio = size.width/ size.height;
	};

	//Destructor
	~Resolution() {};

	void setSize(int w, int h);
	ScreenSize getSize();

	void setAspectRatio(float inAspect);
	float getAspectRatio();
};

//--------------------------------------------------------------------------------------//
//									Media Interface										//
//--------------------------------------------------------------------------------------//

class Media: public IMediaInterface
{
protected:
	string mediaName;
	string format;
	
public:
	Media() {};
	~Media() {};

	//IMediaInterface
	void setMediaName(string inName) override;
	string getMediaName() override;
	void setFormat(string inFormat) override;
	string getFormat() override;

	virtual void printProperties() override;
};

//--------------------------------------------------------------------------------------//
//									Video Interface										//
//--------------------------------------------------------------------------------------//

class Video : public Media
{
protected:
	int timeInSeconds;
	Resolution resolution;
public:

	Video(string inName, string inFormat, int inTimeInSeconds, Resolution inResolution) : 
		timeInSeconds(inTimeInSeconds), resolution(inResolution) {
		mediaName = inName;
		format = inFormat;
	}
	~Video() {};

	void setTimeInSeconds(int inTimeInSeconds);
	int getTimeInSeconds();

	void setResolution(Resolution inResolution);
	Resolution getResolution();

	virtual void printProperties();
};

//--------------------------------------------------------------------------------------//
//									Music Interface										//
//--------------------------------------------------------------------------------------//

class Music : public Media
{
protected:
	string artist;
	int timeInSeconds;
	int sampleRate;

public:
	Music() : artist("Unknown Artist"), sampleRate(192), timeInSeconds(180)
	{
		mediaName = "Unknown Title";
		format = "WAV";
	}

	Music(string inName, string inArtist, string inFormat, int inSampleRate, int inTimeInSeconds) :
		artist(inArtist), sampleRate(inSampleRate), timeInSeconds(inTimeInSeconds) {
		mediaName = inName;
		format = inFormat;
	}

	~Music() {};

	void setArtist(string inArtist);
	string getArtist();

	void setTimeInSeconds(int inTimeInSeconds);
	int getTimeInSeconds();

	void setSampleRate(int inSampleRate);
	int getSampleRate();

	virtual void printProperties();
};