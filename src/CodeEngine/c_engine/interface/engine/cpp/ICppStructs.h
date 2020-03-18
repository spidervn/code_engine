#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPSTRUCTS_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPSTRUCTS_H_

#include <string>
#include <vector>


#define INHERIT_PUBLIC      1
#define INHERIT_PROTECTED   2
#define INHERIT_PRIVATE     3

struct CppInheritanceDef
{
    /* data */
    std::string class_Name;
    int inherit_type;
};

struct CppClassDef
{
    /* data */
    std::string class_Name;
    std::vector<CppInheritanceDef> vInheritance;
    std::string class_Content;   

    CppClassDef()
    {
        class_Name = "";
        vInheritance.clear();
    }


};


#endif