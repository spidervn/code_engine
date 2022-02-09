/*
 * Console.h
 *  Created on: April 23 2021
 */

#ifndef CODEENGINE_C_ENGINE_LAB_PROB_CPRINCIPLETEST_H_
#define CODEENGINE_C_ENGINE_LAB_PROB_CPRINCIPLETEST_H_

namespace PrincipleTest
{
    struct Event
    {
        int ID;
        int Type;
    };

    struct UniversalInterest
    {
        int t;  // Index of time
    };

    class Principal
    {
        public:
            void Space()
            {
            }
    };
    
} // namespace PrincipleTest


class CPrincipleTest
{
private:
    /* data */
public:
    CPrincipleTest(/* args */);
    ~CPrincipleTest();

    int ConditionalTest();
};



#endif