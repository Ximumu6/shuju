template<typename T>
 
 
class DataType
{
public: 
	T key;
	DataType(T k):key(k){}
 
	DataType(void){}
 
	bool operator ==(const DataType &a)
	{
		return key == a.key;
	}
 
	bool operator !=(const DataType &a)
	{
		return key != a.key;
	}
	
};
 
enum KindOfItem{Empty, Active, Delete};
 
template<typename T>
class HashItem
{
public:
	DataType<T> data;
	KindOfItem info;
	HashItem(KindOfItem i = Empty):info(i){}
	HashItem(DataType<T> d, KindOfItem i = Empty):data(d),info(i){}
 
	bool operator ==(const HashItem & a)
	{
		return a.data == data;
	}
 
	bool operator !=(const HashItem &a)
	{
		return a.data != data;
	}
 
};
 
template<typename T>
class HashTable
{
public:
	const int size;
	HashItem<T> *ht;
	int FindItem(const HashItem<T> &a);
	int InsertItem(const HashItem<T> &a);
	int DeleteItem(const HashItem<T> &a);
	 
	HashTable(int k);
	~HashTable();
 
};
