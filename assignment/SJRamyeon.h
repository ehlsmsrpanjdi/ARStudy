#pragma once
#include <thread>
#include <vector>
#include <mutex>

namespace lsj
{
    class Store
    {
    public:
        Store(int _StoveCount, int _ToCookCount);

        void Cook();
        int GetCookedCount();
    private:
        //int CookedCount = 0;
        std::atomic_int CookedCount = 0;
        int StoveCount = 4;
        int ToCookCount = 10000000;
    };
}