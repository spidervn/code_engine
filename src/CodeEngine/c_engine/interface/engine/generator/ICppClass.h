#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_GENERATOR_ICPPCLASS_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_GENERATOR_ICPPCLASS_H_

#include <string>
#include <vector>

class ICppClass
{
    public:
        virtual ~ICppClass() {}
        virtual std::string generate_HeaderFile(std::string projectCode,
                                        std::string relative_Path,
                                        std::string className) = 0;

        virtual int analyzeHeaderFile(
            std::string fileName
        ) = 0;

};

#endif