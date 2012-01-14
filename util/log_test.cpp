#include "logger.h"

using namespace ucb;

int main()
{
    CFileLogger log("err");
    log.Log("START\n");
    log.Log("This is a simple string.");
    log.Log("This is a message!\n");
    log.Log("Here is some number: %02d %02d %02d \n", 13, 2, 54);
    log.Log("END\n");

    return 0;
}
