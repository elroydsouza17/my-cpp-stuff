#include <iostream>

class DynamicArray {

    public:

        // TL O(n) each element has to be assigned 0, just allocating memory without initialising is O(1)
        DynamicArray(int capacity)
        {
            this->capacity = capacity;
            array = new int[capacity]{};
            size = 0;
        };

        ~DynamicArray()
        {
            delete[] array;
        }

        int* array;
        int size;
        int capacity;

        // O(1)
        int getSize()
        {
            return size;
        };

        //O(1)
        int get(int i)
        {
            if(i < size)
            {
                return array[i];
            }
        
            return -1;
        }

        //O(1)
        int insert(int i, int n)
        {
            if(i < size)
            {
                array[i] = n;
                return n;
            }

            return -1;
        }

        //O(n) however since the resize function won't be called always on average i.e. amortized its O(n);
        int pushBack(int n)
        {
            if(size < capacity)
            {
                array[size] = n;
                size = size + 1;
                return size;
            }

            resize();
            array[size] = n;
            size = size + 1;
            return size;
        }

        // O(1)
        int popBack()
        {
            int popElement = array[size - 1];
            array[size - 1] = 0;
            size = size - 1;

            return popElement;
        }

        //O(N) ELEMENTS NEED TO BE COPIED 
        void resize()
        {
            int* newArray = new int[capacity * 2];
            for(int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
            capacity = capacity * 2;
        }
};


int main()
{

    DynamicArray arr(5);
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.pushBack(4);
    arr.pushBack(5);

    arr.insert(4, 89);

    for(int i = 0; i < arr.size; i++)
    {
        std::cout << arr.get(i) << std::endl;
    }

    std::cout << "size is: " << arr.size << std::endl;

    arr.popBack ();


    for(int i = 0; i < arr.size; i++)
    {
        std::cout << arr.get(i) << std::endl;
    }

    std::cout << "size is: " << arr.size << std::endl;

    return 0;
}
