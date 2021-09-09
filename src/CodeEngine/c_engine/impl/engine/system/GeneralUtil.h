#ifndef CODEENGINE_C_ENGINE_IMPL_SYSTEM_GENERALUTIL_H_
#define CODEENGINE_C_ENGINE_IMPL_SYSTEM_GENERALUTIL_H_

#include <ctime>
#include <string>

class GeneralUtil
{
public:
	/*
	 * ISO 8601:
	 * 		Time format: 2021-07-30T07:08:38.000-0700
	 * 		Time format: yyyy-MM-ddThh:mm:ss.sss+zzzz

	 * Return:
	 *		0: Success	
	 * 		!=0: Code Error
	 */
	static int getISO8601Time(std::string time1, std::tm& tmTime, int& timezone);

	static std::string TimetoHumanReadable(double seconds);

};

#endif