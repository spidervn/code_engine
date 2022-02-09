#ifndef CODEENGINE_C_ENGINE_IMPL_ENGINE_LOG_LOG_H_
#define CODEENGINE_C_ENGINE_IMPL_ENGINE_LOG_LOG_H_

#include <fstream>
#include <ctime>

#define QUICKLOGFILE "SSS.log"
#define QUICKLOG(strLog) { std::ofstream outfile; outfile.open(QUICKLOGFILE, std::ios_base::app); std::time_t t = std::time(0); std::tm* now = std::localtime(&t); outfile << "Time:" << (now->tm_year + 1900) << "/" << (now->tm_mon+1) << "/" << (now->tm_mday) << " " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "; " << strLog << std::endl; outfile.close();  }

#endif