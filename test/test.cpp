#include "platform.h"
#include "cpu.h"

int main()
{
    NCNN_LOGE("NCNN_VERSION_STRING: %s\n", NCNN_VERSION_STRING);

    int powersave = ncnn::get_cpu_powersave();
    NCNN_LOGE("powersave: %d\n", powersave);

    int cpu_count = ncnn::get_cpu_count();
    NCNN_LOGE("cpu_count: %d\n", cpu_count);

    return 0;
}