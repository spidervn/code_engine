#include "GeneralUtil.h"
#include <string>
#include <ctime>

int GeneralUtil::getISO8601Time(std::string time1, std::tm& tmTime, int& timezone)
{
	// ISO 8601
	// Time format: 2021-07-30T07:08:38.000-0700
	// Time format: yyyy-MM-ddThh:mm:ss.sss+zzzz

	// Validate 
	int nRet = 1;
	int number_Pos[] = { /* year */ 0,1,2,3, /* month */ 5,6, /* day */ 8,9, /* hour */ 11,12, /* minute */ 14, 15, /* second */ 17,18,20,21,22, /* timezone */ 24,25,26,27 };
	int minus_Pos[] = { 4, 7 };
	int twoDot_Pos[] = { 13, 16 };
	int dot_Pos[] = { 19 };
	int sign_Pos[] = { 23 };

	int NPos = sizeof(number_Pos) / sizeof(number_Pos[0]);
	int NMinus = 2;
	int NTwoDot = 2;
	int NDot = 1;
	int NSign = 1;

	bool validate = true;

	validate &= time1.length() == 28;
	if (validate)
	{
		for (int i = 0; i < NPos; ++i)
		{
			if (time1[number_Pos[i]] < '0' || time1[number_Pos[i]] > '9')
			{
				validate = false;
				break;
			}
		}

		for (int i = 0; i < NMinus; ++i)
		{
			if (time1[minus_Pos[i]] != '-')
			{
				validate = false;
				break;
			}
		}

		for (int i = 0; i < NTwoDot; ++i)
		{
			if (time1[twoDot_Pos[i]] != ':')
			{
				validate = false;
				break;
			}
		}

		for (int i = 0; i < NDot; ++i)
		{
			if (time1[dot_Pos[i]] != '.')
			{
				validate = false;
				break;
			}
		}

		for (int i = 0; i < NSign; ++i)
		{
			if (time1[sign_Pos[i]] != '-' && time1[sign_Pos[i]] != '+')
			{
				validate = false;
				break;
			}
		}
	}

	if (validate)
	{
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int seconds;
		int millisecs;

		year = atoi(time1.substr(0, 4).c_str());
		month = atoi(time1.substr(5, 2).c_str());
		day = atoi(time1.substr(8, 2).c_str());
		hour = atoi(time1.substr(11, 2).c_str());
		minute = atoi(time1.substr(14, 2).c_str());
		seconds = atoi(time1.substr(17, 2).c_str());
		millisecs = atoi(time1.substr(20, 3).c_str());

		timezone = atoi(time1.substr(23, 3).c_str());	// Use 03 first digits only: (+/-)nnnn

		tmTime.tm_year = year - 1900;
		tmTime.tm_mon = month - 1;
		tmTime.tm_mday = day;
		tmTime.tm_hour = hour;
		tmTime.tm_min = minute;
		tmTime.tm_sec = seconds;

		nRet = 0;
	}

	return nRet;
}

std::string GeneralUtil::TimetoHumanReadable(double seconds)
{
	if (seconds < 86400) // Less than one day
	{
		double dblHour = seconds / 3600.0;
		int nHour =  dblHour;

		char szBuff[100];
		sprintf_s(szBuff, "%d Hour", nHour);
		return szBuff;
	}
	else 
	{
		double dblDays = seconds / 86400;
		char szBuff[100];
		sprintf_s(szBuff, "%.2f Day", dblDays);
		return szBuff;
	}
}
