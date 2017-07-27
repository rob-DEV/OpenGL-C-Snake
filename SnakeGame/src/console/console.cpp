#include "console.h"
#include "utilities.h"

const std::string Console::m_sFileName = "Log.txt";
Console* Console::m_pThis = NULL;
std::ofstream Console::m_Logfile;

Console::Console() 
{

}

Console* Console::GetConsole()
{
	if (m_pThis == NULL) 
	{
		m_pThis = new Console();
		m_Logfile.open(m_sFileName.c_str(), std::ios::out | std::ios::app);
	}
	return m_pThis;
}

void Console::Log(const std::string& sMessage)
{
	std::cout << sMessage << std::endl;
}

void Console::Log(const char * format, ...) 
{
	char* sMessage = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, format);
	//  Return the number of characters in the string referenced the list of arguments.
	// _vscprintf doesn't count terminating '\0' (that's why +1)
	nLength = _vscprintf(format, args) + 1;
	sMessage = new char[nLength];
	vsprintf_s(sMessage, nLength, format, args);
	//vsprintf(sMessage, format, args);
	std::cout << Util::CurrentDateTime() << ":\t" << sMessage << "\n";
	va_end(args);

	delete[] sMessage;
}

void Console::LogAndFile(const std::string& sMessage)
{

	std::cout << Util::CurrentDateTime() << ":\t" << sMessage << "\n";

	m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
}

void Console::LogAndFile(const char * format, ...)
{
	char* sMessage = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, format);
	//  Return the number of characters in the string referenced the list of arguments.
	// _vscprintf doesn't count terminating '\0' (that's why +1)
	nLength = _vscprintf(format, args) + 1;
	sMessage = new char[nLength];
	vsprintf_s(sMessage, nLength, format, args);
	//vsprintf(sMessage, format, args);
	std::cout << Util::CurrentDateTime() << ":\t" << sMessage << "\n";
	m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	va_end(args);

	delete[] sMessage;
}

int Console::Pause() 
{
	return std::cin.get();
}

Console& Console::operator<<(const std::string& sMessage)
{
	m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	return *this;
}
