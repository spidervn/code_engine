#include <iostream>
#include "c_engine/impl/engine/system/FileSystemUtil.h"

using namespace std;
int main(int argc, char const *argv[])
{
    class FHandler: public IFileSystemUtilHandler 
    {
        public:
        int counter;
        FHandler() { counter = 0; }
        int onVisitFile(const std::string enumeratingFolder, std::string filepath)
        {
            counter++;
            printf("VisitFile[%d]=%s\r\n", counter, filepath.c_str());
            return 0;
        }
    };

    FHandler fh;
    FileSystemUtil fsu;
    fsu.walk_through_files("C:\\BIN", &fh, true, 25);
    return 0;
}
