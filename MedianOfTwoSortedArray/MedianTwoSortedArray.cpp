#include <iostream>
#include <vector>

int pivot(std::vector<int>& a, int pivotVal, int inda, int indb)
{
    while (inda < indb)
    {
        while (a[inda] < pivotVal){inda++;}
        while (a[indb] >= pivotVal){indb--;}
        if (inda < indb)
        {
            int tmp = a[inda];
            a[inda] = a[indb];
            a[indb] = tmp;
        }
    }
    a[inda] = pivotVal;
    return inda;
}

void qsort(std::vector<int>& a, int low, int high)
{
    int pivotVal = a[low];
    int dividePos = pivot(a, pivotVal, low, high);

#if 1
    std::cout << " low: " << low;
    std::cout << " pivotVal: " << pivotVal;
    std::cout << " dividePos: " << dividePos << std::endl;
#endif

    if (dividePos - 1 > low)
    {
        qsort(a, low, dividePos - 1);
    }

    if (dividePos + 1 < high)
    {
        qsort(a, dividePos + 1, high);
    }
}

void print(const std::vector<int>& vec)
{
    for (int i = 0;i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int median(std::vector<int>& a, int low, int high)
{
    int pivotVal = a[low];
    int dividePos = pivot(a, pivotVal, low, high);

    if (dividePos == a.size() / 2)
    {
        return a[dividePos];
    }

#if 1
    std::cout << " low: " << low;
    std::cout << " pivotVal: " << pivotVal;
    std::cout << " dividePos: " << dividePos << std::endl;
#endif

    int result1,result2;
    if (dividePos - 1 > low)
    {
        result1 = median(a, low, dividePos - 1);
    }

    if (dividePos + 1 < high)
    {
        result2 = median(a, dividePos + 1, high);
    }
    return result1 == -1 ? result2 : result1;
}

int main(void)
{
    int a[] = {4, 0,12,143,4356,57,56,4,5,9,1,2,7,6};
    std::vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
    
    print(vec); 
    qsort(vec, 0, vec.size() - 1);
    print(vec);

    std::cout << "Median: " << median(vec, 0, vec.size() - 1) << std::endl;
    return 0;
}
