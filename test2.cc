// CPP program to find all subsets by backtracking.
#include <bits/stdc++.h>
using namespace std;

// In the array A at every step we have two
// choices for each element either we can
// ignore the element or we can include the
// element in our subset
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
				vector<int>& subset, int index)
{
	res.push_back(subset);
	for (int i = index; i < A.size(); i++) {

		// include the A[i] in subset.
		subset.push_back(A[i]);

		// move onto the next element.
		subsetsUtil(A, res, subset, i + 1);

		// exclude the A[i] from subset and triggers
		// backtracking.
		subset.pop_back();
	}

	return;
}

// below function returns the subsets of vector A.
vector<vector<int> > subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int> > res;

	// keeps track of current element in vector A;
	int index = 0;
	subsetsUtil(A, res, subset, index);

	return res;
}

int n = 0;

void loopv(vector<vector<int>> &a, vector<int> v){      
 ++n;
 if(n >= v.size()){         
  a.insert(a.end(), vector<int>{});
  return;
 }

  bool repeat = false;      
 
 int size = a.size();
 for(size_t i = 0; i != size; ++i){     //traverse elements in a
   //vector<int> subv{a[i]};
   auto end = a.end();
   for(size_t j = 0; j != v.size(); ++j){        
    //cout << "loopv(vector<vector<int>> &a, vector<int> v)" << endl;
    vector<int> temp = a[i];
    for(auto iter = temp.begin(); iter!= temp.end(); ++iter){   // compare each element in temp to v[j], check that wether it is repeated(equal)
        if(*iter == v[j])
            repeat = true;
    }
    if(repeat == true){
        repeat = false;
        continue;
    }

    temp.push_back(v[j]);
    
    
    a.push_back(temp);
    
   }
   //cout << a.size() << endl;
 }
 loopv(a, v);
}      

// Driver Code.
int main()
{
	//vector<int> v = {1, 2, 3, 4, 5,};
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //vector<int> v{94, 34, 90, 68, 67, 100, 59, 45, 86, 24, 99, 0, 48, 29, 35, 7, 96, 57, 64, 92};
  // vector<int> v;
  // default_random_engine e(time(0));
  // uniform_int_distribution<unsigned> u(0,100);
  // for (size_t i = 0; i != 12; ++i)
  //   v.push_back(u(e));
  
  // auto begin = v.begin();
  // ++begin;
  // v.insert(begin, 42);
  vector<vector<int>> a;
  for(size_t i = 0; i != v.size(); ++i)
     a.push_back(vector<int> {v[i]});

  cout << a.size() << endl;
  cout << endl;
  loopv(a, v);
  cout << a.size() << endl;
  cout << endl;
  for(auto iter = a.begin(); iter != a.end(); ++iter){
    for(auto i = iter->begin(); i != iter-> end(); ++i)
      cout << *i << " " ;
    cout << endl;
  }
	return 0;
}
