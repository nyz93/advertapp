#ifndef ACTION_H
#define ACTION_H
template <class T>
class Action
{
protected:
	T result;
public:
	T getResult() { return result; }
};
#endif 
