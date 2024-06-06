#include "PreCompile.h"
#include "SJRamyeon.h"

lsj::Store::Store(int _StoveCount, int _ToCookCount)
    : StoveCount(_StoveCount), ToCookCount(_ToCookCount)
{
}

void lsj::Store::Cook()
{
    std::vector<std::thread*> Threads;
    Threads.resize(StoveCount);

    int PerStoveCount = ToCookCount / StoveCount;
    std::function<void()> Job = [this, PerStoveCount]() mutable {
        while (PerStoveCount)
        {
            ++CookedCount;
            --PerStoveCount;
        }
    };

    for (int i = 0; i < Threads.size(); ++i)
    {
        Threads[i] = new std::thread(Job);
    }

    for (int i = 0; i < Threads.size(); ++i)
    {
        Threads[i]->join();
        delete Threads[i];
    }

    Threads.clear();
}

int lsj::Store::GetCookedCount()
{
    return CookedCount;
}
