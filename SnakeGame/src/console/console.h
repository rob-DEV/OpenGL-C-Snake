#pragma once
#ifndef CUSTOM_LOGGER
#define CUSTOM_LOGGER
#include <fstream>
#include <iostream>
#include <string>
#include <cstdarg>

//using namespace std;

/**
* Singleton Logging class
*/
class Console
{
public:
	/**
	*   Logs a message
	*   @param sMessage message to be logged.
	*/
	void Log(const std::string&);

	/**
	*   Variable Length Logger function
	*   @param format string for the message to be logged.
	*/
	void Log(const char* format, ...);

	/**
	*   Logs a message to the console and file
	*   @param sMessage message to be logged.
	*/
	void LogAndFile(const std::string&);

	/**
	*   Variable Length Logger function
	*   @param format string for the message to be logged.
	*/
	void LogAndFile(const char* format, ...);

	/**
	*	Holds the console window open until the enter key is pressed.
	*/
	int Pause();

	/**
	*   << overloaded function to Logs a message
	*   @param sMessage message to be logged.
	*/
	Console& operator <<(const std::string&);

	/**
	*   Funtion to create the instance of logger class.
	*   @return singleton object of Clogger class..
	*/
	static Console* GetConsole();
private:
	/**
	*    Default constructor for the Logger class.
	*/
	Console();

	/**
	*   copy constructor for the Logger class.
	*/
	Console(const Console&) {};             // copy constructor is private

	/**
	*   assignment operator for the Logger class.
	*/
	Console& operator=(const Console&) { return *this; };  // assignment operator is private
														   
	/**
	*   Log file name.
	**/
	static const std::string m_sFileName;

	/**
	*   Singleton logger class object pointer.
	**/
	static Console* m_pThis;

	/**
	*   Log file stream object.
	**/
	static std::ofstream m_Logfile;
};
#endif
/**
*
*/