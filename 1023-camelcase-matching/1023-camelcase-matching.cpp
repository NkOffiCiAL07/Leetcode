class Solution {
public:
	struct node{
		bool isEnd;
		struct node* link[52];
		node(){
			isEnd=false;
			for(int i=0;i<52;i++)
				link[i]=NULL;
		}
	};
	struct node* start=new node();
	void insertTrie(const string &s){
		struct node* ptr=start;
		int n=s.size();
		for(int i=0;i<n;i++){
			if(s[i]>='a' && s[i]<='z'){
				if(ptr->link[s[i]-'a']==NULL){
					ptr->link[s[i]-'a']=new node();
				}
				ptr=ptr->link[s[i]-'a'];
			}
			else{
				if(ptr->link[s[i]-'A'+26]==NULL){
					ptr->link[s[i]-'A'+26]=new node();
				}
				ptr=ptr->link[s[i]-'A'+26];	
			}
		}
		ptr->isEnd=1;
	}
	int findTrie(const string &s){
		struct node* ptr=start;
		int n=s.size();
		for(int i=0;i<n;i++){
			if(s[i]>='a' && s[i]<='z'){
				if(ptr->link[s[i]-'a']!=NULL){
					ptr=ptr->link[s[i]-'a'];
                }
			}
			else{
				if(ptr->link[s[i]-'A'+26]!=NULL){
					ptr=ptr->link[s[i]-'A'+26];
                }	
                else return false;
			}
		}
		return (ptr->isEnd);
	}

    bool check(string s,string t){
        int i=0,j=0;
        while(j<t.size() && i<s.size()){
            if(s[i]==t[j]) i++,j++;
            else if(s[i]>='a' && s[i]<='z') i++;
            else return false;
        }
        while(i<s.size()){
            if(s[i]>='a' && s[i]<='z') i++;
                else return false;
        }
        return (j==t.size());
    }
    vector<bool> camelMatch(vector<string>& queries, string pat) {
        vector<bool> ans;
        insertTrie(pat);
        for(auto i:queries){
            ans.push_back(findTrie(i));
        }
        return ans;
    }
}; 