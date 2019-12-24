#include <iostream>

using namespace std;

void FunctionToBeFuzzed(const uint8_t *data, size_t size) {
    if (size > 0 && data[0] == 'H') {
        if (size > 1 && data[1] == 'I') {
            __builtin_trap();
        }
    }
}

extern "C" {


int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    FunctionToBeFuzzed(data, size);
    return 0;
    }
}

