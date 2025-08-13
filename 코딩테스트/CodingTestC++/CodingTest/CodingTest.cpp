#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Component
{
public:
	Component() {}
	virtual void Update()
	{
		cout << "기본 업데이트" << endl;
	}
	~Component()
	{
		cout << "컴포넌트 소멸" << endl;
	}
};

class HealthComponent : public Component
{
public:
	HealthComponent() {}
	void Update() override
	{
		cout << "체력 업데이트" << endl;
	}
};

class PositionComponent : public Component
{
public:
	PositionComponent() {}
	void Update() override
	{
		cout << "위치 업데이트" << endl;
	}
};

class AIComponent : public Component
{
public:
	AIComponent() {}
	void Update() override
	{
		cout << "AI 업데이트" << endl;
	}
};

class ComponentManager
{
private:
	vector<Component*> allComponent;

public:
	ComponentManager()
	{
		allComponent.push_back(new Component());
		allComponent.push_back(new HealthComponent());
		allComponent.push_back(new PositionComponent());
		allComponent.push_back(new AIComponent());
	}

	void AllComponentUpdate()
	{
		for (auto c : allComponent)
		{
			c->Update();
		}
	}

	~ComponentManager()
	{
		for (auto c : allComponent)
		{
			delete c;
		}
	}
};

int main()
{
	ComponentManager cm;

	cm.AllComponentUpdate();
}
