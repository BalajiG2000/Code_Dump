// Sets

void explainSet()
{
	set<int> s; // empty set
	s.insert(1); // {1}
	s.emplace(2); // {1,2}
	s.insert(4); // {1,2,4}
	s.insert(3); // {1,2,3,4}
	
	// Functionality of insert in vector
	// can be also, that only increases
	// efficiency
	
	// begin(),end(),rbegin(),rend(),size()
	// empty() and swap() are same as those of previous 
	
	// {1,2,3,4,5}
	auto it=s.find(3); // iterator points to 3
	auto it=s.find(6); // iterator points after set
	
	s.erase(5); // {1,2,3,4} // erase takes logarithmic time
	int cnt=s.count(1); // you can find element is present or not
	
	auto it = s.find(3);
	s.erase(it); // it will erase position of 3
	
	//{1,2,3,4,5}
	auto it1 =s.find(2);
	auto it2 =s.find(4);
	s.erase(it1,it2); // after erase {1,2,5}
	
	// lower_bound() and upper_bound() functions work in the same way
	// as in vector does.
	
	//Syntax
	auto it = s.lower_bound(2);
	auto it = s.upper_bound(3);
}
