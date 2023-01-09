//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> s(wordList.begin() , wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> seq = q.front();
            string word = seq.back();
            int wordsz = word.size();
            q.pop();
            
            if(word == endWord)
            {
                ans.push_back(seq);
            }
            //update the last word and if new word found put new sequence in queue
            auto it = s.find(word);
            if(it != s.end())
                s.erase(it);
            for(int i = 0 ; i<wordsz ; i++)
            {
                char ch = word[i];
                for(char letter = 'a'; letter<='z'; letter++)
                {
                    word[i] = letter;
                    if(s.find(word) != s.end())
                    {
                        seq.push_back(word);
                        q.push(seq);
                        seq.pop_back();
                    }
                }
                word[i] = ch;
            }
        }
        if(ans.size() == 0)
            return {};
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	// cin >> tc;
    tc = 1;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends