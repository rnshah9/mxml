#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>
#include "mxml.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString(1000);

    mxml_node_t* node = mxmlLoadString(NULL, str.c_str(), NULL);

    mxmlRelease(node);
    return 0;
}
