#include "PreCompile.h"
#include "EngineTime.h"

EngineTime::EngineTime()
{
    QueryPerformanceFrequency(&Frequency);
    Reset();
}

EngineTime::~EngineTime()
{
}

void EngineTime::Reset()
{
    QueryPerformanceCounter(&Count);
}

double EngineTime::TimeCheck()
{
    LARGE_INTEGER PrevCount = Count;
    QueryPerformanceCounter(&Count);
    return static_cast<double>(Count.QuadPart - PrevCount.QuadPart) / Frequency.QuadPart;
}
