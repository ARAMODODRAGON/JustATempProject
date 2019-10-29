#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H
#include <vector>
#include <string>

class Part;
class Transform;

class GameObject {
private:
	std::vector<Part*> partslist;
	std::string name;
	Transform* transform;
public:
	GameObject(std::string name);
	~GameObject();

	template<typename T>
	T* CreatePart();

	Transform* GetTransform();
	const std::string& GetName();

	virtual int Init();
	virtual int Exit();
	virtual void Update(const float delta);
	virtual void Render();

};


#endif // !GAMEOBJECT_H
