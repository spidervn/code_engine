#ifndef CODEENGINE_CENGINE_IMPL_EXAMPLE_CPARSESENTENCE_H_
#define CODEENGINE_CENGINE_IMPL_EXAMPLE_CPARSESENTENCE_H_

#include <vector>
#include <string>

class CParseSentence
{
private:
    /* data */
public:
    CParseSentence(/* args */);
    ~CParseSentence();

    int segmentASentence(std::string s, std::vector<std::string>& v);

    int segmentAFile(std::string fileContent, std::vector<std::vector<std::string>>& v);
};

#endif