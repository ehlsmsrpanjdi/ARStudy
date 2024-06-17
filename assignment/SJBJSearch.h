#pragma once

class SJBJSearch
{
public:
	// constructor destructor
	SJBJSearch();
	~SJBJSearch();

	// delete Function
	SJBJSearch(const SJBJSearch& _Other) = delete;
	SJBJSearch(SJBJSearch&& _Other) noexcept = delete;
	SJBJSearch& operator=(const SJBJSearch& _Other) = delete;
	SJBJSearch& operator=(SJBJSearch&& _Other) noexcept = delete;

	void BJ1926();

	void BJ2178();

protected:

private:
	void visit(int x, int y);
};

