#include <iostream>

void unionArrays(int array1 [], int array2 [], int n1, int n2);
void unionArraysTwoPointers(int array1 [], int array2 [], int n1, int n2);


int main()1  
{
    int array1[] = { 1, 2, 3, 3, 4, 5, 5, 12};
    int array2[] = {2, 3, 4, 6, 6, 7, 9, 9 , 12};

    // unionArrays(array1, array2, 7, 5);
    unionArraysTwoPointers(array1, array2, 8, 9);
}

void unionArrays(int array1 [], int array2 [], int n1, int n2)
{
    int temp = -1;
    int unionArrayPtr = 0;
    int unionArray [n1 + n2];

    for (int i = 0; i < n1; i++)
    {
        if(temp != array1[i])
        {
            unionArray[unionArrayPtr] = array1[i];
            temp = array1[i];
            unionArrayPtr++;
        }
    }

    temp = -1;
    int position = 0;
    for(int j = 0; j < n2; j++)
    {
        if(temp != array2[j])
        {
            for(int k = position; k < unionArrayPtr; k++)
            {
                if(array2[j] == unionArray[k])
                {
                    position = k;
                    break;
                }
                else if(array2[j] > unionArray[k])
                {
                    unionArray;
                }
            }
        }
    }

    for (int i = 0; i < unionArrayPtr; i++)
    {
        std::cout << " " << unionArray[i];
    }
}

void unionArraysTwoPointers(int array1 [], int array2 [], int n1, int n2)
{
    int pointer1 = 0;
    int pointer2 = 0;
    int unionArr[n1 + n2];
    int unionPosition = 0;


    while (pointer1 < n1 && pointer2 < n2)
    {
        if(array1[pointer1] <= array2[pointer2])
        {
            if(unionPosition == 0 || unionArr[unionPosition - 1] != array1[pointer1])
            {
                unionArr[unionPosition] = array1[pointer1];
                unionPosition++;
            }

            pointer1++;
        }
        else
        {
            if(unionPosition == 0 || unionArr[unionPosition - 1] != array2[pointer2])
            {
                unionArr[unionPosition] = array2[pointer2];
                unionPosition++;
            }

            pointer2++;
        }
    }

    while(pointer1 < n1)
    {
            if(unionPosition == 0 || unionArr[unionPosition - 1] != array1[pointer1])
            {
                unionArr[unionPosition] = array1[pointer1];

                unionPosition++;
            }
            pointer1++;

    }

    while(pointer2 < n2)
    {
            if(unionPosition == 0 || unionArr[unionPosition - 1] != array2[pointer2])
            {
                unionArr[unionPosition] = array2[pointer2];

                unionPosition++;
            }
            pointer2++;

    }


    for(int i = 0; i < unionPosition; i++)
    {
        printf("  %d",unionArr[i]);
    }

}