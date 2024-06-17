#pragma once
#include <vector>
#include <Windows.h>
#include <functional>
#include <string_view>
#include <thread>

enum class ThreadWorkType
{
	Work,
	Destroy,
};

struct ThreadJob
{
	std::function<void()> WorkFunction;
};

class JYThread
{
public:
	// constrcuter destructer
	JYThread();
	~JYThread();

	bool IsEnd()
	{
		return Thread.joinable();
	}

	void SetFunction(std::function<void()> _Function);
	void SetOrder(int _Order);

	void Start(std::function<void()> _Function = nullptr);

protected:
	std::thread Thread;
	std::function<void()> CallBack;
	int Order = 0;
	bool End = false;

private:
	static void ThreadStartFunction(JYThread* _Thread);
};

class JYRamyeon
{
public:
	// constrcuter destructer
	JYRamyeon();
	~JYRamyeon();

	// delete Function
	JYRamyeon(const JYRamyeon& _Other) = delete;
	JYRamyeon(JYRamyeon&& _Other) noexcept = delete;
	JYRamyeon& operator=(const JYRamyeon& _Other) = delete;
	JYRamyeon& operator=(JYRamyeon&& _Other) noexcept = delete;

	void Initialize(int _StoveCount = 0, int _RamyeonCount = 0);
	void Work(std::function<void()> _Function);
	void End();

	void StartCooking();

protected:

private:
	HANDLE IOCPHandle = nullptr;
	int StoveCount = -1;
	int RamyeonCount = 0;
	std::atomic_bool IsRun = false;
	std::atomic_int RunStoveCount = 0;

	std::vector<std::shared_ptr<JYThread>> Stoves;

	static void ThreadPoolWorkFunction(JYRamyeon* _Pool, HANDLE _IOCPHandle);
	void Boil();
};

// ���� 100�� �ִ�.

// ������� 5�� �� �־��.

// IOCP�� �� �������� ����۾��� ���ļ� �� ����ϰ� �ֽ��ϴ�.

// IOCP�� �ڽſ��� ��ϵ� ��������� ������ ���� �����Ѵ�.

// waiting
// Release
// Paused

// ������ �� �������� ����
// [waiting][waiting][waiting][waiting][waiting]

// ���� ó���Ϸ��� ��ǻ�Ϳ� �ɾƾ� �Ѵٰ� ����.
// job qeueue [��][��][��][��][��][��][��][��][��][��]
// Waiting Queue �ٱ����� ����ϰ� �ִ� ���
// Release Queue ��ǻ�� �ڸ��� �ɾ��ִ� ���
// Paused Queue ��ǻ�� �ڸ��� �ɾ��ִµ� ������ �յ� ��� �ϳ������.

// ���� 1���� ���Ծ�.
// job qeueue [��][��][��][��][��][��][��][��][��][��]
// Waiting Queue [waiting][waiting][waiting][waiting]
// Release Queue [Release[��]]
// Paused Queue 

// ���� 1���� ���Ծ�.
// job qeueue [��][��][��][��][��][��][��][��][��][��]
// Waiting Queue [waiting][waiting][waiting]
// Release Queue [Release[��]][waiting[��]]
// Paused Queue 

// release�� �����ϴ� �������� 1���� ���� ������
// job qeueue [��][��][��][��][��][��][��][��][��][��]
// Waiting Queue [waiting][waiting][waiting] // ���� �ڸ��� ������ ���� ����
// Release Queue [waiting[��]]
// Paused Queue [Paused] 

// ���� 1�� ���Ծ�
// job qeueue [��][��][��][��][��][��][��][��][��][��]
// Waiting Queue [waiting][waiting][waiting]
// Release Queue [waiting[��]]
// Paused Queue [Paused[��]] 

// job qeueue [��][��][��][��][��][��][��][��][��][��]
// Waiting Queue [waiting][waiting][waiting]
// Release Queue [waiting[��]]
// Paused Queue [Paused] // ��ǻ�������� ���� ���� �ִ� ���°� �ɼ��� �ִ�.

// iocp�� �����ϴµ� ���� ǥ�����ڸ� 10�ʸ��� 1���� �شٰ� ġ��.
// 
// �����尡 ���� �Ѵٴ� ���� CPU�� �ھ��� �θ��� ��ǻ���� �ڸ��� �ɾƼ�
// ������ Ű�� ���η��� Ű�� ���� ���� �ϵ� ������ ��� �ؾ��ϴ����� ����.
// �����尡 ���� �ϱ� ���ؼ� ���� �غ� �ϴ� �۾��� ���ؽ�Ʈ ����Ī�̶�� �մϴ�
// ���ؽ�Ʈ ����Ī�� �Ͼ�� ���� �����带 busy�������� �մϴ�.
// 
// �����尡 �ڽ��� ����� �ִ� �����带 ���� �Ǹ� �翬�� ĳ������ �޸𸮵� ����
// �� cpu�� �ٸ� ������� ���Ҽ� �ִ� ���·� ����� �����ſ���.


