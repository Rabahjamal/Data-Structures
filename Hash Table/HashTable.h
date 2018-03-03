
template<class T, class V>
class Node
{
public:
	T key;
	V value;
	Node(T k, V v)
	{
		this->key = k;
		this->value = v;
	}
};


template<class T, class V>
class HashTable
{
	int HASH_TABLE_SIZE;
	Node<T, V> **hash_table;
	Node<T, V> *dummy_node;
public:
	HashTable();
	~HashTable();
	int size;
	int hashFunc(T key);
	void insert(T key, V value);
	int search(T key);
	void remove(T key);
	V get(T key);
	bool empty();
};

template<class T, class V>
HashTable<T, V>::HashTable()
{
	size = 0;
	HASH_TABLE_SIZE = 100;
	dummy_node = new Node<T, V>(-1, -1);
	hash_table = new Node<T, V>*[HASH_TABLE_SIZE];
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		hash_table[i] = NULL;
	}
}

template<class T, class V>
HashTable<T, V>::~HashTable()
{
	for(int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		delete hash_table[i];
	}
	delete dummy_node;
	delete[] hash_table;
}

template<class T, class V>
int HashTable<T, V>::hashFunc(T key)
{
	return key % HASH_TABLE_SIZE;
}

template<class T, class V>
void HashTable<T, V>::insert(T key, V value)
{
	if(search(key)==1)
		return;

	int index = hashFunc(key);
	while(hash_table[index] != NULL && hash_table[index] != dummy_node)
	{
		index++;
		index %= HASH_TABLE_SIZE;
	}
	if(hash_table[index] == dummy_node)
		delete hash_table[index];
	hash_table[index] = new Node<T, V>(key, value);
	size++;
}

template<class T, class V>
int HashTable<T, V>::search(T key)
{
	int i = 0;
	int index = hashFunc(key);
	while(true)
	{
		if(hash_table[index] == NULL)
			return -1;
		else if(hash_table[index]->key == key)
			return index;
		else
			index++,index %= HASH_TABLE_SIZE;
	}
}

template<class T, class V>
void HashTable<T, V>::remove(T key)
{
	int index = search(key);
	if(index != -1)
	{
		delete hash_table[index];
		hash_table[index] = dummy_node;
		size--;
	}
}


template<class T, class V>
V HashTable<T, V>::get(T key)
{
	int index = search(key);
	if(index != -1)
		return hash_table[index]->value;
	return NULL;
}

template<class T, class V>
bool HashTable<T, V>::empty()
{
	return size == 0;
}
