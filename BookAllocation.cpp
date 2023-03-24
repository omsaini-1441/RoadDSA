/* You need to allocate all the books to "m" students such that the <b>maximum no. of pages assigned to a student is minimum.</b> */

#include<vector>
using namespace std;
/* check if ele at mid is the solution? i.e minimum, alot mid amount of books to each student and move on, if no. of students exceed given n ,then there is no solution on left side sode move the start to mid+1,otherwise u have a possible solutin os move the end to mid-1.
10 20 30 40    mid = 50    (10 20) (30) (40) now n= 3 so no solution behind 50
                for 51 to 100 space    mid = 75  (10 20 30) (40) n=2 so possible solution , lises between 51 to 75 sp move the end to 74

*/
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;            
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];           // maintaining a sum of books one student gets
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;      // start of search space
    int sum = 0;    
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];        
    }
    int e = sum;        // end of search space which should be summ of all elements
    int ans = -1;
    int mid = s + (e-s)/2;                          // finding middle
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
