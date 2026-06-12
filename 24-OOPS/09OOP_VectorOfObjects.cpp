#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// // return true if you want a to be ordered before b otherwise return false

// bool cmp(customer a, customer b) {
// 	if (a.age < b.age) {
// 		// we want a to be ordered before b
// 		// since we are sorting customer
// 		// on age in the inc. order
// 		return true;
// 	}

// 	return false;
// }

// class ageCmp {

// public:

// 	// return true if you want a to be ordered before b otherwise return false

// 	bool operator()(customer a, customer b) {
// 		if (a.age < b.age) {
// 			return true;
// 		}
// 		return false;
// 	}

// };

// return true if you want "a" to be ordered before "b" , otherwie return false 
bool cmp(customer a , customer b)
{
    return a.age <= b.age ;
}

class ageCmp{

    public :
    // return true if you want a to be ordered before b otherwise return false
        bool operator()(customer c1 , customer c2)
        {
            return c1.age <= c2.age ;
        }
};

int main() {

	vector<customer> v;

	customer c1("Ramanujan", 32, 'M', 1729);
	v.push_back(c1);
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

    //sort(v.begin() , v.end() , cmp);
    
    cout<<endl<<endl;

    ageCmp obj ;
    // annonymous object syntax -->
     sort(v.begin() , v.end() , ageCmp());
     
    // sort(v.begin() , v.end() , obj);

    for( customer c : v)
    {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;        
    }
    vector<int> v2 = {4,3,0,1,5};

    // sort(v2.begin() , v2.end() , greater<int>());// in this syntax , we are passing annonymous object of greater<int> type  , annonymous object means ki object hia but usska naam nahi hai 

    greater<int> obj2 ; // function object 

    sort(v2.begin() , v2.end() , obj2);

	
	return 0;
}