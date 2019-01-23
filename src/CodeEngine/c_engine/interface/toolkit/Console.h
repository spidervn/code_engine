/*
 * Console.h
 *  Created on: Jan 23, 2019
 */

#ifndef CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_CONSOLE_H_
#define CODEENGINE_C_ENGINE_INTERFACE_TOOLKIT_CONSOLE_H_

#include <iostream>
#include <vector>

class Console
{
public:
	template<class T>
	static void log(T t)
	{
		std::cout << t << std::endl;
	}

	template<class T>
	static void log(std::vector<T> v, std::string separator=" ")
	{
		for (int i=0;i<v.size();i++)
		{
			if (i>0)
			{
				std::cout <<separator;
			}
			std::cout << v[i];
		}

		std::cout << std::endl;
	}
};



#endif /* APP_UTIL_CONSOLE_H_ */
