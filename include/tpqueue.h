#include <cassert>
 
struct SYM
{
	char ch;
	int  prior;
};

template<typename T>
class TPQueue
{
private:
    T *arr;
    int size;
    int begin,
        end;
    int count;
public:
    TPQueue(int = size);
    ~TPQueue();
 
    void push(const T &);
    T pop(); 
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};

template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue), 
    begin(0), end(0), count(0)
{
    arr = new T[size + 1];
}

template<typename T>
TPQueue<T>::~TPQueue()
{
    delete [] arr;
}

//the push function adds an element to the array and swaps elements by priority from end to begin
template<typename T>
void TPQueue<T>::push(const T & item)
{
	assert( count < size );

	arr[end++] = item;
	count++;

	if (end > size)
	end -= size + 1;
	
	T temp;
	int endTemp = end - 1, endTemp_ = end - 2;
	while(true)
	{
		if (endTemp_ == -1)
			break;
		if (arr[endTemp].prior > arr[endTemp_].prior)
		{
			temp = arr[endTemp];
			arr[endTemp] = arr[endTemp_];
			arr[endTemp_] = temp;	
		}
		else
			break;
		endTemp--;
		endTemp_--;
		if (endTemp == 0)
			endTemp_ = size;
		if (endTemp == -1)
			endTemp = size;
		if (endTemp_ == begin)
			break;
	}

}

template<typename T>
T TPQueue<T>::pop()
{
    assert( count > 0 );
 
    T item = arr[begin++];
    count--;
 
    if (begin > size)
        begin -= size + 1;
 
    return item;
}

template<typename T>
T TPQueue<T>::get() const 
{
    assert( count > 0 );
    return arr[begin];
}

template<typename T>
bool TPQueue<T>::isEmpty() const
{
  return count==0;
}

template<typename T>
bool TPQueue<T>::isFull() const
{
  return count==size;
}
