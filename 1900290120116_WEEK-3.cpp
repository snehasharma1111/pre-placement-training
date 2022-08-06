   binarySearch(arr, x, low, high)
        repeat till low = high
               mid = (low + high)/2
                   if (x == arr[mid])
                   return mid
   
                   else if (x > arr[mid]) // x is on the right side
                       low = mid + 1
   
                   else                  // x is on the left side
                       high = mid - 1



class Heap
{
        vector <int> v; // array to store the data
        bool min_heap; // by default we will generate a min_heap
public:
        // constructor
        Heap(int default_size = 10, bool type = true)
        {
                v.reserve(default_size);
                v.push_back(-1); // to block the 0th index
                min_heap = type;
        }
 
        //custom comparator function
        bool compare(int a, int b)
        {       
                if(min_heap)
                        return a < b;
                return a > b;
        }
};