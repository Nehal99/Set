#include <iostream>
#include <set>

using namespace std;

int countSubsetSumWays(set<int> & sset, int target)
{
    int counter=0 ;
    set <int> :: iterator it = sset.begin();
    set <int> :: iterator it1 ;

    *it++ ;

    set<int> subSet ;
    for (int i = 1 ; it!=sset.end() ; it++)
    {
        subSet.insert(*it) ;
    }

    it = sset.begin();

    for (it ; it!=sset.end() ; it++)
    {
        if (*it == target)
        {
            counter++ ;
        }
        for (it1 = subSet.begin() ; it1 != subSet.end() ; it1++)
        {
            if ( (*it + *it1) == target )
            {
                counter++ ;
            }
        }
        it1 = subSet.begin() ;
        subSet.erase(*it1) ;
    }

    return counter ;
}

int main()
{
    set<int> sampleSet ;
    set<int> :: iterator itr ;
    int x , y , z;

    cout << " how many number would you like to enter ? " ;
    cin >> x ;

    cout << " Numbers ready to be inserted: " ;
    for (int i = 0 ; i < x ; i++)
    {
        cin >> y ;
        sampleSet.insert(y) ;
    }

    cout << " enter the target number: " ;
    cin >> z ;

    cout << " There are " << countSubsetSumWays(sampleSet , z ) << " ways to make " << z ;
}
