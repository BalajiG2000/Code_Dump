// all AllPossible SubStrings using bit

vector<string> AllPossibleStrings(string s){
	int n = s.length();
		    
	vector<string> v;
	
    for(int num=0;num<(1<<n);num++){
	    string st="";
	    for(int i=0; i < n; i++){
	        if(num&(1<<i)){
	            st+=s[i];
            }
        }
        if(st!="")
           v.push_back(st);
    }
    
    sort(v.begin(),v.end());
    
    return v;
}