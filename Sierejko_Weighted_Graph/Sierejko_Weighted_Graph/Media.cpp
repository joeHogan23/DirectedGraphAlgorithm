#include "pch.h"
#include "Media.h"

//--------------------------------------------------------------------------------------//
//									Media Class											//
//--------------------------------------------------------------------------------------//

void Media::printProperties()
{
	cout << "File Name: " << mediaName << endl;
	cout << "Format: " << format << endl;
}

void Media::setMediaName(string inName) { mediaName = inName; }

string Media::getMediaName() { return mediaName; }

void Media::setFormat(string inFormat) { format = inFormat; }

string Media::getFormat() { return format; }

//Set the pixel size of Resolution
void Resolution::setSize(int w, int h) { size = { w,h }; }

//Get the pixel size of Resolution
ScreenSize Resolution::getSize() { return size; }

//Set Aspect Ratio
void Resolution::setAspectRatio(float inAspect) { aspectRatio = inAspect; }

//Get Aspect Ratio
float Resolution::getAspectRatio() { return aspectRatio; }

//--------------------------------------------------------------------------------------//
//									Video Class											//
//--------------------------------------------------------------------------------------//

//Set Time
void Video::setTimeInSeconds(int inTimeInSeconds) { timeInSeconds = inTimeInSeconds; }

//Get Time
int Video::getTimeInSeconds() { return timeInSeconds; }


//Set the struct Resolution
void Video::setResolution(Resolution inResolution) { resolution = inResolution; }

//Get the struct Resolution
Resolution Video::getResolution() { return resolution; }

void Video::printProperties()
{
	Media::printProperties();

	cout << "Resolution: " << resolution.getSize().width << " x " << resolution.getSize().height << endl;
	cout << "Aspect Ratio: " << resolution.getAspectRatio() << endl;

	int seconds = timeInSeconds % 60;	//Get the remaining seconds
	int minutes = timeInSeconds / 60;	//Get the minutes

	//Get the time in 00:00 format
	cout << "Time: " << minutes << ":" << ((seconds < 10) ? "0" : "") << seconds << endl;
}

//--------------------------------------------------------------------------------------//
//									Music Class											//
//--------------------------------------------------------------------------------------//

void Music::setArtist(string inArtist) { artist = inArtist; }

string Music::getArtist() { return artist; }

void Music::setTimeInSeconds(int inTimeInSeconds) { timeInSeconds = inTimeInSeconds; }

int Music::getTimeInSeconds() { return timeInSeconds; }

void Music::setSampleRate(int inSampleRate) { sampleRate = inSampleRate; }

int Music::getSampleRate() { return sampleRate; }

void Music::printProperties()
{
	Media::printProperties(); //Print the base properties

	cout << "Sample Rate: " << sampleRate << endl;
	
	int seconds = timeInSeconds % 60;	//Get the remaining seconds
	int minutes = timeInSeconds / 60;	//Get the minutes

	//Get the time in 00:00 format
	cout << "Time: " << minutes << ":" << ((seconds < 10) ? "0" : "") << seconds << endl;
}
