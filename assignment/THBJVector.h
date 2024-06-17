#pragma once

// Ό³Έν :
class THBJVector
{
public:
	// constrcuter destructer
	THBJVector();
	~THBJVector();

	// delete Function
	THBJVector(const THBJVector& _Other) = delete;
	THBJVector(THBJVector&& _Other) noexcept = delete;
	THBJVector& operator=(const THBJVector& _Other) = delete;
	THBJVector& operator=(THBJVector&& _Other) noexcept = delete;

protected:

private:

};

