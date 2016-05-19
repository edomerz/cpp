
template<typename T>
class Singleton
{
public:
	static T& GetIns()
	{
		if(ins)
		{
			return NULL;
		}
		ins = new Singleton;
		atexit(&Clean);
		
		return(ins);
	}
	
	static void Clean()
	{
		this->~Singleton();
		ins = reinterpert_cast<T*>0xdeadbeef;
	}
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton& other_);
	Singleton& operator=(const Singleton& other_);
	
	static T* ins;
}
