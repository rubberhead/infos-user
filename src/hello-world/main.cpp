/*
 * "Hello, world!"
 * SKELETON IMPLEMENTATION TO BE FILLED IN FOR TASK 0
 * ============================================================================
 * DONE: 2023-01-19 17:11:13
 * 
 * ZC
 */

#include <infos.h>

int main(const char *cmdline)
{
    const char* hw = "Hello world!"; 
    if (cmdline == nullptr) { 
        printf("%s\n", hw);
    } else {
        // No buffer overflow in `printf` definition as seems.  
        // Also seems impossible to create a buffer overflow in console
        // but maybe there are other means to supply a cmdline input? 

        // Also this impl may allow for introduction of '\0' into cmdline[]. 
        // I haven't found a way to send a '\0' into cmdline though... 
        printf("%s\n", cmdline); 
    }
    return 0;
}
