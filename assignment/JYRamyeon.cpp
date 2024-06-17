#include "PreCompile.h"
#include "JYRamyeon.h"

#include <assert.h>

JYThread::JYThread()
{

}

JYThread::~JYThread()
{
	if (true == Thread.joinable())
	{
		Thread.join();
	}
}

void JYThread::SetFunction(std::function<void()> _Function)
{
	CallBack = _Function;
}

void JYThread::SetOrder(int _Order)
{
	Order = _Order;
}

void JYThread::ThreadStartFunction(JYThread* _Thread)
{
	_Thread->CallBack();
	_Thread->End = true;
}

void JYThread::Start(std::function<void()> _Function/* = nullptr*/)
{
	if (true == Thread.joinable())
	{
		return;
	}

	if (nullptr != _Function)
	{
		SetFunction(_Function);
	}

	if (nullptr == CallBack)
	{
		return;
	}

	Thread = std::thread(std::bind(ThreadStartFunction, this));
}

JYRamyeon::JYRamyeon()
{

}

JYRamyeon::~JYRamyeon()
{
	End();
}

void JYRamyeon::Initialize(int _StoveCount/* = 0*/, int _RamyeonCount/* = 0*/)
{
	StoveCount = _StoveCount;
	RamyeonCount = _RamyeonCount;

	if (0 >= StoveCount)
	{
		SYSTEM_INFO Info;
		GetSystemInfo(&Info);
		StoveCount = Info.dwNumberOfProcessors;
	}

	IOCPHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, StoveCount);

	if (nullptr == IOCPHandle)
	{
		std::string ErrorText = std::string("iocp 핸들 생성에 실패했습니다.");
		MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);
	}

	Stoves.resize(StoveCount);
	IsRun = true;
	RunStoveCount = StoveCount;

	for (size_t i = 0; i < Stoves.size(); i++)
	{
		Stoves[i] = std::make_shared<JYThread>();
		Stoves[i]->SetOrder(i + 1);
		Stoves[i]->Start(std::bind(ThreadPoolWorkFunction, this, IOCPHandle));
	}

	std::cout << "JY Ramyeon Store Open!" << "\n";
}

void JYRamyeon::ThreadPoolWorkFunction(JYRamyeon* _Pool, HANDLE _IOCPHandle)
{
	DWORD Byte;
	ULONG_PTR Ptr;
	LPOVERLAPPED OverLapped = nullptr;

	while (_Pool->IsRun)
	{
		GetQueuedCompletionStatus(_IOCPHandle, &Byte, &Ptr, &OverLapped, INFINITE);

		ThreadWorkType Type = static_cast<ThreadWorkType>(Byte);

		if (Type == ThreadWorkType::Destroy)
		{
			break;
		}

		ThreadJob* NewJob = reinterpret_cast<ThreadJob*>(Ptr);
		NewJob->WorkFunction();
		delete NewJob;
		NewJob = nullptr;
	}

	--_Pool->RunStoveCount;
}

void JYRamyeon::Work(std::function<void()> _Function)
{
	ThreadJob* NewJob = new ThreadJob();
	NewJob->WorkFunction = _Function;
	PostQueuedCompletionStatus(IOCPHandle, static_cast<BYTE>(ThreadWorkType::Work), reinterpret_cast<__int64>(NewJob), nullptr);
}

void JYRamyeon::End()
{
	IsRun = false;

	while (RunStoveCount)
	{
		PostQueuedCompletionStatus(IOCPHandle, static_cast<BYTE>(ThreadWorkType::Destroy), 3333333, nullptr);
	}

	std::cout << "Complete!" << "\n";
}

void JYRamyeon::StartCooking()
{
	if (RamyeonCount <= 0)
	{
		End();
	}

	Work(std::bind(Boil));
}

void JYRamyeon::Boil()
{
	--RamyeonCount;
	std::cout << RamyeonCount << "/100000 Left" << "\n";
}