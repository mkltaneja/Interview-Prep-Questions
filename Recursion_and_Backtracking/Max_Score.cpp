#include<iostream>
#include<vector>
using namespace std;

int maxscore(vector<string> &words, vector<int> &freq, vector<int> &score, int idx)
{
    if(idx == words.size())
        return 0;
        
    int score_without = maxscore(words, freq, score, idx+1);
    
    int scoreof_word = 0;
    bool valid = true;
    string word = words[idx];
    for(int i=0; i<word.size(); i++)
    {
        char ch = word[i];
        if(freq[ch - 'a'] == 0)
            valid = false;
        freq[ch - 'a']--;
        scoreof_word += score[ch - 'a'];
    }
    int score_with = 0;
    if(valid)
        score_with = scoreof_word + maxscore(words, freq, score, idx+1);
    for(int i=0; i<word.size(); i++)
        freq[word[i] - 'a']++;
        
    return max(score_without, score_with);
}

int main()
{
    int n,m;
    cin>>n;
    vector<string> words(n);
    for(int i=0; i<n; i++)
        cin>>words[i];
    cin>>m;
    vector<char> alpha(m);
    vector<int> freq(26,0);
    for(int i=0; i<m; i++)
    {
        cin>>alpha[i];
        freq[alpha[i] - 'a']++;   
    }
    vector<int> score(26,0);
    for(int i=0; i<26; i++)
        cin>>score[i];
    
    cout<<maxscore(words,freq,score,0);
}